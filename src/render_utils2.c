/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:41:51 by ddiniz-m          #+#    #+#             */
/*   Updated: 2024/02/22 12:55:52 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_collision(t_general *gen, int y, int x)
{
	if (y >= 0 && x >= 0 && y / CUB < gen->map->y
		&& x / CUB < ft_strlen(gen->map->tilemap[y / CUB])
		&& gen->map->tilemap[y / CUB][x / CUB] != '1')
		return (0);
	return (1);
}

unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(img->addr
			+ (y * img->line_length + x * (img->bits_per_pixel / 8)));
	return (color);
}

int	get_color(t_RGB *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}
