/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:37:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	change_border(double start, double end, double zoom)
{
	return (start - (start - end) / zoom);
}

int	zoom(int keycode, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	t_complex	window;
	double		zoom;

	zoom = 1;
	window = init_complex(fractol->max.re - fractol->min.re, \
	fractol->max.im - fractol->min.im);
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(\
		fractol->min.re + (double)x * window.re / WIDTH, \
		fractol->max.im - (double)y * window.im / HEIGHT);
		if (keycode == MOUSE_SCROLL_UP)
			zoom = ZOOM_IN;
		else if (keycode == MOUSE_SCROLL_DOWN)
			zoom = ZOOM_OUT;
		fractol->min.re = change_border(mouse.re, fractol->min.re, zoom);
		fractol->min.im = change_border(mouse.im, fractol->min.im, zoom);
		fractol->max.re = change_border(mouse.re, fractol->max.re, zoom);
		fractol->max.im = change_border(mouse.im, fractol->max.im, zoom);
		draw_fractol(fractol);
	}
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->k_julia = init_complex(4 * ((double)x / (double)WIDTH - 0.5), \
	4 * ((double)(HEIGHT - y) / (double)HEIGHT - 0.5));
	draw_fractol(fractol);
	return (0);
}
