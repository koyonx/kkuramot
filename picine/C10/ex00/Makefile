
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_display_file.c
OBJS = $(SRCS:.c=.o)
TARGET = ft_display_file

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
