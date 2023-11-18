#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"
#include "../mesinkarakter/charmachine.h"
#include "mesinkalimat.h"

Sentence currentSentence;
boolean EndSentence;

void IgnoreBlanksS()
{
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        ADV();
    }
}

void StartSentence()
{
    ClearSentence(&currentSentence);

    START();
    //Word currentWord;

    IgnoreBlanksS();
    if (currentChar == MARK) {
        EndSentence = true;
    } else {
        EndSentence = false;

        // Copy Sentence
        // Asumsi panjang sentence (nama/sandi/etc) < NMax
        CopySentence();
    }
}

void AdvSentence() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksS();
    if (currentChar == MARK) EndSentence = true;
    else CopySentence();
}

void CopySentence()
{
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i=0;
    do {
        if (i < NMax) {
            currentSentence.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    } while (currentChar != MARK);
    currentSentence.Length = i;
}

void ClearSentence(Sentence *sentence)
{
    int i;

    for(i=0;i<sentence->Length;i++){
        sentence->TabWord[i] = '\0';
    }
    sentence->Length = 0;
}

void printSentence(Sentence sentence) {
   int i;
   for (i = 0; i < sentence.Length; i++) {
      printf("%c", sentence.TabWord[i]);
   }
}

void readLineFile(){
    ClearSentence(&currentSentence);
    int i=0;
    while (currentChar != '\n') {
        if (i < NMax) {
            currentSentence.TabWord[i] = currentChar;
            i++;
        }
        ADVFILE();
    }
    currentSentence.Length = i;
    ADVFILE();
}
