#include "../Include/cub3D.h"

static void	move_is_correct(t_cub *game,mlx_key_data_t key)
{
	if(key.key == MLX_KEY_D)
		key_d(game);
	if(key.key == MLX_KEY_A)
		key_a(game);
	if(key.key == MLX_KEY_S)
		key_s(game);
	if(key.key == MLX_KEY_W)
		key_w(game);
	if(key.key == MLX_KEY_LEFT)
	{

		game->radian_view -= ANGLE_MOVE;
		paint_all(game,0,0);
		ray_casting(game->ray,game);
	}
	if(key.key == MLX_KEY_RIGHT)
	{
		game->radian_view += ANGLE_MOVE;
		paint_all(game,0,0);
		ray_casting(game->ray,game);
	}
}
void	mouse_move(void *data)
{
	int x;
	int y;
	t_cub *aux;

	aux = (t_cub *)data;
	mlx_get_mouse_pos(aux->mlx,&x,&y);
	if (y < MAP_HEIGHT && y > 0)
	{
		if(x < (MAP_WIDTH / 2) && x < (MAP_WIDTH / 2) - (MAP_WIDTH / 4))
		{
			aux->radian_view -= ANGLE_MOVE;
			paint_all(aux,0,0);
			ray_casting(aux->ray,aux);
		}
		if(x > (MAP_WIDTH / 2) && x > (MAP_WIDTH / 2) + (MAP_WIDTH / 4))
		{
			aux->radian_view += ANGLE_MOVE;
			paint_all(aux,0,0);
			ray_casting(aux->ray,aux);
		}
	}
}

void	key_press(mlx_key_data_t key, void *data)
{
	t_cub	*aux;

	aux = (t_cub *)data;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(aux->mlx);
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_S
		|| key.key == MLX_KEY_A || key.key == MLX_KEY_D
		|| key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		move_is_correct(aux,key);
}
