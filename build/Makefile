#CC = arm-linux-gnueabi-g++-4.6
#CFLAGS = -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -L/usr/arm-linux-gnueabi/lib -g3 -Wall
CFLAGS = -I/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/include/c++ -L/opt/alphalem/0.1.0/sysroots/armv5te-poky-linux-gnueabi/usr/lib -g3 -Wall

PATH := /opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin:/opt/alphalem/0.1.0/sysroots/x86_64-pokysdk-linux/usr/bin/armv5te-poky-linux-gnueabi:$(PATH)


CC = arm-poky-linux-gnueabi-g++
CV_CFLAGS = `pkg-config --cflags opencv`
CV_LIBS = `pkg-config --libs opencv`

default: angstrom_avoid_obj
	@echo Executable located in bin

all: angstrom_avoid_obj videoStream
	@echo Executable located in bin

angstrom_avoid_obj: angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o 
	$(CC) $(CFLAGS) angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o -o ../bin/angstrom_avoid_obj

angstrom_avoid_obj.o: ../src/angstrom_avoid_obj.cpp
	$(CC) $(CFLAGS) -c ../src/angstrom_avoid_obj.cpp

Hexapod.o: ../src/Hexapod.cpp ../src/Hexapod.h
	$(CC) $(CFLAGS) -c ../src/Hexapod.cpp

AdaFruitServoDriver.o: ../src/AdaFruitServoDriver.cpp ../src/AdaFruitServoDriver.h
	$(CC) $(CFLAGS) -c ../src/AdaFruitServoDriver.cpp

Srf08.o: ../src/Srf08.cpp ../src/Srf08.h
	$(CC) $(CFLAGS) -c ../src/Srf08.cpp

Matrix.o: ../src/Matrix.cpp ../src/Matrix.h
	$(CC) $(CFLAGS) -c ../src/Matrix.cpp

SlaveDevice.o: ../src/SlaveDevice.cpp ../src/SlaveDevice.h
	$(CC) $(CFLAGS) -c ../src/SlaveDevice.cpp

videoStream: videoStream.o
	$(CC) $(CV_CFLAGS) $(CV_LIBS) videoStream.o -o ../bin/videoStream

videoStream.o: ../src/videoStream.cpp
	$(CC) $(CV_CFLAGS) $(CV_LIBS) -c ../src/videoStream.cpp

clean:
	$(RM) *.o *~ ../bin/*
