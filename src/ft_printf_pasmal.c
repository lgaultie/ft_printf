/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pasmal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/06 22:22:49 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_analyse_conv(char *flags, t_data *data)
{
	int		len;
	char	*final;

	//WOWOW il est ou le malloc de final ?
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



/////////////////////////////////////////////////////////
ALLAN PAS MAL MAIS CASSCOUILLE
////////////////////////////////////////////////////////





#include "ft_printf.h"
#include <stdio.h>

int		ft_next_p100_i(char *str)
{
	int	i;
	int	p_nb;

	p_nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			p_nb++;
			i++;
		}
		if (str[i] == '%' && (i == 0 || str[i - 1] != '%'))
			return (i - p_nb);
		i++;
	}
	return (i);
}

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
		 ft_putchar(str[x]);
		 ft_putchar('\n');
		x++;
	}
	data->flag_sz = x + 1;

	printf("flag_size : %d\n", data->flag_sz);
	if (!(flags = malloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_sz);
	if ((final = ft_analyse_conv(flags, data)) == NULL)
		return (NULL);
	free(flags);
//	printf("got flag return : |%s|\n", final);
	return (final);
}

char	*ft_next_p100(char *str)
{
	int	i;
	int	j;
	int	n_p100;
	char *ret;

	i = 0;
	j = 0;
	n_p100 = ft_next_p100_i(str);
	if(!(ret = malloc(sizeof(char) * (n_p100))))
		return (NULL);
	while ((i + j) <= n_p100)
	{
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && (i == 0 || str[i + j - 1] != '%'))
		{
			ret[i] = '\0';
			return (ret);
		}
		ret[i] = str[i + j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_analyse(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;
	int		n_p100;

	i = 0;
	j = 0;
	data->conv_t_sz = 0;
	n_p100 = 0;
	while (str[i + j] != '\0' && i < 50)
	{
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && ((i+j) == 0 || str[(i + j) - 1] != '%'))
		{
			//data->buf[i + data->conv_t_sz] = '\0';
			tmp = ft_strdup(data->buf);
			free(data->buf);
			data->buf = ft_strjoin(tmp, ft_got_flag(&str[i + j], data));
			free(tmp);
			j += data->flag_sz;
		}
		if (str[i + j] != '%')
		{
			printf("data buf : |%s|\n n_p100 : |%s|\n", data->buf, ft_next_p100(&str[i + j]));
			tmp = ft_strdup(data->buf);
			free(data->buf);


			if (!(data->buf = ft_strjoin(tmp, ft_next_p100(&str[i + j]))))
				return (NULL)
			i += ft_strlen(ft_next_p100(&str[i + j]));
		}
		//data->buf[i + data->conv_t_sz] = str[i + j];
		i++;
	}
	//data->buf[i + data->conv_t_sz] = '\0';
	return (data->buf);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;
	int 	i;

	i = 0;
	// while (format[i] != '%')
	// 	i++;
	i = ft_strlen(ft_next_p100(format));
	if (!(data->buf = ft_strsub(format, 0, i)))
        return (-1);
	data->buf = ft_analyse(format, data);
	printf("conv_t_sz : %d\n", data->conv_t_sz);
	ft_putstr(data->buf);
	len = ft_strlen(data->buf);
	free(data->buf);
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
