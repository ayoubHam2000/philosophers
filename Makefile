# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 17:50:17 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/12 18:27:04 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
	_philo/code/init_philos.c \
	_philo/code/competition.c \
	_philo/code/supervisor.c \
	_philo/utils/print_status.c \
	_philo/utils/check_args.c \
	_philo/utils/ft_atoi.c \
	_philo/utils/ft_put_str.c \
	_philo/utils/get_time.c \
	_philo/utils/help.c \
	_philo/utils/ft_usleep.c \
	_philo/main.c

#FILES_BONUS = \

CFLAGS =  -Wall -Wextra -Werror -I includes/
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = philo
BONUS_NAME = philo_bonus

OBJ_DIR = OUT/
OBJ_DIR_BONUS = OUT/bonus/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
#OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(FILES_BONUS:.c=.o))

deps = $(OBJ:.o=.d)
deps_bonus = $(OBJ_BONUS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

##################

# bonus : $(BONUS_NAME)

# $(BONUS_NAME) : $(OBJ_BONUS)
# 	gcc $(OBJ_BONUS) -o $(BONUS_NAME)

# $(OBJ_BONUS) : $(OBJ_DIR_BONUS)%.o : %.c
# 	mkdir -p $(dir $@)
# 	gcc $(CFLAGS) -c $(@:OUT/bonus/%.o=%.c) $(DEPFLAGS) -o $@

# -include $(deps_bonus)

###################

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all
