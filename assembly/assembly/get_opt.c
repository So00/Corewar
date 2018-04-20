/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:30:30 by atourner          #+#    #+#             */
/*   Updated: 2018/04/20 17:13:22 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int		all_op(char *line)
{
	if (!ft_strncmp(line, "live", 4) && line[4] != ':')
		return (1);
	if (!ft_strncmp(line, "ld", 2) && line[2] != ':')
		return (2);
	if (!ft_strncmp(line, "st", 2) && line[2] != ':')
		return (3);
	if (!ft_strncmp(line, "add", 3) && line[3] != ':')
		return (4);
	if (!ft_strncmp(line, "sub", 3) && line[3] != ':')
		return (5);
	if (!ft_strncmp(line, "and", 3) && line[3] != ':')
		return (6);
	if (!ft_strncmp(line, "or", 2) && line[2] != ':')
		return (7);
	if (!ft_strncmp(line, "xor", 3) && line[3] != ':')
		return (8);
	if (!ft_strncmp(line, "zjmp", 4) && line[4] != ':')
		return (9);
	if (!ft_strncmp(line, "ldi", 3) && line[3] != ':')
		return (10);
	if (!ft_strncmp(line, "sti", 3) && line[3] != ':')
		return (11);
	if (!ft_strncmp(line, "fork", 4) && line[4] != ':')
		return (12);;
	if (!ft_strncmp(line, "lld", 3) && line[3] != ':')
		return (13);
	if (!ft_strncmp(line, "lldi", 4) && line[4] != ':')
		return (14);
	if (!ft_strncmp(line, "lfork", 5) && line[5] != ':')
		return (15);
	if (!ft_strncmp(line, "aff", 3) && line[3] != ':')
		return (16);
	return (0);
}

int		valid_opt(char **file, int *line, t_label *act)
{
	int		i;

	if (!ft_strncmp(file[*line], act->name, (i = (int)ft_strlen(act->name))))
		i = (file[*line][i] == ':' ? i + 1 : 0);
	else
		i = 0;
	while (file[*line][i] && ft_iswhitespace(file[*line][i]))
		i++;
	return (all_op(&file[*line][i]));
}

int		get_act_opt(char **file, int *line, t_label *act)
{
	while (file[*line])
	{
		if (!valid_opt(file, line, act))
			return (-1);
		*line += 1;
		act->size = 1;
	}
	if (!file[*line] || ((!valid_opt(file, line, act) && label_name_valid(file[*line], NULL))))
		return (1);
	return (0);
}

int		get_opt(char **file, int *line, t_label *act)
{
	int		ret;

	ret = 0;
	ft_printf("LABEL %s\n", act->name);
	while (file[*line] && !ret)
		ret = get_act_opt(file, line, act);
	return (ret);
}
