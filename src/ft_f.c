/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/13 23:11:45 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_f2_3(char *before, char *str_after, char *str_ar_cp)
{
	char *tmp;

	tmp = str_after;
	if (!(str_after = ft_strjoin(tmp, str_ar_cp)))
	{
		ft_free(before, str_after, str_ar_cp, 2);
		return (NULL);
	}
	free(tmp);
	return (str_after);
}

char	*ft_conv_f2_2(char *before, char *s_a, long long after, char *str_ar_cp)
{

	if (!(str_ar_cp = ft_itoa(after)))		//leaks
	{
		ft_free(before, s_a, str_ar_cp, 1);
		return (NULL);
	}
	return (str_ar_cp);
}
char	*ft_conv_f2_1(char *before, char *str_after, long long after)
{
		if (!(str_after = ft_itoa(after)))
		{
			free(before);
			return (NULL);
		}
	return (str_after);
}

char	*ft_conv_f2(long double ap, char *before, int j)
{
	long double		ret;
	long long		after;
	char			*str_after;
	char			*str_ar_cp;

	ret = ap - (long long)ap;
	after = ret;
	while ((ap - (long long)ap) != 0.0 && (ap - (long long)ap) > 0.0 && j < 6)
	{
		ret = ret * 10;
		after = ret;
		if (j == 0)
			str_after = ft_conv_f2_1(before, str_after, after);
		else
		{
			if (j > 1)
				free(str_ar_cp);
			str_ar_cp = ft_conv_f2_2(before, str_after, after, str_ar_cp);
		}
		after = 0;
		ret = (ret - (long long)ret);
		if (j++ != 0)
			str_after = ft_conv_f2_3(before, str_after, str_ar_cp);
		ap = ret;
	}
	return (ft_ffinal(before, str_after, str_ar_cp, j));
}

char	*ft_conv_f(t_data *data)
{
	long double	ap;
	char	*before;
	char 	*final;
	int		j;

	j = 0;
	if (!(data->f & ONLY_CONV))
		return (ft_strdup(""));
	if (data->f & F_BIG_L)
		ap = (va_arg(data->ap, long double));
	else
		ap = (va_arg(data->ap, double));
	if (!(before = ft_itoa(ap)))
		return (NULL);
	final = before;
	if (!(before = ft_strjoin(final, ".")))
		return (NULL);
	free(final);
	if (ap < 0)
		ap = -ap;
	if (!(final = ft_conv_f2(ap, before, j)))
		return (NULL);
	data->ap_sz = ft_strlen(final);
	data->conv_sz = ft_strlen(final);
	return (final);
}
