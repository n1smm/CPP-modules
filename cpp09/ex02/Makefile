# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:33:45 by tjuvan            #+#    #+#              #
#    Updated: 2025/02/23 13:11:14 by thiew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pthread -g
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs
HEADERS = $(wildcard $(INC_DIR)/*.hpp) 
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME = pmergeMe
GENERATOR = randomNumGenerator

all : $(NAME)

generate : $(GENERATOR)

$(GENERATOR) : generator/randomNumGenerator.o
	$(C) $(CFLAGS) generator/randomNumGenerator.o -o randomNumGenerator

generator/%.o : generator/%.cpp
	$(C) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir	-p $(dir $@)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f generator/randomNumGenerator.o

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	rm -f $(GENERATOR)

re: fclean all

.PHONY: clean fclean re all
