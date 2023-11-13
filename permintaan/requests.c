# include "ADT\queue\prioqueue.h"
# include "ADT\liststatik\listpengguna.h"
# include "ADT\graf\graf.h"
# include "../data/data.h"

void TambahTeman(){
    printf("Masukkan nama pengguna: \n");
    STARTWORD();

    char *nama = currentWord.TabWord;
    int idUser = searchNama(LPengguna, nama);

    if(idUser == IDX_UNDEF){
        printf("Pengguna bernama %s tidak ditemukan.\n", nama);
        return;
    } else {
        if(IsPrioQueueEmpty(FREQ(currentUser))){
            infotype newFriendRequest;
            Info(newFriendRequest) = ID(currentUser);
            Prio(newFriendRequest) = TOTALFRIENDS(currentUser); 

            for (int i = 0; i < listLengthP(LPengguna); i++) {
                if (ID(ELMT(LPengguna, i)) == idUser) {
                    EnqueuePrio(&FREQ(ELMT(LPengguna, i)), newFriendRequest);
                    break;
                }
            }

            printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n", nama);
            return;
        } else {
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
            return; 
        }
    }
}


void printDaftar() {
    int i = Head(FREQ(currentUser));
    if (!IsPrioQueueEmpty(FREQ(currentUser))) {
        do {
            int popularity = Prio(Elmt(FREQ(currentUser), i));
            int id = Info(Elmt(FREQ(currentUser), i));
            char *s = searchNamabyId(LPengguna, id);
            if (s != NULL) {
                printf(" | %s\n", s);
                printf(" | Jumlah teman: %d\n", popularity);
            }
            i = (i + 1) % MaxEl(FREQ(currentUser));
        } while (i != (Tail(FREQ(currentUser)) + 1) % MaxEl(FREQ(currentUser)));
    }
}


void DaftarPermintaanTeman(){
    int i;
    int len = lengthPrioQueue(FREQ(currentUser));
    
    if(!IsPrioQueueEmpty(FREQ(currentUser))){
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n",len);
        printDaftar();
    }else{
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
}

void SetujuiTeman(ListPengguna *LPengguna, Pengguna *currentUser) {
    if (IsPrioQueueEmpty(FREQ(*currentUser))) {
        printf("Tidak ada yang mengajukan pertemanan dengan Anda.\n");
    } else {
        infotype topRequest;
        DequeuePrio(&FREQ(*currentUser), &topRequest);
        int topID = Info(topRequest);
        int jlhTeman = Prio(topRequest);
        char* topName = searchNamabyId(*LPengguna, topID);

        if (topName != NULL) {
            printf("Permintaan teratas dari %s\n", topName);
            printf(" | %s\n", topName);
            printf(" | Jumlah Teman: %d\n", jlhTeman);
            
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (ya/tidak)\n");
            STARTWORD();
            char* answer = currentWord.TabWord;
            if (isStrEqual(answer, "ya")) {
                TOTALFRIENDS(*currentUser)++; 
                
                for (int i = 0; i < listLengthP(*LPengguna); i++) {
                    if (ID(ELMT(*LPengguna, i)) == topID) {
                        TOTALFRIENDS(ELMT(*LPengguna, i))++; 
                        UpdatePrioQueue(&FREQ(ELMT(*LPengguna, i)), ID(*currentUser)); 
                        connectNode(&Teman,topID - 1,Id(*currentUser) - 1);
                        break;
                    }
                }
                printf("Permintaan pertemanan dari %s telah disetujui.\n", topName);
            } else {
                printf("Permintaan pertemanan dari %s tidak disetujui.\n", topName);
            }
        } else {
            printf("Nama pengguna tidak ditemukan.\n");
        }
    }
}
