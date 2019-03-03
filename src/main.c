/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/03 11:57:50 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("VRAI --> Je m'appel%%le : |%+-.7d| et j'ai combien deja ? %d ans\n", 66, 1227);
	ft_printf("FAUX --> Je m'appel%%le : |%-d| et j'ai combien deja ? %d ans\n", 66, 1227);
	return 0;
}
