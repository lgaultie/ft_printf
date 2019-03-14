/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/14 20:08:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// short	i = 32767;		//32767 short max
	// printf("Oui %hd\n", i);
	printf("VRAI -- oui bonjour %.5d\n", 2147);
	ft_printf("FAUX -- oui bonjour %.5d\n", 2147);

	//ft_printf("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n"); <-------- segfault for sure
	return 0;
}
/*
to test :
"%%blabla %d" : NOK -> go direct to %d
%dblabla : ok
%dFAUX --> Je m'appg%%gelle : |%0177d| et j'ai c%dombien deja ? %07s ans\n\n : ok

*/
