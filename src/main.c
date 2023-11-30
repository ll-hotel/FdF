/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:26 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/30 12:57:53 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_events.h"
#include "fdf_map.h"
//#include "ft_put_pixels.h"
#include "fdf_data.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

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
	printf("Failure: %d\n", fdf_map_parse(&map, fd));
	printf("array: %p\n\tarray[1]: %p\n\tarray[1][0]: %d\n", map.array, map.array[1], map.array[1][0]);
	printf("map.width: %d\tmap.height: %d\n", map.width, map.height);
	for (int i = 0; i < map.height; i += 1)
	{
		for (int j = 0; j < map.width; j += 1)
			printf("|%d|\t", map.array[i][j]);
		printf("\n");
	}
	free_2d_array((void ***)&map.array);
	mlx_loop_hook(data.mlx_ptr, &fdf_handle_noevent, &data);
	mlx_key_hook(data.win_ptr, &fdf_handle_event, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
