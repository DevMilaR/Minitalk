#include "minitalk.h"

void handle_signal(int signal) {
    static int bits = 0;
    static char character = 0;

    if (signal == SIGUSR1)
        character <<= 1;  // Si recibe SIGUSR1, añade un '0' (desplaza a la izquierda)
    else if (signal == SIGUSR2)
        character = (character << 1) | 1;  // Si recibe SIGUSR2, añade un '1'

    bits++;
    if (bits == BYTE_SIZE) {
        if (character == '\0')  // Fin del mensaje
            write(1, "\n", 1);
        else
            write(1, &character, 1);
        bits = 0;
        character = 0;
    }
}

int main(void) {
    int pid;

    pid = getpid();
	ft_printf("SUCCESS!, Server is ready :D! The PID: %d\n", pid);
	ft_printf("Waiting fot the string...\n");

    // Configurar manejadores de señales
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    // Espera señales indefinidamente
    while (1)
        pause();

    return 0;
}