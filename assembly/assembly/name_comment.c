/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:35 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 18:41:28 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"

int		get_len(char **file, int i, int *act)
{
	unsigned int	line;
	unsigned int	len;

	if (i < 0)
		return (-1);
	line = *act;
	len = 0;
	while (file[line] && file[line][i] != '\"')
	{
		i++;
		len++;
		if (!file[line][i])
		{
			if (!file[line + 1])
				return (-1);
			i = 0;
			line++;
		}
	}
	*act = line + 1;
	return (len);
}

int		content_start(char *file, int start)
{
	int		i;

	i = 0;
	while (file[i] && ft_iswhitespace(file[i]))
		i++;
	if (file[i] == '\"')
		return (i + 1 + start);
	return (-1);
}

char	*get_content(char **file, int line, int act)
{
	char			*content;
	int				i;
	int				len;

	content = NULL;
	i = 0;
	if ((content = ft_strnew((act == 5 ? 128 : 200))))
	{
		len = content_start(&file[line][act], act);
		while (file[line][len] != '\"')
		{
			content[i] = file[line][len];
			if (!file[line][len])
			{
				len = -1;
				content[i] = '\n';
				line++;
			}
			len++;
			i++;
		}
	}
	return (content);

}

char	*get_name(char **file, int *act)
{
	int			len;

	if (!strncmp(file[0], ".name", 5) && (len = get_len(file, content_start(&file[0][5], 5), act) > 0) && len <= 128)
		return (get_content(file, 0, 5));
	return (NULL);
}

char	*get_comment(char **file, int *line)
{
	int		len;
	int		save_start;

	save_start = *line;
	if (!strncmp(file[*line], ".comment", 8) && (len = get_len(file, content_start(&file[*line][8], 8), line)))
		return (get_content(file, save_start, 8));
	return (NULL);
}

void	get_name_and_comment(char **file, char **champion_describe)
{
	int		act;

	act = 0;
	champion_describe[0] = get_name(file, &act);
	ft_printf("%s\n", champion_describe[0]);
	champion_describe[1] = get_comment(file, &act);
	ft_printf("%s\n", champion_describe[1]);
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
