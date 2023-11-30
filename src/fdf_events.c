/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:33 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/30 03:49:28 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_data.h"
#include <stdio.h>

int	fdf_handle_noevent(void *data)
{
	*(t_mlx_data *)data = *(t_mlx_data *)data;
	return (0);
}

int	fdf_handle_event(int keysym, t_mlx_data *data)
{
	printf("Key: %i\n", keysym);
	if (keysym == KEY_ESCAPE)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
