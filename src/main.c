/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:26 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/12/04 21:48:25 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_events.h"
#include "fdf_map.h"
#include "fdf_points.h"
#include "ft_put_pixels.h"
#include "fdf_data.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_mlx_data	data;
	t_map		map;
	int			fd;

	if (ac == 1)
		return (0);
	if (data_init(&data))
		return (1);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	fdf_map_parse(&map, fd);
	for (int j,i = 0; i < map.height; i += 1)
	{
		for (j = 0; j < map.width; j += 1)
			printf("%02d", map.array[i][j]);
		free(map.array[i]);
		printf("\n");
	}
	free(map.array);
	/* events */
	mlx_loop_hook(data.mlx_ptr, &fdf_handle_noevent, &data);
	mlx_key_hook(data.win_ptr, &fdf_handle_event, &data);
	/* draw & blit image */
	for (int j, i = 1; i < map.height; i += 1)
	{
		for (j = 0; j < map.width; j += 1)
		{
				ft_img_draw_line(&data.img, (t_point){j * 20, (i-1) * 20}, (t_point){j * 20, i * 20}, rgb(255, 255, 255));
				ft_img_draw_line(&data.img, (t_point){j * 20, (i-1) * 20}, (t_point){(j + 1) * 20, (i-1) * 20}, rgb(255, 255, 255));
		}
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	/* display until escape */
	mlx_loop(data.mlx_ptr);
	/* free all pointers */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	close(fd);
	return (0);
}
