#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minheap.h"

// Bellek ayýrarak kuyruðu baþlatma (Hocanýn istediði malloc)
Kuyruk* kuyruk_olustur(int baslangic_kapasite) {
    Kuyruk* k = (Kuyruk*)malloc(sizeof(Kuyruk));
    k->kapasite = baslangic_kapasite;
    k->eleman_sayisi = 0;
    k->dizi = (Istek*)malloc(baslangic_kapasite * sizeof(Istek));
    return k;
}

// Belleði temizleme (Hocanýn istediði free - bellek sýzýntýsý önleme)
void kuyruk_yok_et(Kuyruk* k) {
    free(k->dizi);
    free(k);
}

// Kuyruða yeni istek ekleme ve Min-Heap sýralamasý yapma
void istek_ekle(Kuyruk* k, int id, const char* rfc_metni) {
    // Eðer dizi dolduysa kapasiteyi 2 katýna çýkar (Hocanýn istediði realloc)
    if (k->eleman_sayisi == k->kapasite) {
        k->kapasite *= 2;
        k->dizi = (Istek*)realloc(k->dizi, k->kapasite * sizeof(Istek));
    }

    // Basit RFC Parser: Sadece "u=3" gibi bir metinden sayýyý alýyoruz
    int aciliyet_degeri = 3; // Varsayýlan deðer
    char* u_yeri = strstr(rfc_metni, "u=");
    if (u_yeri != NULL) {
        aciliyet_degeri = u_yeri[2] - '0'; // Karakteri rakama çevir
    }

    // Ýsteði dizinin en sonuna ekle
    Istek yeni_istek = {id, aciliyet_degeri};
    int i = k->eleman_sayisi;
    k->dizi[i] = yeni_istek;
    k->eleman_sayisi++;

    // Heapify-Up (Aþaðýdan yukarýya doðru acil olanlarý taþý)
    while (i != 0 && k->dizi[(i - 1) / 2].aciliyet > k->dizi[i].aciliyet) {
        // Ebeveyn ile yer deðiþtir
        Istek gecici = k->dizi[i];
        k->dizi[i] = k->dizi[(i - 1) / 2];
        k->dizi[(i - 1) / 2] = gecici;
        i = (i - 1) / 2;
    }
}

// Kuyruktan en acil olaný alma (Heapify-Down)
Istek en_acil_istegi_al(Kuyruk* k) {
    if (k->eleman_sayisi == 0) {
        Istek bos = {-1, -1};
        return bos;
    }

    // En tepedeki (en acil) elemaný al
    Istek en_acil = k->dizi[0];
    
    // En sondaki elemaný en tepeye koy ve sayýyý azalt
    k->dizi[0] = k->dizi[k->eleman_sayisi - 1];
    k->eleman_sayisi--;

    // Heapify-Down (Tepeden aþaðýya doðru düzenle)
    int i = 0;
    while (2 * i + 1 < k->eleman_sayisi) {
        int sol = 2 * i + 1;
        int sag = 2 * i + 2;
        int en_kucuk = i;

        if (k->dizi[sol].aciliyet < k->dizi[en_kucuk].aciliyet) en_kucuk = sol;
        if (sag < k->eleman_sayisi && k->dizi[sag].aciliyet < k->dizi[en_kucuk].aciliyet) en_kucuk = sag;

        if (en_kucuk == i) break; // Sýralama düzgünse dur

        // Yer deðiþtir
        Istek gecici = k->dizi[i];
        k->dizi[i] = k->dizi[en_kucuk];
        k->dizi[en_kucuk] = gecici;
        i = en_kucuk;
    }

    return en_acil;
}
