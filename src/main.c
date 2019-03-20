/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/20 19:11:36 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	// char	*tmp;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 9;
	i = 0;
	data = ft_memalloc(sizeof(t_data));


	str = ft_strdup(" %177d%%%s%%%d ");
	printf("Vrai : %+2.5d\n", 12345);
	ft_printf("Vrai : %+2.5d\n", 12345);
	// ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);
	// ft_printf("i = |%05.2d|test\n", 7);
	// ft_printf("i = %00.05d test\n",i);
	// ft_printf("Mine : i = %5%\n");

	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);

	return 0;
}

// printf("----- Test 01 ----\n int + Accuracy\n");
// str = ft_strdup("|%5d|\n");
// tmp = ft_printf(str, 5);
// if ((ft_strcmp("|    5|\n", tmp) == 0))
// {
// 	i++;
// 	printf("\n----> OK <----\n\n");
// }
// else
// printf("NOOOON\n");
// printf("---------------\n\n");
//
// printf("----- Test 02 ----\n int + Width + *\n");
// str = ft_strdup("|%*d|\n");
// tmp = ft_printf(str, 5, 10);
// if ((ft_strcmp("|   10|\n", tmp) == 0))
// {
// 	i++;
// 	printf("\n----> OK <----\n\n");
// }
// else
// printf("NOOOON\n");
// printf("---------------\n\n");
//
// printf("----- Test 03 ----\n int + Width + *\n");
// str = ft_strdup("|%s|\n");
// tmp = ft_printf(str, "SAlUT");
// if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
// {
// 	i++;
// 	printf("\n----> OK <----\n\n");
// }
// else
// printf("NOOOON\n");
// printf("---------------\n\n");
//
// printf("----- Test 04 ----\n char * + accuracy\n");
// str = ft_strdup("|%.4s|\n");
// tmp = ft_printf(str, "SAlUT");
// if ((ft_strcmp("|SAlU|\n", tmp) == 0))
// {
// 	i++;
// 	printf("\n----> OK <----\n\n");
// }
// else
// printf("NOOOON\n");
// printf("---------------\n\n");
//
// printf("----- Test 05 ----\n char * + accuracy + *\n");
// str = ft_strdup("|%.*s|\n");
// tmp = ft_printf(str, 3, "SAlUT");
// if ((ft_strcmp("|SAl|\n", tmp) == 0))
// {
// 	i++;
// 	printf("\n----> OK <----\n\n");
// }
// else
// printf("NOOOON\n");
// printf("---------------\n\n");
//
// printf("Score : %d/5\n\n", i);
