CC ?= cc 
CFLAGS ?= -fsanitize=address -Wall  -g -O2

all: 
	$(CC) $(CFLAGS) -o main main.c square.c

clean:
	rm -f main