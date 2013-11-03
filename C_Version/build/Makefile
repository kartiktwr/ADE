
CFLAGS = -I/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/include/c++ -L/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/lib -g3 -Wall

PATH := /opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin:/opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin/armv5te-poky-linux-gnueabi:$(PATH)

CC = g++
CROSS_CC = arm-poky-linux-gnueabi-gcc
CV_CFLAGS = -I/usr/local/include/opencv -I/usr/local/include/opencv2

CV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so 

default: toby
	@echo Executable located in bin

toby: toby.o hexapod.o adaFruitDriver.o slaveDevice.o
	$(CROSS_CC) $(CFLAGS) toby.o hexapod.o adaFruitDriver.o slaveDevice.o -o ../bin/toby -lm

toby.o: ../src/toby.c
	$(CROSS_CC) $(CFLAGS) -c ../src/toby.c

arm.o: ../src/arm.c
	$(CROSS_CC) $(CFLAGS) -c ../src/arm.c ../src/arm.h

hexapod.o: ../src/hexapod.c ../src/hexapod.h
	$(CROSS_CC) $(CFLAGS) -c ../src/hexapod.c ../src/hexapod.h

adaFruitDriver.o: ../src/adaFruitDriver.c ../src/adaFruitDriver.h
	$(CROSS_CC) $(CFLAGS) -c ../src/adaFruitDriver.c ../src/adaFruitDriver.h

slaveDevice.o: ../src/slaveDevice.c ../src/slaveDevice.h
	$(CROSS_CC) $(CFLAGS) -c ../src/slaveDevice.c ../src/slaveDevice.h

clean:
	$(RM) *.o *~ ../bin/*
