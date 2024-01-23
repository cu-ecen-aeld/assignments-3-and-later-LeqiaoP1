CC = gcc
SRC := writer.c

all: writer

writer: writer.o
	$(CROSS_COMPILE)$(CC) $^ -o $@

writer.o: writer.c
	$(CROSS_COMPILE)$(CC) -c $^

clean:
	-rm -f *.o writer *.elf *.map