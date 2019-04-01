/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 18:12:01 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_dlh(t_data *data)
{
	char *final;

	if (data->flag & F_H)
		if(!(final = ft_dh(data)))
			return (NULL);
	if (data->flag & F_HH)
		if(!(final = ft_dhh(data)))
			return (NULL);
	if (data->flag & F_L)
		if(!(final = ft_dl(data)))
			return (NULL);
	if (data->flag & F_LL)
		if(!(final = ft_dll(data)))
			return (NULL);

	return (final);
}

char	*ft_conv_di(t_data *data)
{
	int		ap;
	int		ap_sz;
	char	*final;

	if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
		data->tmp = (va_arg(data->ap, int));
	if (data->flag & F_H || data->flag & F_HH || data->flag & F_L
	|| data->flag & F_LL)
	{
		if (!(final = ft_conv_dlh(data)))
			return (NULL);
		return (final);
	}
	else
	{
		ap = (va_arg(data->ap, int));
		ap_sz = ft_intlen(ap);
		data->ap_sz = ap_sz;
		if (ap < 0 && !(data->flag & ONLY_CONV))
		{
			data->flag |= AP_NEG;
			ap = -ap;
		}
		if (((data->flag & F_PLUS) || (data->flag & F_MINUS)) && ap < 0 \
		&& data->flag & F_PRECIS)
		{
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
		data->conv_sz = ft_strlen(final);
		return (final);
	}
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
	unsigned int	ap;
	int				ap_sz;
	char			*final;

	ap = (va_arg(data->ap, unsigned int));
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	if (!(final = ft_itoa_base_mode(ap, 10, 1)))
		return (NULL);
	data->conv_sz = ft_strlen(final);
	return (final);
}
