/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_hh_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/03/30 23:21:07 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_dhh(t_data *data)
{
	char	ap;
	int		ap_sz;
	char	*final;

	ap = (char)(va_arg(data->ap, int));
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

char *ft_dh(t_data *data)
{
	short	ap;
	int		ap_sz;
	char	*final;

	ap = (short)(va_arg(data->ap, int));
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

char *ft_dl(t_data *data)
{
	long	ap;
	int		ap_sz;
	char	*final;

	ap = (va_arg(data->ap, long));
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

char *ft_dll(t_data *data)
{
	long long	ap;
	int			ap_sz;
	char		*final;

	ap = (long long)(va_arg(data->ap, int));
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
