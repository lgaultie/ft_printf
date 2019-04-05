/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/05 22:14:28 by amamy            ###   ########.fr       */
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
   printf("vrai|%2c|\n", 0);
ft_printf("mine|%2c|\n", 0);

i2 = ft_printf("mine : null %c and text\n", 0);
i = printf("vrai : null %c and text\n", 0);

//     i = printf("vrai : |@moulitest: %c|\n", 0);
// i2 = ft_printf("mine : |@moulitest: %c|\n", 0);
printf("Vrai : %d\nMine : %d\n",i, i2 );


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
	    // ft_printf("|%-5.2s| is a string\n\n", "");
	    // printf("--------------\n");
	    // printf("%+d\n", -42);
	    // ft_printf("%+d\n", -42);
	    // printf("--------------\n");
	    // printf("% d\n", -42);
	    // ft_printf("% d\n", -42);
	    // printf("--------------\n");
	    // printf("%+5d\n", 42);
	    // ft_printf("%+5d\n", 42);
	    // printf("--------------\n");
	    // printf("%+4.5d\n", 42);
	    // ft_printf("%+4.5d\n", 42);
	    // printf("--------------\n");
	    // printf("%+.5d\n", 42);
	    // ft_printf("%+.5d\n", 42);
	    // printf("--------------\n");
	    // printf("%05d\n", -42);
	    // ft_printf("%05d\n", -42);
	    // printf("--------------\n");
	    // printf("%03.2d\n", -1);
	    // ft_printf("%03.2d\n", -1);
	    // printf("--------------\n");
	    // printf("%#o\n", 42);
	    // ft_printf("%#o\n", 42);
	    // printf("--------------\n");
	    // printf("%#5x\n", 42);
	    // ft_printf("%#5x\n", 42);
	    // printf("--------------\n");
	    // printf("%#05x\n", 42);
	    // ft_printf("%#05x\n", 42);
	    // printf("--------------\n");
	    // printf("%#.05x\n", 42);
	    // ft_printf("%#.05x\n", 42);
	    // printf("--------------\n");
	    // printf("|%#08o|\n", 42);
	    // ft_printf("|%#08o|\n", 42);
	    // printf("--------------\n");
	    // printf("%+05d\n", 42);
	    // ft_printf("%+05d\n", 42);
	    // printf("--------------\n");
	    // printf("%0+5d\n", -42);
	    // ft_printf("%0+5d\n", -42);
	    // printf("--------------\n");
	    // printf("%0+5d\n", 42);
	    // ft_printf("%0+5d\n", 42);
	    // printf("--------------\n");
	    // printf("%#10.05x\n", 42);
	    // ft_printf("%#10.05x\n", 42);




	// i = ft_printf("null %c and text", 0);
	// i2 = printf("null %c and text", 0);
	// i = printf("%c", 0);
	// i2 = ft_printf("%c", 0);

	// i = printf("|%2c|\n", 0);
	// i2 = ft_printf("|%2c|\n", 0);



	return 0;
}
