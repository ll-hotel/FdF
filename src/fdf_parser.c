/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:01:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/30 13:00:11 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf_map.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_realloc(void *old, unsigned long size_old, unsigned long size)
{
	char			*p;
	unsigned long	i;

	p = malloc(size);
	if (!p)
	{
		if (old)
			free(old);
		return (0);
	}
	if (size < size_old)
		size_old = size;
	i = 0;
	while (i < size_old)
	{
		p[i] = ((char *)old)[i];
		i += 1;
	}
	while (i < size)
		p[i++] = 0;
	return (free(old), p);
}

void	free_2d_array(void ***array)
{
	unsigned long	i;

	if (!*array)
		return ;
	i = 0;
	while (array[0][i])
		free(array[0][i++]);
	free(array[0]);
	array[0] = 0;
}

static void	_append(int ***array, int *nums, int len)
{
	int	**old;

	old = *array;
	*array = malloc(sizeof(int *) * (len + 1));
	if (!*array)
	{
		if (old)
			free_2d_array((void ***)&old);
		return ;
	}
	array[0][len] = nums;
	while (len--)
		array[0][len] = old[len];
}

int	fdf_map_parse(t_map *map, int fd)
{
	char	*s;
	char	**values;
	int		*nums;
	int		i;

	nums = 0;
	map->height = 0;
	map->array = 0;
	s = get_next_line(fd);
	while (s)
	{
		values = ft_split(s, ' ');
		if (!values)
			return (1);
		i = 0;
		while (values[i])
			i += 1;
		nums = ft_calloc(i, sizeof(int));
		if (!nums)
			return (free_2d_array((void ***)&map->array), 1);
		i = -1;
		while (++i)
			nums[i] = ft_atoi(values[i]);
		_append(&map->array, nums, map->height);
		if (!map->array)
			return (1);
		map->height += 1;
		s = (free(s), get_next_line(fd));
	}
	if (map->array)
		map->width = i;
	_append(&map->array, 0, map->height);
	return (0);
}
