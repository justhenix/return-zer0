/* UAS Konsep Pemrograman Kelompok 1
 * Judul Program : Return Zer0
 * Anggota Kelompok :
 * Gamma Assyafi Fadhillah Ar Rasyad (L0125013)
 * Jaffan Arya Wirasena (L0125017)
 * Linda Sihmawati (L0125049)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Warna teks
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CLR "\033[0m"

// Path folder test (untuk data uji)
#define PATH_SOAL "../test/soal.txt"
#define PATH_SAVE "../test/save.txt"
#define PATH_LEADERBOARD "../test/leaderboard.txt"

// Durasi delay teks
#define DELAY_VFAST 350
#define DELAY_FAST 600
#define DELAY_MEDIUM 1000
#define DELAY_SLOW 1600
#define DELAY_VSLOW 2200

void CLEAR_SCREEN() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void delay(int ms) {
	#ifdef _WIN32
        Sleep(ms);
	#else
	    usleep(ms * 1000);
	#endif
}

typedef struct {
    char nama[100];
    unsigned int nyawa;
    unsigned int level;
    unsigned int skor;
    unsigned int jumlahBenar;
} dataPemain;

typedef struct {
    char pertanyaan[200];
    char opsi[4][200];
    int kunci;
} Soal;

typedef struct {
    char nama[100];
    int skor;
    int level;
} LeaderboardEntry;

enum menu {
    START = 1,
    LOAD,
    LEADERBOARD,
    CREDITS,
    EXIT
};

// Menu dan Tampilan
void banner(void);
// more to come?

// Sistem Permainan
void sistemPermainan(dataPemain *p, Soal *daftarSoal, int totalSoal);

// Simpan dan Buka File
void simpanPermainan(dataPemain *p, int indeksSoal);
int muatPermainan(dataPemain *p, int *indeksSoal);
int bukaPermainan(void);
void gameOverFile();
void parseLine(char *line, Soal *s); // Parsing dari file
int bukaSoal(Soal *daftarSoal);
void updateLeaderboard(char *nama, int skor, int level);
void lihatLeaderboard(void);

int main(void) {
    dataPemain player;
    Soal daftarSoal[20];
    int jumlahSoal = 0;
    int pilihanMenu;

    jumlahSoal = bukaSoal(daftarSoal);
    if (jumlahSoal == 0) return 1;

    while (1) {
        CLEAR_SCREEN();
        banner();

        printf("\n1. MULAI BARU (New Game)\n");
        printf("2. LANJUTKAN (Load Game)\n");
        printf("3. LEADERBOARD\n");
        printf("4. CREDITS\n");
        printf("5. KELUAR\n");
        printf(YELLOW "\nPilih >> " CLR);

        if (scanf("%d", &pilihanMenu) != 1) {
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (pilihanMenu) {
            case START:
                // Validasi input nama
                do {
                    printf("Masukkan Nama: ");
                    fgets(player.nama, sizeof(player.nama), stdin);

                    player.nama[strcspn(player.nama, "\n")] = 0;

                    // Cek: Kalau panjang string 0 (Cuma tekan Enter)
                    if (strlen(player.nama) == 0) {
                        printf(RED "Nama tidak boleh kosong!\n\n" CLR);
                    } else if (strlen(player.nama) > 15) {
                        printf(RED "Nama terlalu panjang! Maksimal 15 huruf!\n" CLR);
                        player.nama[0] = '\0';
                    }

                } while (strlen(player.nama) == 0);

                // Inisialisasi pemain
                player.nyawa = 3;
                player.skor = 0;
                player.level = 0;
                player.jumlahBenar = 0;

                sistemPermainan(&player, daftarSoal, jumlahSoal);
                break;

            case LOAD:
                CLEAR_SCREEN();
                int indeksSoal = 0;
                printf(RED "\nMemuat data pemain...\n" CLR);
                delay(DELAY_FAST);
                 if (muatPermainan(&player, &indeksSoal)) {
                    sistemPermainan(&player, daftarSoal, jumlahSoal);
                 }
                delay(DELAY_MEDIUM);
                break;

            case LEADERBOARD:
                CLEAR_SCREEN();
                lihatLeaderboard();
                printf("\nTekan 'Enter' untuk kembali...");
                getchar();
                break;

            case CREDITS:
                CLEAR_SCREEN();
                printf(BLUE "\n=== CREDITS ===\n" CLR);
                printf("Code by: Kelompok 1\n");
                printf("Gamma Assyafi Fadhillah Ar Rasyad (L0125013)\n");
                printf("Jaffan Arya Wirasena (L0125017)\n");
                printf("Linda Sihmawati (L0125049)\n");
                printf("\nTekan 'Enter' untuk kembali...");
                getchar();
                break;

            case EXIT:
                printf(YELLOW "Bye bye! Jangan lupa tetap belajar, ya!\n" CLR);
                delay(DELAY_SLOW);
                return 0;

            default:
                printf(RED "Pilihan tidak valid! Masukkan angka 1-5!\n" CLR);
                delay(DELAY_MEDIUM);
        }
    }
}


// Menu dan Tampilan
void banner(void) {
    printf(GREEN);
    printf(":::::::::  :::::::::: ::::::::::: :::    ::: :::::::::  ::::    :::      ::::::::: :::::::::: :::::::::   :::::::  \n");
    printf(":+:    :+: :+:            :+:     :+:    :+: :+:    :+: :+:+:   :+:           :+:  :+:        :+:    :+: :+:   :+: \n");
    printf("+:+    +:+ +:+            +:+     +:+    +:+ +:+    +:+ :+:+:+  +:+          +:+   +:+        +:+    +:+ +:+  :+:+ \n");
    printf("+#++:++#:  +#++:++#       +#+     +#+    +:+ +#++:++#:  +#+ +:+ +#+         +#+    +#++:++#   +#++:++#:  +#+ + +:+ \n");
    printf("+#+    +#+ +#+            +#+     +#+    +#+ +#+    +#+ +#+  +#+#+#        +#+     +#+        +#+    +#+ +#+#  +#+ \n");
    printf("#+#    #+# #+#            #+#     #+#    #+# #+#    #+# #+#   #+#+#       #+#      #+#        #+#    #+# #+#   #+# \n");
    printf("###    ### ##########     ###      ########  ###    ### ###    ####      ######### ########## ###    ###  #######  \n");
    printf(CLR);
}

// Sistem Permainan
void sistemPermainan(dataPemain *p, Soal *daftarSoal, int totalSoal) {
    int i = (p->level > 0) ? p->level : 0;

    for (; i < totalSoal; i++) {
        CLEAR_SCREEN();
        banner();

        int levelDisplay = 1;
        int poinSoal = 1;
        char tipeLevel[20] = "DASAR";

        if (i < 5) {
            levelDisplay = 1; poinSoal = 1; strcpy(tipeLevel, "DASAR (1 Poin)");
        } else if (i < 10) {
            levelDisplay = 2; poinSoal = 2; strcpy(tipeLevel, "MENENGAH (2 Poin)");
        } else if (i < 15) {
            levelDisplay = 3; poinSoal = 3; strcpy(tipeLevel, "MAHIR (3 Poin)");
        } else {
            // SYARAT BONUS: Cek p->jumlahBenar
            // Total soal reguler = 15. Syarat > 12 benar.
            if (p->jumlahBenar <= 12) {
                printf(YELLOW "\nJawaban benar kamu (%d), coba lagi untuk dapat level Bonus!\n" CLR, p->jumlahBenar);
                printf("Latihan lagi ya!\n");
                delay(DELAY_SLOW);
                break;
            }
            levelDisplay = 4; poinSoal = 5; strcpy(tipeLevel, "BONUS C++ (5 Poin)");
        }

        printf(BLUE "\nPLAYER: %s | HP: %d | SKOR: %d | BENAR: %d\n" CLR, p->nama, p->nyawa, p->skor, p->jumlahBenar);
        printf(YELLOW "LEVEL %d: %s\n" CLR, levelDisplay, tipeLevel);
        printf("========================================\n");
        printf("SOAL %d: %s\n", i + 1, daftarSoal[i].pertanyaan);
        printf("1. %s\n", daftarSoal[i].opsi[0]);
        printf("2. %s\n", daftarSoal[i].opsi[1]);
        printf("3. %s\n", daftarSoal[i].opsi[2]);
        printf("4. %s\n", daftarSoal[i].opsi[3]);

        printf("\nJawab (1-4) atau ketik 9 untuk SIMPAN & KELUAR: ");
        int jawaban;

        if (scanf("%d", &jawaban) != 1) {
            while(getchar() != '\n');
            printf(RED "\nHanya angka 1-4 ya! \n" CLR);
            delay(DELAY_SLOW); i--; continue;
        }

        if ((jawaban < 1 || jawaban > 4) && jawaban != 9) {
            printf(RED "\nPilih angka 1-4 ya!\n" CLR);
            delay(DELAY_SLOW); i--; continue;
        }

        if (jawaban == 9) {
            p->level = i;
            simpanPermainan(p, i);
            return;
        }

        if (jawaban == daftarSoal[i].kunci) {
            printf(GREEN "\nBENAR! (+%d Poin)\n" CLR, poinSoal);
            p->skor += poinSoal;
            p->jumlahBenar++;
            delay(DELAY_MEDIUM);
        } else {
            printf(RED "\nSALAH! Jawaban: %d\n" CLR, daftarSoal[i].kunci);
            p->nyawa--;
            delay(DELAY_SLOW);

            if (p->nyawa == 0) {
                printf(RED "\nGAME OVER!\n" CLR);
                updateLeaderboard(p->nama, p->skor, levelDisplay);
                gameOverFile();
                delay(DELAY_VSLOW);
                return;
            }
        }
    }

    printf(GREEN "\nSELAMAT! PERMAINAN SELESAI!\n" CLR);
    printf("Skor Akhir: %d (Benar: %d)\n", p->skor, p->jumlahBenar);
    updateLeaderboard(p->nama, p->skor, (i >= 15 ? 4 : 3));
    delay(DELAY_VSLOW);
}

void simpanPermainan(dataPemain *p, int indeksSoal) {
    FILE *file;
    file = fopen(PATH_SAVE, "w");

    if (file == NULL) {
        printf(RED "Gagal menyimpan! Pastikan folder 'test' ada!" CLR "\n");
        return;
    }

    fprintf(file, "%s#%u#%d#%u#%u#%u",
            p->nama,
            p->level,
            indeksSoal,
            p->skor,
            p->nyawa,
            p->jumlahBenar);

    printf(GREEN "\n[DATA TERSIMPAN] %s berada di Level %u, Soal ke-%d\n"
        CLR, p->nama, p->level, indeksSoal + 1);

    delay(DELAY_SLOW);

    fclose(file);
}

int muatPermainan(dataPemain *p, int *indeksSoal) {
    FILE *file = fopen(PATH_SAVE, "r");

    if (file == NULL) {
        printf(RED "Tidak ada data save!\n" CLR);
        delay(DELAY_SLOW);
        return 0;
    }

    int hasil = fscanf(file, "%99[^#]#%u#%d#%u#%u#%u",
            p->nama,
            &p->level,
            indeksSoal,
            &p->skor,
            &p->nyawa,
            &p->jumlahBenar);

    fclose(file);

    if (hasil != 6) {
        printf(RED "Data save rusak!\n" CLR);
        delay(DELAY_SLOW);
        return 0;
    }

    printf(GREEN "\n[LOAD BERHASIL]\n" CLR);
    printf("Player : %s\n", p->nama);
    printf("Level  : %u\n", p->level);
    printf("Soal   : %d\n", *indeksSoal + 1);
    printf("Skor   : %u\n", p->skor);
    printf("Nyawa  : %u\n", p->nyawa);

    delay(DELAY_SLOW);
    return 1;
}


void gameOverFile() {

    remove(PATH_SAVE);
    delay(DELAY_SLOW);
}


int bukaSoal(Soal *daftarSoal) {
    FILE *file;
    int jumlahSoal = 0;
    char buffer[500];

    file = fopen (PATH_SOAL, "r");
    if (file == NULL) {
        printf(RED "File soal tidak ditemukan di %s\n" CLR, PATH_SOAL);
        printf("Cek kembali posisi file .exe kamu ya!\n");
        return 0;
    }
    printf("\nMemuat...");
    delay(DELAY_MEDIUM);
    while (fgets(buffer, sizeof(buffer), file)) {

        buffer[strcspn(buffer, "\n")] = 0;

        parseLine(buffer, &daftarSoal[jumlahSoal]);
        jumlahSoal++;
    }
    fclose(file);
    return jumlahSoal;
}

void parseLine(char *line, Soal *s) {
    char *token = strtok(line, "#");
    strcpy(s->pertanyaan, token);

    for (int i = 0; i < 4; i++) {
        token = strtok(NULL, "#");
        strcpy(s->opsi[i], token);
    }

    token = strtok(NULL, "#");
    s->kunci = atoi(token);
}

void updateLeaderboard(char *nama, int skor, int level) {
    LeaderboardEntry entries[100];
    int count = 0;

    FILE *file = fopen(PATH_LEADERBOARD, "r");
    char buffer[200];

    if (file != NULL) {
        while (fgets(buffer, sizeof(buffer), file)) {
            buffer[strcspn(buffer, "\n")] = 0;
            char *token = strtok(buffer, "#");
            if (token != NULL) {
                strcpy(entries[count].nama, token);

                token = strtok(NULL, "#");
                if (token) entries[count].skor = atoi(token);

                token = strtok(NULL, "#"); // Baca Level lama
                if (token) entries[count].level = atoi(token);

                count++;
            }
        }
        fclose(file);
    }

    strcpy(entries[count].nama, nama);
    entries[count].skor = skor;
    entries[count].level = level; // Simpan level user
    count++;

    // SORTING (Bubble Sort berdasarkan SKOR tertinggi)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (entries[j].skor < entries[j + 1].skor) {
                LeaderboardEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }

    if (count > 5) count = 5; // Top 5

    file = fopen(PATH_LEADERBOARD, "w");
    if (file == NULL) return;

    for (int i = 0; i < count; i++) {
        // Format simpan: Nama#Skor#Level
        fprintf(file, "%s#%d#%d\n", entries[i].nama, entries[i].skor, entries[i].level);
    }
    fclose(file);
}

void lihatLeaderboard(void) {
    FILE *file = fopen(PATH_LEADERBOARD, "r");
    char buffer[200];
    int rank = 1;

    printf(BLUE "\n================================\n" CLR);
    printf(YELLOW "   HALL OF FAME - RETURN ZER0   \n" CLR);
    printf(BLUE "================================\n" CLR);

    // Header Kolom (Perhatikan spasi dan garisnya)
    printf("No. | %-10s | %-5s | %-3s\n", "Name", "Score", "Lvl");
    printf("--------------------------------\n");

    if (file == NULL) {
        printf(RED "      BELUM ADA JUARA!      \n" CLR);
        printf("--------------------------------\n");
        return;
    }

    // Baca File format: Nama#Skor#Level
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;

        char *nama = strtok(buffer, "#");
        char *skorStr = strtok(NULL, "#");
        char *levelStr = strtok(NULL, "#"); // Ambil token ketiga (Level)

        if (nama && skorStr && levelStr) {
            printf("%-3d | %-10.10s | %-5s | %-3s\n",
                   rank++, nama, skorStr, levelStr);
        }
    }
    printf("--------------------------------\n");
    fclose(file);
}
