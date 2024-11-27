#ifndef CUB3D_H
#define CUB3D_H

# include "LIBFT/includes/libft.h"

typedef struct s_cub
{
	int		count_map;
	int		count_data;
	int		count_line;
	int		*arr_ceiling;
	int		*arr_floor;
	int		value_rgb_floor;
	int		value_rgb_ceiling;
	int 	player;
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

//check map
void check_map(char **map,t_cub *game);
void check_caracter_map(char **map,t_cub *game);

//save_fd
void save_map(t_cub *game,char *file,int i, int j);
char *read_fd(char *file,t_cub *game);

//valid_info
void valid_info(char *str,t_cub *game);
int *valid_numbers(char *str,t_cub *game);

//utils
char *ft_joinfree(char *s1, char *s2);
int	skip_spaces(char *str);
int count_comma(char *str);
void free_matrix(char **str);
int rgb(int r,int g,int b, int a); ///funcion de la mlx (set_rgb)


//exit

void error_msg(char *str,t_cub *game);


#endif