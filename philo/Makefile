# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 17:50:17 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/13 15:56:21 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
	check_args.c \
	competition.c \
	ft_atoi.c \
	get_time.c \
	help.c \
	init_philos.c \
	print_status.c \
	supervisor.c \
	main.c

# -fsanitize=thread -lpthread
CFLAGS =  -Wall -Wextra -Werror  
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = philo
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
