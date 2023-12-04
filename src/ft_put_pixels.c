/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:01:40 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/12/04 21:50:57 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_data.h"
#include "fdf_points.h"
#include <math.h>

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_img_put_pixel(t_img *img, int x, int y, int color)
{
	char	*p;
	int		i;

	i = img->bpp - 8;
	p = img->addr + (y * img->line_len) + x * (img->bpp >> 2);
	while (i >= 0)
	{
		if (img->endian)
			*p++ = (color >> i) & 0xFF;
		else
			*p++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

#include <stdio.h>
void	ft_img_draw_line(t_img *img, t_point p0, t_point p1, int color)
{
	const double	sy = p1.y - p0.y;
	double			sx;
	double			frac;
	int				x;
	double			y;
	
	sx = p1.x - p0.x;
	if (sx == 0)
		sx = sy * (sy >= 0) - sy * (sy < 0);
	frac = sy / sx;
	printf("\n(%d, %d) -> (%d, %d): step=%f (num=%f, denom=%f)\n", p0.x, p0.y, p1.x, p1.y, frac, sy, sx);
	x = 0;
	y = p0.y;
	while (x < sx || y < p1.y)
	{
		ft_img_put_pixel(img, x + p0.x, round(y), color);
		x += (x < sx);
		y += frac;
	}
}
