.PHONY: clean

NAME = monitor
OBJ = mnt_common.o mnt_token_list.o cmp.o $(NAME).o

CC = gcc

CFLAGS = \
    --std=c99 \
    -Wall

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME).out $(OBJ) -lrt

clean:
	rm $(OBJ) $(NAME).out
