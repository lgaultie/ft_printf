/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/22 15:47:13 by takou            ###   ########.fr       */
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
		ap = data->tmp_s;
		if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
			data->tmp = (va_arg(data->ap, int));
		len = ft_precision_s(flag, data);
		//printf("len : %d\n", len);
		data->ap_sz = len;
		if (!(final = ft_strsub(ap, 0, len)))
			return (NULL);
	}
	if (mode == 0)
	{
		if (data->flag ^ F_STAR)
			ap = (va_arg(data->ap, char*));
		if (data->flag & F_PRECIS)
		{
			if (data->flag & F_STAR)
				data->tmp = (va_arg(data->ap, int));
			if ((data->flag & F_PRECIS) && (data->flag ^ F_STAR))
				data->tmp_s = ft_strdup(ap);
			return ("");
		}

		data->ap_sz = ft_strlen(ap);
		if (!(final =  ft_memalloc(sizeof(char) * (data->ap_sz + 1))))
			return (NULL);
		final = ap;
	}
	//printf("final : |%s|\n", final);
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
