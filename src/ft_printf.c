/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:45 by amamy             #+#    #+#             */
/*   Updated: 2019/03/01 14:35:24 by amamy            ###   ########.fr       */
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
	if (format[0] == 's')
	{
		return (va_arg(data->ap, char*));
	}
	if (format[0] == 'd')
		return (ft_itoa(va_arg(data->ap, int)));
	return (NULL);
}



int		ft_printf(const char* format, ...) // fid a better name for the chat *
{

	char	*buf;
	int		i;
	t_data	data;
	t_data	*p_data;

	i = 0;
	if(!(buf = ft_memalloc(sizeof(char) * 1000)))
		return (0);
	p_data = &data;
	va_start(data.ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i++)
		{
			ft_strcat(buf, ft_analyse((char*)&format[i++], p_data));
			printf("&format[i] : |%s| \nargs size : %zu\n", &format[i], ft_strlen(&format[i]));
		}
		buf[ft_strlen(buf)] = format[i];
		i++;
	}
	buf[ft_strlen(buf)] = '\0';
	ft_putstr(buf);
	return (0);
}
