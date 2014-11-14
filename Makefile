CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=cssOptimizer
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
PREFIX=$(DESTDIR)/usr/local
BINDIR=$(PREFIX)/bin

all: $(EXEC)

cssOptimizer: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.c: %.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper install uninstall

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

install:
	install $(EXEC) $(BINDIR)/$(TARGET)

uninstall:
	rm $(BINDIR)/$(EXEC)