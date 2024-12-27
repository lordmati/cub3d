/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:07:43 by misaguir          #+#    #+#             */
/*   Updated: 2024/12/27 14:08:25 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	set_paths(t_cub *game)
{
	int		spaces;
	char	*aux;

	aux = ft_strdup(game->north);
	spaces = skip_spaces(aux, 0);
	free(game->north);
	game->north = ft_substr(aux, spaces, ft_strlen(aux) - spaces - 1);
	free(aux);
	aux = ft_strdup(game->south);
	spaces = skip_spaces(aux, 0);
	free(game->south);
	game->south = ft_substr(aux, spaces, ft_strlen(aux) - spaces - 1);
	free(aux);
	aux = ft_strdup(game->east);
	spaces = skip_spaces(aux, 0);
	free(game->east);
	game->east = ft_substr(aux, spaces, ft_strlen(aux) - spaces - 1);
	free(aux);
	aux = ft_strdup(game->west);
	spaces = skip_spaces(aux, 0);
	free(game->west);
	game->west = ft_substr(aux, spaces, ft_strlen(aux) - spaces - 1);
	free(aux);
}
