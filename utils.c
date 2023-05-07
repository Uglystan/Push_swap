/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:48 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/01 11:03:23 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_pile(t_pile *pile, int limit)
{
	int	i;

	i = 0;
	while (i != limit)
	{
		if (pile == NULL)
			return (0);
		pile = pile->next;
		i++;
	}
	return (1);
}

int	ind_le_plus_grand(t_pile *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index > i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}

int	ind_le_plus_petit(t_pile *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index < i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}

void	free_pile(t_pile **pile)
{
	write(2, "Error\n", 6);
	lstclear(pile);
	exit(EXIT_FAILURE);
}

long long	ft_atoi(const char *nptr, t_pile **pile)
{
	int			i;
	int			neg;
	long long	ret;
	long long	old_ret;

	i = 0;
	ret = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			neg = neg * (-1);
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		old_ret = ret;
		ret = ret * 10 + (nptr[i] - 48);
		if (ret < old_ret)
			free_pile(pile);
		i++;
	}
	return (ret * neg);
}
