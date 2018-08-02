/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenpcsn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:38:10 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 12:00:55 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenpcsn(const char *s, int pcsn)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] && pcsn--)
			i++;
	}
	return (i);
}
