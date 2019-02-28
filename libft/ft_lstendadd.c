/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstendadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:35:05 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/16 14:46:56 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstendadd(t_list **alst, t_list *new)
{
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	if (new)
		(*alst)->next = new;
}
