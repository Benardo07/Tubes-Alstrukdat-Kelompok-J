# include "ADT\queue\prioqueue.h"
# include "ADT\liststatik\listpengguna.h"
# include "ADT\graf\graf.h"
# include "../data/data.h"

void TambahTeman(){
    printf("Masukkan nama pengguna: \n");
    STARTWORD();

    char *nama = currentWord.TabWord ;
    int idUser = searchNama(LPengguna,nama);

    if(idUser == IDX_UNDEF){
        printf("Pengguna bernama %c tidak ditemukan.\n",nama);
        return;
    }else{
        if(IsEmptyPrio(FREQ(currentUser))){
            printf("Permintaan pertemanan kepada Bob telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
            return;
        }else{
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
            return; 
        }
    }
}

void printDaftar(){
    int i;
  
    for(i = Head(FREQ(currentUser)); i < Tail(FREQ(currentUser));i++){
        int popularity = Prio(Elmt(FREQ(currentUser), i));
        int id = Info(Elmt(FREQ(currentUser),i));
        char *s = searchNamabyId(LPengguna,id);

        if(s != NULL){
            printf(" | %c\n",s);
            printf(" | Jumlah teman: %d\n",popularity);
        }
    }
}

void DaftarPermintaanTeman(){
    int i;
    int len = lengthQueue(FREQ(currentUser));
    
    if(!IsEmptyPrio(FREQ(currentUser))){
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
                
                for (int i = 0; i < NEFF(*LPengguna); i++) {
                    if (ID(ELMT(*LPengguna, i)) == topID) {
                        TOTALFRIENDS(ELMT(*LPengguna, i))++; 
                        UpdatePrioQueue(&FREQ(ELMT(*LPengguna, i)), ID(*currentUser)); 
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