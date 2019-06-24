# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 09:31:10 by Roger Ndaba       #+#    #+#              #
#    Updated: 2019/06/24 09:31:10 by Roger Ndaba      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	avm

INCL =	-I../inc/

CC =	clang++

FLAGS = -Wall -Wextra -Werror -std=c++11

SRC =	AVM.cpp \
		ErrorException.cpp \
		Factory.cpp \
		Lexer.cpp \
		Parser.cpp \
		main.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(INCL)  $(addprefix src/, $(SRC)) -o $(NAME)
	@printf "\n🌸 \e[1;32m[ ✔ ] avm excecutable made\n\e[0m\n"

clean:
	@rm -fr $(NAME)
	@printf "\n🌸 \e[1;31m[ ✔ ] avm excecutable deleted\n\e[0m\n"

fclean: clean

re: fclean all

.PHONY: clean all fclean