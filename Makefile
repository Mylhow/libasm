# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgascon <dgascon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 03:34:09 by dgascon           #+#    #+#              #
#    Updated: 2020/05/25 06:46:45 by dgascon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		=	libasm

PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
SRC_LIST	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
INC_LIST	=	libasm.h

OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRC_LIST:.s=.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INC_LIST))

CC			=	clang #if gcc add -no-pie for run
INCLUDES	=	-I$(PATH_INC)
CFLAGS		=	-Wall -Wextra -Werror

all:	$(NAME)
	@ $(shell mkdir -p test)
	@ printf "\033[1mLibasm \e[0;38;5;82mCompilation\e[0;38;5;82m done.\n\033[0m"

$(NAME): $(OBJS) $(INCS)
	@ ar rc $(NAME).a $(OBJS)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.s $(INCS)
	@ $(shell mkdir -p $(PATH_OBJ))
	@ printf "\033[0mMake \e[38;5;220m$@ \033[0mfrom \e[38;5;220m$<\n"
	@ nasm -f elf64 $(INCLUDES) $< -o $@

clean:
	@ /bin/rm -rf $(PATH_OBJ)
	@ printf "\033[0mDirectory \e[38;5;220m$(PATH_OBJ) \033[0mdeleted !\n"

fclean: clean
	@ /bin/rm -rf $(NAME) $(NAME).a test
	@ printf "\e[38;5;220m$(NAME) \033[0mdeleted !\n"
	@ printf "\e[38;5;220m$(NAME).a \033[0mdeleted !\n"

re: fclean all

run: all
	@ $(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) main.c -L. -lasm 