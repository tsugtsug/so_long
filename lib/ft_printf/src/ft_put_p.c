/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:01:23 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:13:04 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_hexlower_extra_addr(unsigned long int n, int res)
{
	unsigned long int	div;
	unsigned long int	mod;

	div = n / 16;
	mod = n % 16;
	if (div != 0)
		res = ft_put_hexlower_extra_addr(div, res);
	res += ft_putchar_p(ft_convert_dix_to_lowerseize(mod));
	return (res);
}

int	ft_put_hexlower_addr(unsigned long int n)
{
	int	res;

	res = 0;
	res += ft_put_hexlower_extra_addr(n, res);
	return (res);
}

int	ft_putaddr(void *p)
{
	unsigned long int	addr;
	int					res;

	res = 0;
	addr = (unsigned long int)p;
	res += ft_putstr("0x");
	res += ft_put_hexlower_addr(addr);
	return (res);
}
