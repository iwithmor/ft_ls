/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:56:08 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/03 14:56:09 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *link;
	t_list *nxt;

	if (!alst || !*alst || !del)
		return ;
	link = *alst;
	while (link)
	{
		nxt = link->next;
		del(link->content, link->content_size);
		free(link);
		link = nxt;
	}
	*alst = NULL;
}
