# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 23:16:50 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/04 23:23:10 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = Harl.hpp
SRC = main.cpp Harl.cpp
OBJ = main.o Harl.o
NAME = harl

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
