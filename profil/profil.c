# include <stdio.h>
# include "../data/data.h"
# include "profil.h"

void setBio(){
    printf("Masukkan Bio Akun (Max : 135 karakter): \n");
    StartSentence();
    int i;
    char* s = currentSentence.TabWord;
    for(i=0;i<listLengthP(LPengguna);i++){
        if(i+1 == IdCurrentUser){
            strCpy(s,BIO(ELMT(LPengguna,i)));
            while(strlength(s) > 135){
                printf("\nBio memiliki panjang melebihi 135 karakter. Masukkan lagi yuk! \n");
                printf("\n");
                printf("Masukkan Bio Akun (Max : 135 karakter): \n");
                StartSentence();
                s = currentSentence.TabWord;
                strCpy(s,BIO(ELMT(LPengguna,i)));
            }
        }
    }
}

boolean NumberValid(Word input){
    int i;
    for(i = 0; i < input.Length; i++){
        if(input.TabWord[i] != '0' && input.TabWord[i] != '1' && input.TabWord[i] != '2' && 
           input.TabWord[i] != '3' && input.TabWord[i] != '4' && input.TabWord[i] != '5' && 
           input.TabWord[i] != '6' && input.TabWord[i] != '7' && input.TabWord[i] != '8' && 
           input.TabWord[i] != '9'){
            return false;
        }
    }
    return true;
}

void setNoHP(){
    printf("Masukkan No HP: \n");
    STARTWORD();
    char* hp;
    hp = currentWord.TabWord;
    int i;
    while(strlength(hp)>15 || !NumberValid(currentWord)){
        if(strlength(hp) > 15){
            printf("\nNo Hp memiliki panjang melebihi 15 karakter. Masukkan lagi yuk!\n");
            printf("\n");
        }else if (!NumberValid(currentWord)){
            printf("\n");
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
            printf("\n");
        }
        printf("Masukkan No HP: \n");
        STARTWORD();  
    }
    for(i=0;i<listLengthP(LPengguna);i++){
        if(i+1 == IdCurrentUser){
            strCpy(hp,HP(ELMT(LPengguna,i)));
            break;
        }
    }
} 


void setWeton(){
    printf("Masukkan Weton: \n");
    STARTWORD();
    char* weton = currentWord.TabWord;
    makeUpper(weton);
    char* wetonNew;
    int i;
    for(i=0;i<listLengthP(LPengguna);i++){
        if(i+1 == IdCurrentUser){
            strCpy(weton,WETON(ELMT(LPengguna,i)));
            while(!isWeton(weton)){
                printf("\n");
                printf("Weton anda tidak valid.\n");
                printf("\n");
                printf("Masukkan Weton: \n");
                STARTWORD();
                wetonNew = currentWord.TabWord;
                makeUpper(wetonNew);
                strCpy(wetonNew,WETON(ELMT(LPengguna,i)));
            }
        }
    }
}

void gantiProfil(){
    printf("\n| Nama: %s\n",NAMA(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| Bio Akun: %s\n", BIO(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| No HP: %s\n", HP(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| Weton: %s\n", WETON(ELMT(LPengguna,IdCurrentUser-1)));
    printf("\n");

    setBio();
    printf("\n");
    setNoHP();
    printf("\n");
    setWeton();
    printf("\n");

    printf("| Nama: %s\n", NAMA(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| Bio Akun: %s\n", BIO(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| No HP: %s\n", HP(ELMT(LPengguna,IdCurrentUser-1)));
    printf("| Weton: %s\n", WETON(ELMT(LPengguna,IdCurrentUser-1)));
    printf("\n");
    
    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void LihatProfil(char *nama){
    int idx;
    boolean isCurrentUser = false;
    if(isStrEqual(NAMA(currentUser),nama)){
        isCurrentUser = true;
    }

    idx = searchNamabyRef(&LPengguna,nama);

    if(idx == -1){
        printf("\nTidak ada pengguna bernama %s\n",nama);
        return;
    }

    if(!isCurrentUser && isStrEqual("Privat",JENIS(ELMT(LPengguna,idx)))){
        printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!", nama,nama);
        return;
    };

    printf("| Nama: %s\n", NAMA(ELMT(LPengguna,idx)));
    printf("| Bio Akun: %s\n", BIO(ELMT(LPengguna,idx)));
    printf("| No HP: %s\n", HP(ELMT(LPengguna,idx)));
    printf("| Weton: %s\n", WETON(ELMT(LPengguna,idx)));
    printf("\n");
    printf("Foto profil akun %s\n",nama);
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,idx)));
}

void aturjenisakun (){
    if(isStrEqual("Publik",JENIS(ELMT(LPengguna,IdCurrentUser-1)))){
        printf("Saat ini, Akun anda adalah akun Publik. Ingin mengubah akun menjadi akun privat? \n");
        printf("(YA/TIDAK) ");
        STARTWORD();
        char *choice = currentWord.TabWord;
        while(!isStrEqual(choice, "YA") && !isStrEqual(choice, "TIDAK")){
                printf("\nTolong untuk memasukkan input sesuai format.\n");
                printf("\n");
                printf("Saat ini, Akun anda adalah akun Publik. Ingin mengubah akun menjadi akun privat? \n");
                printf("(YA/TIDAK) ");
                STARTWORD();
                choice = currentWord.TabWord;
        }
        printf("\n");
        if(isStrEqual(choice,"YA")){
            strCpy("Privat",JENIS(ELMT(LPengguna,IdCurrentUser-1)));
            printf("Akun anda telah diubah menjadi akun Privat.\n");
        }else{
            printf("Akun anda tetap menjadi akun Publik. \n");
        }
    }else if(isStrEqual("Privat",JENIS(ELMT(LPengguna,IdCurrentUser-1)))){
        printf("Saat ini, Akun anda adalah akun Privat. Ingin mengubah akun menjadi akun publik? \n");
        printf("(YA/TIDAK) ");
        STARTWORD();
        char *choice = currentWord.TabWord;
        while(!isStrEqual(choice, "YA") && !isStrEqual(choice, "TIDAK")){
                printf("Tolong untuk memasukkan input sesuai format.\n");
                printf("\n");
                printf("Saat ini, Akun anda adalah akun Privat. Ingin mengubah akun menjadi akun publik? \n");
                printf("(YA/TIDAK) ");
                STARTWORD();
                choice = currentWord.TabWord;
        }
        printf("\n");
        if(isStrEqual(choice,"YA")){
            strCpy("Publik",JENIS(ELMT(LPengguna,IdCurrentUser-1)));
            printf("Akun anda telah diubah menjadi akun Publik.\n");
        }else{
            printf("Akun anda tetap menjadi akun Privat. \n");
        }
    }
}

int isAscii(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || (ch >= 0 && ch <= 31);
}

void UbahfotoProfil() {
    printf("\nFoto profil anda saat ini adalah\n");
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,IdCurrentUser-1)));
    printf("\n");
    printf("Masukkan foto profil yang baru\n");
    StartSentence();  
    char* input = currentSentence.TabWord;

    int row = 0, col = 0, i = 0;
    while (input[i] != '\0' && input[i] != ';') {
        if (!isAscii(input[i])) {
            if (col < COL_EFF(FOTO(ELMT(LPengguna,IdCurrentUser-1)))) {
                ChangePhotoMatrix(&FOTO(ELMT(LPengguna,IdCurrentUser-1)), row, col, input[i]);
                col++;
            }
        } else if (input[i] == '\n' || input[i] == '\r') {
            row++;
            col = 0;
        }
        i++;
    }
    printf("\n");
    printf("Foto Profil Anda sudah berhasil diganti!\n");
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,IdCurrentUser-1)));
}
