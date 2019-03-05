/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/05 14:30:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("VRAI --> Je m'appel%%le : |%0177d| et j'ai combien deja ? %07d ans\n", 66, 122777);
	ft_printf("FAUX --> Je m'appel%%le : |%0177d| et j'ai combien deja ? %07d ans\n", 66, 122777);
	return 0;
}
