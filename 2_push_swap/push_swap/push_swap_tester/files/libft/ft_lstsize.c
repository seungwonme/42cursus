/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:43:52 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:46:53 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ans;
	t_list	*temp;

	ans = 0;
	temp = lst;
	while (temp)
	{
		ans++;
		temp = temp->next;
	}
	return (ans);
}