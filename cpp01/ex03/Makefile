# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:20:18 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/03 20:05:18 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC_DIR = includes
HEADERS = $(INC_DIR)/main.hpp $(INC_DIR)/Weapon.hpp $(INC_DIR)/HumanA.hpp $(INC_DIR)/HumanB.hpp
NAME = violence
SRC_DIR = srcs
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Weapon.cpp $(SRC_DIR)/HumanA.cpp $(SRC_DIR)/HumanB.cpp
OBJ_DIR = obj
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re



