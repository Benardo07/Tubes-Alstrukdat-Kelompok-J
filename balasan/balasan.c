#include "balasan.h"

void balasKicauan(int idkic,int idbal ,List *l){
    if(indexOf(*l,idkic) == IDXUNDEF){
        printf("\nWah, tidak terdapat kicauan yang ingin Anda balas!\n");
    }else if(idbal != -1 && findBalasanInTree(getElmt(*l,indexOf(*l,idkic)).Balas,idbal) == NULL){
        printf("\nWah, tidak terdapat balasan yang ingin Anda balas!\n");
    }else if(isPenggunaPrivate(&LPengguna, getElmt(*l,indexOf(*l,idkic)).author)  && !isTeman(findIDPenggunaByName(&LPengguna,currentUser.nama), findIDPenggunaByName(&LPengguna,getElmt(*l,indexOf(*l,idkic)).author))){
        printf("\nWah, akun tersebut merupakan akun private dan anda belum berteman dengan akun tersebut!\n");
    }else if(idbal != -1 && isPenggunaPrivate(&LPengguna,BALASAN(findBalasanInTree(getElmt(*l,indexOf(*l,idkic)).Balas,idbal)).writer) && !isTeman(findIDPenggunaByName(&LPengguna,currentUser.nama), findIDPenggunaByName(&LPengguna,BALASAN(findBalasanInTree(getElmt(*l,indexOf(*l,idkic)).Balas,idbal)).writer))){
        printf("\nWah, akun tersebut merupakan akun private dan anda belum berteman dengan akun tersebut!\n");
    }else{
        printf("\nMasukkan balasan : \n");
        Word text;
        readKicau(&text);
        Balasan B;
        int IdBalasan = getElmt(*l,indexOf(*l,idkic)).lastIDBalas + 1;
        DATETIME d = getLocalTime();
        CreateBalasan(&B,IdBalasan,text.TabWord,currentUser.nama,d);
        Tree T = newTree(B,1000);
        if(idbal == -1){
            AddBalasanKicauAt(l,idkic,T);
        }else{
            Kicau tempKicau = getElmt(*l,indexOf(*l,idkic));
            insertLastDinTree(&CHILDREN(findBalasanInTree(tempKicau.Balas,idbal)),T);
        }
        setLastId(l,idkic,IdBalasan);
        printf("Selamat! balasan telah diterbitkan\n");
        printf("Detail balasan :\n");
        printBalasan(B);
        printf("\n");
    }
}


void printSemuaBalasan(int idKicau){
    printAllBalasanWithIndent(getElmt(LKicau,indexOf(LKicau,idKicau)).Balas,0);
}

void printAllBalasanWithIndent(Tree T, int depth) {
    if(T == NULL){
        return;
    }

    // Print the current node's Balasan with indentation
    if(depth != 0){
        if(isPenggunaPrivate(&LPengguna,BALASAN(T).writer) && !isTeman(findIDPenggunaByName(&LPengguna,currentUser.nama), findIDPenggunaByName(&LPengguna,BALASAN(T).writer))){
            printBalasanPrivate(BALASAN(T), depth);
        }else{
            printBalasanWithIndent(BALASAN(T), depth);
        }
        
    }
    
    // Recursively call the function on all children with increased depth
    int i;
    for(i = getFirstIdxDinTree(CHILDREN(T)); i <= getLastIdxDinTree(CHILDREN(T)); i++){
        printAllBalasanWithIndent(ELMTDINTREE(CHILDREN(T), i), depth + 1);
    }
}

void printBalasanPrivate(Balasan B,int depth){
    printf("\n");
    for(int i = 0; i < depth -1; i++) {
        printf("    "); // 4 spaces for each level of indent
    }
    printf("| ID = %d\n", IDBalasan(B));
    
    for(int i = 0; i < depth -1; i++) {
        printf("    ");
    }
    printf("| %s\n", "PRIVAT");
    
    for(int i = 0; i < depth - 1; i++) {
        printf("    ");
    }
    printf("| %s\n", "PRIVAT");
    
    for(int i = 0; i < depth-1; i++) {
        printf("    ");
    }
    printf("| %s\n", "PRIVAT");
}
void printBalasanWithIndent(Balasan B, int depth){
    printf("\n");
    for(int i = 0; i < depth -1; i++) {
        printf("    "); // 4 spaces for each level of indent
    }
    printf("| ID = %d\n", IDBalasan(B));
    
    for(int i = 0; i < depth -1; i++) {
        printf("    ");
    }
    printf("| %s\n", WriterBalasan(B));
    
    for(int i = 0; i < depth - 1; i++) {
        printf("    ");
    }
    printf("| ");
    TulisDATETIME(WaktuBalasan(B));
    printf("\n");
    
    for(int i = 0; i < depth-1; i++) {
        printf("    ");
    }
    printf("| %s\n", TweetBalasan(B));
}

void hapusBalasan(int idkic , int idbal){
    if(indexOf(LKicau,idkic) == IDXUNDEF){
        printf("Tidak anda kicauan dengan id tersebut.\n");
    }else if(findBalasanInTree(getElmt(LKicau,indexOf(LKicau,idkic)).Balas,idbal) == NULL){
        printf("Balasan tidak ditemukan. \n");
    }else if(!isStrEqual(findBalasanInTree(getElmt(LKicau,indexOf(LKicau,idkic)).Balas,idbal)->B.writer,currentUser.nama)){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
    }else{
        Tree temp = findBalasanInTree(getElmt(LKicau,indexOf(LKicau,idkic)).Balas,idbal);
        Tree parentTemp = findBalasanParentInTree(getElmt(LKicau,indexOf(LKicau,idkic)).Balas,idbal,NULL);
        printAllBalasanWithIndent(parentTemp,0);
        deleteListDinAt(&CHILDREN(parentTemp),indexOfDinTree(CHILDREN(parentTemp),temp));
        printf("Balasan berhasil di hapus!\n");
    }
}


