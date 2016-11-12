CC = gcc
CFLAGS  = -g -Wall -Wextra -Werror

all: singly_linked_list.o list.o node.o

singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	$(CC) $(CFLAGS) -c singly_linked_list.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

clean:
	$(RM) *.o *~
