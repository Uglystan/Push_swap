/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:03:13 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/02 10:52:46 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft_tot/libft.h"

typedef struct s_pile
{
	int				index;
	long long		content;
	struct s_pile	*next;
}	t_pile;

int			check_arg_nbr(char **argv);
int			check(t_pile **pileA);
int			better_play_ind_max(t_pile *pileB);
int			better_play_ind_min(t_pile *pileB);
int			check_arg_double(t_pile *pileA);
int			swap_a(t_pile **pileA, int ind);
int			swap_b(t_pile **pileB, int ind);
int			swap_a_and_b(t_pile **pileA, t_pile **pileB, int ind);
int			lstsize(t_pile *lst);
int			push_a(t_pile **pile_pushB, t_pile **pile_destA, int ind);
int			push_b(t_pile **pile_pushA, t_pile **pile_destB, int ind);
int			rotate_a(t_pile **pileA, int ind);
int			rotate_b(t_pile **pileB, int ind);
int			rotate_a_and_b(t_pile **pileA, t_pile **pileB, int ind);
int			rev_rot_a(t_pile **pileA, int ind);
int			rev_rot_b(t_pile **pileB, int ind);
int			rev_rot_a_and_b(t_pile **pileA, t_pile **pileB, int ind);
int			ind_le_plus_grand(t_pile *pile);
int			better_play(t_pile *pileA, int ind, int offset);
int			ind_le_plus_petit(t_pile *pile);
int			better_play_ind_min(t_pile *pileB);
long long	ft_atoi(const char *nptr, t_pile **pile);
void		lstadd_back(t_pile **lst, t_pile *new);
void		lstclear(t_pile **lst);
void		lstadd_front(t_pile **lst, t_pile *new);
void		index_pile(t_pile **pileA);
void		tri(t_pile **pileA, t_pile **pileB);
void		tri_3(t_pile **pileA);
void		print_pile(t_pile *pile);
void		tri_fin_push_b(t_pile **pileA, t_pile **pileB, int ind);
void		tri_fin_push_a(t_pile **pileA, t_pile **pileB, int size);
void		do_coup(t_pile **pileA, t_pile **pileB, char **tab_coup);
void		free_tab(char **tab, t_pile **pileA, t_pile **pileB, int bool);
t_pile		*make_pile(char **argv);
t_pile		*lstnew(long long nbr, int index);

#endif