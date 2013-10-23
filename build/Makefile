
CFLAGS = -I/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/include/c++ -L/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/lib -g3 -Wall

PATH := /opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin:/opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin/armv5te-poky-linux-gnueabi:$(PATH)

CC = g++
CROSS_CC = arm-poky-linux-gnueabi-g++
CV_CFLAGS = -I/usr/local/include/opencv -I/usr/local/include/opencv2

CV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so 

default: angstrom_avoid_obj
	@echo Executable located in bin


all: angstrom_avoid_obj videoStream facedetect
	@echo Execulable located in bin

all: angstrom_avoid_obj videoStream
	@echo Executable located in bin

facedetect: faceDetect.o
	$(CC) $(CV_CFLAGS) $(CV_LIBS) faceDetect.o -o ../bin/faceDetect -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann

faceDetect.o: ../src/faceDetect.cpp
	$(CC) $(CV_LIBS) -c ../src/faceDetect.cpp

angstrom_avoid_obj: angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o 
	$(CROSS_CC) $(CFLAGS) angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o -o ../bin/angstrom_avoid_obj

angstrom_avoid_obj.o: ../src/angstrom_avoid_obj.cpp
	$(CROSS_CC) $(CFLAGS) -c ../src/angstrom_avoid_obj.cpp

Hexapod.o: ../src/Hexapod.cpp ../src/Hexapod.h
	$(CROSS_CC) $(CFLAGS) -c ../src/Hexapod.cpp

AdaFruitServoDriver.o: ../src/AdaFruitServoDriver.cpp ../src/AdaFruitServoDriver.h
	$(CROSS_CC) $(CFLAGS) -c ../src/AdaFruitServoDriver.cpp

Srf08.o: ../src/Srf08.cpp ../src/Srf08.h
	$(CC) $(CFLAGS) -c ../src/Srf08.cpp

Matrix.o: ../src/Matrix.cpp ../src/Matrix.h
	$(CROSS_CC) $(CFLAGS) -c ../src/Matrix.cpp

SlaveDevice.o: ../src/SlaveDevice.cpp ../src/SlaveDevice.h
	$(CROSS_CC) $(CFLAGS) -c ../src/SlaveDevice.cpp

videoStream: videoStream.o
	$(CROSS_CC) $(CV_CFLAGS) $(CV_LIBS) videoStream.o -o ../bin/videoStream

videoStream.o: ../src/videoStream.cpp
	$(CROSS_CC) $(CV_CFLAGS) $(CV_LIBS) -c ../src/videoStream.cpp

clean:
	$(RM) *.o *~ ../bin/*
