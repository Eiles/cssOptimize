CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=css_optimizer
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
PREFIX=$(DESTDIR)/usr/local
BINDIR=$(PREFIX)/bin

all: $(EXEC)

css_optimizer: $(OBJ)
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
	cp css_optimizerman /usr/share/man/man1/css_optimizer.1

uninstall:
	rm $(BINDIR)/$(EXEC)
	rm /usr/share/man/man1/css_optimizer.1