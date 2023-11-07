# include "queue.h"
# include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q) = -1;
    IDX_TAIL(*q) = -1;
};
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q){
    return (IDX_HEAD(q) == -1 && IDX_TAIL(q)==-1);
};
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isQueueFull(Queue q){
    return (((IDX_TAIL(q)+1) % CAPACITYQ == IDX_HEAD(q)));
};
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueue(Queue q){
    if (isQueueEmpty(q)){
        return 0;
    }else if(isQueueFull(q)){
        return CAPACITYQ;
    }else{
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            return (IDX_TAIL(q)- IDX_HEAD(q) + 1);
        }else{
            return(CAPACITYQ+(IDX_TAIL(q)- IDX_HEAD(q) + 1));
        }
    }
};
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, int val){
    if(isQueueEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }else{
        IDX_TAIL(*q) = (IDX_TAIL(*q)+1) % CAPACITYQ;
        TAIL(*q) = val;
    }
};
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, int *val){
    *val = HEAD(*q);
    if (lengthQueue(*q) - 1 == 0){
        IDX_HEAD(*q) = -1;
        IDX_TAIL(*q) = -1;
    }else{
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1) % CAPACITYQ;
    }
};
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    int i,val;
    printf("[");
    if(!isQueueEmpty(q)){
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i+1)%CAPACITYQ){
            printf("%d", q.buffer[i]);
            if(!isQueueEmpty(q)){
                printf(",");
            }     
        }
        printf("%d", TAIL(q));
    }
    printf("]");
    printf("\n");
};
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */


