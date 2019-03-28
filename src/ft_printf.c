/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/28 21:37:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 23bbbf5a5035ebea7107b24fb3f15c18b229e708
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_analyse_flag: checks if we need to analyse flags or simply do a conversion
*/

static char		*ft_analyse_flags(char *flags, t_data *data)
{
	int		len;
	char	*final;

	len = data->flag_sz;
	if (len == 1)
		final = ft_only_conv(flags, data);
	else
		final = ft_flag_conv(flags, data);
	return (final);
}

/*
** ft_got_flag: returns the new converted sentence by calling ft_analyse_flags,
** %flagconv will be replaced by this new sentence.
*/

char			*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final;

	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' && str[x] != '%'	\
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f')
		x++;
	if (str[x] == '%' && str[x - 1] == '%')
		data->flag_sz = 1;
	else
		data->flag_sz = x + 1;
	if (!(flags = ft_memalloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_sz);
	if ((final = ft_analyse_flags(flags, data)) == NULL)
		return (NULL);
	free(flags);
	return (final);
}

/*
** ft_print_format : print final sentence returned by ft_analyse.
*/

static int		ft_print_format(char *format, t_data *data)
{
	int		len;

	if (!(data->buf = ft_strnew(0)))
		return (-1);
	data->buf = ft_analyse(format, data);
	ft_putstr(data->buf);
	len = ft_strlen(data->buf);
	// free(data->buf); //to uncom when not in tests
	return (len);

}

/*
** ft_printf : if error returns -1, else return nb of printed caracters
*/

//int				ft_printf(const char *format, ...)
char		*ft_printf(const char *format, ...) // for tests
{
	int			len;
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	free(data); //to uncom when not in tests
	return (data->buf);
 	//return (len);
}
