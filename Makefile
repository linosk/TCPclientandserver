CC = gcc
CFLAGS = -Wall -Wextra -pedantic
DEBUGFILE = -g

CFILES = main.c security.c server.c
OFILES = main.o security.o server.o

OUTPUT = TCPserverandclient

.PHONY: all
all: $(OUTPUT)

$(OUTPUT): $(OFILES)
	$(CC) $(CFLAGS) $(DEBUGFILE) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm *.o