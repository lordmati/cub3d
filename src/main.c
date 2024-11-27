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
	game->player = 0;
	game->value_rgb_ceiling = 0;
	game->value_rgb_floor = 0;
	game->count_data = 0;
	game->count_map = 0;
	game->count_line = 0;
}

int main(int argc, char **argv)
{
	t_cub game;

	init_cub(&game);
	if(argc != 2)
		error_msg("Error: Arguments Incorrect\n",NULL);
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
	check_map(game.map,&game);
}
