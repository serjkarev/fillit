/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:50:43 by skarev            #+#    #+#             */
/*   Updated: 2018/04/25 14:50:44 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetri
{
	char			c;
	int				x[4];
	int				y[4];
	int				height;
	int				weight;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	char			**array;
	struct s_tetri	*next;
	int				size;
}					t_map;

t_map				*solution(t_tetri *tetri);
char				*stock_str(int fd);
int					check_str(char *stock);
int					check_valid_char(char *stock, int j);
int					check_neighbors(char *stock, int j);
t_tetri				*struct_tetri(char *str);
int					count_tetri(char *str);
void				coordinates_tetri(t_tetri **tmp, char *str);
t_tetri				*zero_position(t_tetri *stock);
int					ft_y_min(t_tetri *tmp);
int					ft_x_min(t_tetri *tmp);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					min_map_size(int quant);
t_map				*map_creation(int size);
void				free_map(t_map *map);
void				out_print(t_map *map);
int					count_list(t_tetri *lst);
void				set_place(t_tetri *tetri, t_map *map, int i, int j);
int					check_place(t_map *map, t_tetri *tetri, int i, int j);
int					algoooo(t_tetri *tetri, t_map *map);
void				ft_x_max(t_tetri *stock);
void				ft_y_max(t_tetri *stock);
void				clean_place(t_map *map, char c);
int					backslash_check(char *str);

#endif
