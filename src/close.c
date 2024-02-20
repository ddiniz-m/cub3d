/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:48:46 by ddiniz-m          #+#    #+#             */
/*   Updated: 2024/01/31 10:48:57 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_t_img(t_img *img, void *mlx)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}

void	free_map(t_map *map)
{
	free(map->east);
	free(map->north);
	free(map->south);
	free(map->west);
	free_array(map->tilemap);
}

int	close_game(t_general *gen)
{
	int i;

	i = 0;
	while(i < 13)
	{
		mlx_destroy_image(gen->mlx, gen->anim[i].img);
		i++;
	}
	free(gen->anim);
	free(gen->textures->F);
	free(gen->textures->C);
	free_t_img(gen->textures->NO, gen->mlx);
	free_t_img(gen->textures->SO, gen->mlx);
	free_t_img(gen->textures->WE, gen->mlx);
	free_t_img(gen->textures->EA, gen->mlx);

	free(gen->textures);
	free_map(gen->map);
	free_array(gen->file);
	free(gen->key);
	free(gen->player);
	free(gen->img);
	free(gen->map);
//	mlx_mouse_show(gen->mlx, gen->win);
	mlx_destroy_window(gen->mlx, gen->win);
	mlx_destroy_display(gen->mlx);
	free(gen->mlx);
	free(gen);
	exit(0);
}