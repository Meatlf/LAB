sh build_android.sh
adb devices
adb push info.xml /mnt/tztang
adb push build_android/Demo /mnt/tztang
