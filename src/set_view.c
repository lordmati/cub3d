/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:09:13 by misaguir          #+#    #+#             */
/*   Updated: 2024/12/27 14:09:46 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

double	set_view(t_cub *game)
{
	if (game->player_view == 'E')
		return (0);
	else if (game->player_view == 'N')
		return (M_PI_2 + M_PI);
	else if (game->player_view == 'W')
		return (M_PI);
	else
		return (M_PI_2);
}
