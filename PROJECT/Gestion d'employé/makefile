# change application name here (executable output name)
TARGET=Gestion
 
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
 
PTHREAD=-pthread
 
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
 
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
 
# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
 
OBJS=  glade.o CRUD.o main.o
 
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o:  src/glade.h src/CRUD.h src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o
CRUD.o: src/CRUD.h src/CRUD.c
	$(CC) -c $(CCFLAGS) src/CRUD.c $(GTKLIB) -o CRUD.o
glade.o: src/glade.h src/glade.c
	$(CC) -c $(CCFLAGS) src/glade.c $(GTKLIB) -o glade.o
	
    
clean:
    
	rm -f *.o $(TARGET)
