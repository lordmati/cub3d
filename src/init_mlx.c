#include "../Include/cub3D.h"

static void ray_casting(t_ray *ray,t_cub *game)
{
	int i = 0;
	double ang;
	double start;
	double radian_fov;

	radian_fov = (FOV * M_PI) / 180;
	ang = (FOV / MAP_WIDTH) * M_PI / 180;
	start = game->radian_view + radian_fov / 2;
	while(i < 3)
	{
		ray[i].ang = start + (ang * i);
		ray[i].sin = sin(ray[i].ang);
		ray[i].cos = cos(ray[i].ang);
		printf("%f\n",ray[i].ang);
		i++;
	}
}
static void paint_all(t_cub *game,int x, int y)
{
	int rgb_ceiling;
	int rgb_floor;

	rgb_ceiling = rgb(game->arr_ceiling[0],game->arr_ceiling[1],game->arr_ceiling[2],255);
	rgb_floor = rgb(game->arr_floor[0],game->arr_floor[1],game->arr_floor[2],255);
	while(MAP_HEIGHT / 2 > y)
	{
		x = 0;
		while(MAP_WIDTH > x++)
			mlx_put_pixel(game->cub_img, x, y, rgb_ceiling);
		y++;
	}
	while(MAP_HEIGHT > y)
	{
		x = 0;
		while(MAP_WIDTH > x++)
			mlx_put_pixel(game->cub_img, x, y, rgb_floor);
		y++;
	}
}

void init_mlx(t_cub *game)
{
	t_ray ray[MAP_WIDTH];
	game->mlx = mlx_init(MAP_WIDTH,
			MAP_HEIGHT, "cub3D", false);
	game->cub_img = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
	paint_all(game,0,0);
	mlx_image_to_window(game->mlx, game->cub_img, 0, 0);
	ray_casting(ray,game);
	mlx_loop(game->mlx);

}