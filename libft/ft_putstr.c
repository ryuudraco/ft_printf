/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:08:28 by jheath            #+#    #+#             */
/*   Updated: 2018/08/02 11:55:22 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s, int pcsn)
{
	int		len;
	char	*temp;

	len = 0;
	if (s == NULL)
		return (ft_putstr("(null)", pcsn));
	len = ft_strlenpcsn(s, pcsn);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	ft_strncpy(temp, s, len);
	write(1, temp, len);
	free(temp);
	return (len);
}
