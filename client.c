#include "minitalk.h"

void send_char(int pid, char c) {
    int i = BYTE_SIZE;

    while (i--) {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);  // Envía un '1'
        else
            kill(pid, SIGUSR1);  // Envía un '0'
        usleep(100);  // Pausa para que el servidor procese la señal
    }
}

void send_message(int pid, char *message) {
    while (*message) {
        send_char(pid, *message);  // Envía cada carácter
        message++;
    }
    send_char(pid, '\0');  // Envía el carácter nulo para indicar el fin
}

int main(int argc, char **argv) {
    if (argc != 3) {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return 1;
    }

    int pid = ft_atoi(argv[1]);
    char *message = argv[2];

    send_message(pid, message);  // Enviar el mensaje al servidor
    return 0;
}
