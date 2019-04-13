/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/13 22:06:57 by amamy            ###   ########.fr       */
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
	char	*ret_conv;

	ret_conv = NULL;
	len = data->flag_sz;
	if (len == 1)
	{
		data->f |= ONLY_CONV;
		if (!(final = ft_only_conv(flags, data)))
			return (NULL);
		data->f &= ~ONLY_CONV;
	}
	else
	{
		len = ft_active_flag(flags, data);
		if (!(final = ft_flag_conv(flags, ret_conv, len, data)))
			return (NULL);
	}
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
	if (!(flags = ft_strndup(str, data->flag_sz)))
		return (NULL);
	if ((final = ft_analyse_flags(flags, data)) == NULL)
	{
		free(flags);
		return (NULL);
	}
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
	len = ft_strlen(data->buf);
	if (data->f & F_C_0)
	{
		len++;
		ft_putstrn(data->buf, (data->index_0 + data->tmp));
		ft_putchar(0);
		ft_putstr(&data->buf[data->index_0]);
	}
	else
		ft_putstr(data->buf);
	free(data->buf);
	return (len);
}

/*
** ft_printf : if error returns -1, else return nb of printed caracters
*/

int				ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	if (data->f & TMP_S_M)
		free(data->tmp_s);
	free(data);
	return (len);
}
