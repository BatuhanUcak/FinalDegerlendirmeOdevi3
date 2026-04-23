#ifndef MINHEAP_H
#define MINHEAP_H

// Çok basit bir İstek yapısı
typedef struct {
    int id;           // İsteğin numarası
    int aciliyet;     // 0 en acil, 7 en az acil
} Istek;

// Min-Heap Kuyruğu
typedef struct {
    Istek* dizi;      // İstekleri tutacağımız dinamik dizi
    int kapasite;     // Dizinin alabileceği max eleman
    int eleman_sayisi;// Şu an içindeki eleman sayısı
} Kuyruk;

// Fonksiyonlarımızın listesi
Kuyruk* kuyruk_olustur(int baslangic_kapasite);
void kuyruk_yok_et(Kuyruk* k);
void istek_ekle(Kuyruk* k, int id, const char* rfc_metni);
Istek en_acil_istegi_al(Kuyruk* k);

#endif