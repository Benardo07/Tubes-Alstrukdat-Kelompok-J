#include <stdio.h>
#include "ADT/graf/graf.h"
#include "ADT/queue/queue.h"
#include "ADT/boolean.h"
#include "main.h"

boolean isTeman(int id_1, int id_2) {
    return isDirectlyConnected(Teman, id_1-1, id_2-1);
}

void daftarTeman(int idUser) {
    Queue q; CreateQueue(&q);

    for (int i=0; i<SIMPUL(Teman); ++i) {
        if (i != idUser-1 && isTeman(idUser-1, i)) enqueue(&q, i);
    }

    if (isEmpty(q)) printf("%s belum mempunyai teman\n", NAMA(currentUser));
    else {
        printf("%s mempunyai %d teman\n", NAMA(currentUser), length(q));
        int temp;
        while (!isEmpty(q)) {
            printf("| %s\n", NAMA(ELMT(LPengguna, HEAD(q))));
            dequeue(&q, &temp);
        }
    }
}

void hapusTeman() {
    printf("Masukkan nama pengguna: ");
    StartSentence();
    Word nama = currentWord;

    boolean foundUser = true; // sementara
    if (foundUser) {
        int id_1 = ID(currentUser) , id_2 = 1; // ntar ganti id_2 = idUser(nama)
        if (isTeman(id_1, id_2)) {
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman Anda? (YA/TIDAK): ", nama);
            boolean inputValid = false;
            while(!inputValid) {
                StartSentence();
                if (isStrEqual(&currentWord, "YA")) {
                    deleteEdge(&Teman, id_1-1, id_2-1);
                    printf("%s berhasil dihapus dari daftar teman Anda.\n", nama);
                    inputValid = true;
                }
                else if (isStrEqual(&currentWord, "TIDAK")) {
                    printf("Penghapusan teman dibatalkan.\n");
                    inputValid = true;
                }
                else printf("Mohon masukkan input yang valid (YA/TIDAK).\n");
            }
        } 
    }
}