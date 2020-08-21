# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 13:27:00 by jonny             #+#    #+#              #
#    Updated: 2020/08/21 12:50:13 by jonny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
# Variables #
#############

# Colors
RED =`tput setaf 1`
GREEN =`tput setaf 2`
CLEAR =`tput sgr0`

# OS
OS := $(shell uname)

# General
TEST = test
MAIN_C = main.c
MAIN_O = $(MAIN_C:.c=.o)
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address
LIB = -L. -lasm

# Linux
ifeq ($(OS), Linux)
NAME = libasm.a
SRCS = ft_write.s \
			 ft_read.s \
			 ft_error.s \
			 ft_strlen.s \
			 ft_strcpy.s \

SRCS_PATH = src
SRC = $(addprefix $(SRCS_PATH)/,$(SRCS))
OBJS = $(SRC:.s=.o)
CC = clang
FLAGS = -f elf64
endif

#########
# Rules #
#########

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled with success$(CLEAR)"

%.o: %.s
	nasm $(FLAGS) $< -o $@

test: $(NAME) $(MAIN_O)
	$(CC) -no-pie $(CFLAGS) $(MAIN_O) $(LIB) -o $(TEST)
	@echo "$(GREEN)$(TEST) compiled with success$(CLEAR)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(MAIN_O)
	@echo "$(RED)removed object files$(CLEAR)"

fclean: clean
	rm -rf $(NAME) $(TEST)
	@echo "$(RED)removed libasm and test$(CLEAR)"

re: fclean all
