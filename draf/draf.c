#include <stdio.h>
#include "draf.h"
#include "..\data\data.h"

void makingDraf (ListPengguna *Lpeng){
    printf("\nMasukkan draf:\n");
    Word text;
    readKicau(&text);
    // Ambil waktu lokal
    time_t currentTime;
    struct tm *localTime;

    
    DATETIME d = getLocalTime();
    Draf tempDraf;
    CreateDraf(&tempDraf,text.TabWord,d);
    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    
    while(true){
        StartSentence();
        char *pilihan;
        pilihan = currentWord.TabWord;
        
        if(isStrEqual(pilihan,"SIMPAN")){
            int index = searchNamabyRef(Lpeng,currentUser.nama);
            PushDrafStack(&DRAF(ELMT(*Lpeng,index)),tempDraf);
            JMLHDRAF(ELMT(*Lpeng,index))++;
            printf("\nDraf telah berhasil disimpan!\n\n");
            break;
        }else if(isStrEqual(pilihan,"TERBIT")){
            Kicau k;
            CreateKicau(&k,IdKicau,0,text,currentUser.nama,d);
            insertLastKicau(&LKicau,k);
            
            // print hasil kicau
            printf("\nSelamat! kicauan telah diterbitkan!\n");
            printKicau(LKicau,IdKicau);
            IdKicau++;
            
            break;
        }else if(isStrEqual(pilihan,"HAPUS")){
            printf("\nDraf telah dihapus!\n\n");
            break;
        }else{
            printf("\nWrong Input !! Please re-input : \n");
        }
    }   
}

void seeDraf(){
    int index = searchNamabyRef(&LPengguna,currentUser.nama);
    if(IsEmptyDrafStack(DRAF(ELMT(LPengguna,index)))){
        printf("\nYahh, anda belum memilki draf apapun! buat dulu ya :D\n");
    }else{
        printf("\nIni draf terakhir anda: \n");
        Draf stemp = printLastDraf(DRAF(ELMT(LPengguna,index)));
        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        DATETIME d1 = getLocalTime();
        while (true)
        {
            StartSentence();
            char *pilihan;
            pilihan = currentWord.TabWord;

            
            
            if(isStrEqual(pilihan,"KEMBALI")){
                break;
            }else if(isStrEqual(pilihan,"TERBIT")){
                Kicau k;
                Word tweet;
                strCpy(DrafTweet(stemp),tweet.TabWord);
                tweet.Length = strlength(tweet.TabWord);

                
                TulisDATETIME(d1);
                CreateKicau(&k,IdKicau,0,tweet,currentUser.nama,d1);
                insertLastKicau(&LKicau,k);
                DeleteLastDraf(&DRAF(ELMT(LPengguna,index)));
                // print hasil kicau
                printf("\nSelamat! kicauan telah diterbitkan!\n");
                printKicau(LKicau,IdKicau);
                IdKicau++;
                break;
            }else if(isStrEqual(pilihan,"HAPUS")){
                DeleteLastDraf(&DRAF(ELMT(LPengguna,index)));
                printf("\nDraf telah dihapus!\n\n");
                break;

            }else if(isStrEqual(pilihan,"UBAH")){
                printf("\nMasukkan draf yang baru:\n");
                Word text;
                readKicau(&text);

                printf("\n Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

                while (true)
                {
                    StartSentence();
                    char *pilihan1;
                    pilihan1 = currentWord.TabWord;

                    
                    
                    if(isStrEqual(pilihan1,"SIMPAN")){
                        EditLastDraf(&DRAF(ELMT(LPengguna,index)),text.TabWord);
                        printf("\nDraf telah berhasil disimpan!\n\n");
                        break;
                    }else if(isStrEqual(pilihan1,"TERBIT")){
                        Kicau k;
                        DATETIME d = getLocalTime();
                        
                        CreateKicau(&k,IdKicau,0,text,currentUser.nama,d);
                        insertLastKicau(&LKicau,k);
                        
                        DeleteLastDraf(&DRAF(ELMT(LPengguna,index)));
                        // print hasil kicau
                        printf("\nSelamat! kicauan telah diterbitkan!\n");
                        printKicau(LKicau,IdKicau);
                        IdKicau++;
                        break;
                    }else if(isStrEqual(pilihan1,"HAPUS")){
                        printf("\nPerubahan Draf telah dihapus!\n\n");
                        break;
                    }else{
                        printf("\nWrong Input !! Please re-input : \n");
                    }

                }
                
                break;
    
            }else{
                printf("\nWrong Input !! Please re-input : \n");
            }
        }
        
    }
} 