/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:10:38 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/12 16:20:55 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** on envoie juste les flags (ex: on envoie 123 pour %123d) dans cette fonction
** qui va les analyser.
*/
char	*ft_analyse_flags(char *flags, t_data *data)
{
	int		i;
	char	*conv;
	int		to_print;	//nb de chars de l'argv variadique a imprimer

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '.' && flags[i + 1] >= '0' && flags[i + 1] <= '9')
		{
			if (flags[ft_strlen(flags)] == 'd')
				conv = ft_precision_d(flags, data);
			if (flags[ft_strlen(flags)] == 's')
				to_print = ft_precision_s(flags, data);
			//FAIRE FLAG POUR PRECISION ICI
		}
		else if (flags[i] >= '0' && flags[i] <= '9')
		{
			conv = ft_width(flags, data);
			//FAIRE FLAG POUR CHAMP ICI
			//champ -> si inferieur, passe rien, sinon, rempli d'espace
		}
		else if (flags[i] == '+')






		// if (flags[i] == '0')
		// 	ft_flag_zero(flags, data);
		// if (flags[i] == '+')
		// 	ft_flag_plus(flags, data);
		// if (flags[i] == '-')
		// 	ft_flag_minus(flags, data);
		// if (flags[i] == ' ')
		// 	ft_flag_space(flags, data);
		// if (flags[i] >= '0' && flags[i] <= '9')
		// 	ft_espaces(flags, data);
		// if (flags[i] == '.' && (flags[i + 1] >= '0') && (flags[i + 1] <= '9'))
		// 	ft_precision(flags, data);
		// else
		// 	ft_wtf(flags, data);
		i++;
	}
	return (conv);
}

// void	ft_flag_zero(char *flags, t_data *data)
// {
// 	int		i;
// 	int		j;
// 	char	*stock_nb;
// 	int		nb_zero;
//
// 	(void)data->flag_sz;
// 	i = 0;
// 	j = 0;
// 	if (!(stock_nb = malloc(sizeof(char) * ft_strlen(flags) + 1)))
// 		return ;
// 	{
// 		while (flags[i] >= '0' && flags[i] <= '9')
// 		{
// 			stock_nb[i] = flags[i];
// 			i++;
// 		}
// 		nb_zero = ft_atoi(stock_nb);
// 		// while (j < nb_zero - data->ap_sz)
// 		// {
// 		// 	data->buf[ft_strlen(data->buf)] = '0';
// 		// 	j++;
// 		// }
// 	}
// 	//free(stock_nb);
// }
