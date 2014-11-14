//
//  format.h
//  cssOptimize
//
//  Created by Elie Raffier on 26/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__format__
#define __cssOptimize__format__

#include <stdio.h>
#include "my_string.h"



char* suppressNewline(char* string);
char* suppressSpaceAccol(char* string);
char* suppressSpaceDeuxPoint(char* string);
char* suppressSpacePointVirg(char* string);
char* suppressComments(char* string);

#endif /* defined(__cssOptimize__format__) */