# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 11:58:28 by abnaciri          #+#    #+#              #
#    Updated: 2023/12/11 17:24:45 by abnaciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar crs
SRC = ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putnbr_un.c \
	ft_putnbr_hex.c \
	ft_print_address.c \
	ft_printf.c \

OBJ = $(SRC:%.c=%.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re