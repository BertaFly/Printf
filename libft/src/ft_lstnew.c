/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:32:29 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:20 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_item;

	new_item = (t_list *)malloc(sizeof(*new_item));
	if (!new_item)
		return (NULL);
	if (content == NULL)
	{
		new_item->content = NULL;
		new_item->content_size = 0;
	}
	else
	{
		if ((new_item->content = malloc(content_size)) == 0)
		{
			free(new_item);
			return (NULL);
		}
		ft_memcpy(new_item->content, content, content_size);
		new_item->content_size = content_size;
	}
	new_item->next = NULL;
	return (new_item);
}
