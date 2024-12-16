# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 21:28:30 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/04 21:34:04 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = test.hpp
SRC = test.cpp
OBJ = test.o
NAME = test_files


all : $(NAME)

$(NAME): $(HEADERS) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(wildcard *.replace)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
