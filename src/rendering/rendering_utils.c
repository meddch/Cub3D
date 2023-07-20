/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:22:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/20 07:28:42 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}


UNI	ft_mlx_put_pixel(mlx_image_t *img, UNI x, UNI y, UNI colour)
{
    UNI    *pixel;

    pixel = (UNI *)&img->pixels[(x + y * img->width) * sizeof(UNI)];
    *pixel = colour;
    return (*pixel);
}

int	color(mlx_texture_t *img, UNI x, UNI y)
{
	UNI	*colour;

	colour = (UNI *)(img->pixels + (x + y * img->width) * sizeof(UNI));
	return (*colour);
}


double	adjust(double i, t_data *mlx)
{
	if (i < 0.0)
		return (0);
	if (i > mlx->w_height)
		return (mlx->w_height - 1);
	return (i);
}
