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
                free(tmp_prop->value);
                tmp_prop->value=list_prop_get_value_by_index(tmp_prop->next, index);
                list_prop_remove_index(&tmp_prop, index+1);
            }
            tmp_prop=tmp_prop->next;
        }
        tmp_tag=tmp_tag->next;
    }
}

void factorize(t_tag** list){
    t_tag* tmp_tag=(*list);
    t_tag* tmp_tag_travel=NULL;
    t_properties* tmp_prop=NULL;
    t_properties* facto_prop=NULL;
    char* new_tag_name=NULL;
    int k;
    int index;
    while(tmp_tag!=NULL){//On parcourt toute la liste pour vérifier qu'il n'y a pas de doublons de prop
        tmp_prop=tmp_tag->props;
        while(tmp_prop!=NULL){
            list_prop_remove_index(&facto_prop,0);
            list_prop_append(&facto_prop,tmp_prop->prop, tmp_prop->value);
            tmp_prop=tmp_prop->next;
            new_tag_name=list_tag_get_all_with_prop_value(tmp_tag,facto_prop->prop, facto_prop->value);
            list_tag_remove_all_prop_by_prop_value(&tmp_tag,facto_prop->prop, facto_prop->value);
            if(list_tag_get_by_name(*list, new_tag_name)==-1){
                list_tag_insert(list, 0, new_tag_name, facto_prop);
            }else{
                tmp_tag_travel=(*list);
                index=list_tag_get_by_name(*list, new_tag_name);
                for(k=0;k<index;k++){
                    tmp_tag_travel=tmp_tag_travel->next;
                }
                list_prop_insert(&tmp_tag_travel->props,0,facto_prop->prop , facto_prop->value);
            }
        }
        tmp_tag=tmp_tag->next;
    }
}


