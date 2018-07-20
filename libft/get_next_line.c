/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:23:16 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/30 16:02:34 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_elem(t_list **ln_lst, int fd)
{
	t_ln	c_ln;
	t_list	*current_elem;

	current_elem = *ln_lst;
	while (current_elem)
	{
		if (((t_ln *)(current_elem->content))->fd == fd)
			return (current_elem);
		current_elem = current_elem->next;
	}
	c_ln.fd = fd;
	c_ln.n_found = 1;
	c_ln.buff = ft_strnew(BUFF_SIZE);
	c_ln.nr = BUFF_SIZE;
	c_ln.index = BUFF_SIZE;
	current_elem = ft_lstnew(&c_ln, sizeof(t_ln));
	ft_lstadd(ln_lst, current_elem);
	return (current_elem);
}

static void		remove_elem(t_list **ln_lst, int fd, char **str)
{
	t_ln	*c_ln;
	t_list	**current_elem;
	t_list	*ptr;

	current_elem = ln_lst;
	while (*current_elem)
	{
		c_ln = (t_ln *)((*current_elem)->content);
		if (c_ln->fd == fd)
			break ;
		*current_elem = ((*current_elem)->next);
	}
	if (*current_elem)
	{
		ptr = (*current_elem)->next;
		ft_strdel(&(c_ln->buff));
		ft_memdel((void **)&c_ln);
		ft_memdel((void **)current_elem);
		*current_elem = ptr;
	}
	ft_strdel(str);
}

static char		*build_str(t_ln *c_ln)
{
	int		i;

	i = 0;
	c_ln->n_found = 0;
	while (c_ln->index + i < c_ln->nr)
	{
		if (c_ln->buff[c_ln->index + i] == '\n')
		{
			c_ln->n_found = 1;
			i++;
			break ;
		}
		i++;
	}
	c_ln->index += i;
	if (c_ln->n_found)
		return (ft_strsub(c_ln->buff, c_ln->index - i, i - 1));
	return (ft_strsub(c_ln->buff, c_ln->index - i, i));
}

static int		one_buff(t_ln *c_ln, t_list **ln_lst, char **str, char **line)
{
	if (c_ln->index == c_ln->nr)
	{
		c_ln->nr = read(c_ln->fd, c_ln->buff, BUFF_SIZE);
		if (c_ln->nr == -1)
		{
			remove_elem(ln_lst, c_ln->fd, str);
			return (-1);
		}
		c_ln->index = 0;
		if (c_ln->nr == 0 && c_ln->n_found == 0)
		{
			*line = *str;
			return (1);
		}
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*ln_lst;
	t_ln			*c_ln;
	char			*str;
	int				read_result;

	if (fd < 0 || line == NULL)
		return (-1);
	c_ln = (t_ln*)(get_elem(&ln_lst, fd)->content);
	str = ft_strnew(0);
	while (c_ln->nr > 0)
	{
		if ((read_result = one_buff(c_ln, &ln_lst, &str, line)) != 0)
			return (read_result);
		while (c_ln->index < c_ln->nr)
		{
			str = ft_strjoin(str, build_str(c_ln));
			if (c_ln->n_found)
			{
				*line = str;
				return (1);
			}
		}
	}
	remove_elem(&ln_lst, fd, &str);
	return (0);
}
