#ifndef __cssOptimize__write__
#define __cssOptimize__write__

#include <stdio.h>
#include <stdlib.h>
#include "tags.h"
#include "my_string.h"

void writeBeautiful(t_tag*, FILE*);
void writeMinimized(t_tag*, FILE*);

#endif /* defined(__cssOptimize__tags__) */
