/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:40 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/03 19:28:41 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_dif(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*stock_nb;
	int		nb_zero;

	i = 0;
	j = 0;
	data->buf = data->buf;
	if (!(stock_nb = malloc(sizeof(char) * ft_strlen(flags) + 1)))
		return ;
	while (flags[i] != '\0')
	{
		if (flags[i] == '0')
		{
			while (flags[i] >= '0' && flags[i] <= '9')
			{
				stock_nb[i] = flags[i];
				i++;
			}
			nb_zero = ft_atoi(stock_nb);
			while (j < nb_zero - data->flag_size)
			{
				data->buf[ft_strlen(data->buf)] = '0';				//foiré
				j++;
				//printf("j = %d\n",j);
			}
		}

		i++;
	}
	// while (flags[i] != 'd' && flags[i] != 'i' && flags[i] != 'f')
	// {
		// if (flags[i] == '0')
		// {
			// 	data->buf[ft_strlen(data->buf) + i] = '0';
			// }


		// if (flags[i] == '.' && (flags[i + 1] >= '0') && (flags[i + 1] <= '9'))
		//
		// if (flags[i] == '+')
		//
		// if (flags[i] == '-')
		//
		// if (flags[i] == ' ')
		//
		// if (flags[i] >= '0' && flags[i] <= '9')

	// 	i++;
	// }
	// printf("data->buf = %s\n", data->buf);
	data->buf = ft_strcat(data->buf, ft_itoa(va_arg(data->ap, int)));
	//data->ag_size += (ft_strlen(flags) - 2);
}
