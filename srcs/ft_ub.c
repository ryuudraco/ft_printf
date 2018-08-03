/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:29:51 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 16:31:30 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	ft_length(intmax_t n)
{
	size_t i;

	i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static size_t		ft_ubl(t_char *ract, intmax_t n)
{
	int i;
	int j;

	i = ft_length(n);
	j = 0;
	if (ract->pcsn != -1 && ract->pcsn > i)
	{
		j = (ract->pcsn - i);
		i = ract->pcsn;
	}
	if (i > 0)
		ract->pcsn = j;
	else if (n == 0 && ract->pcsn == 0)
	{
		ract->pcsn = -2;
		i = 0;
	}
	else
		ract->pcsn = -1;
	return (i);
}

static size_t ft_printub(uintmax_t n, t_char *ract)
{
	int len;

	len = 0;
	if (n == 0 && ract->pcsn == -2)
		return (0);
	if (n >= 10)
	{
		len += ft_printub(n / 10, ract);
		len += ft_putchar(n % 10 + 48);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

static int 	ft_manager(t_char *ract, uintmax_t n)
{
	int len;

	len = 0;
	if ((ract->flg)[2] == '0' && ract->pcsn == -1)
		(ract->flg)[0] = '0';
	ract->slen = ft_ubl(ract, n);
	while ((ract->flg[3] != '-' && ract->width > (ract->slen)))
		(len += ft_putchar((ract->flg)[0])) && ract->width--;
	while (ract->pcsn != -1 && ract->pcsn > 0)
		(len += ft_putchar('0')) && ract->pcsn--;
	len += ft_printub(n, ract);
	while (ract->width > ract->slen && (ract->flg)[3] == '-')
		(len += ft_putchar(' ')) && ract->width--;
	return (len);
}

int 		ft_ub(t_char *ract, void *n)
{
	if (ract->spec == 'U')
		return (ft_manager(ract, (unsigned long)n));
	else if (ract->h)
		return (ft_manager(ract, (unsigned short)n));
	else if (ract->hh)
		return (ft_manager(ract, (unsigned char)n));
	else if (ract->l)
		return (ft_manager(ract, (unsigned long)n));
	else if (ract->ll)
		return (ft_manager(ract, (unsigned long long)n));
	else if (ract->z)
		return (ft_manager(ract, (size_t)n));
	else if (ract->j)
		return (ft_manager(ract, (uintmax_t)n));
	else
		return (ft_manager(ract, (unsigned int)n));
}
