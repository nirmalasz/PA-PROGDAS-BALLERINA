#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    tidak_sekolah, SD, SMP, SMA, D3, D4, S1, S2, S3
} tingkatPendidikan;

typedef struct {
    char namaPekerja[50];
    char kotaTinggal[20];
    tingkatPendidikan pendidikanTerakhir;
    char skillDipunyai[10][20];
    int jumlahSkillDipunya;
    float gajiEkspektasi;
    char posisiEkspektasi[20];
} dataJobSeeker;

typedef struct {
    char namaUMKM[50];
    char kotaUMKM[20];
    tingkatPendidikan minimalPendidikan;
    char skillDibutuhkan[5][20];
    int jumlahSkillDibutuhkan;
    float gajiMinimal;
    char posisiDibutuhkan[20];
} dataUMKM;

// Function prototypes
void toLowerRemoveSpace(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM);
void registerJobSeeker(dataJobSeeker *pekerja);

int main() {
    dataJobSeeker pekerja;

    dataUMKM listUMKM[10] = {
        {
            .namaUMKM = "Toko Roti Ceria",
            .kotaUMKM = "Bandung",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "memasak", "kebersihan", "komunikasi" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3000000,
            .posisiDibutuhkan = "Asisten Dapur"
        },
        {
            .namaUMKM = "Bengkel Motor Jaya",
            .kotaUMKM = "Yogyakarta",
            .minimalPendidikan = SMP,
            .skillDibutuhkan = { "mekanik", "kerjasama", "problem solving" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3500000,
            .posisiDibutuhkan = "Montir"
        },
        {
            .namaUMKM = "Warung Kopi Nusantara",
            .kotaUMKM = "Malang",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "barista", "komunikasi", "multitasking" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3200000,
            .posisiDibutuhkan = "Barista"
        },
        {
            .namaUMKM = "Konveksi Bunda",
            .kotaUMKM = "Surabaya",
            .minimalPendidikan = D3,
            .skillDibutuhkan = { "menjahit", "ketelitian", "desain dasar" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3800000,
            .posisiDibutuhkan = "Penjahit"
        },
        {
            .namaUMKM = "Kedai Sehat Hijau",
            .kotaUMKM = "Depok",
            .minimalPendidikan = S1,
            .skillDibutuhkan = { "manajemen", "komunikasi", "keuangan" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4500000,
            .posisiDibutuhkan = "Manajer Operasional"
        },
        {
            .namaUMKM = "Studio Foto Cerah",
            .kotaUMKM = "Bogor",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "fotografi", "editing", "kreativitas" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4000000,
            .posisiDibutuhkan = "Fotografer"
        },
        {
            .namaUMKM = "Laundry Express Bersih",
            .kotaUMKM = "Jakarta",
            .minimalPendidikan = SMP,
            .skillDibutuhkan = { "kebersihan", "efisiensi", "komunikasi" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3100000,
            .posisiDibutuhkan = "Petugas Laundry"
        },
        {
            .namaUMKM = "Percetakan Digital Pro",
            .kotaUMKM = "Bekasi",
            .minimalPendidikan = D3,
            .skillDibutuhkan = { "desain grafis", "pengoperasian mesin", "ketelitian" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4200000,
            .posisiDibutuhkan = "Operator Mesin Cetak"
        },
        {
            .namaUMKM = "Toko Bunga Mawar",
            .kotaUMKM = "Semarang",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3300000,
            .posisiDibutuhkan = "Florist"
        },
        {
            .namaUMKM = "Katering Harapan Ibu",
            .kotaUMKM = "Tangerang",
            .minimalPendidikan = D4,
            .skillDibutuhkan = { "memasak", "pengemasan", "manajemen waktu" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4600000,
            .posisiDibutuhkan = "Koki"
        }
    };

    registerJobSeeker(&pekerja);

    printf("\n--- Hasil Rekomendasi ---\n");
    rekomendasiUMKM(&pekerja, listUMKM, 10);

    return 0;
}

void registerJobSeeker(dataJobSeeker *pekerja) {
    printf("Nama Anda: ");
    scanf(" %[^\n]", pekerja->namaPekerja);
    getchar();

    printf("Kota Tinggal: ");
    scanf(" %[^\n]", pekerja->kotaTinggal);
    getchar();

    printf("Pendidikan Terakhir (0: tidak_sekolah - 8: S3): ");
    scanf("%d", &pekerja->pendidikanTerakhir);
    getchar();

    printf("Jumlah Skill yang Anda miliki: ");
    scanf("%d", &pekerja->jumlahSkillDipunya);
    getchar();

    for (int i = 0; i < pekerja->jumlahSkillDipunya; i++) {
        printf("Skill %d: ", i + 1);
        scanf(" %[^\n]", pekerja->skillDipunyai[i]);
        getchar();
    }

    printf("Gaji Ekspektasi: ");
    scanf("%f", &pekerja->gajiEkspektasi);
    getchar();

    printf("Posisi yang Diharapkan: ");
    scanf(" %[^\n]", pekerja->posisiEkspektasi);
    getchar();
}

void toLowerRemoveSpace(char *skill) {
    int j = 0;
    for (int i = 0; skill[i]; i++) {
        skill[i] = tolower(skill[i]);
    }
    for (int i = 0; skill[i] != '\0'; i++) {
        if (skill[i] != ' ') {
            skill[j++] = skill[i];
        }
    }
    skill[j] = '\0';
}

int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm) {
    int score = 0;
    for (int i = 0; i < pekerja->jumlahSkillDipunya; i++) {
        for (int j = 0; j < umkm->jumlahSkillDibutuhkan; j++) {
            char skillUser[20], skillUMKM[20];
            strcpy(skillUser, pekerja->skillDipunyai[i]);
            strcpy(skillUMKM, umkm->skillDibutuhkan[j]);

            toLowerRemoveSpace(skillUser);
            toLowerRemoveSpace(skillUMKM);

            if (strcmp(skillUser, skillUMKM) == 0) score += 10;
        }
    }

    if (strcasecmp(pekerja->kotaTinggal, umkm->kotaUMKM) == 0) score += 5;
    if (strcasecmp(pekerja->posisiEkspektasi, umkm->posisiDibutuhkan) == 0) score += 10;
    if (umkm->gajiMinimal >= pekerja->gajiEkspektasi) score += 10;

    if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) score += 10;
    else score = 0;

    return score;
}

void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM) {
    for (int i = 0; i < jumlahUMKM; i++) {
        int score = calculateMatchScore(pekerja, &daftarUMKM[i]);
        if (score >= 70) {
            printf("[Sangat Cocok] %s (score: %d)\n", daftarUMKM[i].namaUMKM, score);
        } else if (score >= 20) {
            printf("[Cocok] %s (score: %d)\n", daftarUMKM[i].namaUMKM, score);
        }
    }
}
