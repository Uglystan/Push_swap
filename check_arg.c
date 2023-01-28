/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:15:02 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:25:46 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_pile *pileA)
{
	int	check;

	check = check_arg_double(pileA);
	if (check == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check == 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check == 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_arg_nbr(char **argv)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (argv[j] != NULL)
	{
		if (argv[j][i] == '+' || argv[j][i] == '-')
		{
			i++;
			if (ft_isdigit(argv[j][i]) == 0)
				return (0);
		}
		while (argv[j][i] != '\0')
		{
			if (ft_isdigit(argv[j][i]) == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_arg_double(t_pile *pileA)
{
	t_pile	*temp;

	while (pileA != NULL)
	{
		if (pileA->content > 2147483647)
			return (2);
		if (pileA->content < -2147483648)
			return (3);
		temp = pileA->next;
		while (temp != NULL)
		{
			if (pileA->content == temp->content)
				return (0);
			temp = temp->next;
		}
		pileA = pileA->next;
	}
	return (1);
}
