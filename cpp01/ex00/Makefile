# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:50:51 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/04 11:55:37 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = main.hpp Zombie.hpp
SRCS = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
NAME = zombola

all: $(NAME)

$(NAME):
	$(C) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean re
