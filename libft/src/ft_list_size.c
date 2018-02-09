/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:10:45 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:16:06 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	t_list	*lst;
	size_t	i;

	if (begin_list != NULL)
	{
		i = 0;
		lst = begin_list;
		while (lst)
		{
			i++;
			lst = lst->next;
		}
		return (i);
	}
	else
		return (0);
}
