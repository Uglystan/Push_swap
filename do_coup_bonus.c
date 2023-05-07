/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_coup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:28:16 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/01 13:01:47 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_pile **pileA, t_pile **pileB, char **tab_coup)
{
	write(2, "Error\n", 6);
	free_tab(tab_coup, pileA, pileB, 1);
}

int	do_coup_2(t_pile **pileA, t_pile **pileB, char **t, int j)
{
	if (t[j][0] == 'r' && t[j][1] == 'r' && t[j][2] == 'a' && t[j][3] == '\0')
		return (rev_rot_a(pileA, 1));
	else if (t[j][0] == 'r' && t[j][1] == 'r'
		&& t[j][2] == 'b' && t[j][3] == '\0')
		return (rev_rot_b(pileB, 1));
	else if (t[j][0] == 'r' && t[j][1] == 'r'
		&& t[j][2] == 'r' && t[j][3] == '\0')
		return (rev_rot_a_and_b(pileA, pileB, 1));
	else if (t[j][0] == 'p' && t[j][1] == 'a' && t[j][2] == '\0')
		return (push_a(pileB, pileA, 1));
	else if (t[j][0] == 'p' && t[j][1] == 'b' && t[j][2] == '\0')
		return (push_b(pileA, pileB, 1));
	return (0);
}

void	do_coup(t_pile **pileA, t_pile **pileB, char **t)
{
	int	j;

	j = 0;
	while (t[j] != NULL)
	{
		if (t[j][0] == 's' && t[j][1] == 'a' && t[j][2] == '\0')
			swap_a(pileA, 1);
		else if (t[j][0] == 's' && t[j][1] == 'b' && t[j][2] == '\0')
			swap_b(pileB, 1);
		else if (t[j][0] == 's' && t[j][1] == 's' && t[j][2] == '\0')
			swap_a_and_b(pileA, pileB, 1);
		else if (t[j][0] == 'r' && t[j][1] == 'a' && t[j][2] == '\0')
			rotate_a(pileA, 1);
		else if (t[j][0] == 'r' && t[j][1] == 'b' && t[j][2] == '\0')
			rotate_b(pileB, 1);
		else if (t[j][0] == 'r' && t[j][1] == 'r' && t[j][2] == '\0')
			rotate_a_and_b(pileA, pileB, 1);
		else if (do_coup_2(pileA, pileB, t, j) == 0)
			test(pileA, pileB, t);
		j++;
	}
}
