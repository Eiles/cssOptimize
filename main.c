//
//  main.c
//  cssOptimize
//
//  Created by Elie Raffier on 24/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "format.h"
#include "parse.h"


int main(int argc, const char * argv[]) {
    /*char s1[4]="foo";
    char s2[4]="bar";
    char s3[4]="o";
    char s4[4]="bar";
    char s[]="azertyuiopqsdfghjklm";*/
    long numbytes=0;
    int i;
    /*printf("Testing my_strlen, length of %s : ",s1);
    printf("%d\n",my_strlen(s1));
    
    printf("Testing my_strconcat, %s + %s : ",s1,s2);
    char* concat=my_strconcat(s1, s2);
    printf("%s\n",concat);
    free(concat);
    
    printf("Testing my_strcmp,  cmp of %s and %s : ",s1,s2);
    printf("%d\n",my_strcmp(s1, s2));
    printf("Testing my_strcmp,  cmp of %s and %s : ",s2,s1);
    printf("%d\n",my_strcmp(s2, s1));
    printf("Testing my_strcmp,  cmp of %s and %s : ",s1,s1);
    printf("%d\n",my_strcmp(s1, s1));
    
    printf("Testing str_search, search of %s in %s : ",s3,s1);
    printf("%d\n",str_search(s1, s3));
    printf("Testing str_search, search of %s in %s : ",s4,s2);
    printf("%d\n",str_search(s2, s4));
    
    printf("Testing my_substr, substring of the %d char of %s  at offset %d: ",4,s,1);
    printf("%s\n",my_substr(s, 4, 1));*/
    
    FILE * css=fopen("./test.css","r");
    fseek(css, 0L, SEEK_END);
    numbytes = ftell(css);
    fseek(css, 0L, SEEK_SET);
    char *buffer = (char*)malloc((numbytes+1)*sizeof(char));
    fread(buffer, sizeof(char), numbytes, css);
    
    buffer[numbytes]='\0';
    /*printf("The file called test.css contains this text\n\n%s", buffer);*/
    buffer = suppressNewline(buffer);
    buffer = suppressSpaceAccol(buffer);
    buffer = suppressSpaceDeuxPoint(buffer);
    buffer = suppressSpacePointVirg(buffer);
    buffer = suppressComments(buffer);
    printf("The file called test.css contains this text\n\n%s", buffer);
    fclose(css);
    t_tag* list=NULL;
    populate_tags(&list,buffer);
    list_tag_display(list);
    free(buffer);
    return 0;
}
