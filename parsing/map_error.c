/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:58:40 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 14:15:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_lencheck(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr(MAP_ELEM, str[i]))
			ft_raise_error(MAP_ELEM_ERR);
	}
	return (i);
}

void	ft_raise_error(char *err_msg)
{
	printf("%s%s\n", RED, err_msg);
	exit(1);
}