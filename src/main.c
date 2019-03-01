/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/03/01 16:21:05 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  //printf("Je m'appelle : |%24s| et j'ai ans\n", "Allan");
  ft_printf("Je m'appelle : |%s| et j'ai combien deja ? %d ans\n", "Allan", 17);
  return 0;
}

//Je m'appelle : |%s| et j'ai combien deja ? %d ans\n
//Je m'appelle : |Allan| et j'ai combien deja ? 24 ans\n
