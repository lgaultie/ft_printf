/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/07 22:48:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str;
	t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
		data->flag_sz = 5;
		data->ap_sz = 3;
	str = ft_strdup("%2s");

	//		   FAUX --> Je m'appggel%le : |ICI| et j'ai cICIombien deja ? SALUT ans\n

	//ft_printf(str);
	printf("%s\n", ft_width(str, data));

	//ft_printf("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n"); <-------- segfault for sure
	return 0;
}
