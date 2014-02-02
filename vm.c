/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:49:55 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/02 16:28:47 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"

void	ft_init(char arena[], t_proc players[], int argc, char *argv[])
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
		arena[i++] = 0;
	ft_init_players(players, argc, argv, arena);
}

int		main(int argc, char *argv[])
{
	char	arena[MEM_SIZE];
	t_proc	players[MAX_PLAYERS];

	if (argc > 1)
		ft_init(arena, players, argc, argv);
	return (0);
}
