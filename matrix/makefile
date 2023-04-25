CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

SRCS = main.c io_opers.c
OBJS = $(SRCS:.c=.o)
HEADERS = op_opers.h

TARGET = matrix

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
