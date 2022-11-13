/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:37:43 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractol(t_fractol *fractol)
{
	int	y;
	int	x;
	int	color;

	fractol->unit_vector = init_complex(\
	(fractol->max.re - fractol->min.re) / WIDTH, \
	(fractol->max.im - fractol->min.im) / HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->vector = init_complex(\
			fractol->min.re + x * fractol->unit_vector.re, \
			fractol->max.im - y * fractol->unit_vector.im);
			color = get_color(fractol->formula_fractol(fractol), fractol);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->wind, \
	fractol->img.img, 0, 0);
}
