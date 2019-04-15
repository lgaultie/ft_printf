/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:19:57 by amamy             #+#    #+#             */
/*   Updated: 2019/04/15 17:29:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_accuracy_size(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (-1);
	while ((flags[i] < '0' || flags[i] > '9') && flags[i] != '\0')
		i++;
	while ((flags[i] >= '0' && flags[i] <= '9') && flags[i] != '\0')
	{
		while (flags[i] == '.' || flags[i] == '*')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
	}
	if (conv[0] == '\0')
		i = 0;
	else
		i = ft_atoi(conv);
	free(conv);
	return (i);
}


char *ft_float_accuracy(t_data *d, char *flag, t_float *ft)
{
	char *final;
	char *tmp;
	int diff;
	int	i;
	int len;

	len = ft_strlen(ft->s_deci_p);
	i = ft_accuracy_size(flag, d);
	diff = i - len;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(ft->s_deci_p, tmp)))
		return (NULL);
	free (tmp);
	return (final);

}

void ft_free(t_float *ft, int j, int m)
{
	if (m == 1)
	{
		free(ft->s_deci_p);
		free(ft->int_p);
	}
	if (m == 2)
	{
		free(ft->int_p);
		free(ft->s_deci_p); // to not do if j == 0
		free(ft->str_deci_ar_cp);
	}
	free(ft->int_p);
	if (j > 0)
	free(ft->s_deci_p);
	if (j > 1)
	free(ft->str_deci_ar_cp);
}

char	*ft_missing_zeros(int len, t_float *ft)
{
	char *final;
	char *tmp;
	int diff;
	int	i;

	diff = 6 - len;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(ft->s_deci_p, tmp)))
		return (NULL);
	free (tmp);
	return (final);
}

char	*ft_ffinal(t_float *ft, t_data *data, char *flag, int j)
{
	char *final;
	char *tmp;
	int	len;

	if (data->f & F_PRECIS)
		ft_conv_f2_2(ft, data, flag, 2);
	len = ft_strlen(ft->s_deci_p);
	if (len < 6 && !(data->f & F_PRECIS))
	{
		tmp = ft->s_deci_p;
		if (!(ft->s_deci_p = ft_missing_zeros(len, ft)))
			return (NULL);
		free (tmp);
	}
	if (!(final = ft_strjoin(ft->int_p, ft->s_deci_p)))
	{
		ft_free(ft, 0, 2);
		return (NULL);
	}
	ft_free(ft, j, 0);
	return (final);
}
