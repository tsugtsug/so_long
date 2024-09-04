/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:13:49 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/16 14:13:28 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_p(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_put_decimal(unsigned int n);
int	ft_convert_dix_to_lowerseize(int mod);
int	ft_put_hexlower(unsigned int n);
int	ft_put_hexupper(unsigned int n);
int	ft_putaddr(void *p);

#endif