#ifndef SPRITES_H
# define SPRITES_H

// struct to display the sprites

typedef struct s_sprites
{
	void		*mini_map_blank;
	void		*wall;
	void		*floor;
	char		**arg_sprite;
	t_img		barrel;
	double		x;
	double		y;
	double		zbuffer[WIN_W];
	int			sprite_order[NUM_SPRITE];
	double		sprite_distance[NUM_SPRITE];
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawstartx;
	int			drawendy;
	int			drawendx;
	int			texx;
	int			texy;
	int			num_sprites;
	u_int32_t 	buffer[WIN_H][WIN_W];
}	t_sprites;

#endif