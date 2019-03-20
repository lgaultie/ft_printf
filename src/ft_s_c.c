/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 20:39:00 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(char *flag, t_data *data, int mode)
{
	char	*ap;
	char	*final;
	int		len;

	len = 0;
	if (mode == 1)
	{
		if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
			data->tmp = (va_arg(data->ap, int));
		if (data->flag & F_PRECIS)
		{
			len = ft_precision_s(flag, data);
		}
		ap = (va_arg(data->ap, char*));
		data->ap_sz = ft_strlen(ap);
		if (!(final = ft_strsub(ap, 0, len)))
			return (NULL);
	}
	if (mode == 0)
	{
		if (data->flag & F_PRECIS)
			return ("");
		ap = (va_arg(data->ap, char*));
		data->ap_sz = ft_strlen(ap);
		if (!(final =  ft_memalloc(sizeof(char) * (data->ap_sz + 1))))
			return (NULL);
		final = ap;
	}
	return (final);
}

char	*ft_char(t_data *data)
{
	char	ap;
	char	*final;
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (!(final =  ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	final[0] = ap;
	final[1] = '\0';
	return (final);
}
