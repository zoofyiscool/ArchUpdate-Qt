#!/bin/bash
if [ "$EUID" -ne 0 ]
  then echo "Please run as root!"
  exit
fi
echo You must install the gksu package with an AUR helper such as yay to be able to run the program as root!
sleep 1
wget https://github.com/zoofyiscool/ArchUpdate-Qt/raw/main/bin/UpdateArch
echo Installation process starting!
cp UpdateArch /usr/bin/UpdateArch
touch /usr/share/applications/UpdateArch.desktop
echo "
[Desktop Entry]
Type=Application
Encoding=UTF-8
Name=Update Arch
Comment=A Qt GUI tool to update Arch Linux
Exec=gksu exec /usr/bin/UpdateArch
Terminal=false" >> /usr/share/applications/UpdateArch.desktop
echo Installed!
echo Type Update Arch in your menu to launch!
