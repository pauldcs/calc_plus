/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emitter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:40:29 by pducos            #+#    #+#             */
/*   Updated: 2022/12/01 17:04:10 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int emit_add(int a, int b)
{
	printf("\tadd\t %d, %d\n", a, b);
	return (a + b);
}
int emit_sub(int a, int b)
{
	printf("\tsub\t %d, %d\n", a, b);
	return (a - b);
}
int emit_mul(int a, int b)
{
	printf("\tmul\t %d, %d\n", a, b);
	return (a * b);
}
int emit_div(int a, int b)
{
	printf("\tdiv\t %d, %d\n", a, b);
	return (a / b);
}
int emit_mod(int a, int b)
{
	printf("\tmod\t %d, %d\n", a, b);
	return (a % b);
}
int emit_val(int val)
{
	printf("\tmov\t r8, %d\n", val);
	return (val);
}

int emitter(t_ast *ast)
{
	size_t dst, x, y;
	dst = 0;
	if (ast->kind == EXP_VAL)
	{
		dst = ast->value;
		emit_val(dst);
		return (dst);
	}
	else
	{
		x = emitter(ast->binop.left);
		y = emitter(ast->binop.right);
		if (ast->kind == EXP_ADD) { dst = emit_add(x, y); }
		if (ast->kind == EXP_SUB) { dst = emit_sub(x, y); }
		if (ast->kind == EXP_MUL) { dst = emit_mul(x, y); }
		if (ast->kind == EXP_DIV) { dst = emit_div(x, y); }
		if (ast->kind == EXP_MOD) { dst = emit_mod(x, y); }
	}
	return (dst);
}