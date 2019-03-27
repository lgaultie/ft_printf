/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/27 19:45:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// ----------------- BITWISE ---------------------

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	//char	*tmp;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 9;
	i = 0;
	data = ft_memalloc(sizeof(t_data));

	// i |= 2; // active le bit 2
	// if (i & 2) // check if bit 2 is enable
	// i &= ~2;// disable bit 2
	//i &= ~4;

	str = ft_strdup(" %177d%%%s%%%d ");
		//  printf("Vrai : i = |%.6s|,|%d|, test\n", "Salut", 17);
		//  ft_printf("Mine : i = |%.6s|,|%d|, test\n\n", "Salut", 17);
	printf("Vrai : i = |%*s|,|%d|, test\n", 6, "Salut", 17);
	ft_printf("Mine : i = |%*s|,|%d|, test\n", 6, "Salut", 17);
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
