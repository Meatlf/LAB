gcc -g example-5-1.cc -I /opt/opencv/include/opencv4 -L /opt/opencv/lib -lstdc++ -lopencv_imgcodecs -lopencv_highgui \
-lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video -o example-5-1
./example-5-1 ../data/input/lena.jpg ../data/input/fruits.jpg 150 150 150 150 0.1 0.9
