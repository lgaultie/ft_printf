/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/02 11:43:33 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	ft_tests();
// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;

	//printf("%lld\n", i);

//	ft_tests();

	// printf("Vrai : |%hho|\n", (char)120);
	// ft_printf("Mine : |%hho|\n", (char)120);
	// printf("Vrai2 : |%o|\n", -12);
	// ft_printf("Mine2 : |%o|\n", -12);

	str = malloc(sizeof(char) * 3);
	str[0] = '1';
	str[1] = '2';
	str[2] = '\0';
	// printf("|%d|\n", -18);

	// ft_tests();
	//char *oui = NULL;


	printf("|%X|\n", -42);
	ft_printf("|%X|\n", -42);
	// printf("|%-20.8o|\n", -42);
	// ft_printf("|%-20.8o|\n", -42);
	// printf("|%-20.15o|\n", -42);
	// ft_printf("|%-20.15o|\n", -42);
	// printf("|%-3.6o|\n", -17);
	// ft_printf("|%-3.6o|\n", -17);

	//ft_tests();
	//ft_printf("Mine : i = |%s|,|%d|, test\n", "Salut", 17);

	// printf("V : |% %|\n");
	// ft_printf("M : |% %|\n");
	// ft_printf("Vrai : %% |%-5%|\n");
	// ft_printf("Vrai : %% |%5%|\n");
	// ft_printf("Vrai : %% |%2.11u|\n", 18);
	//ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);
	//ft_printf("i = |%05.2d|test\n", 7);
	// ft_printf("i = %00.05d test\n",i);

// <<<<<<< HEAD
// 	// printf("Vrai : i = %5%\n");
// 	// ft_printf("Mine : i = %5%\n");
// 	//PUTAIN PRINTF printf("i = |%05.2d|test\n", 7);
// 	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);
// 	// MARCHE PAS ft_printf("i = %00.05d test\n",i);
//
//
//
//
// =======
// 	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);
//
	return 0;
}
