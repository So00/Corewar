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

typedef struct		s_label
{
	char				*name;
	char				*command;
	int					relative_pos;
	int					size;
	struct	s_label		*next;
}					t_label;

int		valid_name(char *name);
int		*val_asm(int fd);
void	print_in_file(int *to_print, char *name);
int		*turn_into_hex(char **file);
int		*is_file_valid(char **file);
char	**check_name_and_comment(char **file, int *act);
t_label	*get_label(char **name, int line);

#endif
