/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/14 16:05:55 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	int		ap;
	int		ap_sz;
	 char	*final;

	ap = (va_arg(data->ap, int));
	ap_sz = ft_intlen(ap);
	if (!(final = malloc(sizeof(char) * (ap_sz + 1))))
		return (NULL);
	final = ft_itoa(ap);
	return (final);
}
