CFLAGS = -std=c89 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Wpedantic -Wshadow -pedantic-errors

PROGS = cat

all: $(PROGS)

.SUFFIXES :
.SUFFIXES : .o .c .h

watch:
	ls *.c *.h | entr ${MAKE}

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o
