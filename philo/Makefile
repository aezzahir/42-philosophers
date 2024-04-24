CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = src/main.c src/ft_atoi.c src/ft_parse_arguments.c 
OBJ_FILES = $(SRC_FILES:%.c=%.o)
INCLUDES=includes/philo.h
EXECUTABLE = philo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
