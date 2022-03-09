/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:03:46 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 13:03:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 4096
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_stack
{
	int	nbr;
	int	pos;
	int	half;
	int	dist;
	int	target;
	struct s_stack *next;
}   t_stack;


// get_next_line.c
int		get_next_line(int fd, char **line);
char	*get_save(char *save);
int		error_check(int fd, char *buff, char **line);

//get_next_line_utils.c
int		newline_end(char *str);
char	*get_line(char *str);
char	*ft_strjoin(char *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);

// check_args_bonus.c
int check_args(int argc, char const **argv);

// find_target_bonus.c
int	set_target_one(t_stack *stack);
int	target_max(t_stack *stack);
int	find_last_assigned_target(t_stack*stack, int max, int last_assigned);
t_stack	*find_target(t_stack *stack);

// freestack_bonus.c
void	freestack(t_stack **stack);

// moves_bonus.c
void    bonus_move(char*str, t_stack **stack, t_stack **stackA, t_stack **stackB);
void    bonus_reverse_rotater(char *str, t_stack **stackA, t_stack **stackB);
void	checker(t_stack **stack);

// operations_bonus.c
t_stack *restore_pos(t_stack **stack);
void	bonus_swap(t_stack **stack);
void	bonus_rotate(t_stack **stack);
void	bonus_reverse_rotate(t_stack **stack);
void	bonus_push(t_stack **stack);

// setup_bonus.c
int	count_int(t_stack *stack);
t_stack	*stack_insert(t_stack *stack, char const *nbr);
t_stack	*create_stack(t_stack *stack, int argc, char const **argv);

#endif