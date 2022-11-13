NAME		:= calc_plus
CC			:= gcc
LBSD        := $(pkg-config --libs libbsd)
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs
CFLAGS 		:= -Wall -Wextra -Werror

SRCS := main.c \
	calc_plus.c                \
	\
	lexer/token_list_build.c   \
	lexer/token_list_display.c \
	lexer/list/lst_newtok.c    \
	lexer/list/lst_addtok.c    \
	lexer/list/lst_destroy.c   \
	lexer/list/lst_size.c      \
	lexer/is_%/is_cparen.c     \
	lexer/is_%/is_oparen.c     \
	lexer/is_%/is_num.c        \
	lexer/is_%/is_op.c         \
	lexer/is_%/is_space.c      \
	\
	parser/parser.c            \
	parser/syntatic_check.c    \
	parser/ast/ast_create.c    \
	parser/ast/ast_display.c   \
	parser/ast/ast_new_val.c   \
	parser/ast/ast_new_op.c    \
	parser/ast/ast_solve.c     \


