DEFAULT_GOAL:=  all

NAME		=	fractol

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc
LIB_DIR		=	./lib

SYS_CAL		=	-lXext -lX11 -lm

MLX_DIR		=	./minilibx
MLX_LIB		=	mlx_Linux
MLX_CAL		=	-L${MLX_DIR} -l${MLX_LIB}

FT_DIR		=	./libft
FT_LIB		=	ft
FT_CAL		=	-L${FT_DIR} -l${FT_LIB}

MAKE_OTR	=	make -C
MAKE_CLEAN	=	make clean -C
MAKE_FCLEAN	=	make fclean -C

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -O3
LIBS		=	${MLX_CAL} ${FT_CAL} ${SYS_CAL}
INCS		=	-I${MLX_DIR} -I${INC_DIR} -I${FT_DIR}
SAN			=	-g3 -fsanitize=address

SRCS		=	ft_atocomplex.c \
				ft_cleaner_memory.c	\
				ft_color_palete.c	\
				ft_fractal_burning_ship.c	\
				ft_fractal_calc.c	\
				ft_fractal_julia.c	\
				ft_fractal_mandelbrot.c	\
				ft_fractal_recalc.c	\
				ft_fractol.c	\
				ft_handler_error_opt_param.c	\
				ft_handler_error.c	\
				ft_handler_hooks.c	\
				ft_handler_opt_parameter.c	\
				ft_handler_parameter.c	\
				ft_handler_translation.c	\
				ft_handler_zoom.c	\
				ft_initializer_hud.c	\
				ft_initializer_fractol.c	\
				ft_initializer_info.c	\
				ft_main.c	\
				ft_printer_help_msg.c	\
				ft_put_hud_to_window.c	\
				ft_put_informantion.c	\
				ft_render_frame.c	\
				ft_render_next_frame.c	\
				ft_utils_window_viewport.c

OBJS		=	${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}

RM			=	@rm -rf

DIR_GUARD	=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			${DIR_GUARD}
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

all:		ft mlx ${NAME}

mlx:
			${MAKE_OTR} ${MLX_DIR}

ft:
			${MAKE_OTR} ${FT_DIR}

san:		${OBJS}
			${CC} ${SAN} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

clean:
			${RM} ${OBJ_DIR}
			${MAKE_CLEAN} ${MLX_DIR}
			${MAKE_CLEAN} ${FT_DIR}

fclean: 	clean
			${RM} ${NAME}
			${MAKE_FCLEAN} ${FT_DIR}

re:			fclean all

.PHONY:		all mlx ft clean fclean re