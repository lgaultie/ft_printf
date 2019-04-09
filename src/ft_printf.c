/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 19:32:06 by amamy            ###   ########.fr       */
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
	{
		data->flag |= ONLY_CONV; 
		final = ft_only_conv(flags, data);
	}
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
	if (!(flags = ft_strndup(str, data->flag_sz)))
		return (NULL);
	if ((final = ft_analyse_flags(flags, data)) == NULL)
		return (NULL);
	// printf("\ndata->buffffffffff 3 : |%s|\n\n", data->buf);
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
	if (data->flag & F_C_0)
	{
		len++;
		ft_putstrn(data->buf, (data->index_0 + data->tmp));
		ft_putchar(0);
		ft_putstr(&data->buf[data->index_0]);
	}
	else
		ft_putstr(data->buf);
	free(data->buf); //to uncom when not in tests
	return (len);

}

/*
** ft_printf : if error returns -1, else return nb of printed caracters
*/

int				ft_printf(const char *format, ...)
// char		*ft_printf(const char *format, ...) // for tests
{
	int			len;
	t_data		*data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		// return (NULL);
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	free(data); //to uncom when not in tests
	// return (data->buf);
 	return (len);
}
