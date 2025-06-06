/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:24:21 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/06 21:50:15 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

unsigned char   bits_to_char(int *arr_bits)
{
    unsigned char   result;
    unsigned int    i;

    result = 0;
    i = 0;
    
    while (i < 8)
    {
        result |= ((arr_bits[i] & 1) << ( 7 - i));
        i++;
    }
    return (result);
}

unsigned char    signal_to_bits(unsigned int signal)
{
    unsigned char   c;
    static unsigned int    i = 0;
    static int arr_bits[8] = {0};

    
    c = '0';

    // printf("%i\n", arr_bits[i]);
    if (signal == SIGUSR1)
        arr_bits[i] = 0;
    else if (signal == SIGUSR2)
        arr_bits[i] = 1;
    else
        return (0);
    i++;
    if (i == 8)
    {
        c = bits_to_char(arr_bits);
        i = 0;
        return (c);
    }
    return (0);
}

#include <signal.h>
#include <stdio.h>

// Funções declaradas (assumindo que já foram definidas acima)
unsigned char signal_to_bits(unsigned int signal);
unsigned char bits_to_char(int *arr_bits);

int main(void)
{
    char c;
    
    c = signal_to_bits(SIGUSR1);
    c = signal_to_bits(SIGUSR2); 
    c = signal_to_bits(SIGUSR1); 
    c = signal_to_bits(SIGUSR2); 
    c = signal_to_bits(SIGUSR1); 
    c = signal_to_bits(SIGUSR2); 
    c = signal_to_bits(SIGUSR2); 
    c = signal_to_bits(SIGUSR1);

    // Após o 8º bit, a função retorna o caractere
    if (c != 0)
        printf("Caractere recebido: %c\n", c);  // Deve imprimir: T
    else
        printf("Ainda não há caractere completo.\n");

    return 0;
}

