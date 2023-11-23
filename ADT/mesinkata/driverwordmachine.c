#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

int main()
{
    // Tes Start Word
    STARTWORD();
    printf("%s\n",currentWord.TabWord);
    printf("%d\n",currentWord.Length);

    // Tes Adv Word
    ADVWORD();
    printf("%s\n",currentWord.TabWord);
    printf("%d\n",currentWord.Length);

    // Tes Clear Word
    ClearWord(&currentWord);
    printf("%s\n",currentWord.TabWord);
    printf("%d\n",currentWord.Length);

    // Tes lain sesuai keperluan
    /* ... */

    return 0;
}
