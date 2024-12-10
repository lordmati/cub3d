#include "../Include/cub3D.h"

static void init_cub(t_cub *game)
{
	game->east = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
	game->info = NULL;
	game->map = NULL;
	game->arr_ceiling = NULL;
	game->arr_floor = NULL;
	game->player_view = '\0';
	game->player = 0;
	game->value_rgb_ceiling = 0;
	game->value_rgb_floor = 0;
	game->count_data = 0;
	game->count_map = 0;
	game->count_line = 0;
	game->x = 0;
	game->y = 0;
	game->radian_view = 0;
}

int main(int argc, char **argv)
{
	t_cub game;

	init_cub(&game);
	if(argc != 2)
		error_msg("Error: Arguments Incorrect\n",NULL);
	if ((MAP_HEIGHT < 500 || MAP_HEIGHT > 1800)
		&& (MAP_WIDTH < 500 || MAP_WIDTH > 3000))
		error_msg("Error: size window\n",NULL);
	check_extension(argv[1]);
	game.info = read_fd(argv[1],&game);
	free(game.info);
	check_info(&game);
	valid_info(game.ceiling,&game);
	valid_info(game.floor,&game);
	game.arr_ceiling = valid_numbers(game.ceiling,&game);
	game.arr_floor = valid_numbers(game.floor,&game);
	save_map(&game,argv[1],0,0);
	check_caracter_map(game.map,&game);
	check_valid_position_player(game.map,&game);
	check_map(game.map,&game);
	game.radian_view = set_view(&game);
	init_mlx(&game);
}
