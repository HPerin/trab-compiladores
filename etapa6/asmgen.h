/*
 * =====================================================================================
 *
 *       Filename:  asmgen.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29-11-2015 12:52:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lucas Hennemann Perin (lhperin), lhperin@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef ASMGEN_H
#define ASMGEN_H

#include "tac.h"
#include "stdio.h"

void asmgen_run(tac_node_t * root, FILE * out);

#endif
