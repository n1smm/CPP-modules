# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 11:38:45 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/13 11:40:58 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = g++
FLAGS = -g -Wall -Wextra -Werror -std=c++98
HEADERS = Account.hpp
SRCS =	tests.cpp Account.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = account_test

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
