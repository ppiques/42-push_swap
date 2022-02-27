# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 12:46:13 by ppiques           #+#    #+#              #
#    Updated: 2022/02/16 12:46:13 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS		= $(addprefix srcs/, check_args.c push_swap.c \
			  $(addprefix utils/, ft_atoi.c ft_isdigit.c ft_strncmp.c))
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re