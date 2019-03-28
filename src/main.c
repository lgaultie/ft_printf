/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/28 19:17:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_tests();
// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// printf("Vrai : i = |%s|,|%d|, test\n", "Salut", 17);
	// ft_printf("Mine : i = |%s|,|%d|, test\n", "Salut", 17);
//	ft_tests();
	printf("V : |%.*s|\n", 3, "SALUT");
	ft_printf("M : |%.*s|\n", 3, "SALUT");
	// ft_printf("Vrai : %% |%-5%|\n");
	// ft_printf("Vrai : %% |%5%|\n");
	// ft_printf("Vrai : %% |%2.11u|\n", 18);
	// ft_printf("Vrai : |%1d|\n", -18);		WTF
	// ft_printf("Vrai : |%.10s|\n", "ouiiiiiiiiiiiiiiiii");
	// ft_printf("Vrai : |%-1.0d|\n", -18);
	// ft_printf("Mine : i = |%07.5d|,|%d|, test\n",150789, 17);
	// ft_printf("i = |%05.2d|test\n", 7);
	// ft_printf("i = %00.05d test\n",i);
	// ft_printf("Mine : i = %5%\n");

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
// >>>>>>> e19e91eb73b4ed239d31e3e2b1b3e92e48c39fbd
	return 0;
}
// printf("----- Test 01 ----\n int + Accuracy\n");
// str = ft_strdup("|%5d|\n");
// tmp = ft_printf(str, 5);
// printf("Before : OK\n");
// if ((ft_strcmp("|    5|\n", tmp) == 0))
// {
	// 		i++;
	// 		printf("\n----> OK <----\n\n");
	// 	}
	// 	else
	// 	printf("NOOOON\n");
	// 	printf("---------------\n\n");
	//
	// 	printf("----- Test 02 ----\n int + Width + *\n");
	// 	str = ft_strdup("|%*d|\n");
	// 	tmp = ft_printf(str, 5, 10);
	// 	printf("Before : OK\n");
	// 	if ((ft_strcmp("|   10|\n", tmp) == 0))
	// 	{
		// 			i++;
		// 			printf("\n----> OK <----\n\n");
		// 		}
		// 		else
		// 		printf("NOOOON\n");
		// 		printf("---------------\n\n");
		//
		// 		printf("----- Test 03 ----\n int + Width + *\n");
		// 		str = ft_strdup("|%s|\n");
		// 		tmp = ft_printf(str, "SAlUT");
		// 		printf("Before : OK\n");
		// 		if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
		// 		{
			// 				i++;
			// 				printf("\n----> OK <----\n\n");
			// 			}
			// 			else
			// 			printf("NOOOON\n");
			// 			printf("---------------\n\n");
			//
			// 			printf("----- Test 04 ----\n int + accuracy + *\n");
			// 			str = ft_strdup("|%.*d|\n");
			// 			tmp = ft_printf(str, 3, 5);
			// 			printf("Before : OK\n");
			// 			if ((ft_strcmp("|005|\n", tmp) == 0))
			// 			{
				// 					i++;
				// 					printf("\n----> OK <----\n\n");
				// 				}
				// 				else
				// 				printf("NOOOON\n");
				// 				printf("---------------\n\n");
				//
				// 				printf("----- Test 05 ----\n char * + accuracy\n");
				// 				str = ft_strdup("|%.4s|\n");
				// 				tmp = ft_printf(str, "SAlUT");
				// 				printf("Before : NOK\n");
				// 				if ((ft_strcmp("|SAlU|\n", tmp) == 0))
				// 				{
					// 						i++;
					// 						printf("\n----> OK <----\n\n");
					// 					}
					// 					else
					// 					printf("NOOOON\n");
					// 					printf("---------------\n\n");
					//
					// 					printf("----- Test 06 ----\n char * + accuracy + *\n");
					// 					str = ft_strdup("|%.*s|\n");
					// 					tmp = ft_printf(str, 3, "SAlUT");
					// 					printf("Before : NOK\n");
					// 					if ((ft_strcmp("|SAl|\n", tmp) == 0))
					// 					{
						// 							i++;
						// 							printf("\n----> OK <----\n\n");
						// 						}
						// 						else
						// 						printf("NOOOON\n");
						// 						printf("---------------\n\n");
						//
						// 						printf("Score : %d/6\n\n", i);
