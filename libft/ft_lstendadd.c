/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstendadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:58:34 by amamy             #+#    #+#             */
/*   Updated: 2019/02/07 20:16:54 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstendadd(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	if (!alst)
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (new)
	{
		tmp->next = new;
		new->next = NULL;
	}
}

