/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/20 06:24:53 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_ang(t_player *player)
{
	if (player->side == 'N')
		player->rotate_ang = 90;
	else if (player->side == 'W')
		player->rotate_ang = 180;
	else if (player->side == 'E')
		player->rotate_ang = 0;
	else if (player->side == 'S')
		player->rotate_ang = 270;
	player->turn_speed = 1;
	player->walk_speed = 5;
}

void	draw_line(t_point *p1, t_point *p2, t_data *mlx)
{
	double	steps;
	t_point	d;
	t_point	p;
	t_point	inc;

	d.y = p2->y - p1->y;
	d.x = p2->x - p1->x;
	if (fabs(d.x) > fabs(d.y))
		steps = fabs(d.x);
	else
		steps = fabs(d.y);
	inc.x = d.x / steps;
	inc.y = d.y / steps;
	p.x = p1->x;
	p.y = p1->y;
	while (steps-- >= 0)
	{
		mlx->txtr->dft = p.y + (mlx->txtr->wall_height / 2) - (mlx->w_height / 2);
		mlx->txtr->offsety = mlx->txtr->dft * ((float)mlx->txtr->t_ea->height / mlx->txtr->wall_height);
		ft_mlx_put_pixel(mlx->img, p.x, p.y,
			color((mlx->txtr->t_ea), mlx->txtr->offsetx, mlx->txtr->offsety));
		p.x += inc.x;
		p.y += inc.y;
	}
}

void	cast_ray(t_data *mlx, double ang, int x)
{
	t_point	*s;
	t_point	*h;
	t_point	*v;
	
	s = ft_malloc(sizeof(t_point));
	s->x = mlx->plr->x;
	s->y = mlx->plr->y;
	h = find_hz_inter(s, to_rad(ang), mlx->map);
	v = find_vrt_inter(s, to_rad(ang), mlx->map);
	if (distance(s, h) < distance(s, v))
	{
		(sin(to_rad(ang)) >= 0) && (mlx->txtr->side = 'N');
		(sin(to_rad(ang)) < 0) && (mlx->txtr->side = 'S');
		mlx->txtr->offsetx = (fmod(h->x, TILE_SIZE) / TILE_SIZE) * mlx->txtr->t_ea->width;
		(ang == mlx->plr->rotate_ang) && (mlx->plr->col_x = h->x, mlx->plr->col_y = h->y);
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->rotate_ang)) * distance(s,h)), x);
	}	
	else
	{
		(cos(to_rad(ang)) >= 0) && (mlx->txtr->side = 'W');
		(cos(to_rad(ang)) < 0) && (mlx->txtr->side = 'E');
		mlx->txtr->offsetx = (fmod(v->y, TILE_SIZE) / TILE_SIZE) * mlx->txtr->t_ea->width;
		(ang == mlx->plr->rotate_ang) && (mlx->plr->col_x = v->x, mlx->plr->col_y = v->y);
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->rotate_ang)) * distance(s,v)), x); // v.y
	}
}


double	adjust(double i, t_data *mlx)
{
	if (i < 0.0)
		return (0);
	if (i > mlx->w_height)
		return (mlx->w_height - 1);
	return (i);
}
void	render_wall(t_data *mlx, double dis, int x)
{
	double		prc_plane;
	double		wall_st_height;
	t_point		*s;
	t_point		*f;

	prc_plane = (mlx->w_width / 2) / tan(to_rad(30));
	wall_st_height = (TILE_SIZE / dis) * prc_plane;
	s = gc(sizeof(t_point) , 0);
	f = gc(sizeof(t_point) , 0);
	mlx->txtr->wall_height = wall_st_height;
	s->y = adjust((mlx->w_height / 2) - (wall_st_height / 2), mlx);
	f->y = adjust((mlx->w_height / 2) + (wall_st_height / 2), mlx);
	s->x = x;
	f->x = x;
	draw_line(s, f, mlx);
}

void	  render_walls(t_data *mlx)
{
	double	ang_step;
	double	cur_ang;
	int		i;

	i = -1;
	ang_step = (60.0 / mlx->w_width);
	cur_ang = mlx->plr->rotate_ang - 30;
	while (++i < mlx->w_width)
	{
		cast_ray(mlx, cur_ang, i);
		cur_ang += ang_step;
	}
}
