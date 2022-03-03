# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 23:00:53 by ppiques           #+#    #+#              #
#    Updated: 2022/03/02 23:00:53 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS_PATH =	$(shell find srcs -type d) \
				$(shell find srcs/utils -type d)

OBJ_DIR = $(BUILD)/obj

INC_DIR = $(shell find includes -type d)

BUILD = .objects

vpath %.c $(foreach dir, $(SRCS_PATH), $(dir):)

SRCS = 	push_swap.c \
check_args.c  find_position.c freestack.c \
operations.c setup.c special_cases.c \
ft_atoi.c ft_isdigit.c ft_strncmp.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC = gcc

CFLAGS =	-Wall -Werror -Wextra -g

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

all :
	@make $(NAME)

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable successfully created\n"

$(OBJ_DIR)/%.o : %.c | $(BUILD)
	@cc $(CFLAGS) -c $< $(IFLAGS) -o $@

$(BUILD):
	@mkdir $@ $(OBJ_DIR)
	@echo "Object directory created\n"
	@echo "Compiling..\n"

clean :
	@rm -rf $(BUILD)
	@echo "Object directory deleted\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "Executable removed\n"

bonus : fclean
	@make all

re : fclean all

.PHONY:		bonus all clean fclean re
