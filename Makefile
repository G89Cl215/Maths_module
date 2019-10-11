# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2019/10/11 14:23:43 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE			=	maths_expansion.c \
					ft_eval.c \
					ft_int64_convert.c \
					maths_dispatcher.c \
					maths_lexer.c \
					maths_token.c \
					operand_token.c \
					parentheses.c \
					ft_build_ast.c\
					ft_itoa64.c \
addition.c \
multiplication.c \
compare.c \
equality_test.c \
logic.c \
bitwise_shifts.c \
bitwise.c \

LIBFILE			=	ft_strlower.c \
					ft_isupper.c

SRC_DIR			=	sources
LIBDIR			=	libft_add

HDR_DIR			=	includes \
					../libft/includes \

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCFILE:.c=.o))
LIBOBJ			=	$(addprefix $(OBJ_DIR)/,$(LIBFILE:.c=.o))

NAME			=	maths_module.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
HFLAGS			=	$(addprefix -I ,$(HDR_DIR))
CFLAGS			+=	$(HFLAGS)
.PHONY: all re clean fclean ls

all				: $(NAME)

$(NAME)			: $(OBJ) $(LIBOBJ) Makefile
	@ar rc $(NAME) $(OBJ) $(LIBOBJ)
	@ranlib $(NAME)
	gcc main_test.c maths_module.a ../libft/libft.a $(HFLAGS)
	@echo "Your LIBFT is ready for use."

$(OBJ)			: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(LIBOBJ)		: $(OBJ_DIR)/%.o : $(LIBDIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)		:
	@/bin/mkdir -p $(OBJ_DIR)


clean			:
	@/bin/rm -Rf $(OBJ_DIR) 2>/dev/null || true

fclean			: clean
	@/bin/rm -f $(NAME)

re				: fclean all
