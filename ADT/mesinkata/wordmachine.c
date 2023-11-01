#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"
#include "../mesinkarakter/charmachine.h"
#include "wordmachine.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks()
{
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD()
{
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    ClearWord(&currentWord);

    START();
    //Word currentWord;

    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK) EndWord = true;
    else CopyWord();
}

void CopyWord()
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
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    } while (currentChar != MARK && currentChar != BLANK);
    currentWord.Length = i;
}

void ClearWord(Word *word)
{
    int i;

    for(i=0;i<word->Length;i++){
        word->TabWord[i] = '\0';
    }
    word->Length = 0;
}

void StartSentence()
{
    ClearWord(&currentWord);

    START();
    //Word currentWord;

    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;

        // Copy Sentence
        // Asumsi panjang sentence (nama/sandi/etc) < NMax
        int i=0;
        do {
            if (i < NMax) {
                currentWord.TabWord[i] = currentChar;
                i++;
            }
            ADV();
        } while (currentChar != MARK);
        currentWord.Length = i;
    }
}
