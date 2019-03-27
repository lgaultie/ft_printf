/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:54:57 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/27 19:37:03 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calculate_size(int before, int after, t_data *data)
{
	int		size;

	if (before > after)
		size = before;
	if (after >= before)
		size = after;
	if (size > data->ap_sz)
		size = size - data->ap_sz;
	if (size < data->ap_sz)
		size = data->ap_sz;
	return (size);
}

char	*ft_preci_width3(int before, int after, t_data *data)
{
	int		i;
	char	*final;
	int		minus;
	int		size;

	i = 0;
	minus = 0;
	if (data->flag & F_MINUS)
		minus = 1;
	size = ft_calculate_size(before, after, data);
	if (!(final = ft_memalloc(sizeof(char) * size)))
		return (NULL);
	if (before == after || before < after)
	{
		if (data->flag & F_PLUS)
		{
			final[i++] = '+';
			while (i < after - data->ap_sz + 1)
				final[i++] = '0';
		}
		else
		{
			while (i < after - data->ap_sz)
				final[i++] = '0';
		}
		return (final);
	}
	if (after < data->ap_sz && before > after)
	{
		if (data->flag & F_PLUS)
			final[i++] = '+';
		while (i < before - data->ap_sz)
			final[i++] = ' ';
	}
	if ((after > data->ap_sz && before > after) || (after == data->ap_sz))
	{
		if (minus == 0)
		{
			while (before > after)
			{
				final[i++] = ' ';
				before--;
			}
		}
		if (data->flag & F_PLUS)
			final[i - 1] = '+';
		while (after > data->ap_sz)
		{
			final[i++] = '0';
			after--;
		}
	}
	final[i] = '\0';
	return (final);
}

/*
** ft_preci_width2: analyse what is before the '.' and what is after. Converts
** them in 2 int to send to preci_width3 which will apply the flag effect.
*/

char	*ft_preci_width2(char *flag, t_data *data, int i, int j)
{
	char	*final;
	char	*before;
	char	*after;

	if (!(before = malloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	if (!(after = malloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	while (flag[i] < '0' || flag[i] > '9')
		i++;
	while (flag[i] != '.')
		before[j++] = flag[i++];
	before[j] = '\0';
	j = 0;
	i++;
	while (flag[i + 1] != '\0')
		after[j++] = flag[i++];
	after[j] = '\0';
	i = ft_atoi(before);
	j = ft_atoi(after);
	free(before);
	free(after);
	if (!(final = ft_preci_width3(i, j, data)))
		return (NULL);
	return (final);
}

/*
** ft_preci_width: will return the converted flag.
*/

char	*ft_preci_width(char *flag, t_data *data)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	if (!(final = ft_preci_width2(flag, data, i, j)))
		return (NULL);
	return (final);
}
