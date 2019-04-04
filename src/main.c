/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/04 15:58:11 by lgaultie         ###   ########.fr       */
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

	// ft_tests();

	// printf("%s\n", NULL);
	// ft_printf("%s\n", NULL);

	// printf("%s\n", "lol");
	// ft_printf("%s\n", "lol");

	//  str = ft_strdup("oui");
	// printf("Vrai : |%llx|\n", (long long)10);
	// ft_printf("Mine : |%llx|\n", (long long)10);




	printf("|%-20s| is a string\n", "this");
	ft_printf("|%-20s| is a string\n", "this");
	printf("--------------\n");
	printf("|%-2s| is a string\n", "this");
	ft_printf("|%-2s| is a string\n", "this");
	printf("--------------\n");
	printf("|%-.2s| is a string\n", "this");
	ft_printf("|%-.2s| is a string\n", "this");
	printf("--------------\n");
	printf("|%-5.2s| is a string\n", "this");
	ft_printf("|%-5.2s| is a string\n", "this");
	printf("--------------\n");
	printf("|%-7.7s| is a string\n", "this");
	ft_printf("|%-7.7s| is a string\n", "this");
	printf("--------------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n", "");
	printf("--------------\n");
	printf("|%-1.0d|\n", -18);
	ft_printf("|%-1.0d|\n", -18);
	printf("--------------\n");
	printf("|%#10o|\n", 524);
	ft_printf("|%#10o|\n", 524);
	printf("--------------\n");
	printf("|%08x|\n", 42);
	ft_printf("|%08x|\n", 42);
	printf("--------------\n");
	printf("|%10.08x|\n", 42);
	ft_printf("|%10.08x|\n", 42);
	printf("--------------\n");
	printf("|%.8x|\n", 42);
	ft_printf("|%.8x|\n", 42);
	printf("--------------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n\n", "");
	printf("--------------\n");
	printf("%+d\n", -42);
	ft_printf("%+d\n", -42);
	printf("--------------\n");
	printf("% d\n", -42);
	ft_printf("% d\n", -42);
	printf("--------------\n");
	printf("%+5d\n", 42);
	ft_printf("%+5d\n", 42);
	printf("--------------\n");
	printf("%+4.5d\n", 42);
	ft_printf("%+4.5d\n", 42);
	printf("--------------\n");
	printf("%+.5d\n", 42);
	ft_printf("%+.5d\n", 42);
	printf("--------------\n");
	printf("%05d\n", -42);
	ft_printf("%05d\n", -42);
	printf("--------------\n");
	printf("%03.2d\n", -1);
	ft_printf("%03.2d\n", -1);
	// printf("--------------\n");
	// printf("%0+5d\n", 42);
	// ft_printf("%0+5d\n", 42);
	// printf("--------------\n");
	// printf("%0+5d\n", -42);
	// ft_printf("%0+5d\n", -42);
	// printf("--------------\n");
	// printf("|%#08x|\n", 42);
	// ft_printf("|%#08x|\n", 42);


	// ft_printf("|%.0s|\n", "salutttt");
	// printf("|%-20.8o|\n", -42);
	// ft_printf("|%-20.8o|\n", -42);
	// printf("|%-20.15o|\n", -42);
	// ft_printf("|%-20.15o|\n", -42);
	// printf("|%-3.6o|\n", -17);
	// ft_printf("|%-3.6o|\n", -17);



	// printf("V : |% %|\n");
	// ft_printf("M : |% %|\n");
	// ft_printf("Vrai : %% |%-5%|\n");
	// ft_printf("Vrai : %% |%5%|\n");
	// ft_printf("Vrai : %% |%2.11u|\n", 18);
	//ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);
	//ft_printf("i = |%05.2d|test\n", 7);
	// ft_printf("i = %00.05d test\n",i);


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
