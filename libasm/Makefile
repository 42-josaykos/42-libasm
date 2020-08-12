# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 13:27:00 by jonny             #+#    #+#              #
#    Updated: 2020/08/12 15:09:42 by jonny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED =`tput setaf 1`
GREEN =`tput setaf 2`
GREEN =`tput sgr0`

# OS
OS := $(shell uname)

TEST = test

ifeq ($(OS), Linux)
NAME = libasm.a
SRCS = ft_write.s \
			 hello.s
SRCS_PATH = src
SRC = $(addprefix $(SRCS_PATH)/,$(SRCS))
OBJS = $(SRC:.s=.o)
FLAGS = -f elf64
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm $(FLAGS) $< -o $@

test: $(NAME)
	clang -Wall -Wextra -Werror -c main.c -o main.o
	clang -Wall -Wextra -Werror -g3 -fsanitize=address main.o -L. -lasm -o $(TEST)
	rm -rf main.o

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean all

