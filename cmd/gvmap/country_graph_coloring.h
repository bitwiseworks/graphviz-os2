/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: Details at https://graphviz.org
 *************************************************************************/

#ifndef COUNTRY_GRAPH_CLUSTERING_H
#define COUNTRY_GRAPH_CLUSTERING_H

#include <sparse/SparseMatrix.h>

enum {DO_SWAPPING = 1, DO_SWAPPING_CHEAP};

void country_graph_coloring(int seed, SparseMatrix A, int **p, real *norm_1);

void improve_antibandwidth_by_swapping(SparseMatrix A, int *p);

#endif
