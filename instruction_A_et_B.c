/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_A_et_B.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:27:10 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:39:26 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rot_a_and_b(t_pile **pileA, t_pile **pileB)
{
	if (lstsize(*pileA) > 1 && lstsize(*pileB) > 1)
	{
		rev_rot_a(pileA, 1);
		rev_rot_b(pileB, 1);
		ft_printf("rrr\n");
	}
	return (0);
}

int	rotate_a_and_b(t_pile **pileA, t_pile **pileB)
{
	if (lstsize(*pileA) > 1 && lstsize(*pileB) > 1)
	{
		rotate_a(pileA, 1);
		rotate_b(pileB, 1);
		ft_printf("rr\n");
	}
	return (0);
}

int	swap_a_and_b(t_pile **pileA, t_pile **pileB)
{
	swap_a(pileA, 1);
	swap_b(pileB, 1);
	ft_printf("ss\n");
	return (1);
}
