/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:06:03 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:47:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"

int		is_file_valid(char **file)
{
	char **name;

	if ((name = check_name_and_comment(file)))
		return (1);
	return (0);
}

int		*turn_into_hex(char **file)
{
	ft_printf("going into hex function \n");
	if (file)
		return (NULL);
	return (NULL);
}
