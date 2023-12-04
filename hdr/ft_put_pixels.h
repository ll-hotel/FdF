/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/12/04 20:46:56 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_PIXELS_H
# define FT_PUT_PIXELS_H
# include "fdf_points.h"

int		rgb(unsigned char red, unsigned char green, unsigned char blue);
void	ft_img_draw_line(void *img, t_point a, t_point b, int color);
void	ft_img_pixel_put(void *img, int x, int y, int color);

#endif
