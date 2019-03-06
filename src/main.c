/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/06 22:05:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_next_p100_i(char *str)
{
	int	i;
	int	p_nb;

	p_nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			p_nb++;
			i++;
		}
		if (str[i] == '%' && (i == 0 || str[i - 1] != '%'))
			return (i - p_nb);
		i++;
	}
	return (i);
}

char	*ft_next_p100(char *str, char *ret)
{
	int	i;
	int	j;
	int	n_p100;
	//char *ret;

	i = 0;
	j = 0;
	n_p100 = ft_next_p100_i(str);
	if(!(ret = malloc(sizeof(char) * (n_p100))))
		return (NULL);
	while ((i + j) <= n_p100)
	{
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && (i == 0 || str[i + j - 1] != '%'))
		{
			ret[i] = '\0';
			return (ret);
		}
		ret[i] = str[i + j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}




int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	char *ret = NULL;

	str = ft_strdup("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n");
	//printf("VRAI --> Je m'appel%%le : |%0177d| et j'ai combien deja ? %078s ans\n", 66, 122777);
	//		   FAUX --> Je m'appel%le : |ici| et j'ai combien deja ? |ici| ans

	printf("|%s|\n", ret = (ft_next_p100(str, ret)));
	free(str);
	free(ret);
	//ft_printf("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n"); <-------- segfault for sure
	return 0;
}
