# Nombre de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#colors 
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0m

# Archivos fuente
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Librería
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos objeto
OBJS_SERVER = $(SRCS_SERVER:.c=.o) 
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Regla principal para compilar todo
all: $(NAME_SERVER) $(NAME_CLIENT)

# Regla para compilar la libft si no está compilada
$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$<$(NC)"
	make -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft Compiled!$<$(NC)"

# Compilar el servidor
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@echo "$(YELLOW)Compiling Server...$<$(NC)"
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Server Compiled!$<$(NC)"

# Compilar el cliente
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@echo "$(YELLOW)Compiling Client...$<$(NC)"
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Client Compiled!$<$(NC)"
	
# Limpiar los archivos objeto
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C $(LIBFT_DIR)

# Limpiar los archivos objeto y ejecutables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(LIBFT_DIR)

# Volver a compilar todo desde cero
re: fclean all

# Evitar que se traten las reglas como archivos
.PHONY: all clean fclean re