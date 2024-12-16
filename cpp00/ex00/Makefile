# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:32:20 by thiew             #+#    #+#              #
#    Updated: 2024/12/13 11:34:27 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone.cpp
OBJ = megaphone.o
OUTPUT = megaphone

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	${CC} ${FLAGS} ${OBJ} -o ${OUTPUT}

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -rf $(OUTPUT)


