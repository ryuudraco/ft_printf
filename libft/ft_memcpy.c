/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:24:02 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 10:51:38 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*strd;
	const char	*strs;

	strd = dest;
	strs = src;
	while (n > 0)
	{
		*strd++ = *strs++;
		n--;
	}
	return (dest);
}
