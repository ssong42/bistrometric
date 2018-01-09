# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 15:12:50 by ssong             #+#    #+#              #
#    Updated: 2018/01/09 11:01:48 by ssong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calc
FLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
CC = gcc
SRCS = ./
INCLUDE = ./
FILES = calc

CFILES = $(patsubst %, $(SRCS)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

all: $(NAME)

$(OFILES):
	$(CC) $(FLAGS) -c -I$(INCLUDE) $(CFILES)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES) $(LIB)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
