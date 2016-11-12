CC = gcc
CFLAGS  = -g -Wall -Wextra -Werror

sll: singly_ll.o ../list_api/list.o ../list_api/node.o ../list_api/singly_linked_list.o
	$(CC) $(CFLAGS) singly_ll.o ../list_api/list.o ../list_api/node.o ../list_api/singly_linked_list.o -o sll.sh

singly_ll.o: singly_ll.c ../list_api/node.h ../list_api/list.h
	$(CC) $(CFLAGS) -c singly_ll.c

clean:
	$(RM) *.o *~
