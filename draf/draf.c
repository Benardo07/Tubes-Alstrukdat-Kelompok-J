#include <stdio.h>
#include "draf.h"

void makingDraf (){
    printf("\nMasukkan draf:\n");
    Word text;
    readKicau(&text);
    
    printWord(text);
    // Ambil waktu lokal
    time_t currentTime;
    struct tm *localTime;

    
    DATETIME d = getLocalTime();
    Draf tempDraf;
    CreateDraf(&tempDraf,currentUser.id,text.TabWord,currentUser.nama,d);
    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    
    while(true){
        StartSentence();
        char *pilihan;
        pilihan = currentWord.TabWord;
        
        
        if(isStrEqual(pilihan,"SIMPAN")){
            PushDrafStack(&sDraf,tempDraf);
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
    if(!findDraf(sDraf, currentUser.id)){
        printf("\nYahh, anda belum memilki draf apapun! buat dulu ya :D\n");
    }else{
        printf("\nIni draf terakhir anda: \n");
        Draf stemp = printLastDraf(sDraf, currentUser.id);
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
                DeleteDrafAt(&sDraf,currentUser.id);
                // print hasil kicau
                printf("\nSelamat! kicauan telah diterbitkan!\n");
                printKicau(LKicau,IdKicau);
                IdKicau++;
                break;
            }else if(isStrEqual(pilihan,"HAPUS")){
                DeleteDrafAt(&sDraf,currentUser.id);   
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
                        EditDrafAt(&sDraf, currentUser.id, text.TabWord);
                        printf("\nDraf telah berhasil disimpan!\n\n");
                        break;
                    }else if(isStrEqual(pilihan1,"TERBIT")){
                        Kicau k;
                        DATETIME d = getLocalTime();
                        
                        CreateKicau(&k,IdKicau,0,text,currentUser.nama,d);
                        insertLastKicau(&LKicau,k);
                        
                        DeleteDrafAt(&sDraf,currentUser.id);
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