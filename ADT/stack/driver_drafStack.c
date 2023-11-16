#include <stdio.h>
#include "drafStack.h"

int main(){
DrafStack S, S2;
    CreateEmptyDrafStack(&S);

    // Assuming CreateDraf and DisplayDraf functions are defined properly.
    DATETIME d;
    CreateDATETIME(&d,20,10,2023,10,12,49);
    Draf d1, d2, dTemp;
    CreateDraf(&d1, "Sample Tweet 1",d);
    CreateDraf(&d2, "Sample Tweet 2",d);

    // Push drafts onto the stack
    PushDrafStack(&S, d1);
    PushDrafStack(&S, d2);

    // Test printDraf
    printf("\nPrint Draft: \n");
    printDraf(d1);

    // Test printLastDraf
    printf("\nPrint Last Draft: \n");
    Draf lastDraft = printLastDraf(S);
    DisplayDraf(lastDraft);

    // Test EditLastDraf
    EditLastDraf(&S, "Edited Sample Tweet");
    printf("\nAfter Editing Last Draft: \n");
    lastDraft = printLastDraf(S);
    DisplayDraf(lastDraft);

    // Test DeleteLastDraf
    DeleteLastDraf(&S);
    printf("\nAfter Deleting Last Draft: \n");
    lastDraft = printLastDraf(S);
    DisplayDraf(lastDraft);

    CreateDraf(&d1, "Sample Tweet 3",d);
    CreateDraf(&d2, "Sample Tweet 4",d);
    PushDrafStack(&S, d1);
    PushDrafStack(&S, d2);

    // Test copyReverse
    Draf temp;
    CreateEmptyDrafStack(&S2);
    copyReverse(S, &S2);
    printf("\nOriginal Stack: \n");
    // Assuming a function to display the whole stack exists
    while(!IsEmptyDrafStack(S)){
        PopDrafStack(&S,&temp);
        printDraf(temp);
    }
    printf("\nReversed Stack: \n");

    while(!IsEmptyDrafStack(S2)){
        PopDrafStack(&S2,&temp);
        printDraf(temp);
    } 

    return 0;
}