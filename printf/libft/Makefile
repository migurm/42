# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 13:15:41 by mrueda-m          #+#    #+#              #
#    Updated: 2024/08/26 12:23:36 by mrueda-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar -rcs
NAME		= libft.a
RM			= rm -rf

SRC			= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
    ft_isprint.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcat.c \
	ft_memcmp.c ft_memchr.c ft_memcpy.c ft_bzero.c ft_memmove.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c

SRC_OBJ		= $(SRC:.c=.o)

# --- Targets ---
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIBC) $(NAME) $(SRC_OBJ)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re