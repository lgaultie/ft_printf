/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/19 20:06:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	// char	*tmp;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 9;
	i = 7;
	data = ft_memalloc(sizeof(t_data));

	// i |= 2; // active le bit 2
	// i |= 4; // active le bit 4
	// if (i & 2) // check if bit 2 is enable
	// i &= ~2;// disable bit 2

	str = ft_strdup(" %177d%%%s%%%d ");
	printf("Vrai : i = |%*d|,|%d|, test\n", 5, 17, 1);
	ft_printf("Mine = i = |%*d|,|%d|, test\n",5, 17, 1);
	//ft_printf("i = %55d  %.10s  %d test\n",2,"nononononononon", i);
	//ft_printf("i = |%.100s|, |%d|, test\n","COUCOU",i);

	//PUTAIN PRINTF printf("i = |%05.2d|test\n", 7);
	//SEG parceque %3s pas géré ft_printf("i = %.5s%3s%dtest\n","oui","nononononononon", i);
	// MARCHE PAS ft_printf("i = %00.05d test\n",i);
		// 	ft_printf(51172,0x7fffaa13f3c0) malloc: *** error for object 0x1016b0fa8: pointer being freed was not allocated
		// *** set a breakpoint in malloc_error_break to debug
		// [1]    51172 abort      ./ft_printf


	//printf("%", 5, test_nb);
	return 0;
}

// printf("----- Test 01 ----\n");
// str = ft_strdup("FAUX --> Je m'appggel%%le : |%d| et j'ai c%dombien deja ? %s ans\n");
// tmp = ft_printf(str);
// if ((ft_strcmp("FAUX --> Je m'appggel%le : |ICI| et j'ai cICIombien deja ? SALUT ans\n", tmp) == 0))
// {
	// 	i++;
	// 	printf("OK\n");
	// }
	// else
	// 	printf("NOOOON\n");
	// printf("---------------\n\n");
	//
	// printf("----- Test 02 ----\n");
	// str = ft_strdup("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n");
	// tmp = ft_printf(str);
	// if ((ft_strcmp("FAUX --> Je m'appggel%le : |ICI| et j'ai cICIombien deja ? SALUT ans\n", tmp) == 0))
	// {
		// 	i++;
		// 	printf("OK\n");
		// }
		// else
		// 	printf("NOOOON\n");
		// printf("---------------\n\n");
		//
		// printf("----- Test 03 ----\n");
		// str = ft_strdup("%%blabla %d");
		// tmp = ft_printf(str);
		// if ((ft_strcmp("%blabla ICI", tmp) == 0))
		// {
			// 	i++;
			// 	printf("\nOK\n");
			// }
			// else
			// 	printf("NOOOON\n");
			// printf("---------------\n\n");
			//
			// printf("----- Test 04 ----\n");
			// str = ft_strdup("");
			// tmp = ft_printf(str);
			// if ((ft_strcmp("", tmp) == 0))
			// {
				// 	i++;
				// 	printf("\nOK\n");
				// }
				// else
				// 	printf("NOOOON\n");
				// printf("---------------\n\n");
				//
				// printf("----- Test 05 ----\n");
				// str = ft_strdup("%dFAUX --> Je m'appg%%gelle : |%0177d| et j'ai c%dombien deja ? %07s ans\n");
				// tmp = ft_printf(str);
				// if ((ft_strcmp("ICIFAUX --> Je m'appg%gelle : |ICI| et j'ai cICIombien deja ? SALUT ans\n", tmp) == 0))
				//
				// {
					// 	i++;
					// 	printf("\nOK\n");
					// }
					// else
					// 	printf("NOOOON\n");
					// printf("---------------\n\n");
					//
					// printf("----- Test 06 ----\n");
					// str = ft_strdup("%%%%%d\n");
					// tmp = ft_printf(str);
					// if ((ft_strcmp("%%ICI\n", tmp) == 0))
					//
					// {
						// 	i++;
						// 	printf("\nOK\n");
						// }
						// else
						// 	printf("NOOOON\n");
						// printf("---------------\n\n");
						//
						// printf("----- Test 07 ----\n");
						// str = ft_strdup("%%%d%d%%%s%%\n");
						// tmp = ft_printf(str);
						// if ((ft_strcmp("%ICIICI%SALUT%\n", tmp) == 0))
						//
						// {
							// 	i++;
							// 	printf("\nOK\n");
							// }
							// else
							// 	printf("NOOOON\n");
							// printf("---------------\n\n");

							//printf("Score : %d/7\n", i);
