#include <stdio.h>
#include "teman.h"

boolean isTeman(int id_1, int id_2) {
    return isDirectlyConnected(Teman, id_1-1, id_2-1);
}

void daftarTeman(int idUser) {
    Queue q; CreateQueue(&q);

    for (int i=0; i<SIMPUL(Teman); ++i) {
        if (i != idUser-1 && isTeman(idUser-1, i)) enqueue(&q, i);
    }

    if (isQueueEmpty(q)) printf("%s belum mempunyai teman\n", NAMA(currentUser));
    else {
        printf("%s mempunyai %d teman\n", NAMA(currentUser), lengthQueue(q));
        int temp;
        while (!isQueueEmpty(q)) {
            printf("| %s\n", NAMA(ELMT(LPengguna, HEAD(q))));
            dequeue(&q, &temp);
        }
    }
}

void hapusTeman() {
    printf("Masukkan nama pengguna: ");
    char nama[21];
    StartSentence();
    strCpy(currentWord.TabWord, nama);

    int id_target = searchNama(LPengguna, nama);
    if (id_target != IDX_UNDEF) {
        if (isTeman(ID(currentUser), id_target)) {
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman Anda? (YA/TIDAK): ", nama);
            boolean inputValid = false;
            while(!inputValid) {
                StartSentence();
                if (isStrEqual(currentWord.TabWord, "YA")) {
                    deleteEdge(&Teman, ID(currentUser)-1, id_target-1);
                    printf("%s berhasil dihapus dari daftar teman Anda.\n", nama);
                    inputValid = true;
                }
                else if (isStrEqual(currentWord.TabWord, "TIDAK")) {
                    printf("Penghapusan teman dibatalkan.\n");
                    inputValid = true;
                }
                else printf("Mohon masukkan input yang valid (YA/TIDAK).\n");
            }
        } 
    }
}