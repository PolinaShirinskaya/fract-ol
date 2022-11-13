/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:37:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*malloc_fractol(void)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit(error_mess("Error: malloc 'fractol'\n", NULL, 1));
	fractol->mlx = NULL;
	fractol->wind = NULL;
	fractol->img.img = NULL;
	fractol->img.addr = NULL;
	fractol->argv = NULL;
	return (fractol);
}

void	free_fractol(t_fractol *fractol)
{
	if (fractol)
	{
		if (fractol->argv)
			free_arr_char(fractol->argv);
		if (fractol->img.img)
			mlx_destroy_image(fractol->mlx, fractol->img.img);
		if (fractol->wind)
			mlx_destroy_window(fractol->mlx, fractol->wind);
		free (fractol);
		fractol = NULL;
	}
}

int	error_mess(char *mess, t_fractol *fractol, int code_error)
{
	ft_putstr_fd(mess, 2);
	free_fractol(fractol);
	return (code_error);
}

t_complex	init_complex(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + \
	x * (img->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}
