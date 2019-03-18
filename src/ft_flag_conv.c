/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:42:44 by takou             #+#    #+#             */
/*   Updated: 2019/03/18 19:12:24 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_p100(t_data *data)
{
	data->conv_sz = 1;
	data->conv_t_sz += data->conv_sz;
	return ("%");
}

char  *ft_only_conv(char *flags, t_data *data)
{
	char  *final;

	if (flags[0] == 'd' || flags[0] == 'i' || flags[0] == 'f')
		final =	ft_conv_di(data);
	else if (flags[0] == 's')
		final = ft_string(data);
	else if (flags[0] == '%')
		final = ft_p100(data);
	else if (flags[0] == 'p')
		final = ft_conv_p(data);
	else if (flags[0] == 'u')
		final = ft_conv_u(data);
	else if (flags[0] == 'c')
		final = ft_char(data);
	else if (flags[0] == 'o')
		final = ft_octal(data);
	else if (flags[0] == 'x')
		final = ft_hexa(data);
	else if (flags[0] == 'X')
		final = ft_caps_x(data);
	else
		final = (NULL);
  return (final);
}

//et avec un flag random -->erreur
char	*ft_which_flag(char *flag, char conv, t_data *data)
{
	int		i;
	char	*final;
	int		nb_to_print;

	i = 0;
	nb_to_print = 0;
	// if ((data->flag & F_PRECIS) && conv == 's')		//quels flags sont compatibles?
	// {
	//
	// }
	if ((data->flag & F_PRECIS) && (conv == 'd' || conv == 'i'))
	{
		if (!(final = ft_precision_d(flag, data)))
			return (NULL);
	}
	if (data->flag & F_WIDTH)
	{
		if (!(final = ft_width(flag, data)))
			return (NULL);
	}
	else
		final = NULL;
	// if (data->flag & F_SPACE)
	// 	final = ft_space();
	// if (data->flag & F_SHARP)
	// 	final = ft_sharp();
	// if (data->flag & F_PLUS)
	// 	final = ft_plus();
	// if (data->flag & F_MINUS)
	// 	final = ft_minus();
	return (final);
}

/*
** 1/ mise au point des binaires
** 2/ analyse des flags (= flags + conversion) et recup de la conversion des flags
** 3/ puis recup du retour des conversions --> ft_only_conv
** 4/ strjoin du retour des flags + retour des conversions
*/

char	*ft_flag_conv(char *flag, t_data *data)
{
	char	*final;
	char	*conv;
	int		i;
	char	*tmp;

	i = 0;
	data->flag = 0;
	// On lance l'analyse de conversion: ft_only_conv(&flag[ft_strlen(flag)]);
	// ou apres le while
	while (flag[i] != 'd' && flag[i] != 'c' && flag[i] != 's' \
		&& flag[i] != 'p' && flag[i] != 'x' && flag[i] != 'o' \
		&& flag[i] != 'x' && flag[i] != 'X' \
		&& flag[i] != 'i' && flag[i] != 'f' && flag[i] != '\0')
	{
		if (flag[i] == '.' && ((flag[i + 1] >= '0' && flag[i + 1] <= '9')
			|| flag[i + 1] == '*'))
			data->flag |= F_PRECIS;
		else if (flag[i] >= '0' && flag[i] <= '9')
			data->flag |= F_WIDTH;			//flag zero est activé ou non dans width
		else if (flag[i] == ' ')
			data->flag |= F_SPACE;
		else if (flag[i] == '#')
			data->flag |= F_SHARP;
		else if (flag[i] == '+')
			data->flag |= F_PLUS;
		else if (flag[i] == '-')
			data->flag |= F_MINUS;
		else
			return (NULL);
		i++;
	}
	if (!(conv = ft_only_conv(&flag[i], data)))
		return (NULL);
	if (!(tmp = ft_which_flag(flag, flag[i], data)))
		return (NULL);
	if (!(final = ft_strjoin(tmp, conv)))
		return (NULL);
	free(tmp);
	return  (final);
}
