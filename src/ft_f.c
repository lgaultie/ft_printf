/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/13 20:32:53 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_free(char * before, char *str_after, char *str_after_copy, int m)
{
	if (m == 1)
	{
		free(str_after);
		free(before);
	}
	if (m == 2)
	{
		free(before);
		free(str_after); // to not do if j == 0
		free(str_after_copy);
	}
}

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
static char	*ft_final(char *before, char *str_after, char *str_ar_cp, int j)
{
	char *final;

	if (!(final = ft_strjoin(before, str_after)))
	{
		ft_free(before, str_after, str_ar_cp, 2);
		return (NULL);
	}
	free(before);
	if (j > 0)
		free(str_after);
	if (j > 1)
		free(str_ar_cp);
	return (final);
}

char	*ft_conv_f2(long double ap, char *before, int j)
{
	long double		ret;
	long long		after;
	char			*str_after;
	char			*str_ar_cp;

	ret = ap - (int)ap;
	after = ret;
	while ((ap - (int)ap) != 0.0 && (ap - (int)ap) > 0.0 && j < 6)
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
		ret = (ret - (int)ret);
		if (j++ != 0)
			str_after = ft_conv_f2_3(before, str_after, str_ar_cp);
		ap = ret;
	}
	return (ft_final(before, str_after, str_ar_cp, j));
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
