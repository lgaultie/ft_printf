/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/28 17:13:18 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	int		ap;
	int		ap_sz;
	char	*final;

	if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
		data->tmp = (va_arg(data->ap, int));
	ap = (va_arg(data->ap, int));
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	if (((data->flag & F_PLUS) || (data->flag & F_MINUS)) && ap < 0 \
	&& data->flag & F_PRECIS)
	{
		ap = -ap;
		if (!(final = ft_itoa(ap)))
			return (NULL);
		data->ap_sz--;
		data->flag |= F_PLUS_MINUS;
	}
	else
	{
		if (!(final = ft_itoa(ap)))
			return (NULL);
	}
	return (final);
}

char	*ft_conv_u(t_data *data)
{
	unsigned int	ap;
	int				ap_sz;
	char			*final;

	ap = (va_arg(data->ap, unsigned int));
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	if (!(final = ft_itoa_base_mode(ap, 10, 1)))
		return (NULL);
	return (final);
}
