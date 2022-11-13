/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:37:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	init_mandelbrot(t_fractol *fractol)
{
	unsigned int	iteration;
	t_complex		z;

	iteration = 0;
	z = init_complex(fractol->vector.re, fractol->vector.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && \
	iteration < fractol->max_iteration)
	{
		z = init_complex(pow(z.re, 2) - pow(z.im, 2) + fractol->vector.re, \
		2.0 * z.re * z.im + fractol->vector.im);
		iteration++;
	}
	return (iteration);
}
