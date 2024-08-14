/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_img *canvas, int x, int y, int color)
{
	char	*dest;

	dest = canvas->data + (y * canvas->size_line + x * (canvas->bpp / 8));
	*(unsigned int *)dest = color;
}

void	draw_block(t_master *master, t_img *canvas, t_xy origin)
{
	int				x;
	int				y;
	unsigned int	color;
	int				tex_x;
	int				tex_y;

	y = 0;
	while (y < master->mini_map_step_size_y)
	{
		x = 0;
		while (x < master->mini_map_step_size_x)
		{
			tex_x = (x + origin.x) * master->imgs.wall_img->width / \
										(SCREEN_SIZE_X / MINI_MAP_DIV_X);
			tex_y = (y + origin.y) * master->imgs.wall_img->height / \
										(SCREEN_SIZE_Y / MINI_MAP_DIV_Y);
			color = *(unsigned int *)(master->imgs.wall_img->data + \
					(tex_y * master->imgs.wall_img->size_line \
					+ tex_x * (master->imgs.wall_img->bpp / 8)));
			draw_pixel(canvas, x + origin.x, y + origin.y, color);
			x++;
		}
		y++;
	}
}

void	draw_cross(t_img *canvas, double x, double y, int color)
{
	draw_pixel(canvas, (int)x - 1, (int)y, color);
	draw_pixel(canvas, (int)x - 2, (int)y, color);
	draw_pixel(canvas, (int)x - 3, (int)y, color);
	draw_pixel(canvas, (int)x + 1, (int)y, color);
	draw_pixel(canvas, (int)x + 2, (int)y, color);
	draw_pixel(canvas, (int)x + 3, (int)y, color);
	draw_pixel(canvas, (int)x, (int)y - 1, color);
	draw_pixel(canvas, (int)x, (int)y - 2, color);
	draw_pixel(canvas, (int)x, (int)y - 3, color);
	draw_pixel(canvas, (int)x, (int)y + 1, color);
	draw_pixel(canvas, (int)x, (int)y + 2, color);
	draw_pixel(canvas, (int)x, (int)y + 3, color);
}

void	clear_canvas(int size_x, int size_y, t_img *canvas)
{
	int	i;

	i = 0;
	while (i < size_x * size_y)
		((unsigned int *)canvas->data)[i++] = 0x00000000;
}
