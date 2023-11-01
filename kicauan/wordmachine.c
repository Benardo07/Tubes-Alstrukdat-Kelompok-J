# include <stdio.h>
# include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

// void IgnoreBlanks(){
//     while (currentChar==BLANK){
//         ADV();
//     }
// }
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    if (currentChar==MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter perama sesudah karakter terakhir kata */

void ADVWORD(){
    if (currentChar==MARK){
        EndWord = true;
    }
    else{
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while (currentChar != MARK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        if (i!=NMax){
            i++;
        }
    }
    currentWord.Length = i;
}

void LOWER(){
    for(int i=0;i<currentWord.Length;i++){
    if(currentWord.TabWord[i]>=65 && currentWord.TabWord[i]<=90){
        currentWord.TabWord[i] =  currentWord.TabWord[i] + 32;
    }
    }
}

boolean isEqual(Word w1,Word w2){
    boolean sama = true;
    if(w1.Length!=w2.Length){
        sama = false;
    }
    else{
        for(int i=0;i<w1.Length;i++){
            if(w1.TabWord[i]!=w2.TabWord[i]){
                sama = false;
            }
        }
    }
    return sama;
}

void readWord(Word *input){
    int i;
    START();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

void readKicau(Word *input){
    int i;
    START();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        if (i<=280){
            (*input).TabWord[i] = currentChar;
        }
        if(i==280){
            (*input).TabWord[i] = '\0';
        }
        ADV();
        i++;
    }

    (*input).Length = i;
}

// cek apakah hanya berisi spasi atau tidak
boolean allSpace(Word input){
    boolean space = true;
    for(int i=0;i<input.Length;i++){
        if(input.TabWord[i]!=' '){
            space=false;
        }
    }
    return space;
}

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}