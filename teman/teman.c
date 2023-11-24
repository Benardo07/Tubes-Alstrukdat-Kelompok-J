#include <stdio.h>
#include "teman.h"
#include "../ADT/liststatik/listpengguna.h"

boolean isTeman(int id_1, int id_2) {
    return isAdjacent(Teman, id_1-1, id_2-1);
}

void daftarTeman(int idUser) {
    PrioQueue q; CreatePrioQueue(&q);

    for (int i=0; i<SIMPUL(Teman); ++i) {
        if (i != idUser-1 && isTeman(idUser, i+1)) {
            infotype node = newPrioElmt(i, 1);
            EnqueuePrio(&q, node);
        }
    }

    if (IsPrioQueueEmpty(q)) printf("%s belum mempunyai teman.\n", NAMA(currentUser));
    else {
        printf("%s mempunyai %d teman\n", NAMA(currentUser), lengthPrioQueue(q));
        infotype temp;
        while (!IsPrioQueueEmpty(q)) {
            printf("| %s\n", NAMA(ELMT(LPengguna, Info(InfoHead(q)))));
            DequeuePrio(&q, &temp);
        }
    }

    // if (TOTALFRIENDS(ELMT(LPengguna, idUser-1)) == 0) {
    //     printf("%s belum mempunyai teman.\n", NAMA(currentUser));
    // }
    // else {
    //     printf("%s mempunyai %d teman\n", NAMA(currentUser), TOTALFRIENDS(ELMT(LPengguna, idUser-1)));
    //     for (int i=0; i<SIMPUL(Teman); ++i) {
    //         if (i != IdCurrentUser-1 && isTeman(i+1, IdCurrentUser)) {
    //             printf("| %s\n", NAMA(ELMT(LPengguna, i)));
    //         }
    //     }
    // }
}

void hapusTeman() {
    if (TOTALFRIENDS(currentUser) == 0) {
        printf("Anda belum memiliki teman!\n");
        return;
    }
    
    printf("Masukkan nama pengguna: ");
    char nama[21];
    StartSentence();
    strCpy(currentSentence.TabWord, nama);

    int id_target = searchPenggunaByName(LPengguna, nama);
    if (id_target != IDX_UNDEF) {
        id_target++;
        if (id_target == ID(currentUser)) {
            printf("Anda tidak dapat menghapus diri sendiri!\n");
        }
        else if (isTeman(ID(currentUser), id_target)) {
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman Anda? (YA/TIDAK): ", nama);
            boolean inputValid = false;
            while(!inputValid) {
                StartSentence();
                if (isStrEqual(currentSentence.TabWord, "YA")) {
                    deleteEdge(&Teman, ID(currentUser)-1, id_target-1);
                    printf("%s berhasil dihapus dari daftar teman Anda.\n", nama);
                    inputValid = true;
                    TOTALFRIENDS(currentUser)--;
                }
                else if (isStrEqual(currentSentence.TabWord, "TIDAK")) {
                    printf("Penghapusan teman dibatalkan.\n");
                    inputValid = true;
                }
                else printf("Mohon masukkan input yang valid (YA/TIDAK).\n");
            }
        }
        else printf("%s bukan teman Anda!\n", nama);
    }
    else printf("Tidak ada user dengan nama %s!\n", nama);
}