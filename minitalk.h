#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>  // Para usar señales
# include <unistd.h>  // Para write, getpid, pause, etc.
# include <stdlib.h>  // Para malloc y free
# include <stdio.h>   // Para printf (si decides usarlo)

# include "libft/libft.h"   // Incluye tu libft
# include "libft/ft_printf.h"

// Macros
#define BYTE_SIZE 8

// Prototipos de funciones específicas de Minitalk
void send_char(int pid, char c);
void send_message(int pid, char *message);
void handle_signal(int signal);

#endif