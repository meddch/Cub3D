# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechane <mechane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 13:40:15 by azari             #+#    #+#              #
#    Updated: 2023/07/22 06:47:41 by mechane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE 		= 	\033[0;35m
CC			= 	cc
GLFW_LIB 		:= $(shell brew --prefix glfw)
CFLAGS		= 	-Wall -Wextra -Werror -Ofast -O3 #-g -fsanitize=address
NAME 		= 	cub3d
LIBFTF	 	= 	libs/libft
GNLF	 	= 	libs/get_next_line
LIBFT		= 	libs/libft/libft.a
GNL			= 	libs/get_next_line/lgnl.a
HEADERS		=	cub3d.h
CFILES		= 	cub3d.c									\
				src/parsing/map_processing.c			\
				src/parsing/map_error.c					\
				src/parsing/ft_utils.c					\
				src/parsing/ft_map_utils.c				\
				src/parsing/parse_token.c				\
				src/rendering/rendering.c				\
				src/rendering/player.c					\
				src/rendering/wall.c					\
				src/rendering/mini_map.c				\
				src/rendering/rendering_utils.c			\
				src/rendering/doors.c					\
				src/rendering/geters.c					\
				src/hooks/moves.c						\
				src/hooks/mouse.c						\
				src/hooks/moves2.c						\
				src/hooks/key.c						\
				src/intersection/horizontal.c			\
				src/intersection/vertical.c				\
				src/textures/textures.c					\
				src/textures/machine_gun.c					\
				src/textures/pistol.c					\
				src/textures/punch.c					\
				libs/gc/gc.c
				
OFILES		= 	$(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	@make -C $(LIBFTF)
	@make -C $(GNLF)
	@$(CC) $(CFLAGS) $(LIBFT) $(GNL)  libs/libmlx42.a -Iinclude -lglfw -L"$(GLFW_LIB)/lib/" $(OFILES) -o $(NAME)
	@echo "$(PURPLE) ✅ cub3D "
	
libs/gc/%.o: libs/gc/%.c libs/gc/gc.h
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $< -o $@
	
%.o:%.c	
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean	:
	@make clean -C $(LIBFTF)
	@make clean -C $(GNLF)
	@rm -rf $(OFILES)
	@echo  "$(PURPLE) ❌ OBJS deleted."

fclean	: clean
	@make fclean -C $(LIBFTF)
	@make fclean -C $(GNLF)	
	@rm -rf $(NAME)
	@echo  "$(PURPLE) ❌ ALL deleted."

norm:
	norminette include/cub3d.h
	norminette ./src
	norminette ./libs
	norminette cub3d.c

re		: fclean all

cl 		: all clean

.PHONY: clean fclean re all cl