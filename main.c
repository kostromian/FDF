/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/04 20:20:01 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->key_x = 0;
	map->key_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->code = 0;
	map->rot_x = 0;
	map->angle_x = 0;
	map->rot_y = 0;
	map->angle_y = 0;
	map->rot_z = 0;
	map->angle_z = 0;
}

int		get_height(char *file)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

int		get_width(char *file)
{
	int		x;
	int		i;
	int		fd;
	char	*line;
	char	**loc;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = 0;
	loc = ft_strsplit(line, ' ');
	while (loc[x])
		x++;
	free(line);
	i = 0;
	while (i < x)
		free(loc[i++]);
	free(loc);
	close(fd);
	return (x);
}

void	fill_z(int *line_z, char *line, int *min_z, int *max_z)
{
	char	**nbrs;
	int		i;

	i = 0;
	nbrs = ft_strsplit(line, ' ');
	while (nbrs[i])
	{
		line_z[i] = ft_atoi(nbrs[i]);
		*max_z = (line_z[i] > *max_z) ? line_z[i] : *max_z;
		*min_z = (line_z[i] > *min_z) ? *min_z : line_z[i];
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->x = get_width(file);
	map->y = get_height(file);
	map->z = (int **)malloc(sizeof(int *) * (map->y + 1));
	i = 0;
	while (i != map->y)
		map->z[i++] = (int *)malloc(sizeof(int) * (map->x + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_z(map->z[i], line, &(map->min_z), &(map->max_z));
		free(line);
		i++;
	}
	close(fd);
	map->z[i] = NULL;
}


int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = (t_map*)malloc(sizeof(t_map));
	init_map(map);
	read_map(argv[1], map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, SIZE, SIZE, "FDF");
	mlx_hook(map->win_ptr, 2, 0, press_key, map);
	mlx_key_hook(map->win_ptr, change_iso, map);
	map->key_y = SIZE / 2 - map->y * SCALE / 2;
	map->key_x = SIZE / 2 - map->x * SCALE / 2;
	draw(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
