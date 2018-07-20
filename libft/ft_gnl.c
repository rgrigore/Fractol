/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:06:12 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/07 15:48:43 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_str(int fd, char *str, int index, int *code)
{
	char	c;
	int		r;

	if ((r = read(fd, &c, 1)) == -1)
		return (NULL);
	if (c == '\n' || r == 0)
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * (index + 1))))
			return (NULL);
		if (r == 0 && index == 0)
			*code = 0;
		else
			*code = 1;
		return (str);
	}
	if ((str = build_str(fd, str, index + 1, code)))
	{
		str[index] = c;
		return (str);
	}
	return (NULL);
}

int			ft_gnl(const int fd, char **line)
{
	static char	*str;
	int			code;

	code = 1;
	if (!(str = build_str(fd, str, 0, &code)))
		return (-1);
	*line = ft_strdup(str);
	free(str);
	return (code);
}
