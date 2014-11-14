//
//  parse.h
//  cssOptimize
//
//  Created by Elie Raffier on 11/7/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__parse__
#define __cssOptimize__parse__

#include <stdio.h>
#include "my_string.h"
#include "tags.h"

#endif /* defined(__cssOptimize__parse__) */

void populate_tags(t_tag**,char* string);
void parseID(t_tag** list,char* string, t_properties* props);