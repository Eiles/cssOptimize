//
//  properties.h
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__properties__
#define __cssOptimize__properties__

#include "my_string.h"
#include <stdio.h>

#endif /* defined(__cssOptimize__properties__) */

typedef struct s_properties{
    char* prop;
    char* value;
    struct s_properties* next;
} t_properties;

t_properties* list_prop_create(char* prop,char* value);
void list_prop_display(t_properties* list);
unsigned int list_prop_size(t_properties* maillon);
void list_prop_remove_index(t_properties** list, unsigned int index);
void list_prop_append(t_properties** list, char* prop, char* value);
void list_prop_insert(t_properties** list, unsigned int index, char* prop,char* value);
int list_prop_get_by_prop_value(t_properties* maillon,char* prop, char* value);
void list_prop_free(t_properties** maillon);