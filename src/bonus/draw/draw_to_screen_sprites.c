#include "cub3d.h"

/*** go the document images/sprites/sprites_col.cub
 *	0 is for R2D2
	4 is for the XWING
***/

void	draw_r2d2_xwing(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 0 || i == 4)
		store_buffer_and_print(data, stripe, color, y);
}

/***go the document images/sprites/sprites_col.cub
 *	2 is for the rolling ball ennemy
***/
void	draw_rolling_ball(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 2 && data->sprites->ennemy.rolling_b_dead == FALSE)
		store_buffer_and_print(data, stripe, color, y);
}

void	draw_darth_vader(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 7 && data->sprites->ennemy.darth_vader == FALSE)
		store_buffer_and_print(data, stripe, color, y);
}

void	draw_stormtrooper(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 8 && data->sprites->ennemy.stormtrooper == FALSE)
		store_buffer_and_print(data, stripe, color, y);
}