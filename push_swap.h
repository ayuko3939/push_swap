/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:03:14 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:51:00 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				group;
	struct s_list	*next;
}					t_list;

typedef struct s_pivot
{
	int				s;
	int				l;
}					t_pivot;

typedef struct s_count
{
	int				ra;
	int				rb;
}					t_count;

// // -+-+-+-+-+-+-+-+-+-+-+-+- push_swap.c -+-+-+-+-+-+-+-+-+-+-+-+-

void				move_a_to_b(t_list **stack_a, t_list **stack_b);
void				recursive_sort(t_list **stack_a, t_list **stack_b);
void				push_swap(t_list **stack_a, t_list **stack_b);

// // -+-+-+-+-+-+-+-+-+-+-+-+-  quick_sort -+-+-+-+-+-+-+-+-+-+-+-+-

void				quick_sort_2pivots_a(t_list **stack_a, t_list **stack_b);
void				quick_sort_2pivots_b(t_list **stack_a, t_list **stack_b,
						int size);

void				quick_sort_b(t_list **stack_a, t_list **stack_b);
void				quick_sort_a(t_list **stack_a, t_list **stack_b, int group);

// // -+-+-+-+-+-+-+-+-+-+-+-+-  sort -+-+-+-+-+-+-+-+-+-+-+-+-

void				simple_sort(t_list **stack_a, t_list **stack_b);
void				sort_stack_b(t_list **stack_a, t_list **stack_b);

// // -+-+-+-+-+-+-+-+-+-+-+-+-  search.c -+-+-+-+-+-+-+-+-+-+-+-+-

int					get_distance(t_list **stack, int idx);
int					get_min(t_list **stack);
int					get_max(t_list **stack);
int					get_min_group(t_list **stack, int group);
int					group_size(t_list *lst, int group);

// // -+-+-+-+-+-+-+-+-+-+-+-+-  sort_helper.c -+-+-+-+-+-+-+-+-+-+-+-+-

void				save_sorted_nm(t_list **stack_a, t_list **stack_b, int size,
						char from);
void				push_b_to_a(t_list **stack_a, t_list **stack_b, int size);
void				save_next_min(t_list **stack_a, int group, int *size);
int					is_sorted_group(t_list **stack, int size);

// // -+-+-+-+-+-+-+-+-+-+-+-+-  operation -+-+-+-+-+-+-+-+-+-+-+-+-

int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);

int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);

int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);

int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

// -+-+-+-+-+-+-+-+-+-+-+-+-  list.c -+-+-+-+-+-+-+-+-+-+-+-+-

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew_ps(int value);
int					ft_lstsize(t_list *lst);

// -+-+-+-+-+-+-+-+-+-+-+-+-  init.c -+-+-+-+-+-+-+-+-+-+-+-+-

t_list				**init_stack(void);
void				set_stack(t_list **stack, int ac, char **av);

// -+-+-+-+-+-+-+-+-+-+-+-+-  validate.c -+-+-+-+-+-+-+-+-+-+-+-+-

void				check_args(int ac, char **av);

// -+-+-+-+-+-+-+-+-+-+-+-+-  utils.c -+-+-+-+-+-+-+-+-+-+-+-+-

void				error_exit(void);
void				free_all(char **array);
void				free_stack(t_list **stack);

#endif