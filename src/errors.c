/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:02:31 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/10 18:02:38 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	invalid_arguments(void)
{
	ft_putstr("Error: Please, enter a valid PID and a single message");
		return (1);
}
int	print_invalid_pid(void)
{
	ft_putstr("Error: you provided an invalid PID (-1). This may cause serious issues.\n");
	return (1);
}
