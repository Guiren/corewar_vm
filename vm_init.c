/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 12:39:06 by cnathana          #+#    #+#             */
/*   Updated: 2014/01/31 18:08:15 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "op.h"

int		ft_access(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		exit(1);
	return (fd);
}

void	ft_add_player(t_proc players[], int fd)
{
	static int		no = 0;
	int				n;
	char			*buf;
	unsigned int	champ_mem_size;

	buf = (char *) malloc(sizeof(char) * 4097);
	n = read(fd, buf, 4);
	buf[n] = 0;
	if (buf[1] != CEM_1 || buf[2] != CEM_2 || buf[3] != CEM_3)
		exit(2);
	ft_fill_name(players, buf, (int)no, fd);
	printf("%s\n", players[no].header.prog_name);
	ft_fill_memsize(players, buf, (int)no, fd);
	printf("%s\n", players[no].mem_size);
	ft_fill_comment(players, buf, (int)no, fd);
	printf("%s\n", players[no].header.comment);
}

void	ft_init_players(t_proc players[], int argc, char *argv[], char arena[])
{
	int		i;
	int		fd;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			fd = ft_access(argv[i]);
			ft_add_player(players, fd);
			close(fd);
		}
		++i;
	}
}

int		main(int argc, char *argv[])
{
	t_proc	players[4];
	char	arena[4096];

	ft_init_players(players, argc, argv, arena);
	return (0);
}