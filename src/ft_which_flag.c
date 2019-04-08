/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:23:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 21:38:52 by lgaultie         ###   ########.fr       */
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
	if (data->f & F_MINUS && !(data->f & F_W_P))
	{
		if (!(final = ft_minus(flag, data)))
			return (NULL);
	}
	if (data->f & F_H || data->f & F_HH || data->f & F_L
		|| data->f & F_LL)
		return (ft_strdup(""));
	else
		final = NULL;
	return (final);
}

char	*ft_which_flag2(char *flag, char cv, t_data *data)
{
	char	*final;

	if (data->f & F_ZERO || (data->f & F_WIDTH && !(data->f & F_PRECIS) \
	&& !(data->f & F_W_P)))
	{
		if (!(final = ft_width(flag, data)))
			return (NULL);
	}
	// if (data->f & AP_NEG)
	// 	ft_putstr("ap neg activé");
	else if (data->f & F_PLUS)
	{
		if (!(final = ft_plus(flag, data)))
			return (NULL);
	//	printf("final de retour dans wich flag = |%s|\n", final);
	}
	// else if (data->f & F_SPACE && data->f & AP_NEG)
	// {
	// 	if (!(final = ft_strnew(0)))
	// 		return (NULL);
	// }
	else if (data->f & F_SPACE)
	{
		if (!(final = ft_strnew(1)))
			return (NULL);
		if (data->f & F_MINUS)
			(void)data;
		else if (!(data->f & F_PERCENT))
			final[0] = ' ';
	}
	else
		final = ft_which_flag3(flag, cv, data);
	return (final);
}

char	*ft_which_flag(char *flag, char cv, t_data *data)
{
	char	*final;
	//printf("flag = |%s|    ft_strlen(flag) = %zu\n", flag, ft_strlen(flag));
	if (ft_strlen(flag) == 2 && data->f & F_PRECIS)
		return (ft_strdup(""));
	if (data->f & F_SHARP || ((data->f & F_PERCENT) \
	&& ((data->f & F_WIDTH) || data->f & F_PRECIS)))
	{
		if (data->f & F_W_P && !(data->f & F_PERCENT))
		{
			if (!(final = ft_preci_width(flag, data)))
				return (NULL);
		}
		else if (data->f & F_WIDTH)
		{
			if (!(final = ft_width(flag, data)))
				return (NULL);
			//printf("final dans which flag = |%s|\n", final);
		}
		else if (data->f & F_PRECIS && !(data->f & F_PERCENT))
		{
			if (!(final = ft_precision_d(flag, data)))
				return (NULL);
		}
		else
		{
			if (!(final = ft_strnew(0)))
				return (NULL);
		}
	}
	else if ((data->f & F_PRECIS || data->f & F_WIDTH) && cv == 's' \
	&& !(data->f & F_W_P))
	{
		if (!(final = ft_string(flag, data, 1)))
			return (NULL);
	}
	else if (data->f & F_PRECIS)
	{
		//ft_putstr("bien ici\n");
		if (!(final = ft_precision_d(flag, data)))
			return (NULL);
	}
	else if (data->f & F_W_P) //&& (cv == 'd' || cv == 'i' || cv == 'u' \
	//|| cv == 'o' || cv == 'x' || cv == 'X' || cv == 's')))
	{
		if (cv == 's')
			data->f |= F_S;
		if (!(final = ft_preci_width(flag, data)))
			return (NULL);
	}
	else
		final = ft_which_flag2(flag, cv, data);
	return (final);
}
