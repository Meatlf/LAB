mkdir build_android
cd build_android
cmake -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI=arm64-v8a -DANDROID_TOOLCHAIN=clang -DANDROID_STL=c++_static ..
make -j3
