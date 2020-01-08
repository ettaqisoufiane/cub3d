/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:58:10 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:20:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include "../GNL/get_next_line.h"
# define FOV 60
# define PI M_PI
# define DEG(x) x * PI / 180
# define RADTODEG(x) x * 180 / PI
# define MAXWIDTH 2560
# define MAXHEIGHT 1440
# define SUCCESS 0
# define FAIL 1

typedef struct		s_colorinfo
{
	short int		color1;
	short int		color2;
	short int		color3;
}					t_colorinfo;

typedef struct		s_imagedata
{
	char			*dataimage;
	int				tx_bpp;
	int				tx_sl;
	int				tx_end;
}					t_imagedata;

typedef struct		s_voidimage
{
	void			*image;
	int				textureheight;
	int				texturewidth;
}					t_voidimage;

typedef struct		s_wallinfo
{
	float			horix;
	float			horiy;
	float			vertx;
	float			verty;
}					t_wallinfo;

typedef struct		s_sprite_1
{
	float			m2;
	float			b2;
	float			m1;
	float			b1;
	float			x;
	float			y;
}					t_sprite_1;

typedef struct		s_sprite
{
	float			m1;
	float			m2;
	float			m3;
	float			b1;
	float			b2;
	float			b3;
	float			r;
	float			x;
	float			y;
	float			delta;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
}					t_sprite;

typedef struct		s_pntsprite
{
	float			pnt1;
	float			pnt2;
}					t_pntsprite;

typedef struct		s_dataview
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	float			gridx;
	float			gridy;
	int				rotatelen;
	int				firstime;
	char			**map;
	int				mapheight;
	int				mapwidth;
	int				maxheight;
	int				maxwidth;
	float			y;
	float			x;
	float			directionoriginx;
	float			directionoriginy;
	float			directionx;
	float			directiony;
	float			angle;
	int				speed;
	int				totalrays;
	int				movpressed;
	int				movkey_1;
	int				movkey_2;
	int				anglepressed;
	int				angkey_1;
	int				angkey_2;
	void			*image_ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	float			ccx;
	float			ccy;
	float			rrx;
	float			rry;
	float			mmx;
	float			mmy;
	float			bbx;
	float			bby;
	float			wallx;
	float			wally;
	float			ax;
	float			ay;
	float			ya;
	float			xa;
	float			cx;
	float			cy;
	float			by;
	float			bx;
	float			walldistance;
	float			distproplane;
	float			wallheight;
	int				start;
	int				end;
	int				firsthitsprite;
	char			*sprite;
	char			*north;
	char			*west;
	char			*south;
	char			*east;
	t_colorinfo		*floor;
	t_colorinfo		*ceil;
	t_voidimage		*image;
	t_voidimage		*image_1;
	t_voidimage		*image_2;
	t_voidimage		*image_3;
	t_voidimage		*image_4;
	t_imagedata		*image_data;
	t_imagedata		*image_data_1;
	t_imagedata		*image_data_2;
	t_imagedata		*image_data_3;
	t_imagedata		*image_data_4;
	t_imagedata		*currentimage;
	t_voidimage		*currentimage_1;
	int				isvert;
	int				ishort;
	float			spritex;
	float			spritey;
	float			newspritex;
	float			newspritey;
	int				i;
	int				signalsp;
	float			pwpp;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			a;
	float			b;
	float			c;
	float			ang;
	float			sprite_x;
	float			sprite_y;
	float			camerax;
	float			cameray;
	int				startgame;
	int				saveimage;
	int				ut;
}					t_dataview;

int					initgame(t_dataview *data);
int					setupimages_andupdates(t_dataview *data);
int					checkforupdates(t_dataview *params);
void				initmap(t_dataview *data, char **argc, int argv);

void				getrayvectors(t_dataview *data, int sizeline, int bpp);
void				upangle(t_dataview *data, float ang);
void				downangle(t_dataview *data, float ang);
void				rightangle(t_dataview *data, float ang);
void				leftangle(t_dataview *data, float ang);
void				getwallcoordinates(t_dataview *data, int angl);
void				wallinfo(t_dataview *data, t_wallinfo *coor);
void				drawalls(t_dataview *data, float angle, int i);
void				my_pixel_put_to_image(t_dataview *data
					, int x, int y, t_colorinfo *color);
float				absff(float a);
int					checkwalls(t_dataview *data, float vecx, float vecy, int c);
void				initraypoints(t_dataview *data);
void				updateplayerposition(t_dataview *data);
void				updatedirectionplayer(t_dataview *data);
void				wallinfo(t_dataview *data, t_wallinfo *coor);
int					anglecalcul(float ang, int c, t_dataview *data);
void				treatfilecontent(int fd, t_dataview *data);
void				upangle_1(t_dataview *data, float ang);
void				downangle_1(t_dataview *data, float ang);
void				rightangle_1(t_dataview *data, float ang);
void				leftangle_1(t_dataview *data, float ang);
void				getwallcoordinates1(t_dataview *data, int angl);
void				wallinfo1(t_dataview *data, t_wallinfo *coor);
void				drawsprite_1(t_dataview *data, int i);
void				sumupanddown(t_dataview *data, int c, float ang);
void				sumupanddown_1(t_dataview *data, int c, float ang);
void				sumrightandleft(t_dataview *data, int c, float ang);
void				sumrightandleft_1(t_dataview *data, int c, float ang);
int					checkpoints(t_dataview *data, int cas);
int					checkpoints_2(t_dataview *data, int cas);
void				handle_walls(t_dataview *data, float *ang);
void				handle_sprite(t_dataview *data, float *ang);
void				start_drawsprite(t_dataview *data,
					t_pntsprite *pnts, int i);
void				settextureimage_getadd(t_dataview *data);
void				getimagevoid(t_voidimage *image,
					char *path_image, t_dataview *data);
void				settextureimage(t_dataview *data);
void				getimagedata(t_imagedata *imagedata, void *image);
int					key_release(int key, t_dataview *params);
int					key_pressed(int key, t_dataview *params);
void				init_data_(t_dataview *data, int sizeline, int bpp);
int					exit_button(void);
void				setpnts(t_dataview *data, t_pntsprite *pnts);
void				freelist(void *data);
t_pntsprite			*jointwopoints(float pnt1, float pnt2);
int					checkwalls_facing(t_dataview *data, float vecx
					, float vecy, int c);
int					checkwalls_back(t_dataview *data, float vecx
					, float vecy, int c);
void				drawsprite_2(t_dataview *data, int x, t_colorinfo *color);
void				exiterror(char *error, int errorn,
					t_dataview *data);
void				checkfilename(char *filename, t_dataview *datad);
void				getresolution(char **arrline, t_dataview *data);
void				getpaths(char **arrline, t_dataview *data, int b);
void				getflandcecolor(char **arrline, t_dataview *data, int n);
void				treatfilecontent_2(t_dataview *data, char **arrline, int i);
void				setthemap(t_dataview *data, t_list **list);
void				getmap(char *line, t_list **list);
void				drawsprite_5(t_dataview *data, int i);
void				angle_z_pi(t_dataview *data, int i);
void				allangles_1(t_dataview *data, int i, t_sprite *sprt);
void				allangles(t_dataview *data, int i, t_sprite *sprt);
void				calculscirclepoints(t_dataview *data, t_sprite *sprt);
void				handleallerrors(t_dataview *data);
void				handlewallsandspritetexture(t_dataview *data);
void				getcolors_(t_dataview *data, t_colorinfo *color
					, int x, int y);
void				getcurrenttexture(t_dataview *data, int *offset);
void				drawtexture(t_dataview *data, int x, t_colorinfo *color);
void				free_all(t_dataview *data);
void				free_after_splitting(char ***data);
void				saveimage(t_dataview *data);
void				setthemap_4(t_list **list);
void				treatfilecontent_4(char **line, char ***arrline, int c);
void				beforeexit(t_dataview *data);
void				checkmapwalls(t_dataview *data);
void				getfloandcecolors_2(int n, t_dataview *data
					, t_colorinfo *colors);
int					getplayerposition_1(t_dataview *data, float x, float y);
int					valuergbchecker(char *value, t_dataview *data);

#endif
