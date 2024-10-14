sudo su -
cd /home/alice/fyp/test/

arduino-cli board list

# blink
arduino-cli compile --fqbn arduino:samd:nano_33_iot blink
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:samd:nano_33_iot blink
picocom -b 9600 -r -l /dev/ttyACM0