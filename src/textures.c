/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:14 by ddiniz-m          #+#    #+#             */
/*   Updated: 2024/02/13 13:40:16 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_img	*init_texture(t_general *gen, char *path)
{
	t_img	*texture;

	texture = (t_img *)malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(gen->mlx, path, &(texture->width), &(texture->height));
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel),
		 &(texture->line_length), &(texture->endian));
	return (texture);
}

void	save_img(t_general *gen, char *dir, char *line, int j)
{
	char	*path;
	int		fd;

	path = ft_chrtrim(&line[j], ' ');
	fd = open(path, O_RDONLY);
	if(fd == -1)
	{
		printf("Error - Invalid texture path\n");
		return;
	}
	close(fd);
	if (dir[0] == 'N' && dir[1] == 'O')
		gen->textures->NO = init_texture(gen, path);
	else if (dir[0] == 'S' && dir[1] == 'O')
		gen->textures->SO = init_texture(gen, path);
	else if (dir[0] == 'W' && dir[1] == 'E')
		gen->textures->WE = init_texture(gen, path);
	else if (dir[0] == 'E' && dir[1] == 'A')
		gen->textures->EA = init_texture(gen, path);
	free(path);
}

int get_textures(t_general *gen)
{
	int i;
	int j;

	i = 0;
	while(gen->file[i])
	{
		j = 0;
		while (gen->file[i][j])
		{
			while(gen->file[i][j] == ' ')
				j++;
			if(gen->file[i][j] == 'N' && gen->file[i][j + 1] == 'O' && gen->file[i][j + 2] == ' ')
				save_img(gen, "NO", gen->file[i], j + 2);
			else if(gen->file[i][j] == 'S' && gen->file[i][j + 1] == 'O' && gen->file[i][j + 2] == ' ')
				save_img(gen, "SO", gen->file[i], j + 2);
			else if(gen->file[i][j] == 'W' && gen->file[i][j + 1] == 'E' && gen->file[i][j + 2] == ' ')
				save_img(gen, "WE", gen->file[i], j + 2);
			else if(gen->file[i][j] == 'E' && gen->file[i][j + 1] == 'A' && gen->file[i][j + 2] == ' ')
				save_img(gen, "EA", gen->file[i], j + 2);
			else if(gen->file[i][j] == 'C' && gen->file[i][j + 1] == ' ')
				save_color(gen, 'C', gen->file[i], j + 1);
			else if(gen->file[i][j] == 'F' && gen->file[i][j + 1] == ' ')
				save_color(gen, 'F', gen->file[i], j + 1);
			break;
		}
		i++;
	}
	return 1;
}

int check_textures(t_general *gen)
{
	if(gen->textures->NO == NULL)
		return(printf("Error - NO texture not found\n"));
	if(gen->textures->SO == NULL)
		return(printf("Error - SO texture not found\n"));
	if(gen->textures->WE == NULL)
		return(printf("Error - WE texture not found\n"));
	if(gen->textures->EA == NULL)
		return(printf("Error - EA texture not found\n"));
	if(gen->textures->C == NULL)
		return(printf("Error - C color not found\n"));
	if(gen->textures->F == NULL)
		return(printf("Error - F color not found\n"));
	return (0);
}