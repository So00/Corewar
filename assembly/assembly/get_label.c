#include "ft_printf.h"
#include "asm.h"
#include "op.h"

t_label		*search_last(t_label *first)
{
	t_label		*last;

	last = first;
	while (last->next != NULL)
		last = last->next;
	last->next = (t_label*)ft_memalloc(sizeof(t_label));
	return (last->next);
}

int			get_current_label(char **name, int *line, t_label **first)
{
	t_label		*act;

	act = *first;
	if (!act)
		act = (t_label*)ft_memalloc(sizeof(t_label));
	else
		act = search_last(*first);
	if (new_label(name, line))
	{
		
	}
	else
		while (!new_label(name, line))
			get_op(name, line, act);
}

t_label		*get_label(char **name, int line)
{
	t_label		*first;

	first = NULL;
	if (!name)
		return (NULL);
	while (name[line])
	{
		get_current_label(name, &line, &first);
	}
	return (NULL);
}
