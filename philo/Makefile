CC = cc
CFLAGS = -Wall -Werror -Wextra #-pthread -g3 -fsanitize=thread
SRC_FILES = src/ft_routine_functions.c src/ft_end_sim.c  src/ft_fork_mutex.c src/write_status.c src/ft_usleep.c src/init_philosopher.c src/ft_atoi.c   src/ft_parse_arguments.c  src/main.c
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
