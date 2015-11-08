#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdio.h>
#include "ast.h"

void generate_code(FILE       *output,
                   ast_node_t *root);

#endif
