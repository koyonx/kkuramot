LIB_NAME="libft.a"
SRC_FILES="ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c"
cc -Wall -Wextra -Werror -c $SRC_FILES
ar rcs $LIB_NAME $OBJ_DIR *.o