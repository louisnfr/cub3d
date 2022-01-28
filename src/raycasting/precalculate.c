/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/28 18:44:49 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		precalculate_rays(t_data *data)
{
	double posX = data->player_x, posY = data->player_y;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	int	x;

	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
		&data->mlx->length, &data->mlx->endian);
	x = -1;
	while (++x < WIN_W)
	{
		double camx = 2 * x / (double)WIN_W - 1;
		double rayDirX = dirX + planeX * camx;
		double rayDirY = dirY + planeY * camx;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double distX;
		double distY;
		double perpWallDist;

		int hit = 0;
		int	side;
		int	stepX;
		int	stepY;

		if (rayDirX < 0)
		{
			stepX = -1;
			distX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			distX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			distY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			distY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(distX < distY)
			{
				distX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				distY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(data->map->tab[mapX][mapY] > '0') hit = 1;
		}
		if(side == 0)
			perpWallDist = (distX - deltaDistX);
		else
			perpWallDist = (distY - deltaDistY);

		int lineHeight = (int)(WIN_H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_H / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_H / 2;
		if(drawEnd >= WIN_H) drawEnd = WIN_H - 1;

		int color;
		switch(data->map->tab[mapX][mapY])
		{
			case '1':  color = RED;    break; //red
			case '2':  color = GREEN;  break; //green
			case '3':  color = BLUE;   break; //blue
			case '4':  color = WHITE;  break; //white
			default: color = YELLOW; break; //yellow
		}

		if(side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		t_point a = {drawStart, drawEnd};
		put_vline(x, a, color, data->mlx);
		// verLine(x, drawStart, drawEnd, color);
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (SUCCESS);
}
