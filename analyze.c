/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/06 16:52:27 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && ((i+j) == 0 || str[(i + j) - 1] != '%'))
		{
			tmp = ft_strdup(data->buf);
			// size = ft_strlen(data->buf);
			// tmp = ft_strnew(size);
			// tmp = ft_strcpy(data->buf);
			free(data->buf);
			data->buf = ft_strjoin(tmp, ft_got_flag(&str[i + j], data)));
			//avec strjoin, data->buf est malloquée d la taille de tmp+retour de ft_gotflags + 1
			free(tmp);
			j = j + data->flag_size;
		}
		data->buf[i + data->conv_t_sz] = str[i + j];
		data->buf[i + data->conv_t_sz + 1] = '\0';
		i++;
	}
	return (data->buf);
}


/////////////////////////////

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



////////////////////////////////////////////


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
	size_t	size;

	i = 0;
	j = 0;
	data->conv_t_sz = 0;
	while (str[i + j] != '\0')
	{
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && ((i + j) == 0 || str[(i + j) - 1] != '%'))
		{
			size = ft_strlen(data->buf);
			printf("size = %zu\nstr[%d + %d] = %c\n", size, i, j, str[i + j]);
			ft_putstr("tmp = ");
			ft_putstr(tmp);
			ft_putchar('\n');
			tmp = ft_strdup(data->buf);
		//	tmp = ft_strcpy(tmp, data->buf);
			free(data->buf);
			data->buf = ft_strjoin(tmp, ft_got_flag(&str[i + j], data));
			//avec strjoin, data->buf est malloquée d la taille de tmp+retour de ft_gotflags + 1
			free(tmp);
			j = j + data->flag_size;
		}
		data->buf[i + data->conv_t_sz] = str[i + j];
		data->buf[i + data->conv_t_sz + 1] = '\0';
		i++;
	}
	return (data->buf);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;

	if (!(data->buf = ft_memalloc(sizeof(char) * 1000)))
	// malloc de format[0] jusqu'au premier % pour commencer str_sub
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











//////////////////////////////////////
CODE AVEC LES ERREURS DE VALGRIND
//////////////////////////////////////////////////////////////////////////




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/06 16:47:40 by lgaultie         ###   ########.fr       */
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
			data->buf[i + data->conv_t_sz] = '\0';
			// 			Invalid write of size 1
			// ==92610==    at 0x100001977: ft_analyse (ft_printf.c:79)
			// ==92610==    by 0x100001B06: ft_print_format (ft_printf.c:106)
			// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
			// ==92610==    by 0x1000015A5: main (main.c:21)
			// ==92610==  Address 0x100b5dd59 is 4 bytes after a block of size 21 alloc'd
			// ==92610==    at 0x10009A616: malloc (in /Users/lgaultie/.brew/Cellar/valgrind/3.14.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
			// ==92610==    by 0x1000013F6: ft_strsub (in ./ft_printf)
			//
			// ==92610==    by 0x100001ADB: ft_print_format (ft_printf.c:104)
			// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
			// ==92610==    by 0x1000015A5: main (main.c:21)
			tmp = ft_strdup(data->buf);
			// 			Invalid read of size 1
			// ==92610==    at 0x100001058: ft_strlen (in ./ft_printf)
			// ==92610==    by 0x10000109B: ft_strdup (in ./ft_printf)
			// ==92610==    by 0x100001987: ft_analyse (ft_printf.c:80)
			// ==92610==    by 0x100001B06: ft_print_format (ft_printf.c:106)
			// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
			// ==92610==    by 0x1000015A5: main (main.c:21)
			// ==92610==  Address 0x100b5dd55 is 0 bytes after a block of size 21 alloc'd
			//
			// ==92610==    at 0x10009A616: malloc (in /Users/lgaultie/.brew/Cellar/valgrind/3.14.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
			// ==92610==    by 0x1000013F6: ft_strsub (in ./ft_printf)
			// ==92610==    by 0x100001ADB: ft_print_format (ft_printf.c:104)
			// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
			// ==92610==    by 0x1000015A5: main (main.c:21)
			free(data->buf);
			if (!(data->buf = ft_strjoin(tmp, ft_got_flag(&frmt[i + j], data))))
				return (NULL);
			free(tmp);
			j = j + data->flag_sz;
		}
		//apres les conversions, on reecrit dedans sans le remalloc ??
		// ==91916== Invalid write of size 1
		// ==91916==    at 0x100001A29: ft_analyse (ft_printf.c:88)
		// ==91916==    by 0x100001B06: ft_print_format (ft_printf.c:106)
		// ==91916==    by 0x100001CDC: ft_printf (ft_printf.c:124)
		// ==91916==    by 0x1000015A5: main (main.c:21)
		// ==91916==  Address 0x100b5dd55 is 0 bytes after a block of size 21 alloc'd
		// ==91916==    at 0x10009A616: malloc (in /Users/lgaultie/.brew/Cellar/valgrind/3.14.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
		// ==91916==    by 0x1000013F6: ft_strsub (in ./ft_printf)
		// ==91916==    by 0x100001ADB: ft_print_format (ft_printf.c:104)
		//
		// ==91916==    by 0x100001CDC: ft_printf (ft_printf.c:124)
		// ==91916==    by 0x1000015A5: main (main.c:21)
		data->buf[i + data->conv_t_sz] = frmt[i + j];
		// if (!(data->buf = ft_strsub(format, 0, i + 1)))
		// 	return (-1);
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
	len = ft_strlen(data->buf);
	// 	==92610== Invalid read of size 1
	// ==92610==    at 0x100001058: ft_strlen (in ./ft_printf)
	// ==92610==    by 0x100001B31: ft_print_format (ft_printf.c:108)
	// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
	//
	// ==92610==    by 0x1000015A5: main (main.c:21)
	// ==92610==  Address 0x100b5e034 is 0 bytes after a block of size 36 alloc'd
	// ==92610==    at 0x10009A616: malloc (in /Users/lgaultie/.brew/Cellar/valgrind/3.14.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
	// ==92610==    by 0x100001517: ft_strjoin (in ./ft_printf)
	// ==92610==    by 0x1000019C8: ft_analyse (ft_printf.c:82)
	// ==92610==    by 0x100001B06: ft_print_format (ft_printf.c:106)
	// ==92610==    by 0x100001CDC: ft_printf (ft_printf.c:124)
	// ==92610==    by 0x1000015A5: main (main.c:21)
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
