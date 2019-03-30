/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:22:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/30 23:37:48 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_active_flag: Analyses between % and the conversion, enable needed flags.
** F_W_P: active flag width + accuracy (ex: %5.2d)
** F_STAR: case of %.*d for example.
** SHOULD ALSO DISABLED IGNORED FLAGS QUAND YEN A DES INCOMPATIBLES............
*/

void ft_active_cast(char *flag, t_data *data, int i)
{
	int	len;

	len = ft_strlen(&flag[i]);
	if (flag[i] == 'h' && len == 2)
		data->flag |= F_H;
	if (flag[i] == 'h' && flag[i + 1] == 'h' && len == 3)
		data->flag |= F_HH;
	if (flag[i] == 'l' && len == 2)
		data->flag |= F_L;
	if (flag[i] == 'l' && flag[i + 1] == 'l' && len == 3)
		data->flag |= F_LL;
}

void	ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
		data->flag |= F_SPACE;
	else if (flag[i] == '#')
		data->flag |= F_SHARP;
	else if (flag[i] == '+')
	{
		data->flag |= F_PLUS;
		if (data->flag & F_MINUS)
			data->flag &= ~F_MINUS;
	}
	else if (flag[i] == '-')
	{
		ft_putstr("flag minus activé\n");
		printf("flag[i] = %c\n", flag[i]);
		data->flag |= F_MINUS;
	}
	else if (flag[i] == 'h' || flag[i] == 'l')
		ft_active_cast(flag, data, i);
}

int		ft_active_flag(char *flag, t_data *data)
{
	int		i;

	i = 0;
	while (flag[i] != 'd' && flag[i] != 'c' && flag[i] != 's' \
		&& flag[i] != 'p' && flag[i] != 'x' && flag[i] != 'o' \
		&& flag[i] != 'x' && flag[i] != 'X' && flag[i] != '%' \
		&& flag[i] != 'i' && flag[i] != 'f' && flag[i] != '\0')
	{
		if (flag[0] == '0')
			data->flag |= F_ZERO;
		else if (flag[i] == '.' && (data->flag & F_WIDTH))
			data->flag |= F_W_P;
		else if (((flag[i] >= '0' && flag[i] <= '9') || flag[i] == '*')
			&& !(data->flag & F_PRECIS))
		{
			data->flag |= F_WIDTH;
			if (flag[i] == '*')
				data->flag |= F_STAR;
		}
		else if (flag[i] == '.' && ((flag[i + 1] >= '0' && flag[i + 1] <= '9')
			|| flag[i + 1] == '*'))
		{
			data->flag |= F_PRECIS;
			if (flag[i + 1] == '*')
				data->flag |= F_STAR;
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
	if (flag[i] != '%')
	{
		if (!(ret_conv = ft_only_conv(&flag[i], data)))
			return (NULL);
	}
	if ((data->flag & F_MINUS) && (data->flag & F_WIDTH) \
	&& !(data->flag & F_PRECIS) && !(data->flag & F_W_P) \
	&& !(data->flag & F_PLUS))
	{
		if (data->flag & AP_NEG)
		{
			if (!(ret_conv = ft_strjoin("-", ret_conv)))
				return (NULL);
		}
		if (!(ret_flag2 = ft_width_minus(flag, data)))
			return (NULL);
		if (!(final = ft_strjoin(ret_conv, ret_flag2)))
			return (NULL);
		return (final);
	}
	if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
		return (NULL);
	if ((data->flag & F_PRECIS) && flag[i] == 's')
		return (ret_flag);
	if (flag[i] == '%')
	{
		if (!(final = ft_percent_percent(ret_flag, data)))
			return (NULL);
		free(ret_flag);
		return (final);
	}
	if (!(final = ft_strjoin(ret_flag, ret_conv)))
		return (NULL);
	if (data->flag & F_W_P && data->flag & F_MINUS)
	{
		i = 0;
		if (!(ret = malloc(sizeof(char) * (data->width_precis_minus + 1))))
			return (NULL);
		while (i < data->width_precis_minus - 1)
			ret[i++] = ' ';
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
