.PHONY: clean

NAME = analyser
OBJ = $(NAME).o

CC = g++

CFLAGS = \
    --std=c++11 \
    -Wall

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME).out $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(NAME).out
