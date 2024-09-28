#include "liststatik.h"
#include <stdio.h>
void CreateListStatik(ListStatik *l){
    int i;
    for (i=0;i<CAPACITY;i++){
        ELMT(*l,i)=MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int count=0,i=0;
    while (ELMT(l,i)!=MARK&&count<CAPACITY)
    {
        i+=1;
        count+=1;
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    int i=0;
    if (listLength(l)>0){
        IdxType firstIdx=0;
        while (ELMT(l,i)==MARK)
        {
            i+=1;
            firstIdx+=1;
        }
        return firstIdx;
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
    if (listLength(l) > 0) {
        IdxType lastIdx = IDX_UNDEF;
        for (int i = 0; i < CAPACITY; i++) {
            if (ELMT(l, i) != MARK) { // Jika elemen valid
                lastIdx = i; // Update lastIdx
            }
        }
        return lastIdx;
    }
}/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return i>=IDX_MIN && i<=CAPACITY-1;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i){
    return i>=IDX_MIN && i<=listLength(l)-1;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    return listLength(l)==0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
    return listLength(l)==CAPACITY;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
    int n,i,elemen;
    scanf("%d",&n);
    while (n<0||n>CAPACITY)
    {
        scanf("%d",&n);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &elemen);
        ELMT(*l, i) = elemen; // Store the element in the list
    }

    // Mark the rest of the list as unused
    for (; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l){
    int i;
    int firstelprinted=0;
    printf("[");
    for (i=0;i<CAPACITY;i++){
        if (ELMT(l,i)!=MARK){
            if (firstelprinted){
                printf(",");
            }
            printf("%d", ELMT(l,i));
            firstelprinted=1;
        }
        
    }
    printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l3;
    CreateListStatik(&l3);
    int i=0;
    if (listLength(l1)==listLength(l2)){
        if (plus){
            while (ELMT(l1,i)!=MARK)
            {
                ELMT(l3,i)=ELMT(l1,i)+ELMT(l2,i);
                i++;
            }
        } else{
            while (ELMT(l1,i)!=MARK)
            {
                ELMT(l3,i)=ELMT(l1,i)-ELMT(l2,i);
                i++;
            }
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
    int i=0;
    boolean equal=true;
    if (listLength(l1)!=listLength(l2)){
        equal=false;
    } else {
        while (i<CAPACITY&&equal)
        {
            if (ELMT(l1,i)!=ELMT(l2,i)){
                equal=false;
            }
            i++;
        }
    }
    return equal;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
    int i=0;
    int index;
    boolean found=false;
    while (i<CAPACITY&&found==false)
    {
        if (ELMT(l,i)==val){
            found=true;
            index=i;
        }
        i++;
    }
    if (found==false){
        index=IDX_UNDEF;
    } 
    return index;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    int i;
    *min=*max=ELMT(l,0);
    for (i=0;i<CAPACITY;i++){
        if (ELMT(l,i)!=MARK&&ELMT(l,i)>*max){
            *max=ELMT(l,i);
        }
        if (ELMT(l,i)!=MARK&&ELMT(l,i)<*min){
            *min=ELMT(l,i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
    int i;
    if (listLength(*l)<CAPACITY){
        if (listLength(*l)==0){
            ELMT(*l,0)=val;
        } else {
            for (i=getLastIdx(*l);i>=getFirstIdx(*l);i--){
                ELMT(*l,i+1)=ELMT(*l,i);
            }
            ELMT(*l,getFirstIdx(*l))=val;
        }
    }
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
    int i;
    if (listLength(*l)>0&&listLength(*l)<CAPACITY){
        for (i=getLastIdx(*l);i>=idx;i--){
            ELMT(*l,i+1)=ELMT(*l,i);
        }
        ELMT(*l,idx)=val;
    }
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
    int i;
    if (listLength(*l)<CAPACITY){
        if (listLength(*l)==0){
            ELMT(*l,0)=val;
        } else {
            ELMT(*l,getLastIdx(*l)+1)=val;
        }
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
    int i;
    if (listLength(*l)>0){
        *val=ELMT(*l,0);
        for (i=0;i<listLength(*l)-1;i++){
            ELMT(*l,i)=ELMT(*l,i+1);
        }
        ELMT(*l,listLength(*l)-1)=MARK;
    }
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i;
    if (idx < 0 || idx >= listLength(*l)) {
        return; 
    }
    if (listLength(*l)>0){
        *val=ELMT(*l,idx);
        for (i=idx;i<listLength(*l)-1;i++){
            ELMT(*l,i)=ELMT(*l,i+1);
        }
        ELMT(*l,listLength(*l)-1)=MARK;
    }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
    if (listLength(*l)>0){
        int lastIdx = getLastIdx(*l);
        // Store the value of the last element in *val
        *val = ELMT(*l, lastIdx);
        // Mark the last element as deleted
        ELMT(*l, lastIdx) = MARK;
    }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    for (int i = 0; i < listLength(*l) - 1; i++) {
        for (int j = 0; j < listLength(*l) - i - 1; j++) {
            if ((asc && ELMT(*l, j) > ELMT(*l, j + 1)) || 
                (!asc && ELMT(*l, j) < ELMT(*l, j + 1))) {
                // Tukar elemen
                ElType temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j + 1);
                ELMT(*l, j + 1) = temp;
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
