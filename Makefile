# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 10:28:33 by aperez-b          #+#    #+#              #
#    Updated: 2021/09/21 11:59:14 by aperez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

UNAME = $(shell uname -s)
ECHO = echo
ifeq ($(UNAME), Linux)
	ECHO = echo -e
endif
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libft.h
DIR_M = mandatory
DIR_B = bonus
DIR_A = additional
DIR_OBJ = lib

SOURCE_M =	ft_atoi.c ft_bzero.c	\
	ft_calloc.c ft_putendl_fd.c		\
	ft_itoa.c ft_putchar_fd.c		\
	ft_putstr_fd.c ft_memccpy.c		\
	ft_memchr.c ft_memcmp.c			\
	ft_memcpy.c ft_isalnum.c		\
	ft_isalpha.c ft_isascii.c		\
	ft_isdigit.c ft_isprint.c		\
	ft_memmove.c ft_memset.c		\
	ft_split.c ft_strchr.c			\
	ft_strdup.c ft_strjoin.c		\
	ft_strlcat.c ft_strlcpy.c		\
	ft_strlen.c ft_strmapi.c		\
	ft_strncmp.c ft_strnstr.c		\
	ft_strrchr.c ft_strtrim.c		\
	ft_substr.c ft_tolower.c		\
	ft_toupper.c ft_putnbr_fd.c
	
	

SOURCE_B = ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstsize.c		\
	ft_lstnew.c			\
	ft_lstmap.c

SOURCE_A = ft_putnbr_base_fd.c		\
	ft_putstrn_fd.c ft_max.c		\
	ft_putnchar_fd.c ft_isspace.c	\
	ft_uitoa.c ft_nbrlen.c			\
	ft_strrncmp.c ft_min.c			\
	ft_countchar.c ft_strenlarge.c	\
	ft_recursive_power.c			\
	ft_chartostr.c ft_sqrt.c		\
	ft_euclideandistance.c			\
	ft_newvector.c ft_free_matrix.c	\
	ft_dup_matrix.c ft_atoi2.c		\

SRC_M = $(addprefix $(DIR_M)/, $(SOURCE_M))

OBJ_M =	$(addprefix $(DIR_OBJ)/, $(SOURCE_M:.c=.o))

SRC_B = $(addprefix $(DIR_B)/, $(SOURCE_B))

OBJ_B = $(addprefix $(DIR_OBJ)/, $(SOURCE_B:.c=.o))

SRC_A = $(addprefix $(DIR_A)/, $(SOURCE_A))

OBJ_A =	$(addprefix $(DIR_OBJ)/, $(SOURCE_A:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_A) $(OBJ_B)
	@$(AR) $(NAME) $^

$(OBJ_M): $(SRC_M)
	@$(ECHO) "$(RED)Mandatory objects outdated in libft! Compiling again...$(DEFAULT)"
	$(CC) $(CFLAGS) -c $^
	@mv -f $(SOURCE_M:.c=.o) $(DIR_OBJ)
	@$(ECHO) "$(GREEN)Mandatory Compilation Complete in libft!$(DEFAULT)"

bonus: $(OBJ_M) $(OBJ_B)
	@$(AR) $(NAME) $^

$(OBJ_B): $(SRC_B)
	@$(ECHO) "$(RED)Bonus objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $^
	@mv -f $(SOURCE_B:.c=.o) $(DIR_OBJ)
	@$(ECHO) "$(MAGENTA)Bonus Compilation Complete in libft!$(DEFAULT)"

additional: $(OBJ_A)
	@$(AR) $(NAME) $^

$(OBJ_A): $(SRC_A)
	@$(ECHO) "$(RED)Additional objects outdated in libft! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $^
	@mv -f $(SOURCE_A:.c=.o) $(DIR_OBJ)
	@$(ECHO) "$(MAGENTA)Additional Functions Compilation Complete in libft!$(DEFAULT)"

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in libft...$(DEFAULT)"
	@$(RM) $(OBJ_M) $(OBJ_B) $(OBJ_A)

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)\nChecking norm for libft...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_M) $(SRC_B) $(SRC_A) lib/libft.h

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"
git:
	git add .
	git commit
	git push

.PHONY: all bonus additional clean fclean git norminette re 
