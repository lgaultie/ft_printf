/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/06 14:02:26 by amamy            ###   ########.fr       */
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
	int	i;
	int	i2;


	// ft_tests();
	// ft_putchar('/0');
//    printf("vrai|%2c|\n", 0);
// ft_printf("mine|%2c|\n", 0);

i2 = ft_printf("mine : null %c and text\n", 0);
i = printf("vrai : null %c and text\n", 0);
printf("Vrai : %d\nMine : %d\n",i, i2 );

//     i = printf("vrai : |@moulitest: %c|\n", 0);
// i2 = ft_printf("mine : |@moulitest: %c|\n", 0);




	// str = ft_strdup("oui");
	//
	// printf("|%s|\n", "this is a string");
	// ft_printf("|%s|\n", "this is a string");
	// printf("--------------\n");
	// printf("|%s|\n", NULL);
	// ft_printf("|%s|\n", NULL);
	// printf("--------------\n");
	// printf("|%s|\n", "lol");
	// ft_printf("|%s|\n", "lol");
	// printf("--------------\n");
	// printf("|%llx|\n", (long long)10);
	// ft_printf("|%llx|\n", (long long)10);
	// printf("--------------\n");
	// printf("|%-20s| is a string\n", "this");
	// ft_printf("|%-20s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-2s| is a string\n", "this");
	// ft_printf("|%-2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-.2s| is a string\n", "this");
	// ft_printf("|%-.2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-5.2s| is a string\n", "this");
	// ft_printf("|%-5.2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-7.7s| is a string\n", "this");
	// ft_printf("|%-7.7s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%-1.0d|\n", -18);
	// ft_printf("|%-1.0d|\n", -18);
	// printf("--------------\n");
	// printf("|%#10o|\n", 524);
	// ft_printf("|%#10o|\n", 524);
	// printf("--------------\n");
	// printf("|%08x|\n", 42);
	// ft_printf("|%08x|\n", 42);
	// printf("--------------\n");
	// printf("|%10.08x|\n", 42);
	// ft_printf("|%10.08x|\n", 42);
	// printf("--------------\n");
	// printf("|%.8x|\n", 42);
	// ft_printf("|%.8x|\n", 42);
	// printf("--------------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%+d|\n", -42);
	// ft_printf("|%+d|\n", -42);
	// printf("--------------\n");
	// printf("|% d|\n", -42);
	// ft_printf("|% d|\n", -42);
	// printf("--------------\n");
	// printf("|%+5d|\n", 42);
	// ft_printf("|%+5d|\n", 42);
	// printf("--------------\n");
	// printf("|%+4.5d|\n", 42);
	// ft_printf("|%+4.5d|\n", 42);
	// printf("--------------\n");
	// printf("|%+.5d|\n", 42);
	// ft_printf("|%+.5d|\n", 42);
	// printf("--------------\n");
	// printf("|%05d|\n", -42);
	// ft_printf("|%05d|\n", -42);
	// printf("--------------\n");
	// printf("|%03.2d|\n", -1);
	// ft_printf("|%03.2d|\n", -1);
	// printf("--------------\n");
	// printf("|%#o|\n", 42);
	// ft_printf("|%#o|\n", 42);
	// printf("--------------\n");
	// printf("|%#5x|\n", 42);
	// ft_printf("|%#5x|\n", 42);
	// printf("--------------\n");
	// printf("|%#05x|\n", 42);
	// ft_printf("|%#05x|\n", 42);
	// printf("--------------\n");
	// printf("|%#.05x|\n", 42);
	// ft_printf("|%#.05x|\n", 42);
	// printf("--------------\n");
	// printf("|%#08o|\n", 42);
	// ft_printf("|%#08o|\n", 42);
	// printf("--------------\n");
	// printf("|%+05d|\n", 42);
	// ft_printf("|%+05d|\n", 42);
	// printf("--------------\n");
	// printf("|%0+5d|\n", -42);
	// ft_printf("|%0+5d|\n", -42);
	// printf("--------------\n");
	// printf("|%0+5d|\n", 42);
	// ft_printf("|%0+5d|\n", 42);
	// printf("--------------\n");
	// printf("|%#10.05x|\n", 42);
	// ft_printf("|%#10.05x|\n", 42);
	// printf("--------------\n");
	// printf("|%-20.8o|\n", -42);
	// ft_printf("|%-20.8o|\n", -42);
	// printf("--------------\n");
	// printf("|%-20.15o|\n", -42);
	// ft_printf("|%-20.15o|\n", -42);
	// printf("--------------\n");
	// printf("|%-3.6o|\n", -17);
	// ft_printf("|%-3.6o|\n", -17);
	// printf("--------------\n");
	// printf("|%.0s|\n", "salutttt");
	// ft_printf("|%.0s|\n", "salutttt");
	// printf("--------------\n");
	// printf("|% %|\n");
	// ft_printf("|% %|\n");
	// printf("--------------\n");
	// printf("%% |%2.11u|\n", 18);
	// ft_printf("%% |%2.11u|\n", 18);
	// printf("--------------\n");
	// printf("|%07.5d|,|%d|\n",150789, 17);
	// ft_printf("|%07.5d|,|%d|\n",150789, 17);
	// printf("--------------\n");
	// printf("|%00.05d| \n", 7);
	// ft_printf("|%00.05d| \n", 7);
	// printf("--------------\n");
	// printf("|%05.2d|\n", 7);
	// ft_printf("|%05.2d|\n", 7);
	// printf("--------------\n");
	// printf("|%5%|\n");
	// ft_printf("|%5%|\n");
	// printf("--------------\n");
	// printf("|%.5%|\n");
	// ft_printf("|%.5%|\n");
	// printf("--------------\n");
	// printf("|%-.5%|\n");
	// ft_printf("|%-.5%|\n");
	// printf("--------------\n");
	// printf("|%8.5%|\n");
	// ft_printf("|%8.5%|\n");
	// printf("--------------\n");
	// printf("|%+8.5%|\n");
	// ft_printf("|%+8.5%|\n");
	// printf("--------------\n");
	// printf("|%-5%|\n");
	// ft_printf("|%-5%|\n");
	// printf("--------------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("--------------\n");
	// printf("|%+-8.5%|\n");
	// ft_printf("|%+-8.5%|\n");
	// printf("--------------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("--------------\n");
	// printf("|%5.2s| is a string\n", "this");
	// ft_printf("|%5.2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%12s| is a string\n", "this");
	// ft_printf("|%12s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%5.x| |%5.0x|\n", 0, 0);
	// ft_printf("|%5.x| |%5.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#.x| |%#.0x|\n", 0, 0);
	// ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%.x| |%.0x|\n", 0, 0);
	// ft_printf("|%.x| |%.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#x|\n", 0);
	// ft_printf("|%#x|\n", 0);
	// printf("--------------\n");
	// printf("|%5.2s| is a string\n", "");
	// ft_printf("|%5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%.o| |%.0o|\n", 0, 0);
	// ft_printf("|%.o| |%.0o|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#.o| |%#.0o|\n", 0, 0);
	// ft_printf("|%#.o| |%#.0o|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#.x| |%#.0x|\n", 0, 0);
	// ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%.d| |%.0d|\n", 0, 0);
	// ft_printf("|%.d| |%.0d|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%5.d| |%5.0d|\n", 0, 0);
	// ft_printf("|%5.d| |%5.0d|\n", 0, 0);
	// printf("--------------\n");
	// printf("%03.2d\n", 0);
	// ft_printf("%03.2d\n", 0);
	// printf("--------------\n");
	// printf("--------------\n");
	// printf("--------------\n");



	// ft_printf("%#-08x", 42);
	// ft_printf("%-05o", 2500);
	// ft_printf("%-05d", 42);
	// ft_printf("%-05d", -42);
	// ft_printf("% u", 4294967295);
	// ft_printf("%+u", 4294967295);

	return 0;
}
