/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:40:17 by wkrippne          #+#    #+#             */
/*   Updated: 2023/01/05 11:40:17 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_check(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = count + (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		count = count + (ft_printstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		count = count + (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		count = count + (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		count = count + (ft_puthexlow(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		count = count + (ft_puthexup(va_arg(args, unsigned int), 0));
	else if (c == 'p')
		count = count + (ft_putpointer(va_arg(args, unsigned long long)));
	else if (c == '%')
	{
		count++;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_check(str[i], args);
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	printf("%d\n", ft_printf("%5c|\n", 'p'));
	printf("%d\n", printf("%5c|\n", 'p'));
}*/