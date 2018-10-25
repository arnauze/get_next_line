/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:36:08 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/17 17:36:10 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					is_good(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}

char				*get_rest(char *str)
{
	int				i;
	char			*new;
	int				j;

	j = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	new = ft_strnew(BUFF_SIZE - i);
	while (str[++i])
	{
		new[j] = str[i];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char				*get_first_part(char *str)
{
	int				i;
	char			*new;

	i = 0;
	new = ft_strnew(BUFF_SIZE);
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				*ft_do(char **tab, int fd, char *buf, char *save)
{
	char			*tmp;
	char			*new;

	tab[fd] = ft_strnew(BUFF_SIZE);
	tab[fd] = get_rest(buf);
	tmp = get_first_part(buf);
	new = ft_strjoin(save, tmp);
	ft_bzero(buf, BUFF_SIZE);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE];
	static char		**tab;
	char			*save;
	int				x;

	if (!tab)
		tab = (char **)malloc(sizeof(char *) * 4864);
	if (!tab[fd])
		tab[fd] = ft_strnew(BUFF_SIZE);
	if (is_good(tab[fd]) == -1)
	{
		save = ft_strjoin("", get_first_part(tab[fd]));
		tab[fd] = get_rest(tab[fd]);
	}
	else
	{
		if (!save)
			save = ft_strnew(0);
		while ((x = read(fd, &buf, BUFF_SIZE)) > 0)
		{
			buf[x] = '\0';
			if (is_good(buf) == 1)
				save = ft_strjoin(save, buf);
			else
			{
				save = ft_do(tab, fd, buf, save);
				break ;
			}
		}
		if (x == 0)
			save = ft_strjoin("", get_first_part(tab[fd]));
	}
	*line = save;
	if (x > 0 || (x == 0 && !tab[fd]))
		return (1);
	return (x);
}
