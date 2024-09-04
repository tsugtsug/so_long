/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:02:46 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:12:20 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_extra(int nbr, int res)
{
	int		div;
	int		mod;

	div = nbr / 10;
	mod = nbr % 10;
	if (div != 0)
		res = ft_putnbr_extra(div, res);
	res += ft_putchar_p(mod + '0');
	return (res);
}

int	ft_putnbr(int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		res += ft_putstr("-2147483648");
	else
	{
		if (nbr < 0)
		{
			res += ft_putchar_p('-');
			nbr *= -1;
		}
		res = ft_putnbr_extra(nbr, res);
	}
	return (res);
}

int	ft_put_decimal_extra(unsigned int n, int res)
{
	int		div;
	int		mod;

	div = n / 10;
	mod = n % 10;
	if (div != 0)
		res = ft_put_decimal_extra(div, res);
	res += ft_putchar_p(mod + '0');
	return (res);
}

int	ft_put_decimal(unsigned int n)
{
	int	res;

	res = 0;
	res += ft_put_decimal_extra(n, res);
	return (res);
}
