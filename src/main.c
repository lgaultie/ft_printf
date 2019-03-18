/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/18 19:11:04 by lgaultie         ###   ########.fr       */
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
		//printf("%d%% b%plabla \n", i, &test_nb);
	ft_printf("i = %05dtest\n", i);
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
