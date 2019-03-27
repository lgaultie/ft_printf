/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:22:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/27 19:06:56 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_active_flag: Analyses between % and the conversion, enable needed flags.
** F_W_P: active flag width + accuracy (ex: %5.2d)
** F_STAR: case of %.*d for example.
** SHOULD ALSO DISABLED IGNORED FLAGS QUAND YEN A DES INCOMPATIBLES............
*/

void	ft_active_flag2(char *flag, t_data *data, int i)
{
	if (flag[i] == ' ')
		data->flag |= F_SPACE;
	else if (flag[i] == '#')
		data->flag |= F_SHARP;
	else if (flag[i] == '+')
		data->flag |= F_PLUS;
	else if (flag[i] == '-')
		data->flag |= F_MINUS;
}

int		ft_active_flag(char *flag, t_data *data)
{
	int		i;

	i = 0;
	while (flag[i] != 'd' && flag[i] != 'c' && flag[i] != 's' \
		&& flag[i] != 'p' && flag[i] != 'x' && flag[i] != 'o' \
		&& flag[i] != 'x' && flag[i] != 'X' \
		&& flag[i] != 'i' && flag[i] != 'f' && flag[i] != '\0')
	{
		if (flag[0] == '0')
			data->flag |= F_ZERO;
		else if (flag[i] == '.' && (data->flag & F_WIDTH))
			data->flag |= F_W_P;
		else if (((flag[i] >= '0' && flag[i] <= '9') || flag[i] == '*')
			&& (data->flag ^ F_PRECIS)) //mal fait, cas %0.5d
		{
			data->flag |= F_WIDTH;
			if (flag[i] == '*')
				data->flag |= F_STAR;
		}
		else
			ft_active_flag2(flag, data, i);
		i++;
	}
	return (i);
}

/*
** ft_flag_conv: join the converted conversion with converted flags.
** should call functions to treat particular cases.............................
*/

char	*ft_flag_conv(char *flag, t_data *data)
{
	char	*final;
	char	*ret_conv;
	char	*ret_flag;
	int		i;

	i = ft_active_flag(flag, data);
	if (!(ret_conv = ft_only_conv(&flag[i], data)))
		return (NULL);
	if ((data->flag & F_PRECIS) && flag[i] == 's')
		return (ret_conv);
	//cas des flags apres les conv pour le '-' et du width, voir brouillon
	if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
		return (NULL);

	// UN BUG TRES INTERESSANT CI DESSOUS -- TOUT DECOMMENTER ET LANCER
	// ft_putstr(ret_conv);
	// ft_putchar('\n');
	// ft_putstr(ret_flag);
	// ret_conv[4] = '\0';		//OK SI ON MET UN \0 FSANITIZE SE LANCE
	// ft_putchar('\n');
	// ft_putstr("strlen de ret_conv(18) = ");
	// ft_strlen(ret_conv);
	// ft_putchar('\n');
	// ft_putstr("strlen de ret_flag(00000000) = ");
	// ft_strlen(ret_flag);
	// ft_putchar('\n');		//oublie de /0 ??

	if (!(final = ft_strjoin(ret_flag, ret_conv)))
		return (NULL);
	free(ret_conv);
	free(ret_flag);
	return (final);
}
