#include "../Include/cub3D.h"

static void paint_texture(t_cub *game,t_ray *ray,int i)
{
    int y;
    uint32_t color;
    y = ray->start_two;

    while(y < ray->end_two)
	{
		ray->texY = (int)((y - ray->start) * (game->current_texture->height) /
                (ray->end - ray->start));
		if (ray->texY < 0)
			ray->texY = 0;
		if (ray->texY >= (int)game->current_texture->height)
			ray->texY = (int)game->current_texture->height - 1;
		color = *(uint32_t *)(game->current_texture->pixels + 
                    (ray->texY * game->current_texture->width + ray->texX) * 4);
		color = (color & 0xff000000) >> 24 | (color & 0x00ff0000) >> 8 |
                (color & 0x0000ff00) << 8 | (color & 0x000000ff) << 24;
		mlx_put_pixel(game->cub_img, i, y, color);
        y++;
	}
}

void paint_wall(t_cub *game,t_ray *ray, int i,double distance_corrected)
{
    ray->start = MAP_HEIGHT/2 - (MAP_WIDTH/(2 * distance_corrected));
	ray->end = MAP_HEIGHT/2 + (MAP_WIDTH/(2 * distance_corrected));
	if (ray->start < 0)
		ray->start_two = 0;
	else
		ray->start_two = ray->start;
	if(ray->end >= MAP_HEIGHT)
		ray->end_two = MAP_HEIGHT;
	else
		ray->end_two = ray->end;
	set_texture(ray, game);
    paint_texture(game,ray,i);
}

void load_textures(t_cub *game)
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

void set_texture(t_ray *ray, t_cub *game)
{
    if (ray->side == 0)
    {
        ray->wallX = game->y + ray->distance * ray->sin;
        if (ray->stepX == -1)
            game->current_texture = game->texture_wall_n;
        else
            game->current_texture = game->texture_wall_s;
    }
    else
    {
        ray->wallX = game->x + ray->distance * ray->cos;
        if (ray->stepY == -1)
            game->current_texture = game->texture_wall_w;
        else
            game->current_texture = game->texture_wall_e;
    }

    ray->wallX -= floor(ray->wallX);
    if (ray->wallX < 0)
        ray->wallX += 1.0;
    ray->texX = (int)(ray->wallX * game->current_texture->width);
    if (ray->texX >= (int)game->current_texture->width)
        ray->texX = (int)game->current_texture->width - 1;
    if (ray->texX < 0)
        ray->texX = 0;
}
