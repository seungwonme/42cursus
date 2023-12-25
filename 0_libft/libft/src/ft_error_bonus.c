/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:12:59 by sunko             #+#    #+#             */
/*   Updated: 2023/12/12 00:13:01 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_error(char *msg)
{
	ft_putendl_fd("\033[0;31mError", STDERR);
	ft_putstr_fd(msg, STDERR);
	ft_putendl_fd("\033[0m", STDERR);
	exit(EXIT_FAILURE);
}
