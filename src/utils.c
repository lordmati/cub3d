#include "../Include/cub3D.h"


int	skip_spaces(char *str, int i)
{
	while(str[i] && str[i] == ' ')
		i++;
	return(i);
}
int count_comma(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while(str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	return(c);
}

void free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int rgb(int r,int g,int b, int a)
{
	return(r << 24 | g << 16 | b << 8 | a);
}