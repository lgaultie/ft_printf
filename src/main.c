/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/17 19:47:12 by takou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int		ft_next_p100_i(char *str, int	mode)
// {
// 	int	p_nb;
// 	int	i;
//
// 	p_nb = 0;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '%' && str[i + 1] == '%')
// 		{
// 			if (mode == 1)
// 				p_nb++;
// 			if (mode == 2)
// 				return (i);
// 			i++;
// 		}
// 		if (str[i] == '%' && (i == 0 || str[i - 1] != '%'))
// 			return (i - p_nb);
// 		i++;
// 	}
// 	return (i);
// }
//
// char	*ft_next_p100(char *str, t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	n_p100;
// 	char *ret;
//
// 	i = 0;
// 	j = 0;
// 	n_p100 = ft_next_p100_i(str, 1);
// 	if(!(ret = malloc(sizeof(char) * (n_p100 + 1))))
// 		return (NULL);
// 	//while ((i + j) <= n_p100)
// 	while (str[i + j] != '\0')
// 	{
// 		if (str[i + j] == '%' && str[i + j + 1] == '%')
// 			j++;
// 		if (str[i + j] == '%' && (i == 0 || str[i + j - 1] != '%'))
// 		{
// 			ret[i] = '\0';
// 			return (ret);
// 		}
// 		ret[i] = str[i + j];
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	data->done = 1;
// 	return (ret);
// }

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	// char	*tmp;
	int		test_nb;
	int		i;

	t_data *data;
	test_nb = 7;
	i = 0;
	data = ft_memalloc(sizeof(t_data));

	// i |= 2; // active le bit 2
	// i |= 4; // active le bit 4
	// if (i & 2) // check if bit 2 is enable
	// i &= ~2;// disable bit 2

	str = ft_strdup(" %177d%%%s%%%d ");
	ft_printf("%.5d%% b%plabla \n", i, &test_nb);
	//printf("%.*d\n", 5, test_nb);
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
