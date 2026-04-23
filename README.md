# FinalDegerlendirmeOdevi3
# RFC 9213 Uyumlu, Modüler API Gateway İstek Zamanlayıcısı (Priority Request Scheduler)

## 📌 Proje Hakkında
Bu proje, **Priority Queue (Öncelikli Kuyruk)** kavramını ve onun implementasyonu olan **Min-Heap algoritmasını** kullanarak gerçeğe yakın bir API Gateway İstek Zamanlayıcısı tasarlamayı amaçlamaktadır.  
İsteklerin öncelik değerleri, **RFC 9213 (Extensible HTTP Priorities)** standardına uygun olarak parse edilmekte ve sistem **C dilinin modüler mimarisi** (header/source ayrımı) ile inşa edilmektedir.

---

## 🏗️ Mimari Yapı
Proje üç ana katmandan oluşmaktadır:
1. **RFC Parser**  
   - HTTP Priority header değerlerini RFC 9213 standardına göre parse eder.
   - `rfc_parser.h` ve `rfc_parser.c` dosyalarında tanımlıdır.

2. **Priority Queue (Min-Heap)**  
   - İstekleri öncelik değerine göre sıralar.  
   - Heapify işlemleri ile verimli ekleme ve çıkarma yapılır.  
   - `priority_queue.h` ve `priority_queue.c` dosyalarında tanımlıdır.

3. **Main Katmanı**  
   - Parser ve Priority Queue bileşenlerini entegre eder.  
   - İsteklerin işlenme sırasını simüle eder.  
   - `main.c` dosyasında bulunur.

📂 **Proje klasör yapısı:**
