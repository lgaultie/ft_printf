/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhh_lll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/04/02 12:03:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_conv_hhhlll_u(t_data *data)
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
		ap = (va_arg(data->ap, int));
	return (ap);
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
