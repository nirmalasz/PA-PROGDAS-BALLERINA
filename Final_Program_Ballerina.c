#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//struct enum (NIRMALA)
typedef enum{
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

//function prototype
const char* getOppositeRole(const char* role);
int showMenu(const char *role);
void toLowerRemoveSpace(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM);
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja);
void registerUMKM( dataUMKM* inputUMKM);


int main(){
    int roleInt;
    char roleStr[20];
    int pilihan;
    dataUMKM listUMKM[11] = {
    
//data UMKM (JOANNA)   
    [1] = {
        .namaUMKM = "Toko Roti Ceria",
        .kotaUMKM = "Bandung",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "memasak", "kebersihan", "komunikasi" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3000000,
        .posisiDibutuhkan = "Asisten Dapur"
    },
    [2] = {
        .namaUMKM = "Bengkel Motor Jaya",
        .kotaUMKM = "Yogyakarta",
        .minimalPendidikan = SMP,
        .skillDibutuhkan = { "mekanik", "kerjasama", "problem solving" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3500000,
        .posisiDibutuhkan = "Montir"
    },
    [3] = {
        .namaUMKM = "Warung Kopi Nusantara",
        .kotaUMKM = "Malang",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "barista", "komunikasi", "multitasking" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3200000,
        .posisiDibutuhkan = "Barista"
    },
    [4] = {
        .namaUMKM = "Konveksi Bunda",
        .kotaUMKM = "Surabaya",
        .minimalPendidikan = D3,
        .skillDibutuhkan = { "menjahit", "ketelitian", "desain dasar" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3800000,
        .posisiDibutuhkan = "Penjahit"
    },
    [5] = {
        .namaUMKM = "Kedai Sehat Hijau",
        .kotaUMKM = "Depok",
        .minimalPendidikan = S1,
        .skillDibutuhkan = { "manajemen", "komunikasi", "keuangan" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4500000,
        .posisiDibutuhkan = "Manajer Operasional"
    },
    [6] = {
        .namaUMKM = "Studio Foto Cerah",
        .kotaUMKM = "Bogor",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "fotografi", "editing", "kreativitas" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4000000,
        .posisiDibutuhkan = "Fotografer"
    },
    [7] = {
        .namaUMKM = "Laundry Express Bersih",
        .kotaUMKM = "Jakarta",
        .minimalPendidikan = SMP,
        .skillDibutuhkan = { "kebersihan", "efisiensi", "komunikasi" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3100000,
        .posisiDibutuhkan = "Petugas Laundry"
    },
    [8] = {
        .namaUMKM = "Percetakan Digital Pro",
        .kotaUMKM = "Bekasi",
        .minimalPendidikan = D3,
        .skillDibutuhkan = { "desain grafis", "pengoperasian mesin", "ketelitian" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4200000,
        .posisiDibutuhkan = "Operator Mesin Cetak"
    },
    [9] = {
        .namaUMKM = "Toko Bunga Mawar",
        .kotaUMKM = "Semarang",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3300000,
        .posisiDibutuhkan = "Florist"
    },
    [10] = {
        .namaUMKM = "Katering Harapan Ibu",
        .kotaUMKM = "Tangerang",
        .minimalPendidikan = D4,
        .skillDibutuhkan = { "memasak", "pengemasan", "manajemen waktu" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4600000,
        .posisiDibutuhkan = "Koki"
    }
};

//Main UI (SORAYA)
    printf("== HireMeow ==\n");
    printf("Your Local Job Matching Application!!\n");
    printf("-------------------------------------\n");

    printf("\nApakah anda seorang Pekerja atau UMKM?");
    printf("\n1. UMKM");
    printf("\n2. Pekerja");

    printf("\nPilhan Anda: ");
    scanf("%d", &roleInt);

    if (roleInt == 1) {
        strcpy(roleStr, "UMKM");
    } else if (roleInt == 2) {
        strcpy(roleStr, "Pekerja");
    } else {
        printf("Input Tidak Valid!\n");
        return 0;
    }
        
    do {
        pilihan = showMenu(roleStr);

        switch (pilihan)
        {
        case 1:
            if (roleInt == 1) {
                printf("\n== Register UMKM ==");
                registerUMKM(&listUMKM[0]);
                break;
            } else if (roleInt == 2) {
                //fungsi register 
                break;
            } 
            else
                break;
        case 2:
            if (roleInt == 1) {
                // rekomendasiPekerja(listUMKM[0]); (kurang data Job Seeker)
                break;
            } else if (roleInt == 2) {
                //fungsi register 
                break;
            } 
            else
                break;
        case 3:
            if (roleInt == 1) {
                // rekomendasiPekerja(listUMKM[0]); (kurang data Job Seeker)
                break;
            } else if (roleInt == 2) {
                //fungsi register 
                break;
            } 
            else
                break;
        case 4:
            if (roleInt == 1) {
                // rekomendasiPekerja(listUMKM[0]); (kurang data Job Seeker)
                break;
            } else if (roleInt == 2) {
                //fungsi register 
                break;
            } 
            else
                break;
        case 5:
            printf("Keluar Program!");
            return 0;
        default:
            printf("Pilihan anda tidak ada di opsi!");
            break;
        }
    } while (pilihan!=-1);

    
    return 0;
}

//function

//fungsi untuk ganti string Jobseeker dan UMKM (SORAYA)
const char* getOppositeRole(const char* role) {
    if (strcmp(role, "UMKM") == 0){
        return "Pekerja";
    }
    if (strcmp(role, "Pekerja") == 0) {
        return "UMKM"; 
    }
    return "Tidak Dikenal";
}
//fungsi untuk menampilkan menu berdasarkan role (SORAYA)
int showMenu(const char *role) {
    int pilihan;
    const char *opposite = getOppositeRole(role);

    if (strcmp(opposite, "Tidak Dikenal") == 0) {
        printf("Role tidak dikenali.\n");
        return -1;
    }

    printf("\n== MENU %s ==\n", role);
    printf("1. Register\n");
    printf("2. Rekomendasi %s\n", opposite);
    printf("3. Filter %s Pilihan\n", opposite);
    printf("4. List Semua %s\n", opposite);
    printf("5. Exit\n");

    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);

    return pilihan;
}

//fungsi untuk comparing agar lowercase dan uppercase seragam (NIRMALA)
void toLowerRemoveSpace(char *skill){
    int j = 0;
    for (int i = 0; i < skill[i]; i++)
    {
        skill[i] = tolower(skill[i]);
    }
    for (int i = 0; skill[i] != '\0'; i++)
    {
        if(skill[i] != ' '){
            skill[j++] = skill[i];
        }
    }
    skill[j] = '\0';
}

//fungsi hitung match score antara perushaan a dan pekerja b (NIRMALA)
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm){
    int score = 0;
    //hitung berdasar skill
    for (int i = 0; i < pekerja->jumlahSkillDipunya; i++)
    {
        for (int j = 0; j < umkm->jumlahSkillDibutuhkan; j++)
        {
            char skillUser[20], skillUMKM[20];
            
            strcpy(skillUser, pekerja->skillDipunyai[i]);
            strcpy(skillUMKM, umkm->skillDibutuhkan[i]);
            

            toLowerRemoveSpace(skillUMKM); toLowerRemoveSpace(skillUser);

            if (strcmp(skillUMKM,skillUser) == 0) score += 10;
        }
    }
    //hitung berdasar kota yang sama
    char kotaUser[20], kotaUMKM[20];
    strcpy(kotaUser, pekerja->kotaTinggal);
    strcpy(kotaUMKM, umkm->kotaUMKM);
    toLowerRemoveSpace(kotaUMKM); toLowerRemoveSpace(kotaUser);
    if (strcmp(kotaUser, kotaUMKM ) == 0) score += 5;
    
    //hitung berdasar posisi yang sama
    char posisiDiinginkan[20], posisiDicari[20];
    strcpy(posisiDiinginkan, pekerja->posisiEkspektasi);
    strcpy(posisiDicari, umkm->posisiDibutuhkan);
    if (strcmp(kotaUser, kotaUMKM ) == 0) score += 10;
    
    //hitung berdasar gaji
    if(umkm->gajiMinimal >= pekerja->gajiEkspektasi) score += 10;
    
    //hitung berdasar level pendidikan
    if (pekerja->pendidikanTerakhir == umkm->minimalPendidikan) score += 5;
    if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) score += 10;
    else score *= 0;
    

    return score;
}

//fungsi rekomendasi umkm bagi jobseeker (NIRMALA)
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM){
    printf("List Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++)
    {
        int scoreMatch = calculateMatchScore(pekerja, &daftarUMKM[i]);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } else if (scoreMatch >= 70)
        {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } 
    }
}

//fungsi rekomendasi pekerja bagi umkm (NIRMALA)
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja){
    printf("List Rekomendasi pekerja untuk usaha %s:\n", umkm->namaUMKM);
    for (int i = 0; i < jumlahPekerja; i++)
    {
        int scoreMatch = calculateMatchScore(&daftarPekerja[i], umkm);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } else if (scoreMatch >= 70)
        {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } 
    }
}

//fungsi untuk input peimilik UMKM (JOANNA)
void registerUMKM( dataUMKM* inputUMKM){
    printf("\nInput nama UMKM anda: ");
    scanf("%[^\n]", inputUMKM->namaUMKM);
    getchar();
    printf("\nInput kota UMKM anda: ");
    scanf("%[^\n]", inputUMKM->kotaUMKM);
    getchar();
    printf("\nMinimal pendidikan untuk apply \n(0=SD, 1=SMP, 2=SMA, 3=D3, 4=D4, 5=S1, 6=S2, 7=S3): ");
    scanf("%d", inputUMKM->minimalPendidikan);
    getchar();
    printf("\nSkill yang dibutuhkan untuk apply: ");
    scanf("%[^\n]", inputUMKM->skillDibutuhkan);
    getchar();
    printf("\nJumlah skill yang dibutuhkan untuk apply: ");
    scanf("%d", inputUMKM->jumlahSkillDibutuhkan);
    getchar();
    printf("\nGaji minimal yang diberikan: ");
    scanf("%lf", inputUMKM->gajiMinimal);
    getchar();
    printf("\nPosisi yang dibutuhkan: ");
    scanf("%[^\n]", inputUMKM->posisiDibutuhkan);
    getchar();
}
