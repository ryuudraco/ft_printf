/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:05:18 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 15:46:53 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_char(t_char *ract, void *c)
{
	int len;

	len = 0;
	if ((ract->flg)[2] == '0')
		(ract->flg)[0] = '0';
	if ((ract->flg)[3] != '-' && ract->width > 1)
	{
		while (--(ract->width))
			len += ft_putchar((ract->flg)[0]);
	}
	if (ract->spec == 'c' && !ract->l)
		len += ft_putchar((int)c);
	else if (ract->spec == 'C' || (ract->spec == 'c' && ract->l))
		len += ft_putchar((int)c);
	else
		len += ft_putchar(ract->spec);
	if (ract->width > 1 && (ract->flg)[3] == '-')
	{
		while (--(ract->width))
			len += ft_putchar(' ');
	}
	return (len);
}
