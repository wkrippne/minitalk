/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:09:24 by wkrippne          #+#    #+#             */
/*   Updated: 2023/01/08 13:09:24 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned int n, int count)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = ft_puthexup(n / 16, count);
		count = ft_puthexup(n % 16, count);
	}
	else
	{
		write(1, &hex[n], 1);
		count++;
	}
	return (count);
}
