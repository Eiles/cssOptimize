//
//  main.c
//  cssOptimize
//
//  Created by Elie Raffier on 24/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__main__
#define __cssOptimize__main__

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "format.h"
#include "parse.h"
#include "optimize.h"
#include "optimize.h"
#endif /* defined(__cssOptimize__main__) */

int main(int argc, const char * argv[]) {
    long numbytes=0;
    
    FILE * css=fopen("./test.css","r");
    fseek(css, 0L, SEEK_END);
    numbytes = ftell(css);
    fseek(css, 0L, SEEK_SET);
    char *buffer = (char*)malloc((numbytes+1)*sizeof(char));
    fread(buffer, sizeof(char), numbytes, css);
    fclose(css);
    
    buffer[numbytes]='\0';
    buffer = suppressNewline(buffer);
    buffer = suppressSpaceAccol(buffer);
    buffer = suppressSpaceDeuxPoint(buffer);
    buffer = suppressSpacePointVirg(buffer);
    buffer = suppressComments(buffer);
    
    t_tag* list=NULL;
    populate_tags(&list,buffer);
    keep_last_prop(&list);
    factorize(&list);
    list_tag_remove_empty_tags(&list);

    list_tag_display(list);
    free(buffer);
    return 0;
}
