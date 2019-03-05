/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/05 14:29:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_analyse_conv(char *flags, t_data *data)
{
	int		len;
	char	*final;

	len = data->flag_size - 1;
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
//	ft_putstr("avant return\n");
	return (final);
}

char	*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final;

	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' \
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f')
	{
		// ft_putstr("la\n");
		// ft_putchar(str[x]);
		// ft_putchar('\n');
		x++;
	}
	data->flag_size = x + 1;

	printf("flag_size : %d\n", data->flag_size);
	if (!(flags = malloc(sizeof(char) * (data->flag_size + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_size);
	final = ft_analyse_conv(flags, data);
	free(flags);
	printf("got flag return : |%s|\n", final);
	return (final);
}

char	*ft_analyse(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	data->conv_t_sz = 0;
	while (str[i + j] != '\0')
	{
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && ((i+j) == 0 || str[(i + j) - 1] != '%'))
		{

			//data->buf = ft_strcat(data->buf, ft_got_flag(&str[i], data));
			printf("buf just before tmp malloc : |%s|\n", data->buf);
			//tmp = malloc(sizeof(char) * (ft_strlen(data->buf) + 1));
			tmp = malloc(sizeof(char) * (1000)); // <- le malloc qui nique tout
			ft_strcpy(tmp, data->buf);
			printf("tmp = %s\n", tmp);
			printf("data->buf'avant copy) = |%s|\n", data->buf);
			free(data->buf);
			//	data->buf = malloc(sizeof(char) * (ft_strlen(tmp) + data->conv_sz));
			data->buf = ft_strdup(ft_strcat(tmp, ft_got_flag(&str[i + j], data)));
			printf("data->+buf = |%s|\n", data->buf);
			//printf("data->buf apres = |%s|\n", data->buf);
			free(tmp);
				j += data->flag_size;
			//i = i + data->flag_size;
			printf("conv_t_sz : %d\n", data->conv_t_sz);
		}
		printf("copie : str[%d] : |%c| dans buf[%d]\n", (i + j), str[i + j], (i + data->conv_t_sz));
		data->buf[i + data->conv_t_sz] = str[i + j];
		data->buf[i + data->conv_t_sz + 1] = '\0';
		printf("%s\n", data->buf);
			//ICI ON SEGFAULT SUR UN TRUC FREE
													//on ecrit apres le '\0'
		//data->buf[i] = str[i];
		//j++;
		i++;
	}
//	data->buf[j] = '\0';
	return (data->buf);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;

	if (!(data->buf = ft_memalloc(sizeof(char) * 1000)))
	// malloc de la string finale -> format + flags + argument variadiques
		return (-1);
	data->buf = ft_analyse(format, data);
	ft_putstr(data->buf);
	len = ft_strlen(data->buf);
	//free(data->buf);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	free(data);
	return (len);
}
