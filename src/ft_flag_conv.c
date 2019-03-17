/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takou <takou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:42:44 by takou             #+#    #+#             */
/*   Updated: 2019/03/17 17:31:27 by takou            ###   ########.fr       */
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

char  *ft_flag_conv(char *flags, t_data *data)
{
  char  *final;

  (void) data;
  (void)flags;
  final = (NULL);
  return  (final);
}
