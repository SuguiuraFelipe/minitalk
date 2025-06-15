/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:04:59 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/15 13:05:07 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		i;
	int		j;
	int		len;
	int		index;
	char	c;
	char	*str;
}			t_data;

void		ft_putstr(char *s);
void		ft_putnbr(int nb);
int			is_numeric(const char *s);
int			ft_strlen(char *s);
int			ft_atoi(const char *s);

#endif