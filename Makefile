# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 18:40:11 by bavirgil          #+#    #+#              #
#    Updated: 2025/10/07 23:21:59 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
# Uncomment for local debugging:
# CFLAGS += -g

# Executable
NAME    = push_swap

# Headers
HEADERS = push_swap.h

# Sources
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
       utils.c \
       sort_five.c 

# Objects
OBJS = $(SRCS:.c=.o)

# Tools
RM = rm -f

#curl parrot.live

# Default
all: $(NAME)

# Link
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile: each .o depends on headers
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean all
fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re debug
