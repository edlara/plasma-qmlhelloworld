# Template for Plasma Applets
Plasma Applet Template

Author: Eduardo Lara

Released under GPL 2.0+

Compile and Install:
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DLIB_INSTALL_DIR=/usr/lib64/qt5 ..
make
sudo make install
kbuildsycoca5
plasmawindowed org.custom.plasma.helloworld

Uninstall:
sudo make uninstall
sudo rm -rf /usr/lib64/qt5/qml/org/custom/plasma/HelloWorld/ /usr/share/plasma/plasmoids/org.custom.plasma.helloworld/
kbuildsycoca5

