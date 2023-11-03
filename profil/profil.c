# include <stdio.h>
# include "ADT/matriks/foto.h"
# include "ADT/boolean.h"
# include "ADT/liststatik/listpengguna.h"
# include "main.h"

void setBio(){
    StartSentence();
    strCpy(currentWord.TabWord,BIO(currentUser));
}

boolean NumberValid(Word input){
    int i;
    for(i=0;i<input.Length;i++){
        if(input.TabWord[i] != "0" || input.TabWord[i] != "1" || input.TabWord[i] != "2" || input.TabWord[i] != "3" || input.TabWord[i] != "4" || input.TabWord[i] != "5" || input.TabWord[i] != "6" || input.TabWord[i] != "7" || input.TabWord[i] != "8" || input.TabWord != "9"){
            return false;
        }
    }
    return true;
}

void setNoHP(){
    printf("Masukkan No HP: \n");
    StartSentence();
    strCpy(currentWord.TabWord,HP(currentUser));
    while(!NumberValid(currentWord)){
        printf("\n");
        printf("No HP tidak valid. Masukkan lagi yuk!\n");
        printf("Masukkan No HP: \n");
        StartSentence();
        strCpy(currentWord.TabWord,HP(currentUser));
    }
}

void setWeton(){
    printf("Masukkan Weton: \n");
    STARTWORD();
    strCpy(currentWord.TabWord,WETON(currentUser));
    while(!isWeton(currentWord.TabWord)){
        printf("\n");
        printf("Weton anda tidak valid.\n");
        printf("Masukkan Weton: \n");
        StartSentence();
        strCpy(currentWord.TabWord,HP(currentUser));
    }
}

void gantiProfil(){
    printf("| Nama: %c\n",currentUser.nama);
    printf("| Bio Akun: \n");
    printf("| No HP: \n");
    printf("| Weton: \n");
    printf("\n");

    printf("Masukkan Bio Akun: \n");
    setBio();
    setNoHP();
    setWeton();
    
    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void LihatProfil(char *s){
    int id;
    id = searchNama(LPengguna,s);
    if(JENIS(ELMT(LPengguna,id)) == "Privat"){
        printf("Wah, akun %c diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %c!", s);
    };

    printf(" | Nama: %c\n", NAMA(ELMT(LPengguna,id)));
    printf(" | Bio Akun: %c\n", BIO(ELMT(LPengguna,id)));
    printf(" | No HP: %c\n", HP(ELMT(LPengguna,id)));
    printf(" | Weton: %c\n", WETON(ELMT(LPengguna,id)));
    
    printf("Foto profil akun TuanBri\n");
    PrintPhotoMatrix(FOTO(ELMT(LPengguna,id)));
}

void aturjenisakun (){
    printf("Saat ini, Akun anda adalah akun Publik. Ingin mengubah ke akun privat? \n");
    printf("(YA/TIDAK) ");
    STARTWORD();
    printf("\n");
    char *choice;
    strCpy(currentWord.TabWord, choice);
    if(isStrEqual(choice,"Privat")){
        strCpy("Publik",JENIS(currentUser));
        printf("Akun anda telah diubah menjadi akun Privat.\n");
    }else{
        strCpy("Publik",JENIS(currentUser));
        printf("Akun anda tetap menjadi akun Publik. \n");
    }
}

void UbahfotoProfil(currentuser){
    printf("Foto profil anda saat ini \n");
    PrintPhotoMatrix(FOTO(currentUser));

    printf("Masukkan foto profil yang baru: \n");

    printf("Foto Profil Anda sudah berhasil diganti!\n");
    }

