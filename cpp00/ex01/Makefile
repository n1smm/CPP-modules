# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 12:30:40 by thiew             #+#    #+#              #
#    Updated: 2024/10/09 17:22:09 by thiew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -g -Wall -Wextra -Werror -std=c++98
HEADERS = main.hpp contact.hpp phoneBook.hpp
SRCS =	main.cpp contact.cpp phoneBook.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = phoneBook


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



