/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/28 16:06:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_tests();
// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2
//i &= ~4;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//char *str;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 9;
	i = 0;
	data = ft_memalloc(sizeof(t_data));


	//		ft_tests();
	//  printf("Vrai : i = |%.6s|,|%d|, test\n", "Salut", 17);
	//  ft_printf("Mine : i = |%.6s|,|%d|, test\n\n", "Salut", 17);
		printf("Vrai : i = |%*s|, test\n", 3, "SALUT");
		ft_printf("Mine : i = |%*s|, test\n", 3, "SALUT");
//	printf("Vrai : %+2.5d\n", 12345);
//	ft_printf("Vrai : %+2.5d\n", 12345);
	// ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);
	// ft_printf("i = |%05.2d|test\n", 7);
	// ft_printf("i = %00.05d test\n",i);
	// ft_printf("Mine : i = %5%\n");

	// printf("Vrai : i = %5%\n");
	// ft_printf("Mine : i = %5%\n");
	//PUTAIN PRINTF printf("i = |%05.2d|test\n", 7);
	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);
	// MARCHE PAS ft_printf("i = %00.05d test\n",i);


	return 0;
}
