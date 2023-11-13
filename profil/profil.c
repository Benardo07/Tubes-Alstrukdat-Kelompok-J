# include <stdio.h>
# include "profil.h"

void setBio(){
    printf("Masukkan Bio Akun (Max : 135 karakter): \n");
    StartSentence();
    int i;
    char* s = currentWord.TabWord;
    for(i=0;i<listLengthP(LPengguna);i++){
        if(ID(ELMT(LPengguna,i)) == IdCurrentUser){
            strCpy(s,BIO(ELMT(LPengguna,i)));
            while(strlength(s) > 135){
                printf("Bio memiliki panjang melebihi 135 karakter. Masukkan sesuai format lagi : \n");
                StartSentence();
                s = currentWord.TabWord;
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
    StartSentence();
    char* hp;
    char* hpnew;
    hp = currentWord.TabWord;
    int i;
    for(i=0;i<listLengthP(LPengguna);i++){
        if(ID(ELMT(LPengguna,i)) == IdCurrentUser){
            strCpy(hp,HP(ELMT(LPengguna,i)));
            while(!NumberValid(currentWord)){
                printf("\n");
                printf("No HP tidak valid. Masukkan lagi yuk!\n");
                printf("\n");
                printf("Masukkan No HP: \n");
                StartSentence();
                hpnew = currentWord.TabWord;
                strCpy(hpnew,HP(ELMT(LPengguna,i)));
            }
        }
    } 
}

void setWeton(){
    printf("Masukkan Weton: \n");
    STARTWORD();
    char* weton = currentWord.TabWord;
    char* wetonNew;
    int i;
    for(i=0;i<listLengthP(LPengguna);i++){
        if(ID(ELMT(LPengguna,i)) == IdCurrentUser){
            strCpy(weton,WETON(ELMT(LPengguna,i)));
            while(!isWeton(weton)){
                printf("\n");
                printf("Weton anda tidak valid.\n");
                printf("\n");
                printf("Masukkan Weton: \n");
                StartSentence();
                wetonNew = currentWord.TabWord;
                strCpy(wetonNew,WETON(ELMT(LPengguna,i)));
            }
        }
    }
}

void gantiProfil(){
    printf("| Nama: %s\n",NAMA(ELMT(LPengguna,IdCurrentUser)));
    printf("| Bio Akun: \n");
    printf("| No HP: \n");
    printf("| Weton: \n");
    printf("\n");

    setBio();
    printf("\n");
    setNoHP();
    printf("\n");
    setWeton();
    printf("\n");

    printf("| Nama: %s\n", NAMA(ELMT(LPengguna,IdCurrentUser)));
    printf("| Bio Akun: %s\n", BIO(ELMT(LPengguna,IdCurrentUser)));
    printf("| No HP: %s\n", HP(ELMT(LPengguna,IdCurrentUser)));
    printf("| Weton: %s\n", WETON(ELMT(LPengguna,IdCurrentUser)));
    printf("\n");
    
    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void LihatProfil(char *s){
    int id;
    id = searchNama(LPengguna,s);
    printf("%d\n",id);
    if(JENIS(ELMT(LPengguna,id)) == "Privat"){
        printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!", s);
        return;
    };

    printf("| Nama: %s\n", NAMA(ELMT(LPengguna,id)));
    printf("| Bio Akun: %s\n", BIO(ELMT(LPengguna,id)));
    printf("| No HP: %s\n", HP(ELMT(LPengguna,id)));
    printf("| Weton: %s\n", WETON(ELMT(LPengguna,id)));
    printf("\n");
    printf("Foto profil akun TuanBri\n");
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,id)));
    printf("\n");
}

void aturjenisakun (){
    printf("Saat ini, Akun anda adalah akun Publik. Ingin mengubah ke akun privat? \n");
    printf("(YA/TIDAK) ");
    STARTWORD();
    printf("\n");
    char *choice = currentWord.TabWord;
    if(isStrEqual(choice,"YA") || isStrEqual(choice,"ya") || isStrEqual(choice,"Ya")){
        strCpy("Privat",JENIS(ELMT(LPengguna,IdCurrentUser)));
        printf("Akun anda telah diubah menjadi akun Privat.\n");
    }else{
        printf("Akun anda tetap menjadi akun Publik. \n");
    }
}

int isSpaceOrControl(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || (ch >= 0 && ch <= 31);
}

void UbahfotoProfil() {
    printf("\nFoto profil anda saat ini adalah\n");
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,IdCurrentUser)));

    printf("Masukkan foto profil yang baru\n");
    STARTWORD();  
    char* input = currentWord.TabWord;

    int row = 0, col = 0, i = 0;
    while (input[i] != '\0' && input[i] != ';') {
        if (!isSpaceOrControl(input[i])) {
            if (col < COL_EFF(FOTO(ELMT(LPengguna,IdCurrentUser)))) {
                ChangePhotoMatrix(&FOTO(ELMT(LPengguna,IdCurrentUser)), row, col, input[i]);
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
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,IdCurrentUser)));
}
