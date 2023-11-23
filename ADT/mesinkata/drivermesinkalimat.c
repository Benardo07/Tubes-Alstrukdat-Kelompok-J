#include <stdio.h>
#include <stdlib.h>
#include "mesinkalimat.h"

int main()
{
    // Tes Start Sentence
    StartSentence();
    printf("%s\n",currentSentence.TabWord);
    printf("%d\n",currentSentence.Length);

    // Tes menerima input ulang
    StartSentence();
    printf("%s\n",currentSentence.TabWord);
    printf("%d\n",currentSentence.Length);

    // Tes Clear Sentence
    ClearSentence(&currentSentence);
    printf("%s\n",currentSentence.TabWord);
    printf("%d\n",currentSentence.Length);

    // Tes baca file
    FILE *test;
    test = fopen("test.txt","r");
    STARTFILE(test);

        // baca line pertama
    readLineFile();
    printf("%s\n",currentSentence.TabWord);
    printf("%d\n",currentSentence.Length);

        // baca line kedua
    readLineFile();
    printf("%s\n",currentSentence.TabWord);
    printf("%d\n",currentSentence.Length);

    // Tes lain sesuai keperluan
    /* ... */

    return 0;
}
