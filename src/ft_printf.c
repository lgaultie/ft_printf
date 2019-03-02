/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/02 15:43:39 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** ft_got_flag:
** Analyze flags and conversions.
*/
char	*ft_got_flag(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'L' || str[i] == '#' \
	str[i] == '0' || str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		i++;
	}
	return (data->buf);
}

/*
** ft_analyse:
** Analyze the string, specify %% case, and call the appropriate function
** when finding a %.
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
			//j = j + data->ag_size;
			j = ft_strlen(data->buf);
		}
		data->buf[j] = str[i];

		j++;
		i++;
	}
	return (data->buf);
}

/*
** ft_printf_format:
** Analyse format and create the appropriate buffer, then print it.
** return the lenght of printed bits or -1.
*/
int		ft_print_format(char *format, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(data->buf = ft_memalloc(sizeof(char) * 1000)))	//malloc foireux
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

	ft_putchar('\n');
	ft_putstr("JUSTE AVANT RETURN data->buf: ");
	ft_putstr(data->buf);
	ft_putchar('\n');

	return (len);
}
