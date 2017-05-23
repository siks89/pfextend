.PHONY: clean

NAME = analyser
OBJ = $(NAME).o

CC = g++

CXXFLAGS = \
    --std=c++11 \
    -Wall

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME).out $(OBJ)

clean:
	rm $(OBJ) $(NAME).out
