/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:54:57 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/19 16:18:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_calculate_size: calculates the needed size for final's malloc.
*/

static int		ft_calculate_size(int before, int after, t_data *data)
{
	int		size;

	if (before > after)
		size = before;
	if (after >= before)
		size = after;
	if (size < data->ap_sz)
		size = data->ap_sz;
	if (data->f & AP_NEG || data->f & F_PLUS)
		size++;
	if (after == 0)
		size++;
	return (size);
}

static char		*ft_case1(char *final, int i, int after, t_data *data)
{

	if (data->f & AP_NEG)
	{
		final[i++] = '-';
		while (i < after - data->conv_sz + 1)
			final[i++] = '0';
	}
	else if (data->f & F_PLUS)
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
	return (final);
}

/*
** ft_preci_width3: calls the appropriate function depending on which
** cases we are: when the flag minus is on, when width > accuracy, etc...
*/

static char		*ft_preci_width3(int before, int after, t_data *data)
{
	int		i;
	char	*final;
	int		size;

	i = 0;
	size = ft_calculate_size(before, after, data);
	if (!(final = ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (data->f & F_MINUS)
		final = ft_flag_minus(before, after, final, data);
	else if (before == after || before < after)
	{
		if (data->f & F_S)
			return (ft_s(final, before, after, data));
		// ft_putstr("case 1\n");
		final = ft_case1(final, i, after, data);
	}
	else if (after < data->conv_sz && before > after && !(data->f & F_SHARP))
	{
		// ft_putstr("case 2\n");
		final = ft_case2(final, before, after, data);
	}
	else if ((after >= data->ap_sz && before > after) \
	|| (after == data->conv_sz) || data->f & F_SHARP)
	{
		// ft_putstr("case 3\n");
		final = ft_case3(final, before, after, data);
	}
	return (final);
}

/*
** ft_preci_width2: analyse what is before the '.' and what is after. Converts
** them in 2 int to send to preci_width3 which will apply the flag effect.
*/

static char		*ft_preci_width2(char *flag, t_data *data, int i, int j)
{
	char	*final;
	char	*before;
	char	*after;

	if (!(before = ft_memalloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	if (!(after = ft_memalloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	while (flag[i] < '0' || flag[i] > '9')
		i++;
	while (flag[i] != '.' && flag[i] != '\0')
		before[j++] = flag[i++];
	before[j] = '\0';
	j = 0;
	i++;
	while (flag[i + 1] != '\0')
		after[j++] = flag[i++];
	if (ft_strlen(flag) > 2 && j == 0)
		after[j++] = '0';
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

char			*ft_preci_width(char *flag, t_data *data)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	if (!(final = ft_preci_width2(flag, data, i, j)))
		return (NULL);
	// printf("final = |%s|\n", final);
	return (final);
}
