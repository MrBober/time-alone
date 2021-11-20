# Define required macros here
SHELL = /bin/sh

OBJS = main.o
CFLAGS = -Wall -g `pkg-config --cflags libnotify`
LDFLAGS = `pkg-config --libs libnotify`
CC = gcc
EXECUTABLE = life

${EXECUTABLE}:${OBJS}
	${CC} ${OBJS} -o $@ ${CFLAG} $(LDFLAGS)

clean:
	rm -f ${OBJS}
