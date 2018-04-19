/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:35 by atourner          #+#    #+#             */
/*   Updated: 2018/04/19 17:02:11 by atourner         ###   ########.fr       */
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
		if (!file[line][i])
		{
			if (!file[line + 1])
				return (-1);
			i = -1;
			line++;
		}
		i++;
		len++;
	}
	if (*act == 0)
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

	i = 0;
	if ((content = ft_strnew((line == 0 ? 128 : 2048))))
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

char	*get_describe(char **file, int *act, int choice)
{
	int			len;

	len = 0;
	if (!choice)
	{
		if (!strncmp(file[0], ".name", 5)
		&& ((len = get_len(file, content_start(&file[0][5], 5), act)) > 0)
		&& len <= 128)
			return (get_content(file, 0, content_start(&file[0][5], 5)));
		else
			ft_printf("%s\n", len <= 0 ? "Wrong name format" : "Max name len is\
128");
	}
	else
	{
		if (!strncmp(file[*act], ".comment", 8)
		&& ((len = get_len(file, content_start(&file[*act][8], 8), act)) > 0)
		&& len <= 2048)
			return (get_content(file, *act, 8));
		else
			ft_printf("%s\n", len <= 0 ? "Wrong comment format" : "Max comment \
len is 2048");
	}
	return (NULL);
}

char	**check_name_and_comment(char **file)
{
	char	**champion_describe;
	int		act;

	act = 0;
	if (!(champion_describe = (char**)malloc(sizeof(char*) * 2)))
	{
		ft_printf("Malloc error\nCheck your memory\n");
		return (NULL);
	}
	champion_describe[0] = get_describe(file, &act, 0);
	champion_describe[1] = get_describe(file, &act, 1);
	if (!champion_describe[0] || !champion_describe[1])
	{
		ft_free_ar((void**)champion_describe);
		return (NULL);
	}
	return (champion_describe);
}
