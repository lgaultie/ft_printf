/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:45:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 18:09:18 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_no_flag_zero(char *ret, int width, int i, t_data *data)
{
	int		surplus;

	surplus = (data->flag & F_PLUS && !(data->flag & F_PERCENT)) ? 1 : 0;
	if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
	{
		while (i < width - data->conv_sz - 1)
			ret[i++] = ' ';
		ret[i++] = '-';
	}
	else
	{
		while (i < width - data->conv_sz - surplus)
			ret[i++] = ' ';
		if (data->flag & F_PLUS && !(data->flag & F_PERCENT))
			ret[i++] = '+';
	}
	return (ret);
}

static char		*ft_small_width(t_data *data)
{
	if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
		return (ft_strdup("-"));
	else if (data->flag & F_PLUS)
		return (ft_strdup("+"));
	return (ft_strdup(""));
}

char			*ft_width2(int width, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (width > data->conv_sz)
	{
		if (!(ret = ft_memalloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		if (data->flag & F_ZERO)
		{
			if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
				ret[i++] = '-';
			else if (data->flag & F_PLUS)
				ret[i++] = '+';
			while (i < width - data->conv_sz)
				ret[i++] = '0';
		}
		if (!(data->flag & F_ZERO))
			ret = ft_no_flag_zero(ret, width, i, data);
	}
	if (width <= data->conv_sz)
		return (ft_small_width(data));
	return (ret);
}
