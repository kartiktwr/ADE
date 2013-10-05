CC = arm-linux-gnueabi-g++-4.6
CFLAGS = -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -L/usr/arm-linux-gnueabi/lib -g3 -Wall

default: angstrom_avoid_obj
	@echo Execulable located in bin

angstrom_avoid_obj: angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o 
	$(CC) $(CFLAGS) angstrom_avoid_obj.o Hexapod.o AdaFruitServoDriver.o SlaveDevice.o -o ../bin/angstrom_avoid_obj

angstrom_avoid_obj.o: ../src/angstrom_avoid_obj.cpp
	$(CC) $(CFLAGS) -c ../src/angstrom_avoid_obj.cpp

Hexapod.o: ../src/Hexapod.cpp ../src/Hexapod.h
	$(CC) $(CFLAGS) -c ../src/Hexapod.cpp

AdaFruitServoDriver.o: ../src/AdaFruitServoDriver.cpp ../src/AdaFruitServoDriver.h
	$(CC) $(CFLAGS) -c ../src/AdaFruitServoDriver.cpp

Matrix.o: ../src/Matrix.cpp ../src/Matrix.h
	$(CC) $(CFLAGS) -c ../src/Matrix.cpp

SlaveDevice.o: ../src/SlaveDevice.cpp ../src/SlaveDevice.h
	$(CC) $(CFLAGS) -c ../src/SlaveDevice.cpp

clean:
	$(RM) *.o *~ /*.o
	$(RM) *.o *~ /*.d
