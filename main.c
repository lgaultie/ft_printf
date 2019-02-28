/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/02/28 21:09:00 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  ft_printf("Je m'appelle : %s et j'ai %d ans\n", "Allan", 17);
  //printf("Je m'appelle : %s et j'ai ans\n", "Allan");
  return 0;
}
