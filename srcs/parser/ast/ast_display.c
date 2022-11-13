/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:39 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 16:48:54 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include "parser.h"

static void	inner(t_ast *ast, size_t depth);

static const char	*g_ast_names[] = {
	"LPAREN",
	"RPAREN",
	"VAL",
	"MUL",
	"ADD",
	"SUB",
	"DIV",
	"MOD",
	"POW"
};

static void	put_binop(t_ast *ast, size_t depth)
{
	putstr("\n");
	inner(ast->binop.left, depth + 1);
	inner(ast->binop.right, depth + 1);
}

static void	inner(t_ast *ast, size_t depth)
{
	size_t	i;

	i = 0;
	while (i++ < depth)
		putstr("%3s", "");
	if (ast->kind == EXP_VAL)
		putstr("[%s]: '%d'\n", "VAL", ast->value);
	else
		putstr("[%s]", g_ast_names[ast->kind]);
	if (ast->kind == EXP_ADD
		|| ast->kind == EXP_SUB
		|| ast->kind == EXP_MUL
		|| ast->kind == EXP_DIV
		|| ast->kind == EXP_MOD)
		put_binop(ast, depth);
}

void	ast_display(t_ast *ast)
{
	inner(ast, 0);
}