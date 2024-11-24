#include "../includes/cub3d.h"

char *ft_joinfree(char *s1, char *s2)
{
	char *temp;
	if(!s1 && s2)
		return(ft_strdup(s2));
	temp = ft_strjoin(s1,s2);
	if (s1)
		free(s1);
	return(temp);
}