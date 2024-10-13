###############################################################################
### Arduino-CLI
###############################################################################

### Step 1: Install Arduino-CLI
# Refer: https://arduino.github.io/arduino-cli/installation/
sudo su -
apt -y install curl wget
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=/usr/bin sh
arduino-cli version

### Step 2: Prepare board library
arduino-cli core update-index
arduino-cli core install arduino:samd
arduino-cli core list

###############################################################################
### Enable Serial Debug and Remote Sync
###############################################################################

# Step 1: Install picocom
apt -y install picocom

# Step 2: Enter serial com
picocom -b 9600 -r -l /dev/ttyACM0

# Step 3: Quit serial com
# To exit picocom, use CTRL-A followed by CTRL-X.

###############################################################################
### Software Libraries
###############################################################################

### Install related library
arduino-cli lib update-index
arduino-cli lib install WiFiNINA

###############################################################################
### Timestamp for PICOCOM
###############################################################################
apt -y install screen moreutils
picocom -b 9600 -r -l /dev/ttyACM0 | ts

###############################################################################
### Detect Hardware
###############################################################################
apt -y install hwinfo

### Senario 1.A : Plug in Arduino NANO 33 IoT as NORMAL start up mode
hwinfo | grep Arduino
#   Model: "Arduino SA Arduino NANO 33 IoT"
#   Vendor: usb 0x2341 "Arduino SA"
#   Device: usb 0x8057 "Arduino NANO 33 IoT"

### Senario 1.B : Plug in Arduino NANO 33 IoT as BOOTLOADER start up mode
hwinfo | grep Arduino
#   Model: "Arduino SA Arduino NANO 33 IoT"
#   Vendor: usb 0x2341 "Arduino SA"
#   Device: usb 0x0054 "Arduino NANO 33 IoT"
