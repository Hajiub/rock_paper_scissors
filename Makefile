CC = gcc
CLFAGS = -Wall -Wextra
SRC = main.c
EXEC = out

all:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)
