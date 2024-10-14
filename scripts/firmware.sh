
###############################################################################
### NINA Firmware Checker
###############################################################################

### Install Related Library
arduino-cli lib update-index
arduino-cli lib install WiFiNINA SD AudioZero IRremote Arduino_LSM6DS3

### Get NINA Code
apt -y install git
cd /home/engineer/zura/third-party/
git clone https://github.com/arduino-libraries/WiFiNINA.git

# Check NINA Firmware Version
cd /home/engineer/zura/third-party/WiFiNINA/examples/Tools/
arduino-cli compile --fqbn arduino:samd:nano_33_iot CheckFirmwareVersion
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:samd:nano_33_iot CheckFirmwareVersion
picocom -b 9600 -r -l /dev/ttyACM0


###############################################################################
### NINA Firmware Updater
###############################################################################

# REFER : https://arduino-insights.com/board/mkr-wifi-1010/wifi-firmware-update-nina-w102/

### Get NINA Updater Code
cd /home/engineer/zura/third-party/
git clone https://github.com/arduino/FirmwareUpdater.git
wget --quiet https://github.com/arduino/arduino-fwuploader/releases/download/2.2.0/arduino-fwuploader_2.2.0_Linux_64bit.tar.gz
#
tar -cvf ./FirmwareUpdater-before.tar ./FirmwareUpdater/
tar -xvf arduino-fwuploader_2.2.0_Linux_64bit.tar.gz --directory=FirmwareUpdater
rm -rf arduino-fwuploader_2.2.0_Linux_64bit.tar.gz

tar -cvf ./FirmwareUpdater-after.tar ./FirmwareUpdater/
cd FirmwareUpdater

cd /home/engineer/zura/third-party/FirmwareUpdater/
./arduino-fwuploader firmware list
### Auto select latest firmware
./arduino-fwuploader firmware flash -b arduino:samd:nano_33_iot -a /dev/ttyACM0
### Manually specific a NINA firmware version
# ./arduino-fwuploader firmware flash -b arduino:samd:nano_33_iot -a /dev/ttyACM0 -m NINA@1.4.3