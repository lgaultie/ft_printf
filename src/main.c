/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/14 18:57:41 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	printf("VRAI -- oui bonjour %x\n", -1342);
	ft_printf("FAUX -- oui bonjour %x\n", -1342);

	//ft_printf("FAUX --> Je m'appggel%%le : |%0177d| et j'ai c%dombien deja ? %07s ans\n"); <-------- segfault for sure
	return 0;
}
/*
to test :
"%%blabla %d" : NOK -> go direct to %d
%dblabla : ok
%dFAUX --> Je m'appg%%gelle : |%0177d| et j'ai c%dombien deja ? %07s ans\n\n : ok

*/
