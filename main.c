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
#include "write.h"
#endif /* defined(__cssOptimize__main__) */

int main(int argc, const char * argv[]) {
    if(argc<2){
        printf("Too few arguments !\n");
        return 1;
    }
    if(my_strcmp(argv[1], "-h")==0){
        printf("-b beautify\n-h display this screen\n");
        return 0;
    }
    int beauty=0;
    if(my_strcmp(argv[1], "-b")==0)
        beauty=1;
    
    if(argc-beauty<3){
        printf("Too few arguments !\n");
        return 1;
    }
    
    long numbytes=0;
    long numbytes2=0;
    FILE * css;
    char* buffer=malloc(sizeof(char));
    buffer[0]='c';
    char* buffer2;
    int i;
    FILE *output;
    for(i=1+beauty; i<argc-1; i++) {
        css=fopen(argv[i],"r");
        if(css==NULL){
            printf("Error: File '%s' not found !", argv[i]);
            return 0;
        }
        fseek(css, 0L, SEEK_END);
        numbytes2=ftell(css);
        numbytes+=numbytes;
        fseek(css, 0L, SEEK_SET);
        buffer2 = (char*)malloc((numbytes2+1)*sizeof(char));
        fread(buffer2, sizeof(char), numbytes2, css);
        buffer2[numbytes2]='\0';
        buffer=my_strconcat(buffer,buffer2);
        free(buffer2);
        fclose(css);
    }
    while(buffer[i]!='\0'){
        if (buffer[i]=='\t'){
            buffer[i]=' ';
        }
        i++;
    }
    buffer = suppressNewline(buffer);
    buffer = suppressSpaceAccol(buffer);
    buffer = suppressSpaceDeuxPoint(buffer);
    buffer = suppressSpacePointVirg(buffer);
    buffer = suppressComments(buffer);
    i=0;
    t_tag* list=NULL;
    populate_tags(&list,buffer);
    keep_last_prop(&list);
    factorize(&list);
    list_tag_remove_empty_tags(&list);
    output=fopen(argv[argc-1], "w");
    if(beauty){
        writeBeautiful(list, output);
    }else{
        writeMinimized(list, output);
    }
    fclose(output);
    list_tag_free(&list);
    free(buffer);
    return 0;
}
