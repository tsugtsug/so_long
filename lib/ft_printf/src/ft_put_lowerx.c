/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lowerx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:11:36 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:12:56 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_convert_dix_to_lowerseize(int mod)
{
	if (mod > 9)
		return (mod - 10 + 'a');
	else
		return (mod + '0');
}

int	ft_put_hexlower_extra(unsigned int n, int res)
{
	int		div;
	int		mod;

	div = n / 16;
	mod = n % 16;
	if (div != 0)
		res = ft_put_hexlower_extra(div, res);
	res += ft_putchar_p(ft_convert_dix_to_lowerseize(mod));
	return (res);
}

int	ft_put_hexlower(unsigned int n)
{
	int	res;

	res = 0;
	res += ft_put_hexlower_extra(n, res);
	return (res);
}
