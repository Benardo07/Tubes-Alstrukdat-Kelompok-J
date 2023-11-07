/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* Kicau adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(Kicau val){
    Address new = (Address) malloc (sizeof(Node));
    INFO(new) = val;
    NEXT(new) = NULL;
    return new;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyListLinier(List l){
    return (FIRST(l)==NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Kicau getElmt(List l, int idx){
    int ctr = 0;
    Address p = l;
    while (ctr<idx){
        ctr= ctr+1;
        p = NEXT(p);
    }
    return(INFO(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, Kicau val){
    int ctr = 0;
    Address p = *l;
    while (ctr < idx){
        ctr = ctr +1;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, int id){
    int idx = 0;
    Address p = l;
    boolean found = false;
    while (p!=NULL && !found){
        if (id(p)==id){
            found = true;
        }
        else{
            idx +=1;
            p = NEXT(p);
        }
    }
    if (found){
        return(idx);
    }
    else{
        return(IDXUNDEF);
    }
}

void AddBalasanKicauAt(List *l, int id,Tree T){
    Address p = *l;
    boolean found = false;
    while ((p!=NULL && !found))
    {
        if(id(p) == id){
            found = true;
            insertLastDinTree(&CHILDREN(Balas(p)),T);
        }else{
            p = NEXT(p);
        }
    }   
}


void setLastId(List *l, int id, int lastID){
    Address p = *l;
    boolean found = false;
    while (p != NULL && !found)
    {
        if(id(p) == id){
            found = true;
            lastId(p) = lastID;
        }else{
            p = NEXT(p);
        }
    }
    
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, Kicau val){
    Address p = newNode(val);
    if (p!=NULL){
        NEXT(p) = *l;
        *l = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastKicau(List *l, Kicau val){
    Address p,loc;
    if(isEmptyListLinier(*l)){
        insertFirst(l,val);
    }
    else{
        p=newNode(val);
        loc = *l;
        while (NEXT(loc)!=NULL){
            loc = NEXT(loc);
        }
        NEXT(loc) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, Kicau val, int idx){
    int ctr;
    Address p,loc;
    if (idx==0){
        insertFirst(l,val);
    }
    else{
        p = newNode(val);
        ctr = 0;
        loc = *l;
        while (ctr<idx-1){
            ctr = ctr+1;
            loc = NEXT(loc);
        }
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, Kicau *val){
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, Kicau *val){
    Address p,loc;
    p = *l;
    loc = NULL;
    while (NEXT(p)!=NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, Kicau *val){
    int ctr;
    Address p,loc;
    if (idx==0){
        deleteFirst(l,val);
    }
    else{
        ctr = 0;
        loc = *l;
        while (ctr<idx-1){
            ctr+=1;
            loc= NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    if (isEmptyListLinier(l)){
        printf("[]");
    }
    else{
        Address p = l;
        printf("[");
        while (p!=NULL){
            if (NEXT(p) != NULL) {
                printf("%d,", INFO(p));
            }else {
                printf("%d", INFO(p));
            }
            p = NEXT(p);
        }
        printf("]");
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int ctr = 0;
    Address p = l;
    if (isEmptyListLinier(l)){
        return 0;
    }
    while (p!=NULL){
        ctr+=1;
        p = NEXT(p);
    }
    return(ctr);
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    Address p;
    List l3;
    CreateList(&l3);
    p = l1;
    while (p!=NULL){
        insertLastKicau(&l3,INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p!=NULL){
        insertLastKicau(&l3,INFO(p));
        p = NEXT(p);
    }
    return(l3);
}

boolean fSearch(List L, Address P){
    Address loc = L;
    boolean found = false;
    while(loc!=NULL && !found){
        if (loc==P){
            found = true;
        }
        else{
            loc = NEXT(loc);
        }
    }
    return found;
}

// Address searchPrec(List L,Kicau X){
//     Address p,loc;
//     Kicau temp;
//     p = L;
//     loc = NULL;
//     while (p!=NULL){
//         if (INFO(p)==X){
//             return loc;
//         }else{
//             loc = p;
//             p = NEXT(p);
//         }
//      }
//      return NULL;
// }

// Address adrMax(List l){
//     Address max = l;
//     Address p = l;
//     p = NEXT(p);
//     while (p!=NULL){
//         if(INFO(p)>INFO(max)){
//             max = p;
//         }
//         p=NEXT(p);
//     }
//     return max;
// }

// Kicau max(List l){
//     return(INFO(adrMax(l)));
// }

// Address adrMin(List l){
//     Address max = l;
//     Address p = l;
//     p = NEXT(p);
//     while (p!=NULL){
//         if(INFO(p)<INFO(max)){
//             max = p;
//         }
//         p=NEXT(p);
//     }
//     return max;
// }

// Kicau min(List l){
//     return(INFO(adrMin(l)));
// }

void deleteAll(List *l){
    Address p = *l;
    Kicau val;
    while(!isEmptyListLinier(*l)){
        deleteFirst(l,&val);
    }
}

void copyList(List *l1, List *l2){
    CreateList(l2);
    *l2=*l1;
}

void inverseList(List *l){
    Address p = *l;
    Kicau temp;
    for(int i = 0; i<length(*l)/2;i++){
        temp = getElmt(*l,i);
        setElmt(l,i,getElmt(*l,length(*l)-1-i));
        setElmt(l,length(*l)-1-i,temp);
    }
}

void splitList(List *l1, List *l2, List l){
    CreateList(l1);
    CreateList(l2);

    Address p, loc, pNew;
    int i=0;
    p=l;
    while (p!=NULL){
        pNew = newNode(INFO(p));
        if (i<length(l)/2){
            insertLastKicau(l1, INFO(pNew));
        }else{
            insertLastKicau(l2, INFO(pNew));
        }
        free(pNew);
        p=NEXT(p);
        i++;
    } 
}