/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 14:38:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width2(int width, t_data *data)
{
	int		i;
	char	*ret;
	int		surplus;

	i = 0;
	surplus = 0;
	if (width > data->conv_sz)
	{
		if (!(ret = ft_memalloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		if (data->flag & F_ZERO)
		{
			if (data->flag & AP_NEG)
			{
				ret[i++] = '-';
				while (i < width - data->ap_sz - 1)
				{
					ret[i] = '0';
					i++;
				}
			}
			else
			{
				while (i < width - data->ap_sz - 1)
				{
					ret[i] = '0';
					i++;
				}
			}
		}
		if (!(data->flag & F_ZERO))
		{
			if (data->flag & AP_NEG)
			{
				while (i < width - data->ap_sz - 1)
				{
					ret[i] = ' ';		//remplacer par des . pour les tests
					i++;
				}
				ret[i++] = '-';
				ret[i] = '\0';
			}
			else
			{
				if (data->flag & F_SHARP)
					surplus = 2;
				while (i < width - data->ap_sz - surplus)
				{
					ret[i] = ' ';		//remplacer par des . pour les tests
					i++;
				}
				ret[i] = '\0';
			}
		}
	}
	if (width <= data->ap_sz)
	{
		if (data->flag & AP_NEG && !(data->flag & UNSIGNED))
			return (ft_strdup("-"));
		else if (data->flag & F_PLUS)
			return (ft_strdup("+"));
		ret = ft_strdup("");
	}
	return (ret);
}

char	*ft_width(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[0] == '0')
		data->flag |= F_ZERO;
	if (flags[0] == '*' && (i = data->tmp))
		data->flag &= ~F_WIDTH & ~F_STAR;
	else
	{
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] != '\0')
		{
			if (flags[i] == '#')
				i++;
			if ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == '+' \
			|| flags[i] == '-')
				conv[j] = flags[i];
			i++;
			j++;
		}
		conv[i] = '\0';
		i = ft_atoi(conv);
		free(conv);
		data->flag &= ~F_WIDTH;
	}
	if (!(conv = ft_width2(i, data)))
		return (NULL);
	return (conv);
}

char	*ft_width_minus2(int width, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (width - data->ap_sz + 1))))
		return (NULL);
	if (width > data->ap_sz)
	{
		if (data->flag & F_ZERO)
			while (i < width - data->ap_sz)
			{
				ret[i] = '0';
				i++;
			}
		if (!(data->flag & F_ZERO))
		{
			if (data->flag & AP_NEG)
			{
				while (i < width - data->ap_sz - 1)
				{
					ret[i] = ' ';		//remplacer par des . pour les tests
					i++;
				}
			}
			else
			{
				while (i < width - data->ap_sz)
				{
					ret[i] = ' ';		//remplacer par des . pour les tests
					i++;
				}
			}
		}
	}
	if (data->flag & F_PLUS)
		ret[i++] = '+';
	ret[i] = '\0';
	return (ret);
}

char	*ft_width_minus(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[0] == '0')
		data->flag |= F_ZERO;
	if (flags[0] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_WIDTH & ~F_STAR;
	}
	else
	{
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
		i = ft_atoi(conv);
		free(conv);
	}
	if (!(conv = ft_width_minus2(i, data)))
		return (NULL);
	return (conv);
}
