CC = gcc
CFLAGS = -Wall -Wextra -pedantic
DEBUGFILE = -g

CFILES = main.c security.c server.c client.c
OFILES = main.o security.o server.o client.o

OUTPUT = TCPserverandclient

.PHONY: all
all: $(OUTPUT)

$(OUTPUT): $(OFILES)
	$(CC) $(CFLAGS) $(DEBUGFILE) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm *.o TCPserverandclient