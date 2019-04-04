/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:17:02 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/04 15:57:47 by lgaultie         ###   ########.fr       */
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
			if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
			{
				ret[i++] = '-';
				while (i < width - data->conv_sz)
				{
					ret[i] = '0';
					i++;
				}
			}
			else
			{
				while (i < width - data->conv_sz)
				{
					ret[i] = '0';
					i++;
				}
			}
		}
		if (!(data->flag & F_ZERO))
		{
			if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
			{
				while (i < width - data->conv_sz - 1)
				{
					ret[i] = ' ';
					i++;
				}
				ret[i++] = '-';
				ret[i] = '\0';
			}
			else
			{
				if (data->flag & F_PLUS)
					surplus = 1;
				while (i < width - data->conv_sz - surplus)
				{
					ret[i] = ' ';
					i++;
				}
				if (data->flag & F_PLUS)
				ret[i++] = '+';
				ret[i] = '\0';
			}
		}
	}
	if (width <= data->conv_sz)
	{
		if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED))
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
	if (width > data->conv_sz)
	{
		if (!(ret = malloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		if (data->flag & F_ZERO)
			while (i < width - data->conv_sz)
			{
				ret[i] = '0';
				i++;
			}
		if (!(data->flag & F_ZERO))
		{
			if (data->flag & AP_NEG)
			{
				while (i < width - data->conv_sz - 1)
				{
					ret[i] = ' ';
					i++;
				}
			}
			else
			{
				while (i < width - data->conv_sz)
				{
					ret[i] = ' ';
					i++;
				}
			}
		}
	}
	else
		return (ft_strdup(""));
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
		while (flags[i] == '+' || flags[i] < '0' || flags[i] > '9' \
		|| flags[i] == '-')
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

char	*ft_width_s2(int width, t_data *data)
{
	char	*ret;
	int		i;

	i = 0;
	if (width < data->ap_sz)
		return (ft_strdup(""));
	else
	{
		if (!(ret = ft_memalloc(sizeof(char) * (width - data->ap_sz + 1))))
			return (NULL);
		while (i < width - data->ap_sz)
		{
			ret[i] = ' ';
			i++;
		}
	}
	ret[i++] = '\0';
	return (ret);
}

char	*ft_width_s(char *flags, t_data *data)
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
	if (!(conv = ft_width_s2(i, data)))
		return (NULL);
	return (conv);
}
