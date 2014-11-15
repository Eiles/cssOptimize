//
//  tags.c
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "tags.h"

t_tag* list_tag_create(char* name,t_properties* props){
    t_tag* list=(t_tag*)malloc(sizeof(t_tag));
    list->name=my_strcpy(name);
    list->props=props;
    list->next = NULL;
    return list;
}

void list_tag_display(t_tag* list){
    if(list==NULL)
        return;
    printf("%s{\n",list->name);
    list_prop_display(list->props);
    printf("}\n");
    if(list->next != NULL)
        list_tag_display(list->next);
}

unsigned int list_tag_size(t_tag* maillon){
    unsigned int i=0;
    if((maillon) == NULL)
        return i;
    while ((maillon)!=NULL) {
        i++;
        (maillon)=(maillon)->next;
    }
    return i;
}

void list_tag_remove_index(t_tag** list, unsigned int index){
    t_tag* f=*list;
    t_tag* tmp;
    if(index>=list_tag_size(*list)){
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

void list_tag_append(t_tag** list, char* name, t_properties* props){
    t_tag* m= list_tag_create(name, props);
    t_tag* tmp=(*list);
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

void list_tag_remove_all_prop_by_prop_value(t_tag** list, char* prop, char* value){
    t_tag* m=(*list);
    while(m!=NULL){
        list_prop_remove_by_prop_value(&m->props,prop,value);
        m=m->next;
    }
}

void list_tag_insert(t_tag** list, unsigned int index, char* name,t_properties* props){
    t_tag* m= list_tag_create(name, props);
    t_tag* tmp=(*list);
    if(index>list_tag_size(*list)+1){
        list_tag_append(list,name,props);
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

int list_tag_get_by_name(t_tag* maillon,char* name){
    int i=0;
    if(maillon == NULL)
        return -1;
    while (maillon!=NULL) {
        if(my_strcmp(maillon->name,name)==0){
            return i;
        }
        i++;
        maillon=maillon->next;
    }
    return -1;
}

char* list_tag_get_all_with_prop_value(t_tag* maillon,char* prop,char* value){
    char* string=malloc(sizeof(char)*1);
    string[0]='\0';
    int first=1;
    if(maillon == NULL)
        return string;
    while (maillon!=NULL) {
        if(list_prop_get_by_prop_value(maillon->props, prop, value)!=-1){
            if(first){
                string=my_strcpy(maillon->name);
                first=0;
            }else{
                string=my_strconcat(string,",");
                string=my_strconcat(string, maillon->name);
            }
        }
        maillon=maillon->next;
    }
    return string;
}

void list_tag_remove_empty_tags(t_tag** list){
    if((*list)==NULL)
        return;
    t_tag*t=(*list);
    int index=0;
    while(t!=NULL){
        if(t->props==NULL){
            t=t->next;
            list_tag_remove_index(list, index);
            index--;
        }
        else{
            t=t->next;
        }
        index++;
    }
}


void list_tag_free(t_tag** maillon){
    t_tag* t;
    while((*maillon)->next!=NULL){
        t=(*maillon)->next;
        free(*maillon);
        maillon=&t;
    }
}