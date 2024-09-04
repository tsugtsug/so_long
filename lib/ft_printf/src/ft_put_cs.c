/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:59:50 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:11:52 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar_p(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	res;

	if (!str)
		return (write(1, "(null)", 6));
	res = 0;
	while (*str)
	{
		res += ft_putchar_p(*str);
		str++;
	}
	return (res);
}
