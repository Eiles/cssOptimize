//
//  my_string.c
//  cssOptimize
//
//  Created by Elie Raffier on 24/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "my_string.h"

//Return 0 if arg1=arg2, 1 if arg1>arg2 or -1 if arg1<arg2
int my_strcmp(char* arg1, char* arg2){
    int i;
    int retour;
    int limit=my_strlen(arg1);
    int pluslong=0;
    if(my_strlen(arg1)<my_strlen(arg2)){
        limit=my_strlen(arg1);
        pluslong=2;
        
    }
    if(my_strlen(arg1)>my_strlen(arg2)){
        limit=my_strlen(arg2);
        pluslong=1;
    }
    for(i=0;i<my_strlen(arg1);i++){
        if(arg1[i]>64 && arg1[i]<91){
            arg1[i]+=32;
        }
    }
    for(i=0;i<my_strlen(arg2);i++){
        if(arg2[i]>64 && arg2[i]<91){
            arg2[i]+=32;
        }
    }
    for(i=0;i<limit;i++){
        if(arg1[i]!=arg2[i]){
            retour=arg1[i]>arg2[i]?1:-1;
            return retour;
        }
    }
    retour = 0;
    if(pluslong==1){
        return 1;
    }
    if(pluslong==2){
        return -1;
    }
    return retour;
}

//Return length of string
int my_strlen(char *string){
    int i;
    for(i=0;string[i]!='\0';i++);
    return i;
}

void to_upper_case(char* input){
    int i;
    for(i=0;i<my_strlen(input);i++){
        if(input[i]>96 && input[i]<123){
            input[i]-=32;
        }
    }
}

void to_lower_case(char* input){
    int i;
    for(i=0;i<my_strlen(input);i++){
        if(input[i]>64 && input[i]<91){
            input[i]+=32;
        }
    }
}

//Return position of first occurence of pattern in string
int str_search(char *string, char *pattern){
    int str_len=my_strlen(string);
    int pat_len=my_strlen(pattern);
    int i,j;
    int flag=1;
    for(i=0;i<str_len-pat_len+1;i++){
        flag=0;
        j=0;
        if(string[i]==pattern[j]){
            for(j=0;j<pat_len;j++){
                if(string[i+j]!=pattern[j]){
                    flag=1;
                }
                if(!flag){
                    return i;
                }
            }
            
        }
    }
    return -1;
    
}
//Convert string to integer
int my_atoi(char *chaine){
    int i,neg=0,res=0;
    if(chaine[0]=='-'){
        neg=i=1;
    }else{
        i=0;
    }
    while(chaine[i]!='\0'){
        if(chaine[i]<48 || chaine[i]>57){
            if(chaine[i]=='.'){
                if(neg){
                    return 0-res;
                }
                return res;
            }
            return 0;
        }
        else{
            res*=10;
            res+=chaine[i]-48;
        }
        i++;
    }
    if(neg){
        return 0-res;
    }
    return res;
}

//Check is char is a digit
int is_number(char ch){
    if( ch<48 || ch>57){
        return 0;
    }
    return 1;
}

char* my_strcpy(char* s1){
    int i;
    char *p=malloc(my_strlen(s1)+1);
    p[my_strlen(s1)]='\0';
    for(i=0;i<my_strlen(s1);i++){
        p[i]=s1[i];
    }
    return p;
}

char* my_substr(char* s1,int n,int offset){
    int i;
    char* string;
    int length=my_strlen(s1)-offset;
    length=length<n?length:n;
    length=length<0?0:length;
    string=malloc(sizeof(char)*(length+1));
    
    for (i=0; i<length; i++) {
        string[i]=s1[i+offset];
    }
    string[length]='\0';
    return string;
}

//Concat v2 at the end of v1 in a new string and return it
char* my_strconcat(char* v1,char* v2){
    int i;
    char* p=malloc(my_strlen(v1) + my_strlen(v2) +1);
    p[my_strlen(v1) + my_strlen(v2)]='\0';
    for(i=0;i<my_strlen(v1);i++){
        p[i]=v1[i];
    }
    for(i=my_strlen(v1);i<my_strlen(v1) + my_strlen(v2);i++){
        p[i]=v2[i-my_strlen(v1)];
    }
    
    return p;	
}

char* my_striconcat(char* v1, char* v2, int start) {
    
    int i;
    char* p=malloc(sizeof(char)*(start + strlen(v2) +1));
    p[start + strlen(v2)]='\0';
    
    for(i=0;i<start;i++){
        p[i]=v1[i];
    }
    
    for(i=start;i<start + strlen(v2);i++){
        p[i]=v2[i-start];
    }
    
    return p;
}
