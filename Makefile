# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 11:53:18 by bnkosi            #+#    #+#              #
#    Updated: 2019/08/16 06:12:27 by bnkosi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1		=	push_swap

NAME_2		=	checker

LIB_PATH	=	./libft/

FLAGS		=	-Wall -Werror -Wextra

SRC_PATH	=	./src/

OBJ_PATH	=	./obj/

OBJ_DIR			= 	obj

PSSRC		=	$(NAME_1).c\
				make_stacks.c\
				do_instrc.c\
				do_rr.c\
				do_rrr.c \
				begin_sort.c\
				global_sort.c\
				stack_man.c\
				sorterh.c \
				rotation_t.c\
				bst_a_to_b.c
					

CHSRC		=	$(NAME_2).c\
				make_stacks.c\
				do_instrc.c\
				do_rr.c\
				do_rrr.c \
				stack_man.c

CHC = $(addprefix $(OBJ_PATH), $(CHSRC))

PSC = $(addprefix $(OBJ_PATH), $(PSSRC))

CHO = $(patsubst %.c, %.o, $(CHC))

PSO = $(patsubst %.c, %.o, $(PSC))

all: $(NAME_1) $(NAME_2)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIB_PATH)/

$(NAME_1): $(OBJ_DIR) $(PSO) libft
	@gcc $(FLAGS) $(PSO) -L $(LIB_PATH) -lft -o $(NAME_1) 
	@echo "$(NAME_1) Created."

$(NAME_2): $(OBJ_DIR) $(CHO) libft
	@gcc $(FLAGS) $(CHO) -L $(LIB_PATH) -lft -o $(NAME_2) 
	@echo "$(NAME_2) Created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_PATH)/ clean
	@rm -rf $(OBJ_DIR)
	@echo "Objects Files Removed"

fclean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects Files Removed"
	@$(MAKE) -C $(LIB_PATH)/ fclean
	rm -f $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all fclean clean re libft
