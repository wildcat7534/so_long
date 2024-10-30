# Name of the library and executable
LIBRARY = lib$(NAME).a

NAME = so_long

HEADERS = mlx_linux/mlx.h include/so_long.h include/ft_printf.h include/libft.h

PROGRAM = so_long.c

PROGRAMME_OUT = so_long

ARGS = map.ber

INFO = so_long mlx_linux

SOURCES_LIBFT = sources_ft_printf/ft_printf.c sources_ft_printf/ft_putcharlen.c sources_ft_printf/ft_putnbrhexlen.c \
		sources_ft_printf/ft_putnbrlen.c sources_ft_printf/ft_putptrlen.c sources_ft_printf/ft_putstrlen.c \
		sources_libft/ft_strlen.c sources_libft/ft_atoi.c sources_libft/ft_itoa.c sources_libft/ft_isdigit.c \
		sources_libft/ft_free.c sources_libft/ft_split.c sources_libft/ft_strcmp.c sources_libft/ft_strdup.c \
		sources_libft/ft_strlcpy.c sources_libft/ft_substr.c sources_libft/ft_nb_words.c

SOURCES_PRINTF = sources_ft_printf/ft_printf.c sources_ft_printf/ft_putcharlen.c sources_ft_printf/ft_putnbrhexlen.c \
		sources_ft_printf/ft_putnbrlen.c sources_ft_printf/ft_putptrlen.c sources_ft_printf/ft_putstrlen.c

SOURCES_PROGRAM = so_long.c

# Object files generated from source files
OBJECTS_LIBFT = $(SOURCES_LIBFT:.c=.o) 
OBJECTS_PRINTF = $(SOURCES_PRINTF:.c=.o)
OBJECTS_PROGRAM = $(PROGRAM:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
CFLAGS_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Utility commands
AR = ar rcs
RM = rm -f


# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

all: $(NAME)

# Rule to compile library files into an archive
$(LIBRARY): $(OBJECTS_LIBFT) $(OBJECTS_PRINTF)
	@echo "              $(YELLOW) **** >>>>> Compiling: $(INFO) <<<<< **** $(DEF_COLOR)"
	$(AR) $@ $^
	@echo ""
	@echo ""
	@echo "$(MAGENTA)>>>>> $(INFO) compiled!$(DEF_COLOR)"

# Rule to compile the main program with the library
$(NAME): $(LIBRARY) $(OBJECTS_PROGRAM)
	@echo "              $(YELLOW)**** Compiling: $(NAME) ****$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJECTS_PROGRAM) $(LIBRARY) $(CFLAGS_MLX) -o $(NAME)
	@echo "$(MAGENTA)>>>>> $(NAME) compiled!$(DEF_COLOR)"
	@echo ""
	@echo "$(GREEN)          () ()$(DEF_COLOR)"
	@echo "$(GREEN)          (>.<) $(DEF_COLOR)"
	@echo "$(GREEN)          ( . ) $(DEF_COLOR)"
	@echo "$(GREEN)           n_n $(DEF_COLOR)"
#	$(CC) $(CFLAGS) $(CFLAGS_MLX) $(PROGRAMME) -o $(PROGRAMME_OUT)
	@echo ""
	@echo "$(MAGENTA)>>>>> Programme : $(NAME) compiled!$(DEF_COLOR)"
	@echo ""
#	@echo "$(CYAN)>>>>> Launching $(PROGRAMME_OUT) with arguments : $(ARGS)$(DEF_COLOR)"
	@echo ""
#	./$(PROGRAMME_OUT) $(ARGS)

# Rule to compile individual object files from source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

clean:
	$(RM) $(OBJECTS_LIBFT) $(OBJECTS_PRINTF) $(OBJECTS_PROGRAM)
	@echo "$(MAGENTA)CLEAN OBJECTS FOR :  $(OBJECTS_LIBFT) $(OBJECTS_PRINTF) $(OBJECTS_PROGRAM) ! $(DEF_COLOR)"
	
fclean: clean
	$(RM) $(NAME) $(LIBRARY)
	@echo "$(MAGENTA)CLEAN NAME FOR :  $(OBJECTS) ! $(DEF_COLOR)"


re: fclean all

.PHONY: clean fclean all re
