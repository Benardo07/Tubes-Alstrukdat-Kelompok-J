/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#include <stdio.h>
#include "../boolean.h"
#include "../datetime/time.h"
#include <time.h>

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int DD;   /* integer [1..31] */
    int MM;   /* integer [1..12] */
    int YYYY; /* integer [1900..2030] */
    TIME T;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
{
    if ((M>=1)&&(M<=7)){
        if (M==2){
        if(Y%400==0){
            return 29;
        }
        else{
            if ((Y%100!=0)&&(Y%4==0)){
                return 29;
            }
            else{
                return 28;
            }
        }
    }
        else if(M%2==1){
        return 31;
    }
        else{
            return 30;
        }
    }
    else{
        if(M%2==0){
        return 31;
    }
        else{
            return 30;
        }
    }
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    return((M>=1)&&(M<=12)&&(Y>=0)&&IsTIMEValid(h,m,s)&&(D<=GetMaxDay(M,Y))&&(D>0));
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    TIME t1;
    Day(*D)= DD;
    Month(*D)= MM;
    Year(*D)=YYYY;
    CreateTime(&t1,hh,mm,ss);
    Time(*D)= t1;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
{
    int dd,mm,yy;
    int h, m, s;
    scanf("%d %d %d",&dd,&mm,&yy);
    scanf("%d %d %d", &h, &m, &s);
    while(!IsDATETIMEValid(dd,mm,yy,h,m,s)){
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d",&dd,&mm,&yy);
        scanf("%d %d %d", &h, &m, &s);;
    }
    CreateDATETIME(D,dd,mm,yy,h,m,s);
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
   {
   printf("%d/%d/%d ",Day(D),Month(D),Year(D));
   TulisTIME(Time(D));
   }

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
{
 return((Day(D1)==Day(D2))&&(Month(D1)==Month(D2))&&(Year(D1)&&Year(D2))&&(TEQ(Time(D1),Time(D2))));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return((Day(D1)!=Day(D2))||(Month(D1)!=Month(D2))||(Year(D1)!=Year(D2))||(TNEQ(Time(D1),Time(D2))));
}
/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean DLT(DATETIME D1, DATETIME D2)
{
    if(Year(D1)<=Year(D2)){
        if(Year(D1)<(Year(D2))){
            return  true;
        }
        else{
            if (Month(D1)>Month(D2)){
                return false;
            }
            else{
                if(Month(D1)<(Month(D2))){
                    return true;
                }
                else{
                    if(Day(D1)>Day(D2)){
                        return false;
                    }
                    else {
                        if(Day(D1)<(Day(D2))){
                            return true;
                            }
                        else{
                            if(TLT(Time(D1),Time(D2))){
                                return false;
                            }
                            else{
                                return false;
                            }
                    }
            }
                }
            }
        }
    }else{
        return false;
    }
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2)
{
    if(Year(D1)>=Year(D2)){
        if(Year(D1)>(Year(D2))){
            return true;
        }
        else{
            if(Month(D1)<Month(D2)){
                return false;
            }
            else{
                if(Month(D1)>(Month(D2))){
                    return true;
                }
                else{
                    if(Day(D1)<Day(D2)){
                        return false;
                    }
                    else{
                        if(Day(D1)>(Day(D2))){
                            return true;
                            }
                        else{
                            if(TGT(Time(D1),Time(D2))){
                                return true;
                            }
                            else{
                                return false;
                            }
                    }
            }
                }
            }
        }
    }
        
    else{
        return true;
    }
}
/* Mengirimkan true jika D1>D2, false jika tidak */
DATETIME DATETIMENextNDetik(DATETIME D, int N){
    int d,m,y;
    d = Day(D);
    m= Month(D);
    y = Year(D);
    TIME t1,t2;
    t1 = Time(D);
    t2 = NextNDetik(t1, N);
    if(TLT(t2,t1)){
        if((d+1)>GetMaxDay(m,y)){
            d=1;
            m=m+1;
            if(m==13){
                m =1;
                y=y+1;
            }
        }
        else{
            d=d+1;
        }
    }
    CreateDATETIME(&D,d,m,y,Hour(t2),Minute(t2),Second(t2));
    return D;
}
/* Mengirim salinan D dengan detik ditambah N */
DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
int d,m,y;
    d = Day(D);
    m= Month(D);
    y = Year(D);
    TIME t1,t2;
    t1 = Time(D);
    t2 = PrevNDetik(t1, N);
    if(TGT(t2,t1)){
        if((d-1)==0){
            d=GetMaxDay(m,y);
            m=m-1;
            if(m==0){
                m =12;
                y=y-1;
            }
        }
        else{
            d=d-1;
        }
    }
    CreateDATETIME(&D,d,m,y,Hour(t2),Minute(t2),Second(t2));
    return D;
}
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    int d1,d2,y1,y2,d,n1,n2;
    y1 = Year(DAw);
    y2 = Year(DAkh);
    d1= 365*y1 + Day(DAw);
    for(int i = 1;i<Month(DAw);i++){
        d1+=GetMaxDay(Month(DAw),Year(DAw));
    }
    if(Month(DAw)<=2){
        y1-=1;
    }
    n1 = y1 / 4;
    n1 -= y1 / 100;
    n1 += y1 / 400;
    d1 += n1;

    d2= 365*y2 + Day(DAkh);
    for(int i = 1;i<Month(DAkh);i++){
        d2+=GetMaxDay(Month(DAkh),Year(DAkh));
    }
    if(Month(DAkh)<=2){
        y2-=1;
    }
    n2 = y2/ 4;
    n2 -= y2 / 100;
    n2 += y2 / 400;
    d2 += n2;

    d = d2-d1;
    d = d*24*60*60;
    return d;

}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */


DATETIME getLocalTime(){
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; 
    int year = localTime->tm_year + 1900;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;
    DATETIME d;
    CreateDATETIME(&d,day,month,year,hour,minute,second);
    return d;
}

void SimpanDATETIME(FILE *f, DATETIME d) {
    fprintf(f, "%d/", Day(d));
    fprintf(f, "%d/", Month(d));
    fprintf(f, "%d ", Year(d));
    fprintf(f, "%02d:", Hour(Time(d)));
    fprintf(f, "%02d:", Minute(Time(d)));
    fprintf(f, "%02d\n", Second(Time(d)));
}