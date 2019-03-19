/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:29:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/19 16:45:39 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(char *flag, t_data *data)
{
	int		i;
	char	*final;

	(void)data;
	i = 0;

	ft_putstr("flag = ");
	ft_putstr(flag);
	ft_putchar('\n');











	final = ft_strdup(flag);
	return (final);
}
