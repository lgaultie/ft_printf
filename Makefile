# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:12:42 by lgaultie          #+#    #+#              #
#    Updated: 2019/03/07 18:51:28 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = @clang
CFLAGS += -Wall -Werror -Wextra -g3
OBJDIR = obj
SRCDIR = src
LIBDIR	= libft
INCDIR	= $(LIBDIR)
HEAD	= $(SRCDIR)/ft_printf.h

SRCS =	main.c			\
		ft_printf.c		\
		ft_conv_dif.c	\
		ft_conv_s.c		\
		ft_flags.c		\
		ft_flags2.c		\
		ft_accuracy.c

CFLAGS += -I$(INCDIR)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a

_GREEN=\e[32m
_YELLOW=\e[33m
_BLUE=\e[34m
_END=\e[0m

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@printf "compiling... "
	$(CC) -o $@ $^
	@printf "[$(_GREEN)✓$(_END)]\n"

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... "
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJDIR)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean... "
	@make -C $(LIBDIR) fclean
	@rm -f $(NAME)
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
