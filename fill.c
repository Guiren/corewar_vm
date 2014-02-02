/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 17:01:52 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/02 13:25:08 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	players[no].mem_size = 0;
	while (i < 8)
	{
		players[no].mem_size += (unsigned int) buf[i];
		++i;
	}
}

void	ft_fill_arena(t_proc players[], char *buf, int no, int fd)
{
	unsigned int	i;

	if (no == 0)
	{
		i = 0;
		lseek(fd, 4, SEEK_CUR);
		while (i < players[no].mem_size)
		{
			read(fd, buf, 1);
			players[no].arena[i] = buf[0];
			++i;
		}
		players[no].reg[0] = 1;
		i = 1;
		while (i < 16)
		   players[no].reg[i++] = 0;	
	}
}
