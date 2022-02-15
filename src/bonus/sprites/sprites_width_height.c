#include "cub3d.h"

/*
Find the lowest and the highest pixel of he sprite
*/

void	lowest_highest_width_pixel(t_sprites *spr)
{
	spr->spritewidth = abs((int)(WIN_H / spr->transformy));
	spr->drawstartx = -spr->spritewidth * 0.5 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawendx >= WIN_W)
		spr->drawendx = WIN_W - 1;
}

/*
Find the lowest and the highest pixel of he sprite
*/

void	lowest_highest_height_pixel(t_sprites *spr)
{
	spr->spriteheight = abs((int)(WIN_H / spr->transformy)) - 20;
	spr->drawstarty = -spr->spriteheight * 0.5 + WIN_H * 0.5;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteheight * 0.5 + WIN_H * 0.5;
	if (spr->drawendy >= WIN_H)
		spr->drawendy = WIN_H - 1;
}
