#include "../Include/cub3D.h"

void check_caracter_map(char **map,t_cub *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != '\n'
			&& map[i][j] != 'E' && map[i][j] != ' ')
				error_msg("Error character invalid in map\n",game);
			if(map[i][j] == 'N')
				game->player++;
			else if(map[i][j] == 'S')
				game->player++;
			else if(map[i][j] == 'E')
				game->player++;
			else if(map[i][j] == 'W')
				game->player++;
			j++;
		}
		i++;
	}
	if(game->player != 1)
		error_msg("Invalid number players\n",game);
}

void check_map(char **map,t_cub *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][0] == '0')
				error_msg("Error zero first caracter\n",game);
			if (map[i][j] == '0' && (i == 0 || (map[i][j - 1] == '\0') || (map[i][j + 1] == '\0')
				|| (!map[i + 1] || map[i + 1][j] == '\0') || ( map[i - 1][j] == '\0')))
				error_msg("Error null around zero\n",game);
			if (map[i][j] == '0' && ((map[i][j - 1] == ' ') || (map[i][j + 1] == ' ')
				|| (map[i + 1][j] == ' ') || (map[i - 1][j] == ' ')))
				error_msg("Error spaces around zero\n",game);
			if (map[i][j] == '0' && ((map[i][j - 1] == '\n') || (map[i][j + 1] == '\n')
				|| (map[i + 1][j] == '\n') || (map[i - 1][j] == '\n')))
				error_msg("Error new line around zero\n",game);
			j++;
		}
		i++;
	}
}
