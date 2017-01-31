/*  Boolector: Satisfiablity Modulo Theories (SMT) solver.
 *
 *  Copyright (C) 2015-2016 Aina Niemetz.
 *
 *  All rights reserved.
 *
 *  This file is part of Boolector.
 *  See COPYING for more information on using this software.
 */

#ifndef BTORDC_H_INCLUDED
#define BTORDC_H_INCLUDED

#include "btortypes.h"

void btor_compute_scores (Btor* btor);
void btor_compute_scores_dual_prop (Btor* btor);

int btor_compare_scores (Btor* btor, BtorNode* a, BtorNode* b);
int btor_compare_scores_qsort (const void* p1, const void* p2);
#endif
