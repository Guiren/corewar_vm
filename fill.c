/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 17:01:52 by cnathana          #+#    #+#             */
/*   Updated: 2014/01/31 17:07:38 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "op.h"

void	ft_fill_name(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, PROG_NAME_LENGTH);
	buf[n] = 0;
	while (buf[i] != 0)
	{
		players[no].header.prog_name[i] = buf[i];
		++i;
	}
	players[no].header.prog_name[i] = 0;
}

void	ft_fill_comment(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, COMMENT_LENGTH);
	buf[n] = 0;
	while (buf[i] != 0)
	{
		players[no].header.comment[i] = buf[i];
		++i;
	}
	players[no].header.prog_name[i] = 0;
}

void	ft_fill_memsize(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, 8);
	buf[n] = 0;
	while (buf[i] != 0)
	{
		players[no].header.mem_size[i] = buf[i];
		++i;
	}
}
