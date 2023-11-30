/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:01:40 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/30 11:25:28 by ll-hotel         ###   ########.fr       */
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

void	ez(t_img *img, int x, int y, int color)
{
	char	*p;
	int		i;

	i = img->bpp - 8;
	p = img->addr + (y * img->line_len) + x * img->bpp / 4;
	while (i >= 0)
	{
		*p++ = (color >> i) & 0xFF;
		i -= 8;
	}
}

void	ft_img_draw_line(t_img *img, t_point a, t_point b, int color)
{
	double	sx;
	double	sy;
	double	x;
	double	y;
	long	d;

	d = ceil(sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
	sx = (b.x - a.x) / (double)d;
	sy = (b.y - a.y) / (double)d;
	x = a.x;
	y = a.y;
	while (d-- > 0)
	{
		ft_img_put_pixel(img, x, y, color);
		x += sx;
		y += sy;
	}
}
