# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    READ_ME.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 15:59:37 by tgouedar          #+#    #+#              #
#    Updated: 2019/10/11 17:50:18 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MATHS MODULE

#include "maths_module.h"

I.Purpose

This module is meant to be part of the larger 42sh project I worked on with 4
other students of the 42 school.
It will interpret arithmetic tokens contained in $(( )) delimiters.

It is fully independant and can be called in the shell by invocking
maths_expansion function:

int			maths_expansion(char *to_expand, char **return_str);

o> to_expand: parameter to expand, without the surrounding $(( )) delimiters.
o> return_str: pointer to the string the module must fill as it interprets
to_expand. The pointer must not containt important informations as the first
step is to set it to point on NULL. As such, any mallocated memory would be lost.

As in bash, it uses 64bits signed intergers with no regards to owerflow. It also
recognizes hexa or octal if the number is prefixed with the base ("0" for octal,
"0X" or "0x" for hexa) or a base of any length as described in bash manual pages
92 and 93 (i.e. number must be written in the baslen#nbr format). It is also
able to get, set or modify shell variables (once this part of the shell is
integrated in the module).
Unlike bash, it doesn't (yet ?) interpret floats or ternary expressions.

II.ERRORS

When expansion fails, return_str wil point to NULL and the module will return
MATHS_ERROR (macro defined in the maths_module so you can us).
This module may fail in a number of ways:

o> Syntax error is the most common: your the expression you've given it or one
of the shel variable it expanded is just mathematically wrong. (two operands
	without an operator, or the contrary, )
o> Division by zero: Does it really need an explanation ?
o> Exponentiation with negative exponent: no floats ! Plus, its a real pain to
	deal with.
o> Value too great for base: In a given base of n length, the base digits are
	the first n symbols of the following sequence:
	"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@_". If one
	of the number digit rank in the sequence above exceeds n, or if the symbol
	isn't in the sequence at all, this error is thrown. If n is inferior or
	equal to 36 (i.e. upper case alphabet is not used in your base) upper case
	letters are interpreted as their lower case counterpart.
o> Invalid arithmetic base: a base length must be set between 2 (Dude really ?
	counting only zero with zeros) and 64 included (you're a madman if you need
	any more ! 64 is already a stretch...) since we only recognize 64 base
	symbols.
o> Parentheses error: It should not occur as a proper shell checks for this
	parsing/lexing error before sending tokens to this module, But a check is
	stil implemented in the module.
o> Invalid number: You did not prototype your number the right way (exemple 2
	'#'symbols in a single number token)

III.NOTA BENE

This piece of code uses functions that can be found in my libft, which is a
library of standard functions mandatory to any student of 42. Mine was enhanced,
as anyone should have, with a few of my own functions. Thus I recommand using
my lib.
