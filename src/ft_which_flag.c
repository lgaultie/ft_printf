/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:23:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/30 18:35:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_which_flag: Call appropriates flag function depending of enabled flags.
** Will return the converted flag.
*/

char	*ft_which_flag3(char *flag, char cv, t_data *data)
{
	char	*final;

	(void)cv;
	if (data->flag & F_MINUS && !(data->flag & F_W_P))
	{
		if (!(final = ft_minus(flag, data)))
			return (NULL);
	}
	else
		final = NULL;
	return (final);
}

char	*ft_which_flag2(char *flag, char cv, t_data *data)
{
	char	*final;

	if (data->flag & F_WIDTH && !(data->flag & F_PRECIS) \
	&& !(data->flag & F_W_P))
	{
		if (!(final = ft_width(flag, data)))
			return (NULL);
	}
	else if (data->flag & F_PLUS)
	{
		if (!(final = ft_plus(flag, data)))
			return (NULL);
	}
	else if (data->flag & F_SPACE)
	{
		if (!(final = ft_strnew(1)))
			return (NULL);
		if (data->flag & F_MINUS)
			(void)data;
		else
			final[0] = ' ';
	}
	else
		final = ft_which_flag3(flag, cv, data);
	return (final);
}

char	*ft_which_flag(char *flag, char cv, t_data *data)
{
	char	*final;

	if (data->flag & F_SHARP)
	{
		if (!(final = ft_strnew(0)))
			return (NULL);
	}
	else if ((data->flag & F_PRECIS || data->flag & F_WIDTH) && cv == 's')
	{
		if (!(final = ft_string(flag, data, 1)))
			return (NULL);
	}
	else if (((data->flag & F_PRECIS) && (cv == 'd' || cv == 'i')))
	{
		if (!(final = ft_precision_d(flag, data)))
			return (NULL);
	}
	else if (((data->flag & F_W_P) && (cv == 'd' || cv == 'i' || cv == 'u')))
	{
		if (!(final = ft_preci_width(flag, data)))
			return (NULL);
	}
	else
		final = ft_which_flag2(flag, cv, data);
	return (final);
}
