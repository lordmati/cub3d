/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:37 by misaguir          #+#    #+#             */
/*   Updated: 2024/12/20 16:29:27 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void paint_texture(t_cub *game, t_ray *ray, int i)
{
    int         y;
    uint32_t    color;

    y = ray->start_two;
    while (y < ray->end_two)
	{
		ray->tex_y = (int)((y - ray->start) * (game->current_texture->height) /
                (ray->end - ray->start));
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= (int)game->current_texture->height)
			ray->tex_y = (int)game->current_texture->height - 1;
		color = *(uint32_t *)(game->current_texture->pixels + 
                    (ray->tex_y * game->current_texture->width + ray->tex_x) * 4);
		color = (color & 0xff000000) >> 24 | (color & 0x00ff0000) >> 8 |
                (color & 0x0000ff00) << 8 | (color & 0x000000ff) << 24;
		mlx_put_pixel(game->cub_img, i, y, color);
        y++;
	}
}

void    paint_wall(t_cub *game, t_ray *ray, int i, double distance_corrected)
{
    ray->start = MAP_HEIGHT/2 - (MAP_WIDTH/(2 * distance_corrected));
	ray->end = MAP_HEIGHT/2 + (MAP_WIDTH/(2 * distance_corrected));
	if (ray->start < 0)
		ray->start_two = 0;
	else
		ray->start_two = ray->start;
	if (ray->end >= MAP_HEIGHT)
		ray->end_two = MAP_HEIGHT;
	else
		ray->end_two = ray->end;
	set_texture(ray, game);
    paint_texture(game, ray, i);
}

void    load_textures(t_cub *game)
{
	game->texture_wall_n = mlx_load_png(game->north);
	if (!game->texture_wall_n)
    	error_msg("Failed to load north texture", game);
	game->texture_wall_s= mlx_load_png(game->south);
	if (!game->texture_wall_s)
    	error_msg("Failed to load south texture", game);
	game->texture_wall_e = mlx_load_png(game->east);
	if (!game->texture_wall_e)
    	error_msg("Failed to load east texture", game);
	game->texture_wall_w = mlx_load_png(game->west);
	if (!game->texture_wall_w)
    	error_msg("Failed to load west texture", game);
}

void    set_texture(t_ray *ray, t_cub *game)
{
    if (ray->side == 0)
    {
        ray->wall_x = game->y + ray->distance * ray->sin;
        if (ray->step_x == -1)
            game->current_texture = game->texture_wall_n;
        else
            game->current_texture = game->texture_wall_s;
    }
    else
    {
        ray->wall_x = game->x + ray->distance * ray->cos;
        if (ray->step_y == -1)
            game->current_texture = game->texture_wall_w;
        else
            game->current_texture = game->texture_wall_e;
    }
    ray->wall_x -= floor(ray->wall_x);
    if (ray->wall_x < 0)
        ray->wall_x += 1.0;
    ray->tex_x = (int)(ray->wall_x * game->current_texture->width);
    if (ray->tex_x >= (int)game->current_texture->width)
        ray->tex_x = (int)game->current_texture->width - 1;
    if (ray->tex_x < 0)
        ray->tex_x = 0;
}
