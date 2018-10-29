/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:49:35 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/25 20:49:36 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 42

int					get_next_line(const int fd, char **line);
int					read_until_line(const int fd, char **tab,
									char **save, char *str);
int					read_line(const int fd, char **tab,
									char **line, char **save);
int					check_for_line(const int fd, char **tab,
									char **save, char *str);

#endif
