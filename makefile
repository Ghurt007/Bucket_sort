CC=gcc -lm
CFLAGS=-I. -g -w 
LDFLAGS = -lm
DEPS= bucketsort.h
OBJ = bucketsort.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
bucketsort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
