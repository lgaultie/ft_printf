/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:23:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/01 14:32:06 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int   main()
{
	ft_printf("MON printf: |le pourcentage s = %s, le pourcentage d = %d|\n", "salut", 14);
	printf("VRAI printf: |le pourcentage s = %s, le pourcentage d = %d|\n", "salut",14);
	return (0);
}
