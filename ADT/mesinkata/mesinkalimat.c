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
    int i = 0;
    int lastNonSpaceIndex = -1;  // Initialize to -1 to indicate no non-space character seen yet

    while (currentChar != '\n' && !EOP) {
        if (i < NMax) {
            currentSentence.TabWord[i] = currentChar;

            // Update lastNonSpaceIndex if current character is not a space
            if (currentChar != ' ' && currentChar != '\f' && currentChar != '\r' && currentChar != '\t' && currentChar != '\v') {
                lastNonSpaceIndex = i;
            }

            i++;
        }
        ADVFILE();
    }

    // Trim trailing spaces by adjusting the length
    if (lastNonSpaceIndex != -1) {
        currentSentence.Length = lastNonSpaceIndex + 1;
        currentSentence.TabWord[currentSentence.Length] = '\0';
    } else {
        currentSentence.Length = 0;  // If the line is only spaces, set length to 0
    }

    // Move past the newline character if not at EOP
    if (!EOP) {
        ADVFILE();
    }

}

void readTwoValuesLine(int *num1, int *num2) {
    ClearSentence(&currentSentence);
    *num1 = 0;
    *num2 = 0;
    int sign = 1;

    // Read first number
    if (currentChar == '-') {
        sign = -1;
        ADVFILE();
    }
    while (currentChar != ' ' && currentChar != '\f' && 
           currentChar != '\r' && currentChar != '\t' && 
           currentChar != '\v' && !EOP) {
        *num1 = (*num1 * 10) + (currentChar - '0');
        ADVFILE();
    }
    *num1 *= sign;

    // Skip to next number
    while (currentChar == ' ' && !EOP) {
        ADVFILE();
    }

    // Read second number
    sign = 1;
    if (currentChar == '-') {
        sign = -1;
        ADVFILE();
    }
    while (currentChar != ' ' && currentChar != '\n' && 
           currentChar != '\f' && currentChar != '\r' && 
           currentChar != '\t' && currentChar != '\v' && !EOP) {
        *num2 = (*num2 * 10) + (currentChar - '0');
        ADVFILE();
    }
    *num2 *= sign;
    if(currentChar == '\n'){
        ADVFILE();
    }
}