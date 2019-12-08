# DECLARATION
## Based on Linux or Android system, I successfully compiled and used minixml static library with CMake.

## NOTICE
### Make sure of commenting out ```#define HAVE_PTHREAD_H 1``` in the``` config.h``` file;

## Run on Linux system
```
sh run_on_linux.sh
```

## Build on Linux system using Andorid NDK toolchain
```
sh build_android.sh
```

## Build on Linux system using Android NDK toolchain ,then push execuable file and configuration files to Android system
### Make sure of connnetint to Android device
```
sh push_to_android.sh
```

## Clean 
```
sh clean.sh
```
