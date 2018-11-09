#include "jam.h"
#include "array.h"
#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean CompStr(char S1[], char S2[]);
int StrLen(char s[]);

int main(){
    char comm[10];
    long tick = 0;
    scanf("%s", comm);
    printf("%d\n", CompStr(comm,"EXIT"));
    /*do{
        scanf("%s", comm);
        if ((CompStr(comm, "GU"))){

        }else if ((CompStr(comm, "GD"))){

        }else if ((CompStr(comm, "GL"))){
            
        }else if ((CompStr(comm, "GR"))){
            
        }else if ((CompStr(comm, "ORDER"))){
            
        }else if ((CompStr(comm, "PUT"))){
            
        }else if ((CompStr(comm, "TAKE"))){
            
        }else if ((CompStr(comm, "CH"))){
            
        }else if ((CompStr(comm, "CT"))){
            
        }else if ((CompStr(comm, "PLACE"))){
            
        }else if ((CompStr(comm, "GIVE"))){
            
        }else if ((CompStr(comm, "RECIPE"))){
            
        }else if ((CompStr(comm, "SAVE"))){
            
        }else if ((CompStr(comm, "LOAD"))){
            
        }
    }while (!(CompStr(comm, "EXIT")));*/
    return 0;
}

boolean CompStr(char S1[], char S2[]){
    int i = 0;
    boolean stop = true;
    int len = StrLen(S2);
    while ((i < len) && stop){
        if(S1[i] != S2[i]){
            stop = false;
        }
        i++;
    }
    return stop;
}

int StrLen(char s[]) {
   int c = 0;
 
   while (s[c] != '\0')
      c++;
 
   return c;
}