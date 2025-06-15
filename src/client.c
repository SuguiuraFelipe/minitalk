/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:05:41 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/15 13:05:50 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	wake_up(int sig)
{
	(void)sig;
}

void	send_len(int len, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((len >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5000);
		i--;
	}
}

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5000);
		i--;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig_struct;
	int					i;
	int					sv_pid;

	if (ac != 3 || !is_numeric(av[1]))
		return (1);
	sv_pid = ft_atoi(av[1]);
	if (sv_pid < 1)
		return (1);
	sig_struct.sa_handler = wake_up;
	sig_struct.sa_flags = 0;
	sigemptyset(&sig_struct.sa_mask);
	sigaction(SIGUSR1, &sig_struct, NULL);
	i = 0;
	send_len(ft_strlen(av[2]) + 1, sv_pid);
	while (av[2][i])
	{
		send_char(av[2][i], sv_pid);
		i++;
	}
	return (0);
}