## Include files and source files are in different directories
## Nested folders and Nested library

## References
[CMake by Example](https://mirkokiefer.com/cmake-by-example-f95eb47d45b1)

## Libraries structure
```
main.cc
   ├── Functions 
   └── Add     └── MathFunctions
```

## Dircetories

```
.
├── clean.sh
├── CMakeLists.txt
├── inc
│   ├── add.h
│   ├── fun.h
│   └── MathFunctions.h
├── main.cc
├── README.md
├── run.sh
└── src
    ├── algroithm
    │   ├── add.cc
    │   └── CMakeLists.txt
    ├── CMakeLists.txt
    └── function
        ├── build.sh
        ├── clean.sh
        ├── CMakeLists.txt
        ├── fun.cc
        └── math
            ├── build.sh
            ├── CMakeLists.txt
            └── MathFunctions.cc

5 directories, 18 files
```