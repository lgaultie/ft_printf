/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/03 14:12:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	char			*final;

	if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
		data->tmp = (va_arg(data->ap, int));
	final = ft_conv_hhhlll(data);
	if (((data->flag & F_PLUS) || (data->flag & F_MINUS)) \
		&& (data->flag & AP_NEG) && data->flag & F_PRECIS)
	{
		data->ap_sz--;
		data->flag |= F_PLUS_MINUS;
	}
	data->conv_sz = ft_strlen(final);
	return (final);
}

char	*ft_conv_u(t_data *data)
{
	// char			*final;
	// int				ap;
	// char			*tmp;
	//
	// data->flag |= F_UNSIGNED;
	// ap = (va_arg(data->ap, int));
	// if (ap < 0)
	// 	data->flag |= AP_NEG;
	// data->ap_sz = ft_intlen(ap);
	// if (data->flag & F_H || data->flag & F_HH || data->flag & F_L
	// || data->flag & F_LL)
	// {
	// 	if (!(final = ft_conv_olh(data, ap)))
	// 		return (NULL);
	// }
	// else
	// {
	// 	if ((data->flag & F_SHARP) && ap != 0)
	// 	{
	// 		tmp = ft_itoa_base_mode(ap, 10, 1);
	// 		if (!(final = ft_strjoin("0", tmp)))
	// 			return (NULL);
	// 		free(tmp);
	// 	}
	// 	else
	// 	{
	// 		if (!(final = ft_itoa_base_mode(ap, 10, 1)))
	// 			return (NULL);
	// 	}
	// }
	unsigned long long	ap;
	int				ap_sz;
	char			*final;

	ap = 0;
	final = ft_conv_hhhlll_u(data, 10);
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	data->conv_sz = ft_strlen(final);
	return (final);
}
