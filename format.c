//
//  format.c
//  cssOptimize
//
//  Created by Elie Raffier on 26/10/2014.
//  Copyright (c) 2014 Elie Raffier. All rights reserved.
//

#include "format.h"


char* suppressNewline(char* string){
    int i=0;
    char *tmp=NULL;
    while(string[i]!='\0'){
        if(string[i]=='\n' || string[i]=='\r'){
            tmp=my_striconcat(string,&string[i+1],i );
            free(string);
            string=tmp;
            i--;
        }
        i++;
    }
    return string;
}

char* suppressSpaceAccol(char* string){
    int i=0;
    int j=0;
    char *tmp=NULL;
    while(string[i]!='\0'){
        if(string[i]=='{' || string[i]=='}' ){
            j=i;
            while(string[j+1]==' '){
                if(string[j+2]!=' '){
                    tmp=my_striconcat(string,&string[j+2],i+1);
                    free(string);
                    string=tmp;
                    break;
                }
                j++;
            }
            j=i;
            while(j>=1 && string[j-1]==' '){
                if(string[j-2]!=' '){
                    tmp=my_striconcat(string,&string[i],j-1);
                    free(string);
                    string=tmp;
                }
                j--;
            }
        }
        i++;
    }
    return string;
}

char* suppressSpaceDeuxPoint(char* string){
    int i=0;
    int j=0;
    char *tmp=NULL;
    while(string[i]!='\0'){
        if(string[i]==':'){
            j=i;
            while(string[j+1]==' '){
                if(string[j+2]!=' '){
                    tmp=my_striconcat(string,&string[j+2],i+1);
                    free(string);
                    string=tmp;
                    break;
                }
                j++;
            }
            j=i;
            while(j>=1 && string[j-1]==' '){
                if(string[j-2]!=' '){
                    tmp=my_striconcat(string,&string[i],j-1);
                    free(string);
                    string=tmp;
                }
                j--;
            }
        }
        i++;
    }
    return string;
}

char* suppressSpacePointVirg(char* string){
    int i=0;
    int j=0;
    char *tmp=NULL;
    while(string[i]!='\0'){
        if(string[i]==';' ){
            j=i;
            while(string[j+1]==' '){
                if(string[j+2]!=' '){
                    tmp=my_striconcat(string,&string[j+2],i+1);
                    free(string);
                    string=tmp;
                    break;
                }
                j++;
            }
            j=i;
            while(j>=1 && string[j-1]==' '){
                if(string[j-2]!=' '){
                    tmp=my_striconcat(string,&string[i],j-1);
                    free(string);
                    string=tmp;
                }
                j--;
            }
        }
        i++;
    }
    return string;
}

char* suppressComments(char* string){
    int i=0;
    int j=0;
    char *tmp=NULL;
    while(string[i]!='\0'){
        if(string[i]=='/' && string[i+1]=='*'){
            j=i+1;
            while(string[j+1]!='*' && string[j+2]!='/'){
                j++;
            }
            tmp=my_striconcat(string,&string[j+3],i);
            free(string);
            string=tmp;
        }
        i++;
    }
    
    return string;
}
