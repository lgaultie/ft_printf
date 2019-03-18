/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:24 by amamy             #+#    #+#             */
/*   Updated: 2019/03/18 12:39:32 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_next_p100_i
** Gives the index of the next char '%'
*/

static int	ft_next_p100_i(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	return (i);
}

/*
** ft_next_p100
** Return a string copied from the begining of str and finishing by the char
** preceeding its first '%' or by '\0' if no '%' found.
*/

char		*ft_next_p100(char *str, t_data *data)
{
	int		i;
	int		n_p100;
	char	*ret;

	i = 0;
	n_p100 = ft_next_p100_i(str);
	if (!(ret = malloc(sizeof(char) * (n_p100 + 1))))
		return (NULL);
	while (str[i] != '\0' && str[i] != '%')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		data->done = 1;
	ret[i] = '\0';
	return (ret);
}

static void	ft_cat_conv(t_data *data, char *str, int i)
{
	char	*tmp;

	tmp = ft_strdup(data->buf);
	free(data->buf);
	data->buf = ft_strjoin(tmp, ft_got_flag(&str[i], data));
	free(tmp);
}

static void	ft_cat_txt(t_data *data, char *str, int i)
{
	char	*tmp;

	tmp = ft_strdup(data->buf);
	free(data->buf);
	if (!(data->buf = ft_strjoin(tmp, ft_next_p100(&str[i], data))))
		return ;
	free(tmp);
}

char		*ft_analyse(char *str, t_data *data)
{
	int		i;

	i = 0;
	data->conv_t_sz = 0;
	while (data->done != 1)
	{
		if (str[i] == '%')
		{
			ft_cat_conv(data, &str[1], i);
			if ((str[i] == '%') && (str[i + 1] == '%'))
				i += 2;
			else
				i += data->flag_sz + 1;
		}
		else if (str[i] != '%')
		{
			ft_cat_txt(data, str, i);
			i += ft_next_p100_i(&str[i]);
		}
	}
	return (data->buf);
}
