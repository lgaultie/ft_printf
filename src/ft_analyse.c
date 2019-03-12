/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:24 by amamy             #+#    #+#             */
/*   Updated: 2019/03/12 18:17:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_next_p100_i
** Used to get size from index [0] to the next conversion
** mode 0 : size untouched.
** mode 1 : size with %% understood as %.
** mode 2 : index of next %.
*/

static int		ft_next_p100_i(char *str, int	mode)
{
	int	p_nb;
	int	i;

	p_nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			if (mode == 1)
				p_nb++;
			if (mode == 2)
				return (i);
			i++;
		}
		if (str[i] == '%' && (i == 0 || str[i - 1] != '%'))
			return (i - p_nb);
		i++;
	}
	return (i);
}

char	*ft_next_p100(char *str, t_data *data)
{
	int	i;
	int	j;
	int	n_p100;
	char *ret;

	i = 0;
	j = 0;
	n_p100 = ft_next_p100_i(str, 1);
	if(!(ret = malloc(sizeof(char) * (n_p100 + 1))))
		return (NULL);
	while (str[i + j] != '\0')
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
	data->done = 1;
	return (ret);
}

static void ft_cat_conv(t_data *data, char *str, int i, int j)
{
	char *tmp;

	tmp = ft_strdup(data->buf);
	free(data->buf);
	data->buf = ft_strjoin(tmp, ft_got_flag(&str[i + j], data));
	free(tmp);
}

static void	ft_cat_txt(t_data *data, char *str, int i, int j)
{
	char *tmp;

	tmp = ft_strdup(data->buf);
	free(data->buf);
	if (!(data->buf = ft_strjoin(tmp, ft_next_p100(&str[i + j], data))))
		return ;
	free(tmp);
}

char	*ft_analyse(char *str, t_data *data)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = ft_next_p100_i(str, 0);
	j = 0;
	data->conv_t_sz = 0;
	while (data->done != 1 && i >= 0 && j >= 0)
	{
		printf("i = %d, j = %d, str[%d] : |%s|\n", i,j, (i + j),  &str[i + j]);
		// on est sur le premier %
		if (str[i + j] == '%' && str[i + j + 1] == '%')
			j++;
		if (str[i + j] == '%' && ((i+j) == 0 || str[(i + j) - 1] != '%'))
		{
			ft_cat_conv(data, str, i, j);
			j += data->flag_sz;
			c = 1;
		}

		if ( (str[i + j] != '%') || ( (str[i + j] == '%') && (str[i + j - 1] == '%')) )
		{
			ft_putstr("Je rentre dans cette condition de merde\n");
			printf("i = %d, j = %d, str[%d] : |%s|\n", i,j, (i + j),  &str[i + j]);
				ft_cat_txt(data, str, i, j);
				if (( (str[i + j] != '%') && (str[i + j - 1] != '%')))
					i += ft_next_p100_i(&str[i + j], 0) - 1;
		}
		c = 0;
		i++;
	}
	return (data->buf);
}
