/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:27:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 18:31:50 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_active_cast: active needed format flags for h, hh, l, ll.
*/

void			ft_active_cast(char *flag, t_data *data, int i)
{
	int	len;

	len = ft_strlen(&flag[i]);
	if (flag[i] == 'h' && flag[i + 1] == 'h' && len == 3 \
	&& (!(data->flag & F_H)))
		data->flag |= F_HH;
	else if (flag[i] == 'h' && len == 2 && (!(data->flag & F_HH)))
		data->flag |= F_H;
	else if (flag[i] == 'l' && len == 2 && (!(data->flag & F_LL)))
		data->flag |= F_L;
	else if (flag[i] == 'l' && flag[i + 1] == 'l' && len == 3 \
	&& (!(data->flag & F_L)))
		data->flag |= F_LL;
}

static void		ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
		data->flag |= F_SPACE;
	else if (flag[i] == '#')
		data->flag |= F_SHARP;
	else if (flag[i] == '+')
		data->flag |= F_PLUS;
	else if (flag[i] == '-')
		data->flag |= F_MINUS;
	else if (flag[i] == '%')
		data->flag |= F_PERCENT;
	else if (flag[i] == 'h' || flag[i] == 'l')
		ft_active_cast(flag, data, i);
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
		&& flag[i] != 'x' && flag[i] != 'X' \
		&& flag[i] != 'i' && flag[i] != 'f' && flag[i] != 'u' \
		&& flag[i] != '\0')
	{
		if ((flag[i] == '0' && i == 0) \
		|| (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9')))
			data->flag |= F_ZERO;
		if (flag[i] == '.' && (data->flag & F_WIDTH))
			data->flag |= F_W_P;
		else if (((flag[i] >= '0' && flag[i] <= '9') || flag[i] == '*')
			&& !(data->flag & F_PRECIS))
			data->flag |= F_WIDTH;
		else if (flag[i] == '.')
			data->flag |= F_PRECIS;
		else
			ft_active_flag2(flag, data, i);
		i++;
	}
	return (i);
}

/*
** ft_percent_percent: deals with %7%, %.5%, or % % cases.
*/

char			*ft_percent_percent(char *ret_flag, t_data *data)
{
	char	*final;

	if (data->flag & F_WIDTH && !(data->flag & F_PRECIS))
	{
		ret_flag[ft_strlen(ret_flag) - 1] = '%';
		final = ft_strdup(ret_flag);
	}
	else
		final = ft_strdup("%");
	return (final);
}
