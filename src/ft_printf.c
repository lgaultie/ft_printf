/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/01 15:38:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Analyze all the flags and options after the '%', and call the appropriate
** function. Return what is to be printed.
*/
char	*ft_analyse_after_percent(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\n')
	{
		if (str[i] == 's' || str[i] == 'S')

		if (str[i] == 'd' || str[i] == 'D')

	}
}

/*
** Analyse format and create the appropriate buffer, then print it.
*/
int		ft_printf_format(char *format, t_data data)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!(buffer = ft_memalloc(sizeof(char)) * (ft_strlen(format) + 1)))
		return ;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_strcat(buffer, ft_analyse_after_percent(&format[i + 1]));
		buffer[i] = format[i];
		i++;
	}
	ft_putstr(buffer);
	return (len);
}

/*
** Return how many bytes has been printed, or -1 if there was an error.
*/
int		ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;
	t_data		data;

	va_start(data->ap, last);
	len = ft_print_format(format, data);
	va_end(data->ap);
	return (len);
}
