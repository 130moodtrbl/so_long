# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: speters <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 13:03:41 by speters           #+#    #+#              #
#    Updated: 2025/03/28 14:59:56 by speters          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -lm -lX11 -lXext

LIBS = -Lmlx -lmlx

RM = rm -f

SRCS =  srcs/handle_images.c\
	srcs/handle_init.c\
	srcs/handle_input.c\
	srcs/handle_map.c\
	srcs/handle_player.c\
	srcs/handle_quit.c\
	srcs/parse_elements.c\
	srcs/parse_map.c\
	srcs/parse_path.c\
	srcs/sl_helpers.c\
	srcs/sl_utils.c\
	srcs/so_long.c\
	inc/gnl/get_next_line_utils.c\
	inc/gnl/get_next_line.c\
	inc/printf/ft_printf.c\
	inc/printf/print_p.c\
	inc/printf/print_udi.c\
	inc/printf/print_xX.c\
	
SRCS_BONUS = bonus/handle_images_bonus.c\
	bonus/handle_init_bonus.c\
	bonus/handle_input_bonus.c\
	bonus/handle_map_bonus.c\
	bonus/handle_player_bonus.c\
	bonus/handle_quit_bonus.c\
	bonus/parse_elements_bonus.c\
	bonus/parse_map_bonus.c\
	bonus/parse_path_bonus.c\
	bonus/sl_helpers_bonus.c\
	bonus/sl_utils_bonus.c\
	bonus/so_long_bonus.c\
	inc/gnl/get_next_line_utils.c\
	inc/gnl/get_next_line.c\
	inc/printf/ft_printf.c\
	inc/printf/print_p.c\
	inc/printf/print_udi.c\
	inc/printf/print_xX.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MAGENTA=\033[38;5;198m
RESET=\033[0m
BLUE=\033[38;5;109m

all: $(NAME)
	@echo "\n\033[38;5;109m$(NAME) done compiling.$(RESET)" \
		"\n\n⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ\n" \
		"\n\n🚀 $(MAGENTA)SUPERNOVA!$(RESET)\n\n\n" \
		" $(BLUE)| [comm check]\n" \
		" | •\n" \
		" | ••\n" \
		" | •••\n" \
		" | [connection established]$(RESET)\n\n\n\n" \
		"\033[38;5;109m[၊၊||၊]\033[0m This is Hyperstellar base.\n\n" \
		"✩ You are about to launch our Hyperstellar-3000 on a one-way trip to Nova.\n" \
		"	✩ We will communicate for safety. Follow our instructions.\n" \
		"		✩ Make sure to collect fuel.\n" \
		"			✩ We're a go? Over.\n" \
		"\n\n⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ🚀⋆*･ﾟ:⋆*･ﾟ⋆*･ﾟ:⋆*･ﾟ\n"
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(MLX_FLAGS) $(LIBS)
	@echo "\033[38;5;109mso_long_bonus done compiling.$(RESET)"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re