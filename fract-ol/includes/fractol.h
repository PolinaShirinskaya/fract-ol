/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:39:58 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "keycode.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol
{
	void			*mlx;
	void			*wind;
	t_image			img;
	t_complex		max;
	t_complex		min;
	unsigned int	max_iteration;
	t_complex		unit_vector;
	t_complex		k_julia;
	t_complex		vector;
	unsigned char	color_shift;
	unsigned int	((*formula_fractol)(struct s_fractol *fractol));
	int				argc;
	char			**argv;
}				t_fractol;

t_fractol		*malloc_fractol(void);
void			free_fractol(t_fractol *fractol);
int				validation_input_data(int argc, char **argv);
void			parsing_input_data(int argc, char **argv, t_fractol *fractol);
int				error_mess(char *mess, t_fractol *fractol, int code_error);
t_complex		init_complex(double re, double im);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
double			ft_double_digit(const char *str);
void			print_help_mess(void);
void			free_arr_char(char **arr);

void			set_default_fractol(t_fractol *fractol);
void			draw_fractol(t_fractol *fractol);
int				get_color(unsigned int iteration, t_fractol *fracto);

int				zoom(int keycode, int x, int y, t_fractol *fractol);
int				julia_motion(int x, int y, t_fractol *fractol);
int				press_key(int keycode, t_fractol *fractol);

unsigned int	init_mandelbrot(t_fractol *fractol);
unsigned int	init_julia(t_fractol *fractol);
unsigned int	init_burning_ship(t_fractol *fractol);

#endif