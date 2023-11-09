#include <stdio.h>
#include <stdlib.h>
#include "../ADT/liststatik/listpengguna.h"
#include "../kicauan/kicauan.h"
#include "../ADT/graf/graf.h"
#include "../ADT/boolean.h"
#include "../ADT/stack/drafStack.h"
#include "../primitif/primitif.h"
#include "../utas/utas.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/mesinkarakter/charmachine.h"
#include "../ADT/tree/tree.h"
#include "../ADT/listdin/listdin.h"


extern ListPengguna LPengguna;
extern ListPengguna users[20];
extern Graf Teman;
extern List LKicau;
extern DrafStack sDraf;
extern Pengguna currentUser;
extern int IdCurrentUser;
extern int IdKicau;
extern int IdUtas;

extern char currentChar;
extern boolean EOP;

extern char currentChar;
extern boolean EOP;

boolean Muat();

boolean Simpan();

void SimpanPengguna(char *namaFolder);

void SimpanKicauan(char *namaFolder);

boolean MuatPengguna(char *namafolder);

boolean MuatKicauan(char *namafolder);

boolean MuatUtas(char *namafolder);

boolean MuatDraf (char *namafolder);

boolean MuatBalasan (char *namafolder);

boolean MASUK();

void DAFTAR();

