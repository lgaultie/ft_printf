/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhh_lll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/04/02 23:33:12 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conv_hhhlll_u(t_data *data)
{
	unsigned long long	ap;

	if (data->flag & F_H)
		ap = (unsigned short)(va_arg(data->ap, int));
	else if (data->flag & F_HH)
		ap = (unsigned char)(va_arg(data->ap, int));
	else if (data->flag & F_L)
		ap = (unsigned long)(va_arg(data->ap, long));
	else if (data->flag & F_LL)
		ap = (unsigned long long)(va_arg(data->ap, long long));
	else
	{
		ap = (va_arg(data->ap, int));
		data->ap_sz = ft_intlen(ap);
		return (ft_itoa_base_mode((int)ap, 8, 1));
	}
	data->ap_sz = ft_intlen(ap);
	return (ft_itoa_b_m_ul(ap, 8, 1));
}

 long long				ft_conv_hhhlll(t_data *data)
{
	long long			ap;

	if (data->flag & F_H)
		ap = (short)(va_arg(data->ap, int));
	else if (data->flag & F_HH)
		ap = (char)(va_arg(data->ap, int));
	else if (data->flag & F_L)
		ap = (long)(va_arg(data->ap, long));
	else if (data->flag & F_LL)
		ap = (long long)(va_arg(data->ap, long long));
	else
		ap = (va_arg(data->ap, int));
	return (ap);
}
