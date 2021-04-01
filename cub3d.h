/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:36:45 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/01 16:36:57 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "srcs/gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>

# define TW 64
# define TH 64
# define MV_SPEED 0.09
# define ROT_SPEED 0.09
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65363
# define RIGHT 65361
# define ESC 65307
# define SCALE 16

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_data		img;
}				t_mlx;

typedef struct	s_i_pos
{
	int			x;
	int			y;
}				t_i_pos;

typedef struct	s_d_pos
{
	double			x;
	double			y;
}				t_d_pos;

typedef struct	s_player
{
	t_d_pos		dir;
	t_d_pos		plane;
	t_d_pos		pos;
	t_i_pos		map_pos;
	t_i_pos		step;
	char		start_view;
}				t_player;

typedef struct	s_text
{
	char		*path;
	t_data		img;
	int			height;
	int			width;
	double		start_pos;
	t_i_pos		pos;
	int			num;
	double		step;
	uint32_t	color;
}				t_text;

typedef struct	s_spr
{
	t_d_pos		spr;
	t_d_pos		*str;
	t_d_pos		transform;
	t_i_pos		drawstart;
	t_i_pos		drawend;
	t_i_pos		stext;
	int			sscreen;
	int			height;
	int			width;
	double		invdet;
	int			stripe;
	int			tmpsy;
	int			tmpsd;
	int			scol;
}				t_spr;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
	int			color;
}				t_col;

typedef struct	s_pars
{
	int			r1;
	int			r2;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_col		f_col;
	t_col		c_col;
	char		**map;
}				t_pars;

typedef struct	s_ray
{
	t_mlx		mlx;
	t_pars		pars;
	t_player	player;
	t_text		textur;
	t_text		no;
	t_text		so;
	t_text		we;
	t_text		ea;
	t_spr		spr;
	t_mlx		sprite;
	int			maplen;
	char		*str;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		wallx;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	double		olddirx;
	double		oldplanex;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			number;
	int			*order;
	double		*dist;
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
	double		*buffer;

}				t_ray;

int				ft_init_game(t_ray *ray);
void			ft_move(t_ray *ray);
int				ft_press_key(int key, t_ray *ray);
int				ft_unpress_key(int key, t_ray *ray);
int				ft_exit(t_ray *ray);
void			ft_dist(t_ray *ray);
void			ft_route(t_ray *ray);
void			ft_text(t_ray *ray);
void			ft_draw(t_ray *ray, int x, int y);
void			ft_init_spr(t_ray *ray);
void			ft_get_spr(t_ray *ray);
void			ft_get_number(t_ray *ray);
int				ft_maplen(char **map);
void			ft_free_str(char **str);
void			ft_init_pars(t_pars *pars);
int				ft_check_map(char **s);
void			ft_sprite(t_ray *ray);
int				ft_start(t_ray *ray);
int				ft_parser(int fd, t_pars *pars);
void			ft_do_screenshot(t_ray *ray);
int				ft_check_resolution(char *s);
int				ft_screen_resolution(char *s1, char *s2, t_pars *pars);
int				ft_set_texture(char *str, char **path);
int				ft_set_color(char *str, t_col *col);
t_col			ft_init_rgb(int r, int g, int b);
void			ft_init_player(t_ray *ray);
void			pixel_put(t_ray *ray, int x, int y, int color);
void			pixel_put2(t_ray *ray, int x, int y, int color);
unsigned int	ft_get_pixel(t_ray *ray, int x, int y);
void			ft_init(t_ray *ray);
void			ft_print_error(char *str);
void			ft_init_texture(t_text *texture, t_ray *ray);
void			ft_init_texture_sprite(t_ray *ray);

#endif
