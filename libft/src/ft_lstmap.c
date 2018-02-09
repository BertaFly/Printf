/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:47:22 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:20 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	free_willy(t_list **lst)
{
	if (lst == NULL)
		return ;
	if (*lst)
		free_willy(&((*lst)->next));
	free(*lst);
	return ;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*head;

	if (lst && f)
	{
		head = (*f)(lst);
		if (head == NULL)
			return (NULL);
		current = head;
		while (lst->next)
		{
			lst = lst->next;
			current->next = (*f)(lst);
			if (current->next == NULL)
			{
				free_willy(&head);
				return (NULL);
			}
			current = current->next;
		}
		return (head);
	}
	return (NULL);
}
