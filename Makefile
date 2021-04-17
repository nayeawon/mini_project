CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = main.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o product
