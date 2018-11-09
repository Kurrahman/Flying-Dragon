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
        switch {
            case CompStr(comm, "GU") :{
                tick++;
                break;
            }
            case CompStr(comm, "GD") :{
                tick++;
                break;
            }
            case CompStr(comm, "GL") :{
                tick++;
                break;
            }
            
            case CompStr(comm, "GR") :{
                tick++;
                break;
            }
            case CompStr(comm, "ORDER") :{
                tick++;
                break;
            }
            case CompStr(comm, "PUT") :{
                tick++;
                break;
            }
            case CompStr(comm, "TAKE") :{
                tick++;
                break;
            }
            case CompStr(comm, "CH") :{
                tick++;
                break;
            }
            case CompStr(comm, "CT") :{
                tick++;
                break;
            }
            case CompStr(comm, "PLACE") :{
                tick++;
                break;
            }
            case CompStr(comm, "GIVE") :{
                tick++;
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