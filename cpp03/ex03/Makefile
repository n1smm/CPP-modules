# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:33:45 by tjuvan            #+#    #+#              #
#    Updated: 2024/12/08 20:52:21 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs
HEADERS = $(wildcard $(INC_DIR)/*.hpp) 
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME = diamondtrap

all : $(NAME)

$(NAME): $(HEADERS) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir	-p $(dir $@)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
