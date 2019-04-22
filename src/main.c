/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/22 14:24:10 by amamy            ###   ########.fr       */
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

//NORMEEEEEEE
//fichier oxcapsx.c a faire
//fichier plus_minus chelou
// fichiers de la libft a faire (comme itoa base)

int main(int argc, char **argv)
{
	long double		i;

	(void)argc;
	(void)argv;
	i = 123131;


	printf("vrai : |%#7.2o|\n", 0);						//ok
	ft_printf("mine : |%#7.2o|\n", 0);					//ok
	printf("--------------\n");
	printf("vrai : |%#7.1o|\n", 00);						//ok
	ft_printf("mine : |%#7.1o|\n", 00);					//ok
	printf("--------------\n");
	printf("vrai : |%#10.8o|\n", 424242);				//ok
	ft_printf("mine : |%#10.8o|\n", 424242);				//ok
	printf("vrai : |%#10.8o|\n", 424242);				//ok
	ft_printf("mine : |%#10.8o|\n", 424242);				//ok
	printf("--------------\n");
	printf("vrai : |%#10.8o|\n", 424242);				//ok
	ft_printf("mine : |%#10.8o|\n", 424242);				//ok
	printf("--------------\n");
	printf("vrai : |%0.0o|\n", 0);
	ft_printf("mine : |%0.0o|\n", 0);
	printf("--------------\n");
	printf("vrai : |%1.o|\n", 0);						//ok
	ft_printf("mine : |%1.o|\n", 0);
	printf("--------------\n");
	printf("vrai : |%03.2o|\n", 0);						//casse couille
	ft_printf("mine : |%03.2o|\n", 0);					//casse couille
	printf("--------------\n");
	printf("vrai : |%#1.o|\n", 0);						//ok
	ft_printf("mine : |%#1.o|\n", 0);					//ok
	printf("--------------\n");
	printf("vrai : |%0.0o|\n", 0);
	ft_printf("mine : |%0.0o|\n", 0);
	printf("--------------\n");
	printf("vrai : |%1.x|\n", 0);						//ok
	ft_printf("mine : |%1.x|\n", 0);					//ok
	printf("--------------\n");
	printf("vrai : |%#1.x|\n", 45);						//ok
	ft_printf("mine : |%#1.x|\n", 45);					//ok
	printf("--------------\n");
	printf("vrai : |%#1.x|\n", 10);						//ok
	ft_printf("mine : |%#1.x|\n", 10);					//ok
	printf("--------------\n");
	printf("vrai : |%#8.10x|\n", 424242);
	ft_printf("Mine : |%#8.10x|\n", 424242);
	printf("--------------\n");
	printf("true : |%.x| |%.0x|\n", 0, 0);
	ft_printf("mine : |%.x| |%.0x|\n", 0, 0);
	printf("--------------\n");
	printf("True : |%#.x| |%#.0x|\n", 0, 0);
	ft_printf("Mine : |%#.x| |%#.0x|\n", 0, 0);
	printf("--------------\n");
	printf("vrai : |%03.2x|\n", 0);						//casse couille
	ft_printf("mine : |%03.2x|\n", 0);					//casse couille
	printf("--------------\n");
	printf("vrai : |%0.0x|\n", 0);
	ft_printf("mine : |%0.0x|\n", 0);
	printf("--------------\n");
	printf("vrai : |%#x|\n", 0);
	ft_printf("Mine : |%#x|\n", 0);
	printf("--------------\n");
	printf("vrai : |%#10.5X|\n", 42); 					//ok
	ft_printf("mine : |%#10.5X|\n", 42);					//ok
	printf("--------------\n");
	printf("vrai : |%3.2X|\n", 0);						//casse couille
	ft_printf("mine : |%3.2X|\n", 0);					//casse couille
	printf("--------------\n");
	printf("vrai : |%03.2d|\n", 0);						//casse couille
	ft_printf("mine : |%03.2d|\n", 0);					//casse couille
	printf("--------------\n");
	printf("vrai : |%1.d|\n", 243);						//ok
	ft_printf("mine : |%1.d|\n", 243);					//ok
	printf("--------------\n");
	printf("vrai : |%-+10d|\n", 42);						//ok
	ft_printf("mine : |%-+10d|\n", 42);					//ok
	printf("--------------\n");
	printf("vrai : |%+.10d|\n", -64);					//ok
	ft_printf("mine : |%+.10d|\n", -64);					//ok
	printf("--------------\n");
	printf("vrai : @moulitest: |%.10d|\n", -42);			//ok
	ft_printf("mine : @moulitest: |%.10d|\n", -42);		//ok
	printf("--------------\n");
	printf("vrai : |%1.s|\n", "243");					//ok
	ft_printf("mine : |%1.s|\n", "243");					//ok
	printf("--------------\n");

	return 0;
}
