/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:49:55 by cnathana          #+#    #+#             */
/*   Updated: 2014/01/31 14:13:06 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"

void	ft_init(char *arena, t_proc *players[], int argc, char *argv[])
{
	int		n_players;

	players = NULL;
	if ((arena = (char *) malloc(sizeof(char) * MEM_SIZE)) == NULL)
		exit(0);
	ft_init_players(&players, argc, argv, arena);
}

int		main(int argc, char *argv[])
{
	char	*arena;
	t_proc	players[4];

	if (argc > 1) //a changer
		ft_init(arena, &players, argc, argv);
	return (0);
}
