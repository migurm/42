# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 17:15:25 by mrueda-m          #+#    #+#              #
#    Updated: 2024/06/19 12:48:38 by mrueda-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar -rcs
NAME		= libftprintf.a
RM			= rm -rf

SRC			= ft_printf.c utils_printf_a.c utils_printf_b.c

SRC_OBJ		= $(SRC:.c=.o)

# --- Targets ---
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C libft
	mv libft/libft.a $(NAME) 
	$(LIBC) $(NAME) $(SRC_OBJ)

clean:
	make clean -C libft
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 