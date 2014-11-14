//
//  my_string.h
//  cssOptimize
//
//  Created by Elie Raffier on 24/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__my_string__
#define __cssOptimize__my_string__

#include <stdio.h>
#include <stdlib.h>

#endif /* defined(__cssOptimize__my_string__) */

int my_strcmp(char*, char*);
int my_strlen(char*);
void to_upper_case(char*);
void to_lower_case(char*);
int str_search(char *, char *);
int my_atoi(char*c);
int is_number(char);
char* my_strcpy(char* s1);
char* my_strconcat(char*,char*);
char* my_striconcat(char*,char*,int);
char* my_substr(char* s1,int n,int offset);