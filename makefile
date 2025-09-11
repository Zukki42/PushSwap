# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 18:40:11 by bavirgil          #+#    #+#              #
#    Updated: 2025/09/11 18:57:52 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = push_swap

# Source files
SRCS = push_swap.c \
		operations_swap.c \
		operations_push.c \
		operations_rotate.c \
		operations_reverse.c \
		sort_small.c \
		sort_k.c \
		indexing.c \
		split.c \
		stack_utils.c \
		utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up everything (object files and executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
