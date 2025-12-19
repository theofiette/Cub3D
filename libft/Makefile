# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 10:43:46 by tchevall          #+#    #+#              #
#    Updated: 2025/12/16 18:38:41 by tfiette          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src/
INCLUDE_DIR = includes

SRCS = $(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strncmp.c $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_bzero.c $(SRC_DIR)ft_calloc.c $(SRC_DIR)ft_isalnum.c $(SRC_DIR)ft_isalpha.c\
		$(SRC_DIR)ft_isascii.c $(SRC_DIR)ft_isdigit.c $(SRC_DIR)ft_isprint.c $(SRC_DIR)ft_memchr.c $(SRC_DIR)ft_memcmp.c $(SRC_DIR)ft_memcpy.c $(SRC_DIR)ft_memmove.c\
		$(SRC_DIR)ft_memset.c $(SRC_DIR)ft_split.c $(SRC_DIR)ft_strchr.c $(SRC_DIR)ft_strdup.c $(SRC_DIR)ft_strjoin.c $(SRC_DIR)ft_strlcat.c $(SRC_DIR)ft_strlcpy.c\
		$(SRC_DIR)ft_strnstr.c $(SRC_DIR)ft_strrchr.c $(SRC_DIR)ft_strtrim.c $(SRC_DIR)ft_substr.c $(SRC_DIR)ft_tolower.c $(SRC_DIR)ft_toupper.c $(SRC_DIR)ft_strmapi.c\
		$(SRC_DIR)ft_itoa.c $(SRC_DIR)ft_striteri.c $(SRC_DIR)ft_putchar_fd.c $(SRC_DIR)ft_putstr_fd.c $(SRC_DIR)ft_putendl_fd.c $(SRC_DIR)ft_putnbr_fd.c \
		$(SRC_DIR)ft_printdigit.c $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_readpercent.c $(SRC_DIR)ft_free_split.c $(SRC_DIR)get_next_line.c $(SRC_DIR)get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(INCLUDE_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
