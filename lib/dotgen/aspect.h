/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: Details at https://graphviz.org
 *************************************************************************/

#pragma once

typedef struct aspect_t {
    double targetAR;      /* target aspect ratio */
    double combiAR;
    int prevIterations;   /* no. of iterations in previous pass */
    int curIterations;    /* no. of iterations in current pass */
    int nPasses;          /* bound on no. of top-level passes */
} aspect_t;

extern void setAspect(Agraph_t *g, aspect_t*adata);
