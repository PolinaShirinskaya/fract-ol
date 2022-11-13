/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:37:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	end_program(t_fractol *fractol)
{
	free_fractol(fractol);
	return (0);
}

double	ft_double_digit(const char *str)
{
	double	d1;
	double	d2;
	char	*c;
	int		len;

	c = (char *)str;
	d1 = (double)ft_atoi(c);
	while (c && *c != '.' && *c)
		c++;
	if (c && *c == '.')
		c++;
	d2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		d2 /= 10;
	if (d1 >= 0 && str[0] != '-')
		return (d1 + d2);
	else
		return (d1 - d2);
}

void	print_help_mess(void)
{
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("--------------- Help information ----------------\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("Enter name of the fractal from the proposed list:\n", 1);
	ft_putstr_fd("\n  1. Mandelbrot\n", 1);
	ft_putstr_fd("\n  2. Julia\n", 1);
	ft_putstr_fd("\n  3. Burning ship\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("Launch example: ./fractol Mandelbrot\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("The julia fractal can be run with two or one parameter.", 1);
	ft_putstr_fd("\nLaunch example: ./fractol Julia -1.1 0.3\n", 1);
	ft_putstr_fd("\nLaunch example: ./fractol Julia -1.1\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
}
