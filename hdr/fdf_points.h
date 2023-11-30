/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:34:32 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/30 04:09:34 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_POINTS_H
# define FDF_POINTS_H

typedef struct {
	int	x;
	int	y;
}	t_point;

typedef struct {
	t_point	a;
	t_point	b;
}	t_line;

#endif
