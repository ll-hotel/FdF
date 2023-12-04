/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:55:35 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/12/04 20:07:20 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H

typedef struct {
	int	width;
	int	height;
	int	**array;
}	t_map;

int		fdf_map_parse(t_map *map, int fd);
void	f2d(void ***p);

#endif
