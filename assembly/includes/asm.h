/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:18:55 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:46:59 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>

int		valid_name(char *name);
int		*val_asm(int fd);
void	print_in_file(int *to_print, char *name);
int		*turn_into_hex(char **file);
int		is_file_valid(char **file);
char	**check_name_and_comment(char **file);

typedef struct	s_adress
{
	char	*name;
	int		relative_pos;
}				t_adress;

#endif
