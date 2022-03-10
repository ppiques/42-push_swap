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
CHECKER		= checker

SRCS_PATH =		$(shell find srcs -type d) \
				$(shell find srcs/utils -type d)
BONUS_PATH =	$(shell find srcs/bonus -type d)

OBJ_DIR =		$(BUILD)/obj
OBJ_BONUS_DIR =	$(BUILD_BONUS)/obj_bonus

OBJS =			$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJS_BONUS =	$(addprefix $(OBJ_BONUS_DIR)/, $(SRCS_BONUS:%.c=%.o))

INC_DIR =		$(shell find includes -type d)

BUILD = .objects
BUILD_BONUS = .objects_bonus

vpath %.c $(SRCS_PATH)
vpath %.c $(BONUS_PATH)

SRCS = push_swap.c \
check_args.c  find_target.c freestack.c \
operations.c setup.c special_cases.c find_base.c \
half_calculator.c moves.c sorting.c \
ft_atoi.c ft_isdigit.c ft_strncmp.c

SRCS_BONUS = push_swap_bonus.c \
check_args_bonus.c find_target_bonus.c \
freestack_bonus.c get_next_line.c \
get_next_line_utils.c moves_bonus.c \
operations_bonus.c setup_bonus.c utils_bonus.c


CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

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
	@echo "\nObject directory created\n"
	@echo "Compiling..\n"

clean :

	@rm -rf $(BUILD) $(BUILD_BONUS)
	@echo "\nObject directory deleted\n"

fclean : clean
	@rm -rf $(NAME) $(CHECKER)
	@echo "Executable removed\n"

bonus :
	@make all
	@make $(CHECKER)

$(CHECKER) : $(OBJS_BONUS)
	@cc $(CFLAG) $(OBJS_BONUS) -o $(CHECKER)
	@echo "Bonus executable successfully created\n"

$(OBJ_BONUS_DIR)/%.o : %.c | $(BUILD_BONUS)
	@cc $(CFLAGS) -c $< $(IFLAGS) -o $@

$(BUILD_BONUS):
	@mkdir $@ $(OBJ_BONUS_DIR)
	@echo "\nObject bonus directory created\n"
	@echo "Compiling bonuses..\n"

re : fclean all

.PHONY:		bonus all clean fclean re
