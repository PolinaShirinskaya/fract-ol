FRACTOL		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
LIBRARIES	=	-L./libft -lft
INCLUDES	=	-I./includes

LIBFT		=	./libft/libft.a
HEADER		=	./includes/fractol.h
HEADER_KEYS	=	./includes/keycode.h

SRCS_DIR	=	srcs/
SRCS_LIST	=	fractol.c \
				utils_1.c \
				utils_2.c \
				validation_input_data.c \
				parsing_input_data.c \
				mouse_control.c \
				keyboard_control.c \
				get_color.c \
				fract_mandelbrot.c \
				fract_julia.c \
				fract_burning_ship.c \
				draw_fractol.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS_LIST))

all : ${FRACTOL}

${FRACTOL} : Makefile $(HEADER) $(HEADER_KEYS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLXFLAGS) $(LIBRARIES) $(INCLUDES)
	@printf "'$(FRACTOL)' was compiled\n"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@printf "'libft' was compiled\n"

%.o : $(addprefix $(SRCS_DIR), %.c) $(HEADER) $(HEADER_KEYS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ $(INCLUDES)

clean :
	@make clean -C ./libft
	@rm -rf $(OBJS)
	@printf "'clean' was done\n"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(FRACTOL)
	@printf "'fclean' was done\n"

re : fclean all
	@printf "'re' was done\n"

.PHONY: all clean fclean re bonus