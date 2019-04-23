# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:12:42 by lgaultie          #+#    #+#              #
#    Updated: 2019/04/23 22:48:42 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS += -Wall -Werror -Wextra
OBJDIR = obj
SRCDIR = src
CONVDIR = conversions
FLAGDIR = flags
LIBDIR	= libft
INCDIR	= $(LIBDIR)
HEAD	= $(SRCDIR)/ft_printf.h

SRCS =	$(LIBDIR)/ft_atoi.c					\
		$(LIBDIR)/ft_bzero.c				\
		$(LIBDIR)/ft_intlen.c				\
		$(LIBDIR)/ft_itoa_base.c			\
		$(LIBDIR)/ft_itoa.c					\
		$(LIBDIR)/ft_memalloc.c				\
		$(LIBDIR)/ft_memset.c				\
		$(LIBDIR)/ft_nb_len_base.c			\
		$(LIBDIR)/ft_putchar.c				\
		$(LIBDIR)/ft_putstr.c				\
		$(LIBDIR)/ft_strcat.c				\
		$(LIBDIR)/ft_strchr.c				\
		$(LIBDIR)/ft_strcmp.c				\
		$(LIBDIR)/ft_strcpy.c				\
		$(LIBDIR)/ft_strdup.c				\
		$(LIBDIR)/ft_strjoin.c				\
		$(LIBDIR)/ft_strlen.c				\
		$(LIBDIR)/ft_strncpy.c				\
		$(LIBDIR)/ft_strndup.c				\
		$(LIBDIR)/ft_strnew.c				\
		$(LIBDIR)/ft_strsub.c				\
		$(LIBDIR)/ft_tolower.c				\
		$(CONVDIR)/ft_c.c					\
		$(CONVDIR)/ft_d_i.c					\
		$(CONVDIR)/ft_f.c					\
		$(CONVDIR)/ft_f2.c					\
		$(CONVDIR)/ft_o.c					\
		$(CONVDIR)/ft_p.c					\
		$(CONVDIR)/ft_s_mode0.c				\
		$(CONVDIR)/ft_s_mode1.c				\
		$(CONVDIR)/ft_u.c					\
		$(CONVDIR)/ft_xx.c					\
		$(FLAGDIR)/ft_accuracy.c			\
		$(FLAGDIR)/ft_f_width_accuracy.c	\
		$(FLAGDIR)/ft_fwp_minus.c 			\
		$(FLAGDIR)/ft_fwp_string.c			\
		$(FLAGDIR)/ft_fwp.c					\
		$(FLAGDIR)/ft_fwp2.c				\
		$(FLAGDIR)/ft_hhh_lll.c				\
		$(FLAGDIR)/ft_plus_minus.c			\
		$(FLAGDIR)/ft_sharp.c				\
		$(FLAGDIR)/ft_width_string_minus.c	\
		$(FLAGDIR)/ft_width.c				\
		ft_printf.c							\
		ft_analyse_format.c					\
		ft_flags.c							\
		ft_which_flag.c						\
		ft_only_conv.c						\
		ft_active_flags.c					\
		ft_flags2.c							\
		ft_disable_flag.c

CFLAGS += -I$(INCDIR)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a

_GREEN=\e[32m
_YELLOW=\e[33m
_BLUE=\e[34m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	printf "compiling... "
	ar rcs $@ $^
	printf "[$(_GREEN)✓$(_END)]\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(LIBDIR)/%.o: $(LIBDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(CONVDIR)/%.o: $(OBJDIR)/$(CONVDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(FLAGDIR)/%.o: $(OBJDIR)/$(FLAGDIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@
	@mkdir $@/$(CONVDIR)
	@mkdir $@/$(FLAGDIR)
	@mkdir $@/$(LIBDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... "
	@rm -rf $(OBJDIR)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean... "
	@rm -rf $(NAME)
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
