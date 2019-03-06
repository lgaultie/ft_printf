/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/06 16:31:15 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//printf("VRAI --> Je m'appel%%le : |%0177d| et j'ai combien deja ? %078s ans\n", 66, 122777);
	//		   FAUX --> Je m'appel%le : |ici| et j'ai combien deja ? |ici| ans
	ft_printf("FAUX --> Je m'appel%%le : %16666s  %222d                                                                  \n", "oui", 42);
	// marche pas : ft_printf("FAUX --> Je m'appel%%le : %s%d%", "oui", 42);
	return 0;
}
