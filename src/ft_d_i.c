/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 21:37:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	char			*final;

	if (data->f & F_STAR && (data->f & F_WIDTH || data->f & F_PRECIS))
		data->tmp = (va_arg(data->ap, int));
	final = ft_conv_hhhlll(data);
	if (((data->f & F_PLUS) || (data->f & F_MINUS)) \
		&& (data->f & AP_NEG) && data->f & F_PRECIS)
	{
		data->ap_sz--;
		data->f |= F_PLUS_MINUS;
	}
	data->conv_sz = ft_strlen(final);
	if (final[0] == '0' && final[1] == '\0' && ((data->f & F_SHARP) \
	|| data->f & F_PRECIS))
	{
		free(final);
		return (ft_strdup(""));
	}
	// if (final[0] == '0' && final[1] == '\0' && (data->f & F_SHARP \
	// || data->f & F_W_P))
	// 	return (ft_strdup(" "));
	return (final);
}

char	*ft_conv_u(t_data *data)
{
	// char			*final;
	// int				ap;
	// char			*tmp;
	//
	// data->f |= F_UNSIGNED;
	// ap = (va_arg(data->ap, int));
	// if (ap < 0)
	// 	data->f |= AP_NEG;
	// data->ap_sz = ft_intlen(ap);
	// if (data->f & F_H || data->f & F_HH || data->f & F_L
	// || data->f & F_LL)
	// {
	// 	if (!(final = ft_conv_olh(data, ap)))
	// 		return (NULL);
	// }
	// else
	// {
	// 	if ((data->f & F_SHARP) && ap != 0)
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
	final = ft_conv_hhhlll_u(data, 10, 1);
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	data->conv_sz = ft_strlen(final);
	return (final);
}
