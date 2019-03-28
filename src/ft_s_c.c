/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/28 20:01:23 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_string_1(t_data *data)
{
	char	*ap;

	if (!(data->flag & F_STAR))
		ap = (va_arg(data->ap, char*));
	if (data->flag & F_PRECIS || data->flag & F_WIDTH)
	{
		if (data->flag & F_STAR)
		{
			data->tmp = (va_arg(data->ap, int));
			data->tmp_s = (va_arg(data->ap, char *));
		}
		if ((data->flag & F_PRECIS || data->flag & F_WIDTH)
		&& (!(data->flag & F_STAR)))
			data->tmp_s = ft_strdup(ap);
		return (ft_strdup(""));
	}
	data->ap_sz = ft_strlen(ap);
	return (ft_strdup(ap));
}

char		*ft_string(char *flag, t_data *data, int mode)
{
	char	*ap;
	char	*final;

	if (mode == 1)
	{
		ap = data->tmp_s;
		if (data->flag & F_PRECIS)
		{
			data->ap_sz = ft_precision_s(flag, data);
			if (!(final = ft_strsub(ap, 0, data->ap_sz)))
				return (NULL);
		}
		if (data->flag & F_WIDTH)
		{
			data->ap_sz = ft_strlen(ap);
			if (!(final = ft_strjoin(ft_width(flag, data), ap)))
				return (NULL);
		}
	}
	if (mode == 0)
		if (!(final = ft_string_1(data)))
			return (NULL);
	return (final);
}

char		*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	final[0] = ap;
	final[1] = '\0';
	return (final);
}
