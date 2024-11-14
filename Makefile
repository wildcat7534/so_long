NAME = libso_long.a

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a

HEADERS = so_long.h mlx_linux/mlx.h

SOURCES_SO_LONG = sources_so_long/ft_free_mlx.c sources_so_long/ft_make.c \
				sources_so_long/ft_parser.c sources_so_long/ft_perso_key.c sources_so_long/ft_perso_mouse.c \
				sources_so_long/ft_player.c sources_so_long/ft_printer.c sources_so_long/ft_verif_map.c \
				sources_so_long/ft_verif.c sources_so_long/ft_init.c sources_so_long/ft_perso_key2.c \

OBJECTS = $(SOURCES_SO_LONG:.c=.o)

PROGRAM = so_long.c

PROGRAMME_OUT = so_long

CFLAGS = -Werror -Wall -Wextra -g3 -Imlx_linux

LDFLAGS = -Lmlx_linux -lmlx -lX11 -lXext

CC = cc

AR = ar rcs

RM = rm -f

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(PROGRAMME_OUT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAMME_OUT): $(LIBFT) $(OBJECTS)
	@echo "              $(YELLOW) **** >>>>> Compiling: $(INFO) <<<<< **** $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(PROGRAM) $(OBJECTS) $(LDFLAGS) -L$(LIBFT_DIR) -lftprintf -o $(PROGRAMME_OUT)
	@echo ""
	@echo ""
	@echo "$(GREEN)          () () $(DEF_COLOR)"
	@echo "$(GREEN)          (>.<) $(DEF_COLOR)"
	@echo "$(GREEN)          ( . ) $(DEF_COLOR)"
	@echo "$(GREEN)           n_n  $(DEF_COLOR)"
	@echo "$(MAGENTA)>>>>> $(INFO) compiled!$(DEF_COLOR)"

clean:
	$(RM) $(OBJECTS) $(NAME) $(PROGRAMME_OUT)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(MAGENTA)CLEAN OBJECTS FOR :  $(OBJECTS) ! $(DEF_COLOR)"
	
fclean: clean
	$(RM) $(PROGRAMME_OUT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(MAGENTA)CLEAN NAME FOR :  $(OBJECTS) ! $(DEF_COLOR)"

re: fclean all

.PHONY: clean fclean all re bonus
