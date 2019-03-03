/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/03 19:14:46 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** ft_analyse_flags
** Analyze flags.
*/
void	ft_analyse_conv(char *flags, t_data *data)
{
	int		len;

	len = ft_strlen(flags) -1 ;
	if (flags[len] == 'd' || flags[len] == 'i' || flags[len] == 'f')
		ft_conv_dif(flags, data);
	// if (flags[len] == 'c' || flags[len] == 's')
	// 	ft_conv_cs(flags, data);
	// if (flags[len] == 'o' || flags[len] == 'x' || flags[len] == 'X')
	// 	ft_conv_oxX(flags, data);
	// if (flags[len] == 'p')
	// 	ft_conv_p(flags, data);
	// if (flags[len] == 'u')
	// 	ft_conv_u(flags, data);
}

/*
** ft_got_flag:
**
*/
char	*ft_got_flag(char *str, t_data *data)
{
	int		i;
	char	*flags;

	i = 0;
	if (!(flags = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != 'd' \
		&& str[i] != 'i' && str[i] != 'o' && str[i] != 'u' \
		&& str[i] != 'x' && str[i] != 'X' && str[i] != 'f')
	{
		flags[i] = str[i];
		i++;
	}
	flags[i] = str[i];
	flags[i + 1] = '\0';
	data->flag_size = ft_strlen(flags) + 1;
	ft_analyse_conv(flags, data);
	return (data->buf);
}

/*
** ft_analyse:
** Analyze format, take care of %% case, and call an analyzing function
** when finding a % to check flags and conversions.
*/
char	*ft_analyse(char *str, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (str[i] == '%' && str[i - 1] != '%')
		{
			ft_strjoin(data->buf, ft_got_flag(&str[i + 1], data));
			j = ft_strlen(data->buf);
			i = i + data->flag_size;
		}
		data->buf[j] = str[i];
		j++;
		i++;
	}
	return (data->buf);
}

/*
** ft_printf_format:
** Malloc, call for analyse and print the final buffer.
** return the lenght of printed bits or -1 if error.
*/
int		ft_print_format(char *format, t_data *data)
{
	if (!(data->buf = ft_memalloc(sizeof(char) * 100000)))
	// if (!(data->buf = ft_memalloc(sizeof(char) * (ft_strlen(format) + 1))))
		return (-1);
	data->buf = ft_analyse(format, data);
	ft_putstr(data->buf);
	return (ft_strlen(data->buf));
}

/*
** ft_printf:
** Return how many bytes has been printed, or -1 if there was an error.
*/
int		ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	return (len);
}
