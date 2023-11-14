#include "../data/data.h"
#include "../teman/teman.h"

void balasKicauan(int idkic,int idbal,List *l);
void printSemuaBalasan(int idKicau);
void printBalasanWithIndent(Balasan B, int depth);
void printBalasanPrivate(Balasan B,int depth);
void printAllBalasanWithIndent(Tree T, int depth);
void hapusBalasan(int idkic , int idbal);