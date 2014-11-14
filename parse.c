//
//  parse.c
//  cssOptimize
//
//  Created by Elie Raffier on 11/7/14.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "parse.h"


void populate_tags(t_tag** list,char* string){
    int i=0,j=0;
    char* ids;
    char* prop="";
    char* value="";
    int length=my_strlen(string);
    t_properties* props=NULL;
    while(string[i]!='\0' && i<length){
        if(string[i]=='{'){
            ids=my_substr(string, i-j, j);
            i++;
            j=i;
            while(string[i]!='}' && string[i]!='\0'){
                while(string[i]!=';'){
                    if(string[i]==':'){
                        prop=my_substr(string, i-j, j);
                        i++;
                        j=i;
                    }
                    i++;
                }
                value=my_substr(string, i-j, j);
                list_prop_append(&props,prop,value);
                i++;
                j=i;
            }
            parseID(list,ids,props);
            //list_prop_free(&props);
            props=NULL;
            i++;
            j=i;
        }
        i++;
    }
}

void parseID(t_tag** list,char* string,t_properties* props){
    int i,j,k,index;
    char* s;
    t_tag* tmp;
    j=0;
    for (i=0; i<my_strlen(string); i++) {
        if(string[i]==','){
            s=my_substr(string, i-j, j);
            if(list_tag_get_by_name(*list, s)==-1){
                list_tag_append(list, s, props);
            }else{
                tmp=(*list);
                index=list_tag_get_by_name(*list, s);
                for(k=0;k<index;k++){
                    tmp=tmp->next;
                }
                while(props!=NULL){
                    list_prop_append(&tmp->props,props->prop , props->value);
                    props=props->next;
                }
            }
            free(s);
            while(string[i]==' ' || string[i]==','){
                i++;
            }
            j=i;
        }
    }
    s=my_substr(string, i-j, j);
    if(list_tag_get_by_name(*list, s)==-1){
        list_tag_append(list, s, props);
    }else{
        tmp=(*list);
        index=list_tag_get_by_name(*list, s);
        for(k=0;k<index;k++){
            tmp=tmp->next;
        }
        while(props!=NULL){
            list_prop_append(&tmp->props,props->prop , props->value);
            props=props->next;
        }
    }
    free(s);
    j=i;
}