/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhh_lll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/04/16 16:19:11 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_hhhlll_u(t_data *data, int base, int mode)
{
	unsigned long long	ap;
	char				*final;

	if (data->f & F_H)
		ap = (unsigned short)(va_arg(data->ap, int));
	else if (data->f & F_HH)
		ap = (unsigned char)(va_arg(data->ap, int));
	else if (data->f & F_L)
		ap = (unsigned long)(va_arg(data->ap, long));
	else if (data->f & F_LL)
		ap = (unsigned long long)(va_arg(data->ap, long long));
	else
	{
		ap = (va_arg(data->ap, int));
		data->ap_sz = ft_intlen(ap);
		if (!(final = itoa_base_m((int)ap, base, mode, data)))
			return (NULL);
		return (final);
	}
	data->ap_sz = ft_intlen(ap);
	if (!(final = ibmul(ap, base, mode, data)))
		return (NULL);
	return (final);
}

char	*ft_conv_hhhlll(t_data *data)
{
	long long			ap;

	if (data->f & F_H)
		ap = (short)(va_arg(data->ap, int));
	else if (data->f & F_HH)
		ap = (char)(va_arg(data->ap, int));
	else if (data->f & F_L)
		ap = (long)(va_arg(data->ap, long));
	else if (data->f & F_LL)
		ap = (long long)(va_arg(data->ap, long long));
	else
		ap = (va_arg(data->ap, int));
	data->ap_sz = ft_intlen(ap);
	if (ap < 0 && !(data->f & ONLY_CONV) && (data->f & F_PRECIS
		|| data->f & F_WIDTH))
	{
		data->f |= AP_NEG;
		ap = -ap;
	}
	if (ap < 0)
		data->f |= AP_NEG;
	return (ft_itoa(ap));
}
