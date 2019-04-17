/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:27:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/16 19:57:22 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_disable_flag(t_data *d)
{
	d->f &= ~F_ZERO;
	d->f &= ~F_PLUS;
	d->f &= ~F_MINUS;
	d->f &= ~F_SHARP;
	d->f &= ~F_SPACE;
	d->f &= ~F_WIDTH;
	d->f &= ~F_PRECIS;
	d->f &= ~F_STAR;
	d->f &= ~F_W_P;
	d->f &= ~B_DONE;
	d->f &= ~F_PLUS_MINUS;
	d->f &= ~F_H;
	d->f &= ~F_HH;
	d->f &= ~F_L;
	d->f &= ~F_LL;
	d->f &= ~AP_NEG;
	d->f &= ~F_UNSIGNED;
	d->f &= ~ONLY_CONV;
	d->f &= ~F_PERCENT;
	d->f &= ~F_S;
	d->f &= ~F_S_0;
	d->f &= ~F0;
	d->f &= ~TMP_S_M;
}

/*
** ft_active_cast: active needed format flags for h, hh, l, ll.
*/

void			ft_active_cast(char *flag, t_data *data, int i)
{
	int	len;

	len = ft_strlen(&flag[i]);
	if (flag[i] == 'h' && flag[i + 1] == 'h' && len == 3 \
	&& (!(data->f & F_H)))
		data->f |= F_HH;
	else if (flag[i] == 'h' && len == 2 && (!(data->f & F_HH)))
		data->f |= F_H;
	else if (flag[i] == 'l' && len == 2 && (!(data->f & F_LL)))
		data->f |= F_L;
	else if (flag[i] == 'l' && flag[i + 1] == 'l' && len == 3 \
	&& (!(data->f & F_L)))
		data->f |= F_LL;
}

static void		ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
		data->f |= F_SPACE;
	else if (flag[i] == '#')
		data->f |= F_SHARP;
	else if (flag[i] == '+')
		data->f |= F_PLUS;
	else if (flag[i] == '-')
		data->f |= F_MINUS;
	else if (flag[i] == '%')
		data->f |= F_PERCENT;
	else if (flag[i] == 'h' || flag[i] == 'l')
		ft_active_cast(flag, data, i);
	else if (flag[i] == 'L')
		data->f |= F_BIG_L;
}

/*
** ft_active_flag: Analyses between % and the conversion, enable needed flags.
** F_W_P: active flag width + accuracy (ex: %5.2d)
*/

int				ft_active_flag(char *flag, t_data *data)
{
	int		i;

	i = 0;
	while (flag[i] != 'd' && flag[i] != 'c' && flag[i] != 's' \
		&& flag[i] != 'p' && flag[i] != 'x' && flag[i] != 'o' \
		&& flag[i] != 'x' && flag[i] != 'X' && flag[i] != 'i' \
		&& flag[i] != 'f' && flag[i] != 'u' && flag[i] != '\0')
	{
		if ((flag[i] == '0' && i == 0) \
		|| (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9')))
			data->f |= F_ZERO;
		if (flag[i] == '.' && (data->f & F_WIDTH))
			data->f |= F_W_P;
		else if (((flag[i] >= '0' && flag[i] <= '9') || flag[i] == '*')
			&& !(data->f & F_PRECIS))
			data->f |= F_WIDTH;
		else if (flag[i] == '.')
			data->f |= F_PRECIS;
		else
			ft_active_flag2(flag, data, i);
		i++;
	}
	if (data->f & F_ZERO && data->f & F_MINUS)
		data->f &= ~F_ZERO;
	if ((flag[i] == 'c' || flag[i] == 'u') && data->f & F_SPACE)
		data->f &= ~F_SPACE;
	if ((flag[i] == 'u') && data->f & F_PLUS)
		data->f &= ~F_PLUS;
	if ((flag[i] == 'c') && data->f & F_PRECIS)
		data->f &= ~F_PRECIS;

	return (i);
}

/*
** ft_percent_percent: deals with %7%, %.5%, or % % cases.
*/

char			*ft_percent_percent(char *ret_flag, t_data *data)
{
	char	*final;

	if (data->f & F_WIDTH && !(data->f & F_PRECIS))
	{
		ret_flag[ft_strlen(ret_flag) - 1] = '%';
		final = ft_strdup(ret_flag);
	}
	else
		final = ft_strdup("%");
	return (final);
}
