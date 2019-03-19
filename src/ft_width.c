/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/19 11:38:18 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width2(int width, int zero, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (width - data->ap_sz + 1))))
		return (NULL);
	if (width > data->ap_sz)
	{
		if (zero == 1)
		{
			while (i < width - data->ap_sz)
			{
				ret[i] = '0';
				i++;
			}
		}
		if (zero == 0)
		{
			while (i < width - data->ap_sz)
			{
				ret[i] = ' ';		//remplacer par des . pour les tests
				i++;
			}
		}
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_width(char *flags, t_data *data)
{
	int		i;
	int		j;
	int		zero;
	char	*conv;
	int		width;

	i = 0;
	j = 0;
	zero = 0;
	if (!(conv = malloc(sizeof(char) * (data->flag_sz - 1))))
		return (0);
	while (flags[i] == '%')
		i++;
	if (flags[i] == '0')
	{
		data->flag |= F_ZERO;
		zero = 1;				//a refaire avec booleen flag f_zero
	}
	while (flags[i] >= '0' && flags[i] <= '9')
	{
		// if (flag[i] == '*')
		// {
		//
		// }
		conv[j] = flags[i];
		i++;
		j++;
	}
	conv[j] = '\0';
	width = ft_atoi(conv);
	free(conv);
	if (!(conv = ft_width2(width, zero, data)))
		return (NULL);
	return (conv);
}
