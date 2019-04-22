/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_string_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:19:28 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 14:19:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_width_minus2 : Case of width + flag minus. Returns the converted flag.
*/

static char		*ft_width_minus2(int width, t_data *d)
{
	int		i;
	char	*ret;
	int		surplus;

	i = 0;
	free(d->tmp_s);
	surplus = (d->f & AP_NEG || (d->f & F_MINUS && d->f & F_PLUS)) ? 1 : 0;
	if (d->f & F_MINUS && d->f & F_ZERO)
		return (ft_strdup(""));
	if (width > d->conv_sz)
	{
		if (!(ret = ft_memalloc(sizeof(char) * ((width - d->conv_sz) + 1))))
			return (NULL);
		if (d->f & F_ZERO)
			while (i < width - d->conv_sz)
				ret[i++] = '0';
		if (!(d->f & F_ZERO))
			while (i < width - d->conv_sz - surplus)
				ret[i++] = ' ';
	}
	else
		return (ft_strdup(""));
	if (d->f & F_PLUS && !(d->f & F_MINUS))
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

/*
** ft_width_s : Deals with width in a %s case. Returns converted flag.
*/

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

/*
** ft_s_width: deals with cases such as %5s --> width only.
*/

char			*ft_s_width(char *flag, char *ap, t_data *data)
{
	char	*final;
	char	*ret_width;

	data->ap_sz = ft_strlen(ap);
	if (!(ret_width = ft_width_s(flag, data)))
		return (NULL);
	if (!(final = ft_strjoin(ret_width, ap)))
		return (NULL);
	free(ret_width);
	return (final);
}
