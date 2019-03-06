/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_allan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:45 by amamy             #+#    #+#             */
/*   Updated: 2019/03/04 19:08:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_analyse:
** Analyze all the flags and options after the '%', and call the appropriate
** function. Return what is to be printed.
*/
char	*ft_analyse(char *str, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'p' \
	&& str[i] != 'd' && str[i] != 'i' && str[i] != 'o' \
	&& str[i] != 'u' && str[i] != 'x' && str[i] != 'X' \
	&& str[i] != 'f')
		i++;
	if (str[i] == 's' || str[i] == 'S')
		tmp = va_arg(data->ap, char*);
	if (str[i] == 'd' || str[i] == 'i')
		tmp = ft_itoa(va_arg(data->ap, int));
	data->ag_size += (ft_strlen(tmp) - 2); // -2 to replace by the flag size
	return (tmp);
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
	if (!(data->buf = ft_memalloc(sizeof(char) * 1000)))
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i++)
			ft_strcat(data->buf, ft_analyse(&format[i++], data));	//on passe adresse de format[i], cad un char, marche pas --> ex %hhd
		data->buf[i + data->ap_size] = format[i];
		i++;
	}
	data->buf[i + data->ap_size] = '\0';
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
