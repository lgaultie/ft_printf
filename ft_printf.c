/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:45 by amamy             #+#    #+#             */
/*   Updated: 2019/02/28 21:08:19 by amamy            ###   ########.fr       */
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
char	*ft_analyse(char *format, va_list args)
{
	if (format[0] == 's')
	{
		return (va_arg(args, char*));
	}
	if (format[0] == 'd')
		return (ft_itoa(va_arg(args, int)));
	return (NULL);
}



int		ft_printf(const char* format, ...) // fid a better name for the chat *
{
	va_list	args;
	char	*buf;
	int		i;

	i = 0;
	if(!(buf = ft_memalloc(sizeof(char) * 1000)))
		return (0);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			buf = ft_strcat(buf, ft_analyse((char*)&format[i + 1], args));
			i = i + 2;
		}
		buf[ft_strlen(buf)] = format[i];
		i++;
	}
	buf[ft_strlen(buf)] = '\0';
	ft_putstr(buf);
	return (0);
}
