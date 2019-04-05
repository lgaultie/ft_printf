/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:54:57 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/05 16:35:14 by lgaultie         ###   ########.fr       */
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
	if (data->flag & AP_NEG)
		size++;
	return (size);
}

char	*ft_preci_width3(int before, int after, t_data *data)
{
	int		i;
	char	*final;
	int		size;
	char	*ap;
	int		surplus;

	i = 0;
	surplus = 0;
	//ft_putstr("ici dans preci_width3\n");
	size = ft_calculate_size(before, after, data);
	if (!(final = ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (data->flag & F_MINUS)
	{
		if (data->flag & F_S)
		{
			ap = data->tmp_s;
			if (!(final = ft_strsub(ap, 0, after)))
				return (NULL);
			if (before > after)
				data->width_precis_minus = before - after;
			if (after >= before)
				data->width_precis_minus = before - data->conv_sz;
			if (ap[0] == '\0' && before > after)
				data->width_precis_minus = before;
			if (ap[0] == '\0' && before <= after)
				data->width_precis_minus = after;
		}
		else
		{
			if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
			{
				final[i++] = '-';
				while (i < after - data->conv_sz + 1)
					final[i++] = '0';
				final[i] = '\0';
				if (after == 0)
					data->width_precis_minus = 0;
			}
			else
			{
				if (data->flag & F_PLUS)
				{
					surplus = 1;
					final[i++] = '+';
				}
				while (i < after - data->conv_sz + surplus)
					final[i++] = '0';
				final[i] = '\0';
			if (before > after)
				data->width_precis_minus = before - i - data->conv_sz;
			}
		}
		return (final);
	}
	else if (before == after || before < after)
	{
		if (data->flag & AP_NEG)
		{
			final[i++] = '-';
			while (i < after - data->conv_sz + 1)
				final[i++] = '0';
		}
		else if (data->flag & F_PLUS)
		{
			final[i++] = '+';
			while (i < after - data->conv_sz + 1)
				final[i++] = '0';
		}
		else
		{
			while (i < after - data->conv_sz)
				final[i++] = '0';
		}
		final[i] = '\0';
		return (final);
	}
	else if (after < data->conv_sz && before > after)
	{
		if (data->flag & AP_NEG)
		{
			while (i < before - data->conv_sz - 1)
			final[i++] = ' ';
			final[i++] = '-';
		}
		if (!(data->flag & AP_NEG))
		{
			if (data->flag & F_PLUS)
				final[i++] = '+';
			while (i < before - data->conv_sz)
				final[i++] = ' ';
		}
	}
	else if ((after >= data->ap_sz && before > after) || (after == data->conv_sz))
	{
		if (!(data->flag & AP_NEG))
		{
			// printf("before = %d, after = %d, data->ap_sz = %d, data->conv_sz = %d\n", before, after, data->ap_sz, data->conv_sz);
			if (data->flag & F_SHARP)
				surplus = 2;
			else
				surplus = 0;
			while (before > after + surplus)
			{
				final[i++] = ' ';
				before--;
			}
			if (data->flag & F_PLUS)
				final[i - 1] = '+';
			if (data->flag & F_SHARP)
			{
				final[i++] = '0';
				final[i++] = 'x';
			}
			while (after > data->conv_sz)
			{
				final[i++] = '0';
				after--;
			}
		}
		else if (data->flag & AP_NEG)
		{
			while (before > after + 1)
			{
				final[i++] = ' ';
				before--;
			}
			final[i++] = '-';
			while (after > data->conv_sz)
			{
				final[i++] = '0';
				after--;
			}
		}
	}
	final[i] = '\0';
	//printf("final = |%s|\n", final);
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
	//printf("i = %d, j = %d\n", i, j);
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
