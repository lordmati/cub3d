/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:20:54 by misaguir          #+#    #+#             */
/*   Updated: 2024/12/20 16:21:28 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void wall_finder(t_ray *ray, t_cub *game)
{
	while(1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1'
			|| game->map[ray->map_y][ray->map_x] == '\n'
			|| game->map[ray->map_y][ray->map_x] == '\0'
			|| game->map[ray->map_y][ray->map_x] == ' ')
			break;
	}
}

static void ray_steps(t_ray *ray, t_cub *game)
{
	if (ray->cos < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 -game->x) * ray->delta_dist_x;
	}
	if (ray->sin < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->y) * ray->delta_dist_y;
	}
}

static void dda_algorithm(t_ray *ray, t_cub *game, int i)
{
	double distance_corrected;

	ray->map_x = (int)game->x;
	ray->map_y = (int)game->y;
	ray->delta_dist_x = fabs(1 / ray->cos);
	ray->delta_dist_y = fabs(1 / ray->sin);
	ray_steps(ray, game);
	wall_finder(ray, game);
	if (ray->side == 0)
		ray->distance = (ray->map_x - game->x + (1 - ray->step_x)  / 2) / ray->cos;
	else
		 ray->distance = (ray->map_y - game->y + (1 - ray->step_y) / 2) / ray->sin;
	distance_corrected = ray->distance * cos (ray->ang - game->radian_view);
	paint_wall(game,ray,i,distance_corrected);
}


void ray_casting(t_ray *ray,t_cub *game)
{
	int i = 0;
	double ang;
	double start;
	double radian_fov;

	radian_fov = (FOV * M_PI) / 180;
	ang = (FOV / MAP_WIDTH) * M_PI / 180;
	start = game->radian_view - radian_fov / 2;
	while(i < MAP_WIDTH)
	{
		ray[i].ang = start + (ang * i);
		ray[i].sin = sin(ray[i].ang);
		ray[i].cos = cos(ray[i].ang);
		dda_algorithm(&ray[i], game, i);
		i++;
	}
}
