/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/21 09:03:31 by mechane          ###   ########.fr       */
=======
/*   Updated: 2023/07/21 09:56:09 by azari            ###   ########.fr       */
>>>>>>> azari
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
	if (mlx_is_key_down(m->ptr, MLX_KEY_LEFT_SHIFT))
		m->plr->walk_speed = 2;
	else
		m->plr->walk_speed = 5;
	if (mlx_is_key_down(m->ptr, MLX_KEY_ESCAPE))
		destroy(mlx);
	mouse_rotate(mlx);
	ft_render(mlx);
	return ;
}
void	chose_gun(t_data *mlx)
{
	if (mlx->type == 0)
		draw_pistol(mlx);
	else if (mlx->type == 1)
		draw_m_g(mlx);
	else
		draw_gun(mlx);
}
void	ft_render(t_data *m)
{
	mlx_delete_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, m->w_width, m->w_height);
	render_ceil_a_floor(m);
	render_walls(m);
	render_doors(m);
	render_mini_map(m->map, m);
	mlx_image_to_window(m->ptr, m->img, 0, 0);
	mlx_set_instance_depth(m->img->instances, 0);
	chose_gun(m);
	
}
