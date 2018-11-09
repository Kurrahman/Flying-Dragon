#include "jam.h"
#include "array.h"
#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean CompStr(char S1[], char S2[]);

int main(){
    char comm[10];
    long tick = 0;
    do{
        tick++;
        switch {
            case CompStr(comm, "GU") :{
                
                break;
            }
            case CompStr(comm, "GD") :{
                
                break;
            }
            case CompStr(comm, "GL") :{
                
                break;
            }
            
            case CompStr(comm, "GR") :{
                
                break;
            }
            case CompStr(comm, "ORDER") :{
                
                break;
            }
            case CompStr(comm, "PUT") :{
                
                break;
            }
            case CompStr(comm, "TAKE") :{
                
                break;
            }
            case CompStr(comm, "CH") :{
                
                break;
            }
            case CompStr(comm, "CT") :{
                
                break;
            }
            case CompStr(comm, "PLACE") :{
                
                break;
            }
            case CompStr(comm, "GIVE") :{
                
                break;
            }
            case CompStr(comm, "RECIPE") :{
                
                break;
            }
            case CompStr(comm, "SAVE") :{
                
                break;
            }
            case CompStr(comm, "LOAD") :{
                break;
            }
            case CompStr(comm, "EXIT") :{
                break;
            }
        }
    }while (!(CompStr(comm, "EXIT")));
    return 0;
}

boolean CompStr(char S1[], char S2[]){
    int i = 0;
    int len = sizeof(S2);
    while ((i < len) && (S1[i] == S2[i])){
        i++;
    }
    return (i > len);
}