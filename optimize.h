//
//  optimize.h
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__optimize__
#define __cssOptimize__optimize__

#include <stdio.h>
#include "tags.h"

void keep_last_prop(t_tag** list);
void factorize(t_tag** list);

#endif /* defined(__cssOptimize__optimize__) */