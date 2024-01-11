/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:15:02 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:14:22 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Un peu inutile je sais pas pourquoi j'ai fais ca pour comprendre go check_arg_double en bas de la page
int	check(t_pile **pileA)
{
	int	check;

	check = check_arg_double((*pileA));
	//Si check_arg_double renvoie 0, 2 ou 3 on free tout et on renvoie error
	if (check == 0 || check == 2 || check == 3)
	{
		write(2, "Error\n", 6);
		lstclear(pileA);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	check_arg_nbr(char **argv)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	//On check tout les arguments
	while (argv[j] != NULL)
	{
		//Si pour un argument on a un - ou + on passe au suivant et si c'est un digit tout ok sinon error
		if (argv[j][i] == '+' || argv[j][i] == '-')
		{
			i++;
			//Si caractere apres le + le - pas digits error
			if (ft_isdigit(argv[j][i]) == 0)
				return (0);
		}
		//Si dans tout l'argument un caractere n'est pas un digit error
		while (argv[j][i] != '\0')
		{
			//Si pas que des digits error
			if (ft_isdigit(argv[j][i]) == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	//Pas d'error
	return (1);
}

//On parcourt la liste si on a un content trop grand ou plus petit que le int max error c'est pas demande mais comme rien de precise j'ai pris la decision de faire comme ca
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
		//Ici je verifie qu'il n'y a pas de doublon dans ma liste je pars du maillon actuel je met temp sur le maillon d'apres et je fais derouler temp jusqu'a la fin
		//et je compare toutes les valeur de temp->content au content actuel si pas de doublon on continue sinon error
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
