#include "draf.h"
#include <stdio.h>



List LKicau; // Initialize as appropriate for your type
int IdKicau; // Initialize with an appropriate starting value
DrafStack sDraf ; // Initialize as appropriate for your type
Pengguna currentUser;

int main(){
    currentUser.id = 1;
    strCpy("TUANNN MAK",currentUser.nama);
    IdKicau = 1;
    CreateEmptyDrafStack(&sDraf);
    while(true){
        StartSentence();
        char *choice = currentWord.TabWord;

        if(isStrEqual(choice,"BUAT")){
            makingDraf();
            Draf temp = printLastDraf(sDraf,currentUser.id);
        }else if(isStrEqual(choice,"Lihat")){
            seeDraf();
        }else{
            printf("Wrong Input !! Please re-input : \n");
        }
        
        
    }
    
}