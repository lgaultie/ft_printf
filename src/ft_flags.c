/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:10:38 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/12 16:51:11 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*stock_nb;
	int		nb_zero;

	i = 0;
	j = 0;
	if (!(stock_nb = malloc(sizeof(char) * ft_strlen(flags) + 1)))
		return ;
	{
		while (flags[i] >= '0' && flags[i] <= '9')
		{
			stock_nb[i] = flags[i];
			i++;
		}
		nb_zero = ft_atoi(stock_nb);
		while (j < nb_zero - data->ap_sz)
		{
			data->buf[ft_strlen(data->buf)] = '0';
			j++;
		}
	}
	//free(stock_nb);
}


// void	ft_flag_plus(char *flags, t_data *data)
// {
// 	int		i;
//
//
// 	i = 0;
// }
//
// void	ft_flag_minus(char *flags, t_data *data)
// {
// 	int		i;
//
// 	i = 0;
// }
//
// void	ft_flag_space(char *flags, t_data *data)
// {
// 	int		i;
//
// 	i = 0;
// }
//
// void	ft_flag_space(char *flags, t_data *data)
// {
// 	int		i;
//
// 	i = 0;
// }
