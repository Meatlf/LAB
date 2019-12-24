gcc -g example_02_01.cc -I /opt/opencv/include/opencv4 -L /opt/opencv/lib -lstdc++ -lopencv_imgcodecs -lopencv_highgui \
-lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video -o example_02_01
./example_02_01 ../data/input/fruits.jpg
