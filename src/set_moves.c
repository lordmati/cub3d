#include "../Include/cub3D.h"

void	key_d(t_cub *game)
{
	if (game->map[(int)(game->y + P_MOVE * cos(game->radian_view))]
		[(int)(game->x - P_MOVE * sin(game->radian_view))] != '1'
		&& game->map[(int)(game->y + P_MOVE * cos(game->radian_view))]
		[(int)game->x] != '1'
		&& game->map[(int)game->y][(int)(game->x - P_MOVE *
		sin(game->radian_view))] != '1')
	{
		game->y += P_MOVE * cos(game->radian_view);
		game->x -= P_MOVE * sin(game->radian_view);
		paint_all(game, 0, 0);
		ray_casting(game->ray, game);
	}
}

void	key_a(t_cub *game)
{
	if (game->map[(int)(game->y - P_MOVE * cos(game->radian_view))]
		[(int)(game->x + P_MOVE * sin(game->radian_view))] != '1'
		&& game->map[(int)(game->y - P_MOVE * cos(game->radian_view))]
		[(int)game->x] != '1'
		&& game->map[(int)game->y][(int)(game->x + P_MOVE *
		sin(game->radian_view))] != '1')
	{
		game->y -= P_MOVE * cos(game->radian_view);
		game->x += P_MOVE * sin(game->radian_view);
		paint_all(game, 0, 0);
		ray_casting(game->ray, game);
	}
}

void	key_s(t_cub *game)
{
	if (game->map[(int)(game->y - P_MOVE * sin(game->radian_view))]
		[(int)(game->x - P_MOVE * cos(game->radian_view))] != '1'
		&& game->map[(int)(game->y - P_MOVE * sin(game->radian_view))]
		[(int)game->x] != '1'
		&& game->map[(int)game->y][(int)(game->x - P_MOVE *
		cos(game->radian_view))] != '1')
	{
		game->y -= P_MOVE * sin(game->radian_view);
		game->x -= P_MOVE * cos(game->radian_view);
		paint_all(game, 0, 0);
		ray_casting(game->ray, game);
	}
}

void	key_w(t_cub *game)
{
	if (game->map[(int)(game->y + P_MOVE * sin(game->radian_view))]
		[(int)(game->x + P_MOVE * cos(game->radian_view))] != '1'
		&& game->map[(int)(game->y + P_MOVE * sin(game->radian_view))]
		[(int)game->x] != '1'
		&& game->map[(int)game->y][(int)(game->x + P_MOVE *
		cos(game->radian_view))] != '1')
	{
		game->y += P_MOVE * sin(game->radian_view);
		game->x += P_MOVE * cos(game->radian_view);
		paint_all(game, 0, 0);
		ray_casting(game->ray, game);
	}
}
