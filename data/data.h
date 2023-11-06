#include <stdio.h>
#include <stdlib.h>
#include "../ADT/liststatik/listpengguna.h"
#include "../kicauan/kicauan.h"
#include "../ADT/graf/graf.h"
#include "../ADT/boolean.h"
#include "../ADT/stack/drafStack.h"
#include "../primitif/primitif.h"
#include "../utas/utas.h"
#include "../ADT/listdin/listdinutas.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/mesinkata/wordmachine.h"
#include "../ADT/mesinkarakter/charmachine.h"

extern ListPengguna LPengguna;
extern ListPengguna users[20];
extern Graf Teman;
extern List LKicau;
extern DrafStack sDraf;
extern Pengguna currentUser;
extern int IdCurrentUser;
extern int IdKicau;

extern char currentChar;
extern boolean EOP;

extern char currentChar;
extern boolean EOP;

boolean Muat();

boolean MuatPengguna(char *namafolder);

boolean MuatKicauan(char *namafolder);

boolean MuatUtas(char *namafolder);

boolean MuatDraf (char *namafolder);

boolean MASUK();

void DAFTAR();

