/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:21:40 by jheath            #+#    #+#             */
/*   Updated: 2018/08/03 15:40:19 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	ft_length(intmax_t n)
{
	size_t	i;

	i = 1;
	n /= 10;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static size_t	ft_numlen(t_char *ract, intmax_t n)
{
	int		i;
	int		j;

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
	if ((n < 0) || (((ract->flg)[4] == '+' || (ract->flg)[5] == ' ') \
					&& n >= 0))
		i++;
	return (i);
}

static size_t	ft_putnbr(intmax_t n, t_char *ract)
{
	int len;

	len = 0;
	if (n == 0 && ract->pcsn == -2)
		return (0);
	if (n >= -9 && n <= 9)
		len += ft_putchar(ABS(n) + 48);
	else
	{
		len += ft_putnbr(n / 10, ract);
		len += ft_putnbr(n % 10, ract);
	}
	return (len);
}

static int		ft_manager(t_char *ract, intmax_t n, int len)
{
	if ((ract->flg)[2] == '0' && ract->pcsn == -1)
		(ract->flg)[0] = '0';
	ract->slen = ft_numlen(ract, n);
	if (n < 0 && ract->flg[0] == '0')
		len += ft_putchar('-');
	else if (n >= 0 && ract->flg[0] == '0' && ract->flg[4] == '+')
		len += ft_putchar('+');
	else if (ract->flg[0] == '0' && ract->flg[5] == ' ')
		len += ft_putchar(' ');
	while ((ract->flg[3] != '-' && ract->width > (ract->slen)))
		(len += ft_putchar((ract->flg)[0])) && ract->width--;
	if ((ract->flg)[4] == '+' && n >= 0 && ract->flg[0] != '0')
		len += ft_putchar('+');
	else if (n < 0 && ract->flg[0] == ' ' && ract->flg[0] != '0')
		len += ft_putchar('-');
	else if ((ract->flg)[5] == ' ' & n >= 0 && ract->flg[0] != '0')
		len += ft_putchar(' ');
	while (ract->pcsn != -1 && ract->pcsn > 0)
		(len += ft_putchar('0')) && ract->pcsn--;
	len += ft_putnbr(n, ract);
	while (ract->width > ract->slen && (ract->flg)[3] == '-')
		(len += ft_putchar(' ')) && ract->width--;
	return (len);
}

int				ft_nbr(t_char *ract, void *n)
{
	int len;

	len = 0;
	if (ract->spec == 'D')
		ft_manager(ract, (long)n, len);
	else if (ract->h)
		ft_manager(ract, (short)n, len);
	else if (ract->hh)
		ft_manager(ract, (char)n, len);
	else if (ract->l)
		ft_manager(ract, (long)n, len);
	else if (ract->ll)
		ft_manager(ract, (long long)n, len);
	else if (ract->z)
		ft_manager(ract, (size_t)n, len);
	else if (ract->j)
		ft_manager(ract, (intmax_t)n, len);
	else
		ft_manager(ract, (int)n, len);
	return (len);
}
