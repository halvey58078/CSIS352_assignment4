# Michael Halverson
# CSIS 352 - Asmt #4
# Makefile - prog4

 
# This file allows an administrator of another unix system to "install"
# the 'progX' program on his/her system. 


EXE = prog4
CC = g++ 
OBJECTS = main.o fraction.o  
LFLAGS = 
CFLAGS =  
 


$(EXE):    $(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 

main.o:    main.cpp fraction.h
		$(CC) $(CFLAGS) -c main.cpp 

fraction.o:    fraction.cpp fraction.h
		$(CC) $(CFLAGS) -c fraction.cpp 
    



    

clean:
		rm *.o

