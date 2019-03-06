/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/06 16:54:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_analyse_conv(char *flags, t_data *data)
{
	int		len;
	char	*final;

	len = data->flag_sz - 1;
	if (flags[len] == 'd' || flags[len] == 'i' || flags[len] == 'f')
	{
		final = ft_conv_dif(flags, data);
	}
	else if (flags[len] == 's')
	{
		final = ft_jonh_claude(flags, data);
	}
	// if (flags[len] == 'c' || flags[len] == 's')
	// 	ft_conv_cs(flags, data);
	// if (flags[len] == 'o' || flags[len] == 'x' || flags[len] == 'X')
	// 	ft_conv_oxX(flags, data);
	// if (flags[len] == 'p')
	// 	ft_conv_p(flags, data);
	// if (flags[len] == 'u')
	// 	ft_conv_u(flags, data);
	else
		final = (NULL);
	return (final);
}

char	*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final_conv;

	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' \
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f')
		x++;
	data->flag_sz = x + 1;
	if (!(flags = malloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_sz);
	if ((final_conv = ft_analyse_conv(flags, data)) == NULL)
		return (NULL);
	free(flags);
	return (final_conv);
}

char	*ft_analyse(char *frmt, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	data->conv_t_sz = 0;
	while (frmt[i + j] != '\0')
	{
		if (frmt[i + j] == '%' && frmt[i + j + 1] == '%')
			j++;
		while (frmt[i + j] == '%' && (i + j == 0 || frmt[i + j - 1] != '%'))
		{
			data->buf[i + data->conv_t_sz] = '\0';		//Invalid write of size 1
			tmp = ft_strdup(data->buf);					//Invalid read of size 1
			free(data->buf);
			if (!(data->buf = ft_strjoin(tmp, ft_got_flag(&frmt[i + j], data))))
				return (NULL);
			free(tmp);
			j = j + data->flag_sz;
		}
		//apres les conversions, on reecrit dedans sans le remalloc !
		data->buf[i + data->conv_t_sz] = frmt[i + j];	//Invalid write of size 1
		i++;
	}
	return (data->buf);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;
	int		i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')	//ouais mais NON si ya %% ?
		i++;										//format[i] = % et i = 19
	if (!(data->buf = ft_strsub(format, 0, i + 1)))
		return (-1);
	if ((data->buf = ft_analyse(format, data)) == NULL)
		return (-1);
	len = ft_strlen(data->buf);						// Invalid read of size 1
	ft_putstr(data->buf);
	free(data->buf);
	//free(data->buf); 	fait planter en incorrect checksum parfois car data->buf semble deja free, cas ou format est loooong
	//mais free quand il faut quand format est court (un leak de moins)
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	free(data);
	return (len);
}
