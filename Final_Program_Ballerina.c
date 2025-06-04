#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Enum for education levels
typedef enum{
    tidak_sekolah, SD, SMP, SMA, D3, D4, S1, S2, S3
} tingkatPendidikan;

// Structure for Job Seeker
typedef struct {
    char namaPekerja[50];
    char kotaTinggal[20];
    tingkatPendidikan pendidikanTerakhir;
    char skillDipunyai[10][20];
    int jumlahSkillDipunya;
    float gajiEkspektasi; // in millions
    char posisiEkspektasi[20];
} dataJobSeeker;

// Structure for UMKM
typedef struct {
    char namaUMKM[50];
    char kotaUMKM[20];
    tingkatPendidikan minimalPendidikan;
    char skillDibutuhkan[5][20];
    int jumlahSkillDibutuhkan;
    float gajiMinimal; // in millions
    char posisiDibutuhkan[20];
} dataUMKM;

// Function prototypes
const char* getOppositeRole(const char* role);
int showMenu(const char *role);
void toLowerRemoveSpace(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM);
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja);
void registerUMKM(dataUMKM* inputUMKM);
void showUMKM(dataUMKM* daftarUMKM);

// Main function
int main() {
    int roleInt;
    char roleStr[20];
    int pilihan;

    // Data for Job Seekers
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
        // Add other job seekers here
    };

    // Data for UMKM
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
        // Add other UMKMs here
    };

    // Register UMKM and show UMKM data
    registerUMKM(&listUMKM[0]);
    showUMKM(listUMKM);

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

// Function to get opposite role (Pekerja or UMKM)
const char* getOppositeRole(const char* role) {
    if (strcmp(role, "UMKM") == 0) {
        return "Pekerja";
    }
    if (strcmp(role, "Pekerja") == 0) {
        return "UMKM"; 
    }
    return "Tidak Dikenal";
}

// Function to show menu based on role
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

// Function to convert string to lowercase and remove spaces
void toLowerRemoveSpace(char *skill) {
    int j = 0;
    for (int i = 0; skill[i] != '\0'; i++) {
        skill[i] = tolower(skill[i]);
    }
    for (int i = 0; skill[i] != '\0'; i++) {
        if (skill[i] != ' ') {
            skill[j++] = skill[i];
        }
    }
    skill[j] = '\0';
}

// Function to calculate match score between job seeker and UMKM
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm) {
    int score = 0;

    // Compare skills
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

    // Compare city
    char kotaUser[20], kotaUMKM[20];
    strcpy(kotaUser, pekerja->kotaTinggal);
    strcpy(kotaUMKM, umkm->kotaUMKM);
    toLowerRemoveSpace(kotaUser);
    toLowerRemoveSpace(kotaUMKM);
    if (strcmp(kotaUser, kotaUMKM) == 0) {
        score += 5;
    }

    // Compare position
    char posisiUser[20], posisiUMKM[20];
    strcpy(posisiUser, pekerja->posisiEkspektasi);
    strcpy(posisiUMKM, umkm->posisiDibutuhkan);
    toLowerRemoveSpace(posisiUser);
    toLowerRemoveSpace(posisiUMKM);
    if (strcmp(posisiUser, posisiUMKM) == 0) {
        score += 10;
    }

    // Compare salary
    if (umkm->gajiMinimal >= pekerja->gajiEkspektasi) {
        score += 10;
    }

    // Compare education level
    if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) {
        score += 10;
    } else {
        score = 0; 
    }

    return score;
}

// Function to recommend UMKMs to job seeker
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM) {
    printf("List Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++) {
        int scoreMatch = calculateMatchScore(pekerja, &daftarUMKM[i]);
        if (scoreMatch >= 20 && scoreMatch < 70) {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } else if (scoreMatch >= 70) {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } 
    }
}

// Function to recommend job seekers to UMKM
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja) {
    printf("List Rekomendasi pekerja untuk usaha %s:\n", umkm->namaUMKM);
    for (int i = 0; i < jumlahPekerja; i++) {
        int scoreMatch = calculateMatchScore(&daftarPekerja[i], umkm);
        if (scoreMatch >= 20 && scoreMatch < 70) {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } else if (scoreMatch >= 70) {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } 
    }
}

// Function to register a new UMKM
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

// Function to show all available UMKMs
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
