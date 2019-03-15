/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:38:29 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/15 15:42:18 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_nb_len_base(long value, int base)
{
	int	size;

	size = 0;
	if (value == 0 || value == -0)
		size = 1;
	if (value < 0)
		size++;
	while (value != 0)
	{
		value = value / (long)base;
		size++;
	}
	return (size);
}
