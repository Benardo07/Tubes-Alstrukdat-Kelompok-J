#include "requests.h"
#include "../teman/teman.h"

void TambahTeman(){
    printf("Masukkan nama pengguna: \n");
    StartSentence();

    int j=0;
    boolean found = false;

    while (j < listLengthP(LPengguna) && !found){
        if (isStrEqual(NAMA(ELMT(LPengguna,j)),currentSentence.TabWord)){
            found = true;
        } else {
            j++;
        }
    }
    if (!found) {j = IDX_UNDEF;}

    if(j == ID(currentUser)-1){
        printf("\nAnda tidak dapat berteman dengan diri sendiri.\n");
        return;
    }
    else if(j == -1){
        printf("\nPengguna bernama %s tidak ditemukan.\n", currentSentence.TabWord);
        return;
    } else if (isTeman(ID(currentUser), j+1)) {
        printf("\nAnda telah berteman dengan %s!\n", NAMA(ELMT(LPengguna, j)));
    }
    else {
        if(!IsPrioQueueEmpty(FREQ(ELMT(LPengguna,ID(currentUser)-1)))){
            printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
            return; 
        }else{        
            boolean alreadyRequested = false;
                                   
            PrioQueue temp;
            CreatePrioQueue(&temp);
            infotype checkRequest;
            
            while (!IsPrioQueueEmpty(FREQ(ELMT(LPengguna,j)))) {
                DequeuePrio(&FREQ(ELMT(LPengguna,j)), &checkRequest);
                if (Info(checkRequest) == ID(currentUser)) {
                    alreadyRequested = true;
                }
                EnqueuePrio(&temp, checkRequest);
            }

            while (!IsPrioQueueEmpty(temp)) {
                DequeuePrio(&temp, &checkRequest);
                EnqueuePrio(&FREQ(ELMT(LPengguna,j)), checkRequest);
            }

            if(alreadyRequested){
                printf("\nAnda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", NAMA(ELMT(LPengguna, j)));
                return;
            }else{
                printf("\nPermintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n", currentSentence.TabWord);

                int i;
                infotype newFriendRequest;
                Info(newFriendRequest) = ID(currentUser);
                Prio(newFriendRequest) = TOTALFRIENDS(currentUser); 

                for (i = 0; i < listLengthP(LPengguna); i++){
                    if(ID(ELMT(LPengguna, i)) == j+1){
                        EnqueuePrio(&FREQ(ELMT(LPengguna, i)), newFriendRequest);
                        break;
                    }
                }
                return;
            } 
        }
    } 
}

void printDaftar() {
    int i = Head(FREQ(ELMT(LPengguna,currentUser.id-1)));
    if (!IsPrioQueueEmpty(FREQ(ELMT(LPengguna,currentUser.id-1)))) {
        do {
            int popularity = Prio(Elmt(FREQ(ELMT(LPengguna,currentUser.id-1)), i));
            int id = Info(Elmt(FREQ(ELMT(LPengguna,currentUser.id-1)), i));
            char *s ;
            int j;
            for(j=0;j<listLengthP(LPengguna);j++){
                if(ID(ELMT(LPengguna,j)) == id){
                    s = NAMA(ELMT(LPengguna,j));
                    break;
                }else{
                    s = NULL;
                }
            }
            if (s != NULL) {
                printf(" | %s\n", s);
                printf(" | Jumlah teman: %d\n", popularity);
            }
            i = (i + 1) % MaxEl(FREQ(ELMT(LPengguna,currentUser.id-1)));
        } while (i != (Tail(FREQ(ELMT(LPengguna,currentUser.id-1))) + 1) % MaxEl(FREQ(ELMT(LPengguna,currentUser.id-1))));
    }
}


void DaftarPermintaanTeman(){
    int len = lengthPrioQueue(FREQ(ELMT(LPengguna,currentUser.id-1)));;
    
    if(!IsPrioQueueEmpty(FREQ(ELMT(LPengguna,currentUser.id-1)))){
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n",len);
        printDaftar();
    }else{
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
}

void SetujuiTeman() {
    if(IsPrioQueueEmpty(FREQ(ELMT(LPengguna,currentUser.id-1)))) {
        printf("Tidak ada yang mengajukan permintaan pertemanan untuk Anda.\n");
    }else {
        infotype topRequest;
        DequeuePrio(&FREQ(ELMT(LPengguna,currentUser.id-1)), &topRequest);
        int topID = Info(topRequest);
        int jlhTeman = Prio(topRequest);
        char *topName;

        int j;
        for(j=0;j<listLengthP(LPengguna);j++){
            if(ID(ELMT(LPengguna,j)) == topID){
                topName = NAMA(ELMT(LPengguna,j));
                break;
            }else{
                topName = NULL;
            }
        }

        if (topName != NULL) {
            printf("Permintaan teratas dari %s\n", topName);
            printf(" | %s\n", topName);
            printf(" | Jumlah Teman: %d\n", jlhTeman);
            
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)\n");
            STARTWORD();
            char *answer = currentWord.TabWord;
            if (isStrEqual(answer, "YA")) {
                TOTALFRIENDS(ELMT(LPengguna,currentUser.id-1))++; 
                for (int i = 0; i < listLengthP(LPengguna); i++) {
                    if (ID(ELMT(LPengguna, i)) == topID) {
                        TOTALFRIENDS(ELMT(LPengguna, i))++;
                        connectNode(&Teman,topID - 1,Id(currentUser) - 1);
                        break;
                    }
                }
                printf("\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", topName,topName);  
            } else {
                printf("\nPermintaan pertemanan dari %s telah ditolak.\n", topName);
            }
        }else {
            printf("Nama pengguna tidak ditemukan.\n");
        }
    }
}
