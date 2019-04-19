/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:47:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/19 21:41:41 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ret_flag_sharp(char *ret_flag, char *f, int i)
{
	if (ft_strlen(ret_flag) < 2)
	{
		return (ret_flag);
	}
	ret_flag[0] = '0';
	ret_flag[1] = f[i];
	return (ret_flag);
}

static char		*ft_sharp(int i, char *f, char *ret_flag, t_data *data)
{
	char	*tmp;

	tmp = ret_flag;
	if (f[i] == 'X' && !(data->f & F_X_0))
		if (!(ret_flag = ft_strjoin("0X", tmp)))
			return (NULL);
	if (f[i] == 'x' && !(data->f & F_X_0))
		if (!(ret_flag = ft_strjoin("0x", tmp)))
			return (NULL);
	if (data->f & F_X_0)
		return (ret_flag);
	free(tmp);
	return (ret_flag);
}

char			*ft_special_cases(int i, char *f, t_data *d)
{
	char	*ret_flag;

	if (!(ret_flag = ft_which_flag(f, f[i], d)))
		return (NULL);
	if (d->f & F_SHARP && d->f & F_ZERO && !(d->f & F_PRECIS) \
	&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_ret_flag_sharp(ret_flag, f, i);
	else if (d->f & F_SHARP && d->f & F_ZERO && d->f & F_PRECIS \
	&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_sharp(i, f, ret_flag, d);
	else if (d->f & F_SHARP && d->f & F_PRECIS \
	&& !(d->f & F_W_P) && (f[i] == 'x' || f[i] == 'X'))
		ret_flag = ft_sharp(i, f, ret_flag, d);
	return (ret_flag);
}

char			*ft_fwp_minus(char *final, t_data *data)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(sizeof(char) * (data->width_precis_minus + 1))))
		return (NULL);
	while (i < data->width_precis_minus)
		ret[i++] = ' ';
	tmp = final;
	if (!(final = ft_strjoin(tmp, ret)))
		return (NULL);
	free(ret);
	free(tmp);
	return (final);
}

char			*ft_for_minus(char *ret_conv, char *f, int i, t_data *d)
{
	char	*ret_flag2;
	char	*final;
	int		plus;

	plus = 0;
	if (d->f & AP_NEG && !(d->f & F_UNSIGNED) && (f[i] != 's' || f[i] != 'c'))
	{
		final = ret_conv;
		if (!(ret_conv = ft_strjoin("-", final)))
			return (NULL);
		free(final);
		plus = 1;
	}
	if (!(ret_flag2 = ft_width_minus(f, d)))
		return (NULL);
	if (d->f & F_PLUS && d->f & F_PLUS && plus != 1)
	{
		final = ret_conv;
		if (!(ret_conv = ft_strjoin("+", final)))
			return (NULL);
		free(final);
	}
	if (!(final = ft_strjoin(ret_conv, ret_flag2)))
		return (NULL);
	free(ret_conv);
	free(ret_flag2);
	return (final);
}
