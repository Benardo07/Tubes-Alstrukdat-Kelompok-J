#include <stdio.h>
#include <stdlib.h>
#include "listpengguna.h"

int main(){
    // Tes Pengguna
    printf("Ini tes pengguna:\n");

    // Create Pengguna
    Pengguna p;
    createPengguna(&p);

    // Tes Create Pengguna
    printPengguna(p);

    // Tes New Pengguna
    newPengguna(&p,"tes_nama","tes_sandi");
    printPengguna(p);

    // Tes manipulasi pengguna
    strCpy("08123415",&HP(p));
    strCpy("tes bio",&BIO(p));
    printPengguna(p);

    // Tes lain

    // Tes List Pengguna
    printf("\nIni tes list pengguna:\n");

    // Create List Pengguna
    ListPengguna l;
    CreateListPengguna(&l);

    // Tes Create List Pengguna;
    if (isEmptyP(l)) printf("isEmpty\n");

    // Tes Insert List
    Pengguna p1,p2,p3,p4;
    createPengguna(&p1); createPengguna(&p2); createPengguna(&p3); createPengguna(&p4);
    newPengguna(&p1,"p1","tes"); newPengguna(&p2,"p2","tes"); newPengguna(&p3,"p3","tes"); newPengguna(&p4,"p4","tes");

    insertFirstP(&l,p1); insertLastP(&l,p2); insertFirstP(&l,p3); insertAtP(&l,p4,1);
    printListP(l);

    // Test nbElmt
    printPengguna(ELMT(l,2));

    // Test lain sesuai keperluan
    // ...

    return 0;

}
