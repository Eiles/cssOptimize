//
//  properties.c
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "properties.h"

t_properties* list_prop_create(char* prop,char* value){
    t_properties* list=(t_properties*)malloc(sizeof(t_properties));
    list->prop=my_strcpy(prop);
    list->value=my_strcpy(value);
    list->next = NULL;
    return list;
}

void list_prop_display(t_properties* list){
    printf("\t%s:%s\n",list->prop,list->value);
    if(list->next != NULL)
        list_prop_display(list->next);
}

unsigned int list_prop_size(t_properties* maillon){
    unsigned int i=0;
    if((maillon) == NULL)
        return i;
    while ((maillon)!=NULL) {
        i++;
        (maillon)=(maillon)->next;
    }
    return i;
}

void list_prop_remove_index(t_properties** list, unsigned int index){
    t_properties* f=*list;
    
    t_properties* tmp;
    if(index>=list_prop_size(*list)){
        return;
    }
    if(index==0){
        (*list)=(*list)->next;
        return;
    }
    
    int i=0;
    while(i<index-1){
        f=f->next;
        i++;
    }
    if(f->next!=NULL)
        tmp=f->next;
    f->next=f->next->next;
    free(tmp);
}

void list_prop_append(t_properties** list, char* prop, char* value){
    t_properties* m= list_prop_create(prop, value);
    t_properties* tmp=(*list);
    if(*list==NULL){
        *list=m;
        return;
    }
    while (tmp->next!=NULL) {
        tmp=tmp->next;
    }
    m->next=tmp->next;
    tmp->next=m;
}

void list_prop_insert(t_properties** list, unsigned int index, char* prop,char* value){
    t_properties* m= list_prop_create(prop, value);
    t_properties* tmp=(*list);
    if(index>list_prop_size(*list)+1){
        list_prop_append(list,prop,value);
        return;
    }
    if(index==0){
        m->next=*list;
        *list=m;
        return ;
    }
    int i=0;
    while (i<index-1 && tmp->next!=NULL) {
        tmp=tmp->next;
        i++;
    }
    m->next=tmp->next;
    tmp->next=m;
}

int list_prop_get_by_prop_value(t_properties* maillon,char* prop, char* value){
    int i=0;
    if(maillon == NULL)
        return -1;
    while (maillon!=NULL) {
        if(my_strcmp(maillon->prop,prop)==0 && my_strcmp(maillon->value,value)==0){
            return i;
        }
        i++;
        maillon=maillon->next;
    }
    return -1;
}
void list_prop_free(t_properties** maillon){
    t_properties* p;
    while((*maillon)->next!=NULL){
        p=(*maillon)->next;
        free(*maillon);
        maillon=&p;
    }
}