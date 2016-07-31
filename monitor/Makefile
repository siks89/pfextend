.PHONY: clean

NAME = monitor
OBJ = mnt_common.o mnt_token_list.o cmp.o $(NAME).o

CC = gcc

CFLAGS = \
    --std=c99 \
    -Wall \
    -lrt \

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME).out $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(NAME).out
