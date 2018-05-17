/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:46:29 by skarev            #+#    #+#             */
/*   Updated: 2018/04/25 17:46:29 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*stock;
	t_map	*map;
	int		fd;
	t_tetri	*tetri;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	stock = stock_str(fd);
	if (!check_str(stock))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	tetri = zero_position(struct_tetri(stock));
	map = solution(tetri);
	out_print(map);
	free_map(map);
	return (0);
}
