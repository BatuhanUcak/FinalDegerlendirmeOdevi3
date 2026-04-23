#include <stdio.h>
#include "minheap.h"

int main() {
    printf("--- Basit API Gateway ---\n\n");

    // Başlangıç kapasitesi 2 olan bir kuyruk oluştur (realloc test edilsin diye)
    Kuyruk* q = kuyruk_olustur(2);

    printf("Istekler sisteme giriyor...\n");
    istek_ekle(q, 101, "u=5"); // Az acil
    istek_ekle(q, 102, "u=1"); // Cok acil
    istek_ekle(q, 103, "u=3"); // Normal
    istek_ekle(q, 104, "u=0"); // En acil!

    printf("\nIstekler isleniyor (Sira Aciliyete Gore Olacak):\n");
    printf("ID\tAciliyet\n");
    printf("----------------\n");

    // Kuyruk bitene kadar elemanları çıkar
    while (q->eleman_sayisi > 0) {
        Istek islenen = en_acil_istegi_al(q);
        printf("%d\t%d\n", islenen.id, islenen.aciliyet);
    }

    // Bellek temizliği (Hocanın dikkat edeceği yer)
    kuyruk_yok_et(q);
    printf("\nSistem temizlendi, kapaniyor.\n");

    return 0;
}