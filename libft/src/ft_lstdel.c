/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:24:23 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:17:15 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next;

	if (alst != NULL && *alst != NULL)
	{
		lst = *alst;
		while (lst)
		{
			if (del != NULL)
				(*del)(lst->content, lst->content_size);
			next = lst->next;
			free(lst);
			lst = next;
		}
		*alst = NULL;
	}
}
