/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/20 15:29:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//char *str;
	// char	*tmp;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 9;
	i = 0;
	data = ft_memalloc(sizeof(t_data));

	// i |= 2; // active le bit 2
	// if (i & 2) // check if bit 2 is enable
	// i &= ~2;// disable bit 2

	str = ft_strdup(" %177d%%%s%%%d ");
	printf("Vrai : i = |%5.05d|,|%d|, test\n", 3, 17);
	ft_printf("Mine : i = |%5.05d|,|%d|, test\n",3, 17);
	// ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);


	//ft_printf("i = %55d  %.10s  %d test\n",2,"nononononononon", i);
	//ft_printf("i = |%.100s|, |%d|, test\n","COUCOU",i);

	//PUTAIN PRINTF printf("i = |%05.2d|test\n", 7);
	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);
	// MARCHE PAS ft_printf("i = %00.05d test\n",i);
		// 	ft_printf(51172,0x7fffaa13f3c0) malloc: *** error for object 0x1016b0fa8: pointer being freed was not allocated
		// *** set a breakpoint in malloc_error_break to debug
		// [1]    51172 abort      ./ft_printf

	//printf("%", 5, test_nb);

	printf("Vrai : i = |%.*s|,|%d|, test\n", 3, "SAlUT", 17);
	ft_printf("Mine = i = |%4s|,|%d|, test\n", "SAlUT", 17);
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
