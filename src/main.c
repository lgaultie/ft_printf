/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/12 16:52:30 by lgaultie         ###   ########.fr       */
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
	t_data *data;

	data = ft_memalloc(sizeof(t_data));
	str = ft_strdup("blabla %d");
	//
	//		   FAUX --> Je m'appggel%le : |ICI| et j'ai cICIombien deja ? SALUT ans\n

	//printf("ft_strlen... : %lu\n", ft_strlen(ft_next_p100(str, data)));
	// printf("ft_n mode 2 : %d\n", ft_next_p100_i(str, 2));
	// printf("ft_n mode 0 : %d\n", ft_next_p100_i(str, 0));
	// printf("ft_n mode 1 : %d\n|%s|\n|%s|\n", ft_next_p100_i(str, 1), str, ft_next_p100(str, data));
	ft_printf(str);

	//ft_printf("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n"); <-------- segfault for sure
	return 0;
}
/*
to test :
"%%blabla %d" : NOK -> go direct to %d
%dblabla : ok
%dFAUX --> Je m'appg%%gelle : |%0177d| et j'ai c%dombien deja ? %07s ans\n\n : ok

*/
