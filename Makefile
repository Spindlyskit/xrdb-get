TARGET = xrdb-get
CFLAGS = -g -Wall -Werror
LDFLAGS = -lX11

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LDFLAGS)

install: $(TARGET)
	mkdir -p $(DESTDIR)$(BINDIR)
	cp $< $(DESTDIR)$(BINDIR)

uninstall:
	$(RM) $(DESTDIR)$(BINDIR)/$(TARGET)

clean:
	$(RM) $(TARGET)

.PHONY: clean

