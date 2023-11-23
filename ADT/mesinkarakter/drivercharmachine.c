#include <stdio.h>
#include <stdlib.h>
#include "charmachine.h"

int main(){
    // Tes Input Command Line
    START();

    printf("%c",currentChar); //membaca dan mengeluarkan karakter pertama
    ADV();
    printf("%c",currentChar); //membaca dan mengeluarkan karakter kedua
    printf("\n");

    // Tes Baca File
    FILE *test;
    test = fopen("test.txt","r");
    STARTFILE(test);
    printf("%c",currentChar); //membaca dan mengeluarkan karakter pertama pada file
    ADVFILE();
    printf("%c",currentChar); //membaca dan mengeluarkan karakter kedua pada file

    // Test lain sesuai keperluan
    // ...

    CLOSE(); //stdin ditutup, tidak bisa lagi memberi input melalui keyboard

    return 0;

}
