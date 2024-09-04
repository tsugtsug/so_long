/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:07:22 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:12:46 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_after_percent(char itr, va_list ap)
{
	int	res;

	res = 0;
	if (itr == '%')
		res += ft_putchar_p('%');
	else if (itr == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (itr == 'c')
		res += ft_putchar_p(va_arg(ap, int));
	else if (itr == 'd' || itr == 'i')
		res += ft_putnbr(va_arg(ap, int));
	else if (itr == 'u' )
		res += ft_put_decimal(va_arg(ap, unsigned int));
	else if (itr == 'x')
		res += ft_put_hexlower(va_arg(ap, unsigned int));
	else if (itr == 'X')
		res += ft_put_hexupper(va_arg(ap, unsigned int));
	else if (itr == 'p')
		res += ft_putaddr(va_arg(ap, void *));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	char	*itr;
	int		res;
	va_list	ap;

	va_start(ap, format);
	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	while (*itr)
	{
		if (*itr == '%')
		{
			itr++;
			res += ft_after_percent(*itr, ap);
		}
		else
			res += ft_putchar_p(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
