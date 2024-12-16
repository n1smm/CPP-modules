# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 12:30:40 by thiew             #+#    #+#              #
#    Updated: 2024/12/13 11:57:43 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -g -Wall -Wextra -Werror -std=c++98
HEADERS = main.hpp Zombie.hpp
SRCS =	main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = zombieHorde


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re



