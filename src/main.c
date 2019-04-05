/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/05 15:04:02 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	ft_tests();
// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// ft_tests();

	printf("|%5c|\n", 't');
	ft_printf("|%5c|\n", 't');

// printf("%.2c", NULL);
// ft_printf("%.2c", NULL);


	return 0;
}
