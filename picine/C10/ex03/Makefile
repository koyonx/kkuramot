CFLAGS = -Wall -Wextra -Werror
SRCS = $(shell find -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
TARGET = ft_hexdump

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(TARGET)
