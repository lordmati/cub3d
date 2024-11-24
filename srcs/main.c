#include "../includes/cub3d.h"

static void init_cub(t_cub *game)
{
	game->east = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
	game->info = NULL;
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
	check_info(&game);
	save_map(&game,argv[1],0,0);
}