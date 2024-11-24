#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

typedef struct s_cub
{
	int		count_map;
	int		count_data;
	int		count_line;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
	char	**map;
	char	*info;
}	t_cub;

//Checks
void check_extension(char *str);
void ft_check_line(char *line,t_cub *game);
void check_info(t_cub *game);

//save_fd
void save_map(t_cub *game,char *file,int i, int j);
char *read_fd(char *file,t_cub *game);

//utils
char *ft_joinfree(char *s1, char *s2);


//exit

void error_msg(char *str,t_cub *game);


#endif