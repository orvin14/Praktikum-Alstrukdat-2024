#include <stdio.h>
#include "complex.h"
#include <math.h>

#ifndef BOOLEAN_H
#define BOOLEAN_H

#define boolean unsigned char
#define TRUE 1
#define FALSE 0

#endif

boolean IsCOMPLEXValid(float Re, float Im){
    return TRUE;
}
/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im){
    Real(*C)= Re;
    Imag(*C)= Im;
}
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C){
    float X,Y;
    scanf("%f %f", &X,&Y);
    CreateComplex(C, X, Y);
}

void TulisCOMPLEX(COMPLEX C){
    if (Imag(C)>=0){
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    }
}
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */


/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C;
    CreateComplex(&C, Real(C1)+Real(C2), Imag(C1)+Imag(C2));
    return C;
}
/* Mengirim hasil penjumlahan C1 + C2 */

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C;
    CreateComplex(&C, Real(C1)-Real(C2),Imag(C1)-Imag(C2));
    return C;
}
/* Mengirim hasil pengurangan C1 - C2 */

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C;
    CreateComplex(&C,(Real(C1)*Real(C2)-Imag(C1)*Imag(C2)), Real(C1)*Imag(C2)+Imag(C1)*Real(C2));
    return C;
}
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX C;
    float denom=powf(Real(C2),2)+powf(Imag(C2),2);
    if (denom) {
        COMPLEX C3= MultiplyCOMPLEX(C1,ConjugateCOMPLEX(C2));
        float C3_Real=Real(C3)/denom;
        float C3_Imag=Imag(C3)/denom;
        CreateComplex(&C, C3_Real,C3_Imag);
    } else{
        CreateComplex(&C, 0, 0);
    }
    return C;
}
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C){
    float abs;
    abs=sqrt(powf(Real(C),2)+powf(Imag(C),2));
    return abs;
}
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */

COMPLEX ConjugateCOMPLEX(COMPLEX C){
    COMPLEX C1;
    CreateComplex(&C1, Real(C), (-1)*Imag(C));
    return C1;
}
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2){
    return (Real(C1)==Real(C2))&&(Imag(C1)==Imag(C2));
}
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return (Real(C1)!=Real(C2)) || (Imag(C1)!=Imag(C2));
}
/* Mengirimkan true jika C1 tidak sama dengan C2 */
