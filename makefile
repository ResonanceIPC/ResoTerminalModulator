CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=-lm
SRC=resomodulator.c
OBJ=resomodulator.o

all: resomodulator

resomodulator: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	rm -f $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

run: resomodulator
	./resomodulator

clean:
	rm -f $(OBJ) resomodulator sinusoid.txt
