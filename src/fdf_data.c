/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:11:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/29 17:04:04 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_data.h"
#include <stdlib.h>

int	data_init(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 800, "Hello world");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, 2400, 1600);
	if (!data->img.mlx_img)
		return (free(data->mlx_ptr), free(data->win_ptr), 1);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, \
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
