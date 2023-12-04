/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:01:42 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/12/04 20:39:07 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf_map.h"
#include <unistd.h>
#include <stdlib.h>

void	f2d(void ***array)
{
	unsigned long	i;

	if (!array || !*array)
		return ;
	i = 0;
	while ((*array)[i])
		free((*array)[i++]);
	*array = 0;
}

static int	_array_len(void **array)
{
	int	len;

	if (!array)
		return (0);
	len = 0;
	while (array[len])
		len += 1;
	return (len);
}

static int	**ft_realloc(int **old, int old_size, int new_size)
{
	int	**p;
	int	i;

	p = ft_calloc(new_size, sizeof(int *));
	if (!p && old)
		f2d((void ***)&old);
	if (!p)
		return (0);
	if (new_size < old_size)
		old_size = new_size;
	i = -1;
	while (++i < old_size)
		p[i] = old[i];
	while (i < new_size)
		p[i++] = 0;
	return (free(old), p);
}

int	fdf_map_parse(t_map *map, int fd)
{
	char	*line;
	char	**numbers;
	int		i;
	int		j;
	int		len;

	line = get_next_line(fd);
	i = 0;
	map->array = 0;
	while (line)
	{
		numbers = ft_split(line, ' ');
		if (!numbers)
			return (free(line), f2d((void ***)&map->array), -1);
		map->array = ft_realloc(map->array, i, i + 2);
		if (!map->array)
			return (f2d((void ***)&numbers), -2);
		len = _array_len((void **)numbers);
		map->array[i] = ft_calloc(len, sizeof(int));
		if (!map->array[i])
		{
			f2d((void ***)&numbers);
			return (free(line), f2d((void ***)&map->array), -1);
		}
		j = -1;
		while (++j < len)
		{
			map->array[i][j] = ft_atoi(numbers[j]);
			free(numbers[j]);
		}
		numbers = (free(numbers), (void *)0);
		line = (free(line), get_next_line(fd));
		i += 1;
	}
	map->height = i;
	map->width = j;
	return (0);
}
