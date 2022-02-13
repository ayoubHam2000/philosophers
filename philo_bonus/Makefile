# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 20:11:08 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/13 15:44:39 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
	check_args.c \
	ft_atoi.c \
	get_time.c \
	help.c \
	print_status.c \
	ft_error.c \
	philo_process.c \
	start_competition.c \
	main.c

CFLAGS = -Wall -Wextra -Werror  -I.
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = philo_bonus
OBJ_DIR = OUT/
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
