/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_hh_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:21:56 by amamy             #+#    #+#             */
/*   Updated: 2019/03/30 22:56:19 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_olh(t_data *data, int ap)
{
	char *final;

	if (data->flag & F_H)
		if(!(final = ft_oh(data, ap)))
			return (NULL);
	if (data->flag & F_HH)
		if(!(final = ft_ohh(data, ap)))
			return (NULL);
	if (data->flag & F_L)
		if(!(final = ft_ol(data, ap)))
			return (NULL);
	if (data->flag & F_LL)
		if(!(final = ft_oll(data, ap)))
			return (NULL);

	return (final);
}

char *ft_ohh(t_data *data, int ap_tmp)
{
	char			*final;
	char			ap;
	char			*tmp;

	ap = (char)ap_tmp;
	data->ap_sz = ft_intlen((int)ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_base_mode((int)ap, 8, 1);
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode((int)ap, 8, 1)))
			return (NULL);
	}
	return (final);
}

char *ft_oh(t_data *data, int ap_tmp)
{
	char	*final;
	short	ap;
	char	*tmp;

	ap = (short)ap_tmp;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_base_mode(ap, 8, 1);
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 8, 1)))
			return (NULL);
	}
	return (final);
}

char *ft_ol(t_data *data, int ap_tmp)
{
	char	*final;
	short	ap;
	char	*tmp;

	ap = (long)ap_tmp;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_base_mode(ap, 8, 1);
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 8, 1)))
			return (NULL);
	}
	return (final);
}

char *ft_oll(t_data *data, int ap_tmp)
{
	char	*final;
	short	ap;
	char	*tmp;

	ap = (long long)ap_tmp;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_base_mode(ap, 8, 1);
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 8, 1)))
			return (NULL);
	}
	return (final);
}
