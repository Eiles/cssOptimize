//
//  optimize.c
//  cssOptimize
//
//  Created by Elie Raffier on 11/14/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "optimize.h"

void keep_last_prop(t_tag** list){
    t_tag* tmp_tag=(*list);
    t_properties* tmp_prop;
    int index;
    while(tmp_tag!=NULL){
        tmp_prop=tmp_tag->props;
        while(tmp_prop!=NULL){
            if(tmp_prop->next==NULL)
                break;
            if((index=list_prop_get_by_prop(tmp_prop->next,tmp_prop->prop))!=-1){
                printf("%s",list_prop_get_value_by_index(tmp_prop->next, index));
                free(tmp_prop->value);
                tmp_prop->value=list_prop_get_value_by_index(tmp_prop->next, index);
                list_prop_remove_index(&tmp_prop, index+1);
            }
            tmp_prop=tmp_prop->next;
        }
        tmp_tag=tmp_tag->next;
    }
}

/*void factorize(t_tag** list){
    while(){
        
    }
}*/
