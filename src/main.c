/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/05 16:47:33 by lgaultie         ###   ########.fr       */
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
	char	*str;
	// ft_tests();

	str = ft_strdup("oui");

	printf("%s\n", "this is a string");
	ft_printf("%s\n", "this is a string");
	printf("--------------\n");
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	printf("--------------\n");
	printf("%s\n", "lol");
	ft_printf("%s\n", "lol");
	printf("--------------\n");
	printf("|%llx|\n", (long long)10);
	ft_printf("|%llx|\n", (long long)10);
	printf("--------------\n");
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
	printf("--------------\n");
	printf("%#o\n", 42);
	ft_printf("%#o\n", 42);
	printf("--------------\n");
	printf("%#5x\n", 42);
	ft_printf("%#5x\n", 42);
	printf("--------------\n");
	printf("%#05x\n", 42);
	ft_printf("%#05x\n", 42);
	printf("--------------\n");
	printf("%#.05x\n", 42);
	ft_printf("%#.05x\n", 42);
	printf("--------------\n");
	printf("|%#08o|\n", 42);
	ft_printf("|%#08o|\n", 42);
	printf("--------------\n");
	printf("%+05d\n", 42);
	ft_printf("%+05d\n", 42);
	printf("--------------\n");
	printf("%0+5d\n", -42);
	ft_printf("%0+5d\n", -42);
	printf("--------------\n");
	printf("%0+5d\n", 42);
	ft_printf("%0+5d\n", 42);
	printf("--------------\n");
	printf("%#10.05x\n", 42);
	ft_printf("%#10.05x\n", 42);
	printf("--------------\n");
	printf("|%-20.8o|\n", -42);
	ft_printf("|%-20.8o|\n", -42);
	printf("--------------\n");
	printf("|%-20.15o|\n", -42);
	ft_printf("|%-20.15o|\n", -42);
	printf("--------------\n");
	printf("|%-3.6o|\n", -17);
	ft_printf("|%-3.6o|\n", -17);
	printf("--------------\n");
	printf("|%.0s|\n", "salutttt");
	ft_printf("|%.0s|\n", "salutttt");
	printf("--------------\n");
	printf("|% %|\n");
	ft_printf("|% %|\n");
	printf("--------------\n");
	printf("%% |%2.11u|\n", 18);
	ft_printf("%% |%2.11u|\n", 18);
	printf("--------------\n");
	printf("|%07.5d|,|%d|\n",150789, 17);
	ft_printf("|%07.5d|,|%d|\n",150789, 17);
	printf("--------------\n");
	printf("|%00.05d| \n", 7);
	ft_printf("|%00.05d| \n", 7);
	printf("--------------\n");
	printf("|%05.2d|\n", 7);
	ft_printf("|%05.2d|\n", 7);
	printf("--------------\n");
	// ft_printf("Vrai : %% |%-5%|\n");
	// ft_printf("Vrai : %% |%5%|\n");

	return 0;
}
