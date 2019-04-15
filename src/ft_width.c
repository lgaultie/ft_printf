/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/15 18:50:48 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_width: analyse the flag to convert it into a int which will be width.
** Sends this int to ft_width2 which will apply the conversion.
*/

char			*ft_width(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (data->f & F_WIDTH && (i = data->tmp))
		data->f &= ~F_WIDTH;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	while (flags[i] != '\0')
	{
		if (flags[i] == '#' || flags[i] == '+')
			i++;
		if ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == '-')
			conv[j] = flags[i];
		i++;
		j++;
	}
	i = ft_atoi(conv);
	free(conv);
	data->f &= ~F_WIDTH;
	data->index_0 = (data->f & F_C_0) ? data->index_0 += i - 1 : 0;
	i = (i < 0) ? -i : i;
	return (ft_width2(i, data));
}

static char		*ft_width_minus2(int width, t_data *data)
{
	int		i;
	char	*ret;
	int		surplus;

	i = 0;
	free(data->tmp_s);
	surplus = (data->f & AP_NEG) ? 1 : 0;
	if (data->f & F_MINUS && data->f & F_ZERO)
		return (ft_strdup(""));
	if (width > data->conv_sz)
	{
		if (!(ret = ft_memalloc(sizeof(char) * ((width - data->conv_sz) + 1))))
			return (NULL);
		if (data->f & F_ZERO)
			while (i < width - data->conv_sz)
				ret[i++] = '0';
		if (!(data->f & F_ZERO))
			while (i < width - data->conv_sz - surplus)
				ret[i++] = ' ';
	}
	else
		return (ft_strdup(""));
	if (data->f & F_PLUS)
		ret[i++] = '+';
	return (ret);
}

/*
** ft_width_minus : Case of width + flag minus. Analyse the flag to convert it
** into a int which will be width. Sends it to ft_width_minus2.
*/

char			*ft_width_minus(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (NULL);
	while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9' \
	|| flags[i] == '-')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
		conv[j++] = flags[i++];
	i = ft_atoi(conv);
	free(conv);
	return (ft_width_minus2(i, data));
}

static char		*ft_width_s2(int width, t_data *data)
{
	char	*ret;
	int		i;

	i = 0;
	if (width < data->ap_sz)
		return (ft_strdup(""));
	else
	{
		if (!(ret = ft_memalloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		while (i < width - data->ap_sz)
		{
			ret[i] = ' ';
			i++;
		}
	}
	return (ret);
}

/*
** ft_width_s : Deals with width in a %s case. Analyse the flag to convert it
** into a int which will be width. Sends it to ft_width_s2.
*/

char			*ft_width_s(char *f, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	while (f[i] != '\0')
	{
		if (f[i] == '#')
			i++;
		if ((f[i] >= '0' && f[i] <= '9') || f[i] == '+' || f[i] == '-')
			conv[j] = f[i];
		i++;
		j++;
	}
	i = ft_atoi(conv);
	free(conv);
	data->f &= ~F_WIDTH;
	return (ft_width_s2(i, data));
}
