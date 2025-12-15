# Return Zer0

## Deskripsi Program
Return Zer0 merupakan permainan kuis berbasis terminal yang bertujuan untuk menguji dan melatih pemahaman konsep pemrograman bahasa C. Permainan ini menyajikan soal pilihan ganda yang terbagi ke dalam beberapa level dengan tingkat kesulitan bertahap, yaitu level dasar, menengah, dan mahir, serta terdapat level bonus soal CPP jika pemain berhasil menjawab lebih dari 12 soal dengan benar.

---

## Fitur Utama
1. **Soal Berbasis Level** 
    - Program menyediakan soal kuis yang terbagi menjadi beberapa level dengan bobot skor yang berbeda tiap levelnya. Soal dimuat dari file eksternal (soal.txt) sehingga mudah diperbarui tanpa mengubah kode program.
2. **Sistem Save dan Load**
    - Program menyediakan fitur penyimpanan dan pemanggilan progres permainan untuk melanjutkan permainan yang telah disimpan di save.txt.
3. **Mekanisme skor dan nyawa (Health Points)**
    - Setiap pemain akan memperoleh skor dari setiap jawaban benar dengan jumlah poin yang berbeda sesuai tingkat level soal. Pemain juga akan memperoleh 3 nyawa di awal permainan, nyawa akan berkurang 1 jika jawaban salah, dan permainan akan berakhir (game over) ketika nyawa 0.
4. **Leaderboard**
    - Program akan menampilkan daftar 5 nama pemain dengan skor tertinggi, beserta level terakhir yang dicapai. 
5. **Menu Utama**
    - Program akan menampilkan beberapa menu, yaitu Mulai Baru, Lanjutkan, Leaderboard, Credits, dan Keluar.

---

## Persyaratan Sistem
    - Compiler C: Diperlukan menggunakan GCC (GNU Compiler Collection) atau kompiler setara (seperti Clang/MinGw).
    - Sistem Operasi: Windows, Linux, atau macOS.

---

## Struktur file
    - 'main.c' : Berisi kode sumber utama program Return Zer0.
    - 'soal.txt' : Menyimpan data soal kuis yang akan dimuat ke dalam program.
    - 'save.txt' : Menyimpan data progres permainan.
    - 'leaderboard.txt' : Menyimpan data skor tertinggi pemain.

---

## Cara Instalasi
### Melalui GitHub
    - Buka repository program Return Zer0 di GitHub.
    - Pilih Code -> Download ZIP, lalu ekstrak folder program atau lakukan clone repository, caranya:
        -```bash 
          git clone https://github.com/justhenix/return-zer0.git
    - Masuk ke folder repository hasil clone atau ekstraksi .
    - Pastikan struktur file dan floder tidak berubah.

### Melalui Google Drive
    - Unduh file program Return Zer0 dari Google Drive.
    - Pastikan seluruh file program berada pada satu folder yang sama.

---

## Cara Menjalankan Program
### Menggunakan compiler GCC secara langsung
    1. Buka Terminal (Command Prompt, PowerShell, atau shell Linux/macOS).
    2. Arahkan terminal ke folder program.
    3. Lakukan proses Kompilasi terhadap file program:
        -```bash
        gcc main.c -o return_zer0 
        ```
        > Perintah ini akan menghasilkan file executable bernama `return_zer0`.
    4. Jalankan hasil kompilasi program:
        -```bash
        ./return_zer0
        ```
    5.  Menu utama akan muncul di terminal.

### Menggunakan IDE
    1. Buka IDE (misal: Code::Blocks) dan buka `main.c` sebagai proyek Console Application.
    2. Pastikan semua file data (`soal.txt`, dll.) berada di direktori proyek yang sama.
    3. Gunakan fitur "Build and Run" 
    4. IDE akan secara otomatis mengkompilasi dan menjalankan program di terminal.
    
---

## Cara Menggunakan Program
    1. Setelah program berjalan, pengguna akan melihat menu utama yang berisi beberapa pilihan fitur.
    2. Pilih menu berdasarkan fitur yang diinginkan:
        1) Mulai Baru (New Game)
            Pengguna memasukkan nama pemain, kemudian permainan dimulai dari level dasar dengan jumlah nyawa 3 dan skor awal. 
        2) Lanjutkan (Load Game)
            Program memuat data pemain yang telah disimpan sebelumnya dan melanjutkan permainan dari level terakhir.
        3) Leaderboard
            Program menampilkan daftar 5 pemain dengan skor tertinggi beserta level yang dicapai.
        4) Credits
            Program menampilkan informasi mengenai tim pembuat.
        5) Keluar
            Program dihentikan dan pengguna keluar dari aplikasi.
    3. Saat permainan berlangsung, pengguna menjawab soal pilihan ganda dengan memasukkan angka sesuai opsi jawaban.
    4. Program akan memberikan umpan balik atas jawaban, memperbarui skor dan nyawa, serta melanjutkan ke soal berikutnya.
    5. Permainan berakhir ketika seluruh soal selesai, nyawa pemain habis, atau pengguna memilih untuk menyimpan dan keluar.

---

## Lisensi
    - Proyek Return Zer0 dilisensikan di bawah Lisensi  MIT 
    - Lihat *file* 'LICENSE' untuk detail lengkap.

---

## Kontributor
    1. Gamma Assyafi Fadhillah Ar Rasyad (L0125013)
    2. Jaffan Arya Wirasena (L0125017)
    3. Linda Sihmawati (L0125049)
    
