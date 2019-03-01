/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:45 by amamy             #+#    #+#             */
/*   Updated: 2019/03/01 17:42:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		ft_str_size(char * str)
{
	//here we need to calculate the size of the final string for malloc
}
*/

char	*ft_arg_type(char *type)
{
	if (type[0] == 's')
		return ("char *");
	return (NULL);
}

#include <stdio.h>
char	*ft_analyse(char *format, t_data *data)
{
	char *tmp;
	if (format[0] == 's')
		tmp = va_arg(data->ap, char*);
	if (format[0] == 'd')
		tmp = ft_itoa(va_arg(data->ap, int));
	data->ag_size += (ft_strlen(tmp) - 2); // -2 to replace by flag size
		return (tmp);
}



int		ft_printf(const char* format, ...) // fid a better name for the chat *
{
	int		i;
	t_data	*data;

	i = 0;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	if(!(data->buf = ft_memalloc(sizeof(char) * 1000)))
		return (0);
	va_start(data->ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i++)
			ft_strcat(data->buf, ft_analyse((char*)&format[i++], data));
		data->buf[i + data->ag_size] = format[i];
		i++;
	}
	data->buf[i + data->ag_size] = '\0';
	ft_putstr(data->buf);
	return (0);
}
