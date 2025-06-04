#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

//struct enum (Nirmala)
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

typedef enum{
    semua, lokasi, gaji, pendidikan
} modeFilter;


// Function prototypes
const char* getOppositeRole(const char* role); //Soraya
int showMenu(const char *role); //Soraya
void toLowerRemoveSpace(char *skill); //Nirmala
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm, modeFilter); //Nirmala
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM, modeFilter); //Nirmala
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja, modeFilter); //Nirmala
void registerUMKM(dataUMKM* inputUMKM); //Joanna
void showUMKM(dataUMKM* daftarUMKM); //Joanna

// Fungsi utama
int main() {
    int roleInt;
    char roleStr[20];
    int pilihan;

    // Data untuk jobseeker
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
        // Tambah lagi
    };

    // Data untuk UMKM
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
        // Tambah yang lain lagi
    };

    //Tampilan ke user (soraya)
    printf("== HireMeow ==\n");
    printf("Your Local Job Matching Application!!\n");
    printf("-------------------------------------\n");

    printf("\nApakah anda seorang Pekerja atau UMKM?");
    printf("\n1. UMKM");
    printf("\n2. Pekerja");

    printf("\nPilihan Anda: ");
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

        switch (pilihan) {
        case 1:
            if (roleInt == 1) {
                printf("\n== Register UMKM ==\n");
                registerUMKM(&listUMKM[0]);
                break;
            } else if (roleInt == 2) {
                // Function for registering job seeker (not yet implemented)
                break;
            }
            break;
        case 2:
            if (roleInt == 1) {
                // Function to recommend job seekers (not yet implemented)
                break;
            } else if (roleInt == 2) {
                // Function to recommend UMKM (not yet implemented)
                break;
            }
            break;
        case 3:
            // Add functionality for filtering job seekers or UMKMs
            break;
        case 4:
            // Add functionality to list all job seekers or UMKMs
            break;
        case 5:
            printf("Keluar Program!\n");
            return 0;
        default:
            printf("Pilihan anda tidak ada di opsi!\n");
            break;
        }
    } while (pilihan != -1);

    return 0;
}

// Fungsi untuk role UMKM atau pekerja (Soraya)
const char* getOppositeRole(const char* role) {
    if (strcmp(role, "UMKM") == 0) {
        return "Pekerja";
    }
    if (strcmp(role, "Pekerja") == 0) {
        return "UMKM"; 
    }
    return "Tidak Dikenal";
}

// Fungsi untuk tunjukkan menu berdasar role (Soraya)
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

//fungsi untuk comparing agar lowercase dan uppercase seragam (Nirmala)
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


//fungsi hitung match score antara perushaan a dan pekerja b (Nirmala)
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm, modeFilter mode){
    int score = 0;
    if(mode > 3 || mode < 0){
        printf("Filter tidak valid");
        return -1;
    }

    if (mode == 0){
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

       //hitung berdasar posisi yang sama
    char posisiDiinginkan[20], posisiDicari[20];
    strcpy(posisiDiinginkan, pekerja->posisiEkspektasi);
    strcpy(posisiDicari, umkm->posisiDibutuhkan);
    if (strcmp(posisiDiinginkan, posisiDicari) == 0) score += 10;
    }
    
    if(mode == 0 || mode == 1){
        //hitung berdasar kota yang sama
        char kotaUser[20], kotaUMKM[20];
        strcpy(kotaUser, pekerja->kotaTinggal);
        strcpy(kotaUMKM, umkm->kotaUMKM);
        toLowerRemoveSpace(kotaUMKM); toLowerRemoveSpace(kotaUser);
        if (strcmp(kotaUser, kotaUMKM ) == 0) score += 5;
    }


    if(mode == 0 || mode == 2){
    //hitung berdasar gaji
    if(umkm->gajiMinimal >= pekerja->gajiEkspektasi) score += 10;
    }
    
    if(mode == 0 || mode ==3){
        //hitung berdasar level pendidikan
        if (pekerja->pendidikanTerakhir == umkm->minimalPendidikan) score += 5;
        if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) score += 10;
        else score *= 0;
    }
    
    return score;
}

//fungsi rekomendasi umkm bagi jobseeker (Nirmala)
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM, modeFilter mode){
    printf("List Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++)
    {
        int scoreMatch = calculateMatchScore(pekerja, &daftarUMKM[i], mode);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } else if (scoreMatch >= 70) {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } 
    }
}


//fungsi rekomendasi pekerja bagi umkm (Nirmala)
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja, modeFilter mode){
    printf("List Rekomendasi pekerja untuk usaha %s:\n", umkm->namaUMKM);
    for (int i = 0; i < jumlahPekerja; i++)
    {
        int scoreMatch = calculateMatchScore(&daftarPekerja[i], umkm, mode);
        if (scoreMatch >= 20 && scoreMatch < 70) {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } else if (scoreMatch >= 70) {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } 
    }
}

// Fungsi daftar UMKM (Joanna)
void registerUMKM(dataUMKM* inputUMKM) {
    printf("\nInput nama UMKM anda: ");
    scanf(" %[^\n]", inputUMKM->namaUMKM);
    printf("\nInput kota UMKM anda: ");
    scanf(" %[^\n]", inputUMKM->kotaUMKM);
    printf("\nMinimal pendidikan untuk apply \n(0=tidak sekolah, 1=SD, 2=SMP, 3=SMA, 4=D3, 5=D4, 6=S1, 7=S2, 8=S3): ");
    scanf("%d", &inputUMKM->minimalPendidikan);
    printf("\nSkill yang dibutuhkan untuk apply: ");
    scanf(" %[^\n]", inputUMKM->skillDibutuhkan);
    printf("\nJumlah skill yang dibutuhkan untuk apply: ");
    scanf("%d", &inputUMKM->jumlahSkillDibutuhkan);
    printf("\nGaji minimal yang diberikan: ");
    scanf("%f", &inputUMKM->gajiMinimal);
    printf("\nPosisi yang dibutuhkan: ");
    scanf(" %[^\n]", inputUMKM->posisiDibutuhkan);
}


// Fungsi show all UMKM (Joanna)
void showUMKM(dataUMKM* daftarUMKM) {
    printf("\n==== List UMKM yang tersedia: ====\n\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. ", i + 1);
        printf("%s\n", daftarUMKM[i].namaUMKM);
        printf("    Kota: %s\n", daftarUMKM[i].kotaUMKM);
        printf("    Minimal Pendidikan: ");
        switch (daftarUMKM[i].minimalPendidikan) {
            case 0: printf("Tidak Sekolah\n"); break;
            case 1: printf("SD\n"); break;
            case 2: printf("SMP\n"); break;
            case 3: printf("SMA\n"); break;
            case 4: printf("D3\n"); break;
            case 5: printf("D4\n"); break;
            case 6: printf("S1\n"); break;
            case 7: printf("S2\n"); break;
            case 8: printf("S3\n"); break;
            default: break;
        }
        printf("    Skill yang dibutuhkan: \n");
        for (int j = 0; j < daftarUMKM[i].jumlahSkillDibutuhkan; j++) {
            printf("        %d. %s\n", j + 1, daftarUMKM[i].skillDibutuhkan[j]);
        }
        printf("    Gaji Minimal: Rp%.2f\n\n", daftarUMKM[i].gajiMinimal);
    }
}

