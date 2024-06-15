# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 13:02:25 by apaula-l          #+#    #+#              #
#    Updated: 2024/06/14 16:56:45 by apaula-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCS := ./ libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
CPPFLAGS := $(addprefix -I,$(INCS)) -MMD -MP
LDLIBS := -lft
LIBFT_DIR = libft/

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_HEADER = libft
MAKE_LIBFT = make -C Libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE_LIBFT)

bonus:	$(BOBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)
	rm -f $(OBJS)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: clean fclean re all bonus