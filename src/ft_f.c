/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/15 21:54:14 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_f2_2(t_float *ft, t_data *d, char *flag, int mode)
{
	char *tmp;

	if (mode == 1)
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_strjoin(tmp, ft->str_deci_ar_cp)))
		{
			ft_free(ft, 0, 2);
				return (NULL);
		}
		free(tmp);
		return (ft->s_deci_p);
	}
	if (mode == 2)
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_float_accuracy(d, flag, ft)))
			return (NULL);
		free(tmp);
		return (NULL);

	}
	return (NULL);
}

// char	*ft_conv_f2_2(char *before, char *s_a, long long after, char *str_ar_cp)
// char	*ft_conv_f2_2(t_float *ft)
// {
// }
char	*ft_conv_f2_1(t_float *ft, int mode)
{
	if (mode == 1)
	{
		if (!(ft->s_deci_p = ft_itoa(ft->deci_p)))
		{
			free(ft->int_p);
			return (NULL);
		}
	return (ft->s_deci_p);
	}
	if (mode == 2)
	{
		if (!(ft->str_deci_ar_cp = ft_itoa(ft->deci_p)))		//leaks
		{
			ft_free(ft, 0, 1);
			return (NULL);
		}
		return (ft->str_deci_ar_cp);
	}
	return (NULL);
}

char	*ft_conv_f2(t_float *ft, t_data *d, char *flag)
{
	long double		ret;
	int				j;
	int 			max;

	if (d->f & F_PRECIS || d->f & F_W_P)
		max = ft_accuracy_size(flag, d);
	else
		max = 6;
	j = 0;
	ret = ft->ap - (long long)ft->ap;
	ft->deci_p = ret;
	while ((ft->ap - (long long)ft->ap) > 0.0 && j < max)
	{
		ret = ret * 10;
		ft->deci_p = ret;
		if (j == 0)
			ft->s_deci_p = ft_conv_f2_1(ft, 1);
		else
		{
			if (j > 1)
				free(ft->str_deci_ar_cp);
			ft->str_deci_ar_cp = ft_conv_f2_1(ft, 2);
		}
		ft->deci_p = 0;
		ret = (ret - (long long)ret);
		if (j++ != 0)
			ft->s_deci_p = ft_conv_f2_2(ft, d, flag, 1);
		ft->ap = ret;
	}
	return (ft_ffinal(ft, d, flag, j));
}

char	*ft_conv_f(t_data *d, char *flag)
{
	t_float	*ft;
	char 	*final;

	if (((d->f & F_PRECIS || d->f & F_W_P) && (ft_strlen(flag) == 1)))
		return (ft_strdup(""));
	if (((d->f & F_BIG_L && !(d->f & F_PRECIS)) && (ft_strlen(flag) != 1)))
		return (ft_strdup(""));
	if (!(ft = ft_memalloc(sizeof(t_float))))
		return (NULL);
	if (d->f & F_BIG_L)
		ft->ap = (va_arg(d->ap, long double));
	else
		ft->ap = (va_arg(d->ap, double));
	if (!(ft->int_p = ft_itoa(ft->ap)))
		return (NULL);
	final = ft->int_p;
	if (!(ft->int_p = ft_strjoin(final, ".")))
		return (NULL);
	free(final);
	if (ft->ap < 0)
		ft->ap = -ft->ap;
	if (!(final = ft_conv_f2(ft, d, flag)))
		return (NULL);
	free(ft);
	return (final);
}
