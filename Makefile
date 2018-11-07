#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 21:48:44 by avallois          #+#    #+#              #
#    Updated: 2018/06/18 21:21:34 by avallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = push_swap

NAME_C = checker

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	 push_swap.c init_and_skills.c cmd_list.c quicksort.c organize_a.c \
			 tools.c get_datas.c sort_short_list.c\

SRC_NAME_C =	 checker.c init_and_skills.c cmd_list.c quicksort.c \
				 organize_a.c get_datas.c tools.c \


LIB_NAME = 	ft_intnew.c ft_putchar.c ft_putstr.c \
			ft_putnbr.c ft_strcmp.c ft_strlen.c ft_putinttab.c \
			ft_strjoin_f.c ft_strdup.c ft_strchr.c ft_strsub.c ft_strcat.c \
			ft_strcpy.c get_next_line.c pos_str_tab.c ft_isdigit.c \
			swap_int.c copy_inttab.c ft_inttab_cmp.c \
			 ft_long_atoi.c ft_putstr_fd.c ft_putchar_fd.c \
			get_mediane.c ft_isascending.c\

INC_NAME = push_swap.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC_C = $(addprefix $(SRC_PATH)/, $(SRC_NAME_C))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_C = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_C))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ) $(OBJLIB)
	@$(CC) $(FLAGS) $(OBJ) $(OBJLIB) -o $(NAME)
	@echo "\033[1;34mpush_swap\t\033[1;33mCreation\t\033[0;32m[OK]\033[0m"
	@$(CC) $(FLAGS) $(OBJ_C) $(OBJLIB) -o $(NAME_C)
	@echo "\033[1;34mchecker\t\t\033[1;33mCreation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<
	@$(CC) $(FLAGS) -o ./obj/checker.o -c ./src/checker.c

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH) $(OBJ) $(OBJLIB)
	@echo "\033[1;34mboth\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME) $(NAME_C)
	@echo "\033[1;34mboth\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
