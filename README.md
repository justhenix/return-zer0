# Return Zer0 🎮

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Active-orange.svg)

> **Uji pemahaman bahasa C-mu sebelum `return 0;` !**

## 📖 Deskripsi Program

**Return Zer0** adalah permainan kuis berbasis terminal (*console-based*) yang dirancang untuk menguji, melatih, dan menantang logika serta pemahaman sintaks pemrograman bahasa C.

Permainan ini tidak hanya sekadar tanya jawab, tetapi membawa pemain melalui perjalanan tingkat kesulitan bertahap:
* **Dasar (Basic)**
* **Menengah (Intermediate)**
* **Mahir (Advanced)**
* **BONUS:** Level C++ (terbuka jika menjawab >12 soal dengan benar!)

Cocok untuk mahasiswa, pemula, atau siapa saja yang ingin memastikan *coding skill* mereka tetap tajam.

---

## ✨ Fitur Utama

| Fitur | Deskripsi |
| :--- | :--- |
| 📈 **Level Progresif** | Soal dimuat secara dinamis dari `soal.txt`. Bobot skor meningkat seiring naiknya level kesulitan. |
| 💾 **Save & Load** | Takut kehilangan progres? Simpan permainanmu ke `save.txt` dan lanjutkan kapan saja. |
| ❤️ **Sistem Nyawa** | Kamu punya **3 Nyawa (HP)**. Salah jawab = nyawa berkurang. Nyawa 0 = *Game Over*. |
| 🏆 **Leaderboard** | Tampilkan dominasimu! Top 5 pemain dengan skor tertinggi akan tercatat abadi di `leaderboard.txt`. |
| 🖥️ **Antarmuka Menu** | Navigasi mudah dengan menu: *New Game*, *Load Game*, *Leaderboard*, *Credits*, dan *Exit*. |

---

## 🛠️ Persyaratan Sistem

Untuk menjalankan program ini, pastikan sistemmu memiliki:

* **Sistem Operasi:** Windows, Linux, atau macOS.
* **Compiler C:** GCC (GNU Compiler Collection), Clang, atau MinGW.

---

## 📂 Struktur File

Berikut adalah susunan direktori proyek **Return Zer0**. 
Pastikan kamu menjaga struktur ini agar program dapat berjalan dengan lancar (terutama lokasi file `.txt`).

```text
return-zer0/
├── src/                    # Folder Source Code & Binary
│   ├── main.c              # Kode sumber utama program
│   └── main.exe            # File executable (hasil kompilasi)
│
└── test/                   # Folder Database & Resources
    ├── soal.txt            # Database soal kuis yang akan dimuat
    └── leaderboard.txt     # Data skor tertinggi pemain
