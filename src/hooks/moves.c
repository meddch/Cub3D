/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/20 08:33:12 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	right(t_data *mlx)
{
	mlx->plr->r_ang += mlx->plr->turn_speed;
	if (mlx->plr->r_ang > 360)
		mlx->plr->r_ang -= 360;
	if (mlx->plr->r_ang < 0)
		mlx->plr->r_ang += 360;
}

void	left(t_data *mlx)
{
	mlx->plr->r_ang -= mlx->plr->turn_speed;
	if (mlx->plr->r_ang > 360)
		mlx->plr->r_ang -= 360;
	if (mlx->plr->r_ang < 0)
		mlx->plr->r_ang += 360;
}

void	destroy(void *mlx)
{
	t_data	*m;

	m = (t_data *)mlx;
	mlx_terminate(m->ptr);
	exit(0);
}

void	ft_moves(void *mlx)
{
	t_data	*m;

	m = (t_data *)mlx;
	if (mlx_is_key_down(m->ptr, MLX_KEY_D))
		move_right(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_A))
		move_left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_W))
		move_forward(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_S))
		move_backword(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_RIGHT))
		right(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_LEFT))
		left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_ESCAPE))
		destroy(mlx);
	if (mlx_is_mouse_down(m->ptr, MLX_MOUSE_BUTTON_LEFT))
		mouse_rotate(mlx);
	ft_render(mlx);
	return ;
}

void	ft_render(t_data *m)
{
	mlx_delete_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, m->w_width, m->w_height);
	render_ceil_a_floor(m);
	render_walls(m);
	render_mini_map(m->map, m);
	mlx_image_to_window(m->ptr, m->img, 0, 0);
}
