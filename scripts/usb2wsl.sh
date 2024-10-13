### Step 1: Install USBIPD-WIN in Windows
https://learn.microsoft.com/en-us/windows/wsl/connect-usb

### Step 2: Open PowerShell as administrator
usbipd list
usbipd bind --busid 2-1
usbipd attach --wsl --busid 2-1

### Step 3: Open WSL
lsusb

### Step 4: Detach USB from WSL (optional)
usbipd detach --busid 2-1
