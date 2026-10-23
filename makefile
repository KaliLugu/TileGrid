CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRCDIR = source
INCLUDEDIR = include
LIBDIR = lib
BUILDDIR = build

SRC = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) \
	    -L$(LIBDIR) \
	    -Wl,-rpath,$(LIBDIR) \
	    -lraylib \
	    -lm

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) main

.PHONY: all clean
