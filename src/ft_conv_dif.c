/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:45:40 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/07 20:29:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_dif(char *flags, t_data *data)
{
	int		i;
	int		ap;
	int		ap_sz;
	 char	*final;

(void)i;
(void)ap;
(void)flags;
(void)data;
(void)ap_sz;
	 if(!(final = ft_strdup("ici")))
	 	return (NULL);
	data->conv_sz = 3;
	data->conv_t_sz = data->conv_t_sz + data->conv_sz;
	// i = 0;
	// ap = (va_arg(data->ap, int));
	// ap_sz = ft_intlen(ap);
	// if (ap_sz > data->flag_sz)
	// 	data->ap_sz = ap_sz - data->flag_sz;
	// else if (ap_sz < data->flag_sz)
	// 	data->ap_sz = data->flag_sz - ap_sz;
	// else if (ap_sz == data->flag_sz)
	// 	data->ap_sz = ft_intlen(ap);
	// //data->ap_sz = ft_intlen(ap);
	// //taille argv variadiq = intlen de l'argv variadiq ?
	// //ouais mais faut mettre la taille des flags dedans
	// //data->flags - intlen de ap OU intlen de ap - data->flags
	// if (!(final = malloc(sizeof(char) * (data->ap_sz))))
	// 	return (NULL);
	// while (flags[i] != '\0')
	// {
	// 	if (flags[i] == '0')
	// 		ft_flag_zero(flags, data);
	// 	// if (flags[i] == '+')
	// 	// 	ft_flag_plus(flags, data);
	// 	// if (flags[i] == '-')
	// 	// 	ft_flag_minus(flags, data);
	// 	// if (flags[i] == ' ')
	// 	// 	ft_flag_space(flags, data);
	// 	// if (flags[i] >= '0' && flags[i] <= '9')
	// 	// 	ft_espaces(flags, data);
	// 	// if (flags[i] == '.' && (flags[i + 1] >= '0') && (flags[i + 1] <= '9'))
	// 	// 	ft_precision(flags, data);
	// 	i++;
	// }
	// final = ft_strcat(flags, ft_itoa(ap));
	return (final);
}
