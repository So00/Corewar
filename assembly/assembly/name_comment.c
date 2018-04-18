/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:35 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:59:11 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"

int		get_name_len(char **file)
{
	unsigned int	line;
	unsigned int	len;
	unsigned int	i;

	line = 0;
	i = 7;
	len = 0;
	while (file[line] && file[line][i] != '\"')
	{
		i++;
		len++;
		if (!file[line][i])
		{
			i = 0;
			line++;
		}
	}
	return (len);
}

char	*get_name(char **file)
{
	int		len;

	if (!strncmp(file[0], ".name", 5) && guillemet(&file[0][5]) != -1 && (len = get_name_len(file)))
	{
		ft_printf("%d\n", len);
		return (NULL);
	}
	return (NULL);
}

void	get_name_and_comment(char **file, char **champion_describe)
{
	champion_describe[0] = get_name(file);
	champion_describe[1] = NULL;
}

char	**check_name_and_comment(char **file)
{
	char	**champion_describe;

	if (!(champion_describe = (char**)malloc(sizeof(char*) * 2)))
	{
		ft_printf("Malloc error\nCheck your memory\n");
		return (NULL);
	}
	get_name_and_comment(file, champion_describe);
	return (champion_describe);
}
