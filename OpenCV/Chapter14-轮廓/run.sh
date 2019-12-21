gcc -g example-14-1.cc -I /opt/opencv/include/opencv4 -L /opt/opencv/lib -lstdc++ -lopencv_imgcodecs -lopencv_highgui \
-lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video -o example-14-1
./example-14-1 ../data/input/fruits.jpg
