
CC = g++

default: send receive
	@echo Executable located in bin

send: ../src/message_send.cpp
	$(CC) ../src/message_send.cpp -o ../bin/message_send

receive: ../src/message_rec.cpp
	$(CC) ../src/message_rec.cpp -o ../bin/message_rec

all: angstrom_avoid_obj facedetect
	@echo Execulable located in bin

sample: alphalem_sample.o master.o
	$(CC) alphalem_sample.o master.o -o ../bin/sample -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann

alphalem_sample.o: ../src/alphalem_sample.cpp
	$(CC) -c ../src/alphalem_sample.cpp

master.o: ../src/master.cpp
	$(CC) -c ../src/master.cpp

facedetect: faceDetect.o
	$(CC) faceDetect.o -o ../bin/faceDetect -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann

faceDetect.o: ../src/faceDetect.cpp
	$(CC) -c ../src/faceDetect.cpp

angstrom_avoid_obj: angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o arm.o
	$(CC) angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o arm.o -o ../bin/angstrom_avoid_obj

angstrom_avoid_obj.o: ../src/angstrom_avoid_obj.cpp
	$(CC) -c ../src/angstrom_avoid_obj.cpp

arm.o: ../src/arm.cpp
	$(CC) -c ../src/arm.cpp

Hexapod.o: ../src/Hexapod.cpp ../src/Hexapod.h
	$(CC) -c ../src/Hexapod.cpp

AdaFruitServoDriver.o: ../src/AdaFruitServoDriver.cpp ../src/AdaFruitServoDriver.h
	$(CC) -c ../src/AdaFruitServoDriver.cpp

Matrix.o: ../src/Matrix.cpp ../src/Matrix.h
	$(CC) -c ../src/Matrix.cpp

SlaveDevice.o: ../src/SlaveDevice.cpp ../src/SlaveDevice.h
	$(CC) -c ../src/SlaveDevice.cpp

clean:
	$(RM) *.o *~ ../bin/*
