# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 11:27:35 by lgaultie          #+#    #+#              #
#    Updated: 2019/02/28 11:21:20 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = @clang
CFLAGS += -Wall -Werror -Wextra
RUNLIB = ranlib
OBJDIR = obj
SRCDIR = src
LIBDIR = libft
INCDIR = $(LIBDIR)
HEAD = $(SRCDIR)/ft_printf.h

SRCS =	ft_printf.c	\
				main.c

CFLAGS += -I$(INCDIR)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
			$(CC) -o $@ $^
			ar rc $(NAME) $(OBJ)
			$(RUNLIB) $(NAME)

$(LIB):
			@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	 		@mkdir $@

$(OBJ): | $(OBJDIR)

clean:
			@make -C $(LIBDIR) clean
			@rm -rf $(OBJDIR)

fclean: clean
			@make -C $(LIBDIR) fclean
			@rm -f $(NAME)

re: fclean all clean

.PHONY: clean fclean all re
