#include <stdio.h>
#include <stdint.h>
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
    float gajiEkspektasi; // dalam juta
    char posisiEkspektasi[20];
} dataJobSeeker;

typedef struct {
    char namaUMKM[50];
    char kotaUMKM[20];
    tingkatPendidikan minimalPendidikan;
    char skillDibutuhkan[5][20];
    int jumlahSkillDibutuhkan;
    float gajiMinimal; // dalam juta
    char posisiDibutuhkan[20];
} dataUMKM;

void toLowerRemoveSpace(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM);
void registerJobSeeker(dataJobSeeker *pekerja);

int main() {
       // Data pekerja
    dataJobSeeker pekerja[10] = {
        {
            .namaPekerja = "Andi Santoso",
            .kotaTinggal = "Bandung",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "memasak", "komunikasi", "manajemen" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.5,
            .posisiEkspektasi = "Asisten Dapur"
        },
        {
            .namaPekerja = "Budi Setiawan",
            .kotaTinggal = "Yogyakarta",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "mekanik", "kerjasama", "problem solving" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.2,
            .posisiEkspektasi = "Montir"
        },
        {
            .namaPekerja = "Citra Ayu",
            .kotaTinggal = "Malang",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "barista", "komunikasi", "multitasking" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.3,
            .posisiEkspektasi = "Barista"
        },
        {
            .namaPekerja = "Dedi Prasetyo",
            .kotaTinggal = "Surabaya",
            .pendidikanTerakhir = D3,
            .skillDipunyai = { "menjahit", "ketelitian", "desain dasar" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.7,
            .posisiEkspektasi = "Penjahit"
        },
        {
            .namaPekerja = "Erika Sari",
            .kotaTinggal = "Depok",
            .pendidikanTerakhir = S1,
            .skillDipunyai = { "manajemen", "komunikasi", "keuangan" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.2,
            .posisiEkspektasi = "Manajer Operasional"
        },
        {
            .namaPekerja = "Fikri Wijaya",
            .kotaTinggal = "Bogor",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "fotografi", "editing", "kreativitas" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.0,
            .posisiEkspektasi = "Fotografer"
        },
        {
            .namaPekerja = "Gina Rahmawati",
            .kotaTinggal = "Jakarta",
            .pendidikanTerakhir = SMP,
            .skillDipunyai = { "kebersihan", "efisiensi", "komunikasi" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.1,
            .posisiEkspektasi = "Petugas Laundry"
        },
        {
            .namaPekerja = "Hendra Saputra",
            .kotaTinggal = "Bekasi",
            .pendidikanTerakhir = D3,
            .skillDipunyai = { "desain grafis", "pengoperasian mesin", "ketelitian" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.0,
            .posisiEkspektasi = "Operator Mesin Cetak"
        },
        {
            .namaPekerja = "Indah Permatasari",
            .kotaTinggal = "Semarang",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.4,
            .posisiEkspektasi = "Florist"
        },
        {
            .namaPekerja = "Joko Nugroho",
            .kotaTinggal = "Tangerang",
            .pendidikanTerakhir = D4,
            .skillDipunyai = { "memasak", "pengemasan", "manajemen waktu" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.6,
            .posisiEkspektasi = "Koki"
        }
    };

    // Data UMKM
    dataUMKM listUMKM[10] = {
        {
            .namaUMKM = "Toko Roti Ceria",
            .kotaUMKM = "Bandung",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "memasak", "kebersihan", "komunikasi" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.0,
            .posisiDibutuhkan = "Asisten Dapur"
        },
        {
            .namaUMKM = "Bengkel Motor Jaya",
            .kotaUMKM = "Yogyakarta",
            .minimalPendidikan = SMP,
            .skillDibutuhkan = { "mekanik", "kerjasama", "problem solving" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.5,
            .posisiDibutuhkan = "Montir"
        },
        {
            .namaUMKM = "Warung Kopi Nusantara",
            .kotaUMKM = "Malang",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "barista", "komunikasi", "multitasking" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.2,
            .posisiDibutuhkan = "Barista"
        },
        {
            .namaUMKM = "Konveksi Bunda",
            .kotaUMKM = "Surabaya",
            .minimalPendidikan = D3,
            .skillDibutuhkan = { "menjahit", "ketelitian", "desain dasar" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.8,
            .posisiDibutuhkan = "Penjahit"
        },
        {
            .namaUMKM = "Kedai Sehat Hijau",
            .kotaUMKM = "Depok",
            .minimalPendidikan = S1,
            .skillDibutuhkan = { "manajemen", "komunikasi", "keuangan" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4.5,
            .posisiDibutuhkan = "Manajer Operasional"
        },
        {
            .namaUMKM = "Studio Foto Cerah",
            .kotaUMKM = "Bogor",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "fotografi", "editing", "kreativitas" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4.0,
            .posisiDibutuhkan = "Fotografer"
        },
        {
            .namaUMKM = "Laundry Express Bersih",
            .kotaUMKM = "Jakarta",
            .minimalPendidikan = SMP,
            .skillDibutuhkan = { "kebersihan", "efisiensi", "komunikasi" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.1,
            .posisiDibutuhkan = "Petugas Laundry"
        },
        {
            .namaUMKM = "Percetakan Digital Pro",
            .kotaUMKM = "Bekasi",
            .minimalPendidikan = D3,
            .skillDibutuhkan = { "desain grafis", "pengoperasian mesin", "ketelitian" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4.2,
            .posisiDibutuhkan = "Operator Mesin Cetak"
        },
        {
            .namaUMKM = "Toko Bunga Mawar",
            .kotaUMKM = "Semarang",
            .minimalPendidikan = SMA,
            .skillDibutuhkan = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 3.3,
            .posisiDibutuhkan = "Florist"
        },
        {
            .namaUMKM = "Katering Harapan Ibu",
            .kotaUMKM = "Tangerang",
            .minimalPendidikan = D4,
            .skillDibutuhkan = { "memasak", "pengemasan", "manajemen waktu" },
            .jumlahSkillDibutuhkan = 3,
            .gajiMinimal = 4.6,
            .posisiDibutuhkan = "Koki"
        }
    };

    printf("\n--- Hasil Rekomendasi UMKM ---\n");
    rekomendasiUMKM(&pekerja[0], listUMKM, 10);

    return 0;
}

void registerJobSeeker(dataJobSeeker *pekerja) {
    printf("Nama Anda: ");
    scanf(" %[^\n]", pekerja->namaPekerja);

    printf("Kota Tinggal: ");
    scanf(" %[^\n]", pekerja->kotaTinggal);

    printf("Pendidikan Terakhir:\n");
    printf("0 = Tidak Sekolah\n");
    printf("1 = SD\n");
    printf("2 = SMP\n");
    printf("3 = SMA\n");
    printf("4 = D3\n");
    printf("5 = D4\n");
    printf("6 = S1\n");
    printf("7 = S2\n");
    printf("8 = S3\n");
    printf("Masukkan pilihan (0-8): ");
    scanf("%d", (int*)&pekerja->pendidikanTerakhir);

    printf("Jumlah Skill yang Anda miliki: ");
    scanf("%d", &pekerja->jumlahSkillDipunya);

    for (int i = 0; i < pekerja->jumlahSkillDipunya; i++) {
        printf("Skill %d: ", i + 1);
        scanf(" %[^\n]", pekerja->skillDipunyai[i]);
    }

    printf("Gaji Ekspektasi (dalam juta): ");
    scanf("%f", &pekerja->gajiEkspektasi);

    printf("Posisi yang Diharapkan: ");
    scanf(" %[^\n]", pekerja->posisiEkspektasi);
}

void toLowerRemoveSpace(char *skill) {
    int j = 0;
    for (int i = 0; skill[i] != '\0'; i++) {
        if (skill[i] != ' ') {
            skill[j++] = tolower(skill[i]);
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

            if (strcmp(skillUser, skillUMKM) == 0) {
                score += 10;
            }
        }
    }

    char kotaUser[20], kotaUMKM[20];
    strcpy(kotaUser, pekerja->kotaTinggal);
    strcpy(kotaUMKM, umkm->kotaUMKM);
    toLowerRemoveSpace(kotaUser);
    toLowerRemoveSpace(kotaUMKM);
    if (strcmp(kotaUser, kotaUMKM) == 0) {
        score += 5;
    }

    char posisiUser[20], posisiUMKM[20];
    strcpy(posisiUser, pekerja->posisiEkspektasi);
    strcpy(posisiUMKM, umkm->posisiDibutuhkan);
    toLowerRemoveSpace(posisiUser);
    toLowerRemoveSpace(posisiUMKM);
    if (strcmp(posisiUser, posisiUMKM) == 0) {
        score += 10;
    }

    if (umkm->gajiMinimal >= pekerja->gajiEkspektasi) {
        score += 10;
    }

    if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) {
        score += 10;
    } else {
        score = 0; 
    }

    return score;
}

void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM) {
    printf("Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++) {
        int skor = calculateMatchScore(pekerja, &daftarUMKM[i]);

        if (skor >= 70) {
            printf("[Sangat Cocok] %s (score: %d)\n", daftarUMKM[i].namaUMKM, skor);
        } else if (skor >= 20) {
            printf("[Cocok] %s (score: %d)\n", daftarUMKM[i].namaUMKM, skor);
        } else {
            printf("[Kurang Cocok] %s (score: %d)\n", daftarUMKM[i].namaUMKM, skor);
        }
    }
}
