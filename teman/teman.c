# include <stdio.h>
# include "ADT/graf/graf.h"
# include "ADT/boolean.h"

// void DaftarTeman()
#include <stdlib.h>
#include <sys/stat.h>
#include "adt\mesinkarakter\charmachine.h"
#include "adt\mesinkata\wordmachine.h"
#include "adt\liststatik\listpengguna.h"
#include "ADT\listlinier\kicau.h"
#include "ADT\graf\graf.h"
#include "adt\boolean.h"
#include "main.h"

//inisialisasi variabel di luar supaya bisa langsung diakses semua function (gk usah oper parameter), tapi! lokalisasi buruk
ListPengguna LPengguna;
List LKicau;
int JumlahId = 1;
ListPengguna users[20];
graf Teman;
