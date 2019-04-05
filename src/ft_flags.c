/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:22:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/05 16:35:23 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_active_flag: Analyses between % and the conversion, enable needed flags.
** F_W_P: active flag width + accuracy (ex: %5.2d)
** SHOULD ALSO DISABLED IGNORED FLAGS QUAND YEN A DES INCOMPATIBLES............
*/

void ft_active_cast(char *flag, t_data *data, int i)
{
	int	len;

	len = ft_strlen(&flag[i]);

	if (flag[i] == 'h' && flag[i + 1] == 'h' && len == 3 && (!(data->flag & F_H)))
		data->flag |= F_HH;
	else if (flag[i] == 'h' && len == 2 && (!(data->flag & F_HH)))
		data->flag |= F_H;
	else if (flag[i] == 'l' && len == 2 && (!(data->flag & F_LL)))
		data->flag |= F_L;
	else if (flag[i] == 'l' && flag[i + 1] == 'l' && len == 3 && (!(data->flag & F_L)))
		data->flag |= F_LL;
}

void	ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
	{
		data->flag |= F_SPACE;
	}
	else if (flag[i] == '#')
		data->flag |= F_SHARP;
	else if (flag[i] == '+')
	{
		data->flag |= F_PLUS;
		//if (data->flag & F_MINUS)
			//data->flag &= ~F_MINUS;
	}
	else if (flag[i] == '-')
		data->flag |= F_MINUS;
	else if (flag[i] == '%')
		data->flag |= F_PERCENT;
	// else if ((flag[i - 1] < '0' || flag[i - 1] > '9') \
	// && flag[i - 1] != '.'&& flag[i - 1] != '#'  && flag[i] == '0' && i > 0)
	// 	data->flag |= F_ZERO;
	else if (flag[i] == 'h' || flag[i] == 'l')
		ft_active_cast(flag, data, i);
}

int		ft_active_flag(char *flag, t_data *data)
{
	int		i;

	i = 0;
	while (flag[i] != 'd' && flag[i] != 'c' && flag[i] != 's' \
		&& flag[i] != 'p' && flag[i] != 'x' && flag[i] != 'o' \
		&& flag[i] != 'x' && flag[i] != 'X' \
		&& flag[i] != 'i' && flag[i] != 'f' && flag[i] != 'u' \
		&& flag[i] != '\0')
	{
		//printf("flag[i] = |%c|  i = %d\n", flag[i], i);
		if (flag[i] == '0' && (flag[i - 1] < '0' || flag[i - 1] > '9'))
			data->flag |= F_ZERO;
		if (flag[i] == '.' && (data->flag & F_WIDTH))
			data->flag |= F_W_P;
		else if (((flag[i] >= '0' && flag[i] <= '9') || flag[i] == '*')
			&& !(data->flag & F_PRECIS))
		{
			data->flag |= F_WIDTH;
		}
		else if (flag[i] == '.' && ((flag[i + 1] >= '0' && flag[i + 1] <= '9')
			|| flag[i + 1] == '*'))
		{
			data->flag |= F_PRECIS;
		}
		else
			ft_active_flag2(flag, data, i);
		i++;
	}
	return (i);
}

/*
** ft_percent_percent: s'occupe des cas %7%, %.5%, ou % %, etc...
*/

char	*ft_percent_percent(char *ret_flag, t_data *data)
{
	char	*final;

	if (data->flag & F_WIDTH && !(data->flag & F_PRECIS))
	{
		ret_flag[ft_strlen(ret_flag) - 1] = '%';
		final = ft_strdup(ret_flag);
	}
	else
		final = ft_strdup("%");
	return (final);
}



/*
** ft_flag_conv: join the converted conversion with converted flags.
** should call functions to treat particular cases.............................
*/

char	*ft_flag_conv(char *flag, t_data *data)
{
	char	*final;
	char	*ret_conv;
	char	*ret_flag;
	char	*ret_flag2;
	char	*ret;
	char	*tmp;
	int		i;

	i = ft_active_flag(flag, data);
	if (flag[i] != '%' && !(data->flag & F_PERCENT))
	{
		if (!(ret_conv = ft_only_conv(&flag[i], data)))
			return (NULL);
		//printf("dans ft_flags.c ret_only_conversion = |%s|\n", ret_conv);
	}
	if ((data->flag & F_MINUS) && (data->flag & F_WIDTH) \
	&& !(data->flag & F_PRECIS) && !(data->flag & F_W_P) \
	&& !(data->flag & F_PLUS))
	{
		if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED) \
		&& (flag[i] != 's' || flag[i] != 'c'))
		{
			if (!(ret_conv = ft_strjoin("-", ret_conv)))
				return (NULL);
		}
		if (!(ret_flag2 = ft_width_minus(flag, data)))
			return (NULL);
		if (!(final = ft_strjoin(ret_conv, ret_flag2)))
			return (NULL);
		free(ret_conv);
		free(ret_flag2);
		return (final);
	}
	if (data->flag & F_PERCENT)
	{
		data->conv_sz = 1;
		if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
			return (NULL);
		if (!(final = ft_strjoin(ret_flag, "%")))
			return (NULL);
		free(ret_flag);
		return (final);
	}
	if (data->flag & F_SPACE && data->flag & AP_NEG)
		return (ret_conv);
		// if (data->flag & F_WIDTH)
		// ft_putstr("F_WIDTH ACTIF\n");
	if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
		return (NULL);
	// printf("ret_flag = |%s|\n", ret_flag);
	// // //
	// if (data->flag & F_ZERO)
	// 	ft_putstr("F_ZERO ACTIF\n");
	// if (data->flag & F_W_P)
	// 	ft_putstr("F_W_P ACTIF\n");
	// if (data->flag & AP_NEG)
	// 	ft_putstr("AP_NEG ACTIF\n");
	// if (data->flag & F_PLUS)
	// 	ft_putstr("F_PLUS ACTIF\n");
	// if (data->flag & F_SHARP)
	// 	ft_putstr("F_SHARP ACTIF\n");
	// if (data->flag & F_PRECIS)
	// 	ft_putstr("F_PRECIS ACTIF\n");
	if (data->flag & F_SHARP && data->flag & F_ZERO \
	&& !(data->flag & F_PRECIS) && !(data->flag & F_W_P) && (flag[i] == 'x' \
	|| flag[i] == 'X'))
	{
		if (flag[i] == 'X')
		{
			ret_flag[0] = '0';
			ret_flag[1] = 'X';
		}
		if (flag[i] == 'x')
		{
			ret_flag[0] = '0';
			ret_flag[1] = 'x';
		}
	}
	if (data->flag & F_SHARP && data->flag & F_ZERO && data->flag & F_PRECIS \
	&& !(data->flag & F_W_P) && (flag[i] == 'x' \
	|| flag[i] == 'X'))
	{
		if (flag[i] == 'X')
		{
			tmp = ret_flag;
			if (!(ret_flag = ft_strjoin("0X", tmp)))
				return (NULL);
			free(tmp);
		}
		if (flag[i] == 'x')
		{
			tmp = ret_flag;
			if (!(ret_flag = ft_strjoin("0x", tmp)))
				return (NULL);
			free(tmp);
		}
	}
	//printf("dans ft_flags.c ret_flag = |%s|\n", ret_flag);
	if ((data->flag & F_PRECIS) && (flag[i] == 's' || flag[i] == 'c'))
		return (ret_flag);
	if (flag[i] == '%')
	{
		if (!(final = ft_percent_percent(ret_flag, data)))
			return (NULL);
		free(ret_flag);
		return (final);
	}
	////////////// ici wtf
	if (flag[i] == 's' && (data->flag & F_MINUS) && (data->flag & F_W_P))
		final = ft_strdup(ret_flag);
	else
	{
		if (!(final = ft_strjoin(ret_flag, ret_conv)))
			return (NULL);
	}
	if (data->flag & F_W_P && data->flag & F_MINUS)
	{
		i = 0;
		//ft_putstr("ft_flags.c rentre dans F_W_P et MINUS\n");
		if (!(ret = malloc(sizeof(char) * (data->width_precis_minus + 1))))
			return (NULL);
		if (!(data->flag & F_PLUS))
		{
			while (i < data->width_precis_minus)
				ret[i++] = ' ';
		}
		else
		{
			while (i < data->width_precis_minus)
				ret[i++] = ' ';
		}
		ret[i] = '\0';
		tmp = final;
		if (!(final = ft_strjoin(tmp, ret)))
			return (NULL);
		free(ret);
		free(tmp);
	}
	free(ret_conv);
	free(ret_flag);
	return (final);
}
