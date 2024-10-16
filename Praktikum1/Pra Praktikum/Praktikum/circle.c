#include "circle.h"
#include <stdio.h>
#include <math.h>
boolean IsCIRCLEValid(float X, float Y, float R){
    return R>0;
}
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    POINT P;
    CreatePoint(&P,X,Y);
    Center(*C)=P;
    Radius(*C)=R;
}
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C){
    float X, Y, R;
    scanf("%f %f %f",&X, &Y, &R);
    while (!(IsCIRCLEValid(X,Y,R)))
    {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f",&X, &Y,&R);
    }
    CreateCIRCLE(C, X, Y, R);
}
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C){
    float x;
    x= 2*3.14*Radius(C);
    return x;
}
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */

float Area(CIRCLE C){
    float x;
    x= 3.14*Radius(C)*Radius(C);
    return x;
}
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    float jarak;
    jarak=Panjang(P,Center(C));
    return jarak<Radius(C);
}
/* Mengirim true jika titik P berada di dalam lingkaran C */

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    float jarak;
    jarak=Panjang(P,Center(C));
    return jarak-Radius(C)<=1e-6;
}
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak=Panjang(Center(C1),Center(C2));
    return jarak<fabs(Radius(C1)-Radius(C2));
}
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
/* d < |R - r| */

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak=Panjang(Center(C1),Center(C2));
    return fabs(jarak-fabs(Radius(C1)+Radius(C2)))<=1e-6||(jarak-fabs(Radius(C1)-Radius(C2)))<=1e-6;
}
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
 /*
 * d = R + r
 * d = |R - r|
 */

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float jarak;
    jarak=Panjang(Center(C1),Center(C2));
    return jarak>fabs(Radius(C1)-Radius(C2))&&jarak<(Radius(C1)+Radius(C2));
}
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
/* |R - r| < PQ < R + r */

/* ***************************************************************** */