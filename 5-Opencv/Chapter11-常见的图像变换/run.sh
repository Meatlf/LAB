gcc -g example_11-01.cpp -I /opt/opencv/include/opencv4 -L /opt/opencv/lib -lstdc++ -lopencv_imgcodecs -lopencv_highgui \
-lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video -o example_11-01
# ./example_11-01 ../data/input/fruits.jpg

gcc -g example_11-02.cpp -I /opt/opencv/include/opencv4 -L /opt/opencv/lib -lstdc++ -lopencv_imgcodecs -lopencv_highgui \
-lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_video -o example_11-02
./example_11-02 ../data/input/fruits.jpg
