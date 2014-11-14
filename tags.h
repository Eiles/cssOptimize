//
//  tags.h
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#ifndef __cssOptimize__tags__
#define __cssOptimize__tags__

#include <stdio.h>
#include <stdlib.h>
#include "properties.h"
#include "my_string.h"



typedef struct s_tag{
    char* name;
    t_properties* props;
    struct s_tag* next;
}t_tag;

t_tag* list_tag_create(char* name, t_properties* props);
void list_tag_display(t_tag* list);
unsigned int list_tag_size(t_tag* maillon);
void list_tag_remove_index(t_tag** list, unsigned int index);
void list_tag_append(t_tag** list, char* name, t_properties* props);
void list_tag_insert(t_tag** list, unsigned int index, char* name,t_properties* props);
int list_tag_get_by_name(t_tag* maillon,char* name);
void list_tag_free(t_tag** maillon);
#endif /* defined(__cssOptimize__tags__) */