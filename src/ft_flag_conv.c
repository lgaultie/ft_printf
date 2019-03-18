/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takou <takou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:42:44 by takou             #+#    #+#             */
/*   Updated: 2019/03/18 12:45:21 by lgaultie         ###   ########.fr       */
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

//active ou non les binaires en fonction des flags pour regarder leurs
//comptabilités
//analyse les flags et lance la fonction qui va retourner la conversion, et
//recupere la conversion des flags
//analyse les conversions et la fonction qui va les traiter, recupere le retour
//fais le strjoin des deux
char  *ft_flag_conv(char *flag, t_data *data)
{
	char  *final;
	int   i;

	i = 0;
	data->flag = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == '.' && ((flag[i + 1] >= '0' && flag[i + 1] <= '9') \
			|| flag[i + 1] == '*'))
		{
			data->flag |= F_PRECIS;
		}
		i++;
	}
	final = NULL;
	return  ("fina");
}
