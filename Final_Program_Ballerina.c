#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

<<<<<<< HEAD
//struct enum (Nirmala)
=======
// Enum for education levels
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
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

<<<<<<< HEAD
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
void registerJobSeeker(dataJobSeeker *pekerja); //Thalita

// Fungsi utama
=======
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
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
int main() {
    int roleInt;
    char roleStr[20];
    int pilihan;

<<<<<<< HEAD
    dataUMKM listUMKM[11] = {
    //data UMKM (JOANNA)   
    [1] = {
        .namaUMKM = "Toko Roti Ceria",
        .kotaUMKM = "Bandung",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "memasak", "kebersihan", "komunikasi" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.0,
        .posisiDibutuhkan = "Asisten Dapur"
    },
    [2] = {
        .namaUMKM = "Bengkel Motor Jaya",
        .kotaUMKM = "Yogyakarta",
        .minimalPendidikan = SMP,
        .skillDibutuhkan = { "mekanik", "kerjasama", "problem solving" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.5,
        .posisiDibutuhkan = "Montir"
    },
    [3] = {
        .namaUMKM = "Warung Kopi Nusantara",
        .kotaUMKM = "Malang",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "barista", "komunikasi", "multitasking" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.2,
        .posisiDibutuhkan = "Barista"
    },
    [4] = {
        .namaUMKM = "Konveksi Bunda",
        .kotaUMKM = "Surabaya",
        .minimalPendidikan = D3,
        .skillDibutuhkan = { "menjahit", "ketelitian", "desain dasar" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.8,
        .posisiDibutuhkan = "Penjahit"
    },
    [5] = {
        .namaUMKM = "Kedai Sehat Hijau",
        .kotaUMKM = "Depok",
        .minimalPendidikan = S1,
        .skillDibutuhkan = { "manajemen", "komunikasi", "keuangan" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4.5,
        .posisiDibutuhkan = "Manajer Operasional"
    },
    [6] = {
        .namaUMKM = "Studio Foto Cerah",
        .kotaUMKM = "Bogor",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "fotografi", "editing", "kreativitas" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4.0,
        .posisiDibutuhkan = "Fotografer"
    },
    [7] = {
        .namaUMKM = "Laundry Express Bersih",
        .kotaUMKM = "Jakarta",
        .minimalPendidikan = SMP,
        .skillDibutuhkan = { "kebersihan", "efisiensi", "komunikasi" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.1,
        .posisiDibutuhkan = "Petugas Laundry"
    },
    [8] = {
        .namaUMKM = "Percetakan Digital Pro",
        .kotaUMKM = "Bekasi",
        .minimalPendidikan = D3,
        .skillDibutuhkan = { "desain grafis", "pengoperasian mesin", "ketelitian" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4.2,
        .posisiDibutuhkan = "Operator Mesin Cetak"
    },
    [9] = {
        .namaUMKM = "Toko Bunga Mawar",
        .kotaUMKM = "Semarang",
        .minimalPendidikan = SMA,
        .skillDibutuhkan = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 3.3,
        .posisiDibutuhkan = "Florist"
    },
    [10] = {
        .namaUMKM = "Katering Harapan Ibu",
        .kotaUMKM = "Tangerang",
        .minimalPendidikan = D4,
        .skillDibutuhkan = { "memasak", "pengemasan", "manajemen waktu" },
        .jumlahSkillDibutuhkan = 3,
        .gajiMinimal = 4.6,
        .posisiDibutuhkan = "Koki"
    }
    };

           // Data pekerja (Thalita)
    dataJobSeeker pekerja[11] = {
        [1] = {
=======
    // Data for Job Seekers
    dataJobSeeker pekerja[10] = {
        {
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
            .namaPekerja = "Andi Santoso",
            .kotaTinggal = "Bandung",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "memasak", "komunikasi", "manajemen" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.5,
            .posisiEkspektasi = "Asisten Dapur"
        },
        [2] = {
            .namaPekerja = "Budi Setiawan",
            .kotaTinggal = "Yogyakarta",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "mekanik", "kerjasama", "problem solving" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.2,
            .posisiEkspektasi = "Montir"
        },
<<<<<<< HEAD
        [3] = {
            .namaPekerja = "Citra Ayu",
            .kotaTinggal = "Malang",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "barista", "komunikasi", "multitasking" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.3,
            .posisiEkspektasi = "Barista"
        },
        [4] = {
            .namaPekerja = "Dedi Prasetyo",
            .kotaTinggal = "Surabaya",
            .pendidikanTerakhir = D3,
            .skillDipunyai = { "menjahit", "ketelitian", "desain dasar" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.7,
            .posisiEkspektasi = "Penjahit"
        },
        [5] = {
            .namaPekerja = "Erika Sari",
            .kotaTinggal = "Depok",
            .pendidikanTerakhir = S1,
            .skillDipunyai = { "manajemen", "komunikasi", "keuangan" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.2,
            .posisiEkspektasi = "Manajer Operasional"
        },
        [6] = {
            .namaPekerja = "Fikri Wijaya",
            .kotaTinggal = "Bogor",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "fotografi", "editing", "kreativitas" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.0,
            .posisiEkspektasi = "Fotografer"
        },
        [7] = {
            .namaPekerja = "Gina Rahmawati",
            .kotaTinggal = "Jakarta",
            .pendidikanTerakhir = SMP,
            .skillDipunyai = { "kebersihan", "efisiensi", "komunikasi" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.1,
            .posisiEkspektasi = "Petugas Laundry"
        },
        [8] = {
            .namaPekerja = "Hendra Saputra",
            .kotaTinggal = "Bekasi",
            .pendidikanTerakhir = D3,
            .skillDipunyai = { "desain grafis", "pengoperasian mesin", "ketelitian" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.0,
            .posisiEkspektasi = "Operator Mesin Cetak"
        },
        [9] = {
            .namaPekerja = "Indah Permatasari",
            .kotaTinggal = "Semarang",
            .pendidikanTerakhir = SMA,
            .skillDipunyai = { "merangkai bunga", "pelayanan pelanggan", "kreativitas" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 3.4,
            .posisiEkspektasi = "Florist"
        },
        [10] = {
            .namaPekerja = "Joko Nugroho",
            .kotaTinggal = "Tangerang",
            .pendidikanTerakhir = D4,
            .skillDipunyai = { "memasak", "pengemasan", "manajemen waktu" },
            .jumlahSkillDipunya = 3,
            .gajiEkspektasi = 4.6,
            .posisiEkspektasi = "Koki"
        }
    };



    //Main UI (SORAYA)
=======
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

>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
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

<<<<<<< HEAD
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
=======
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
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3

    return 0;
}

<<<<<<< HEAD
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

            if (strcmp(skillUMKM,skillUser) == 0) score += 15;
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
        if (strcmp(kotaUser, kotaUMKM ) == 0) score += 10;
    }


    if(mode == 0 || mode == 2){
    //hitung berdasar gaji
    if(umkm->gajiMinimal >= pekerja->gajiEkspektasi) score += 15;
    }
    
    if(mode == 0 || mode ==3){
        //hitung berdasar level pendidikan
        if (pekerja->pendidikanTerakhir == umkm->minimalPendidikan) score += 10;
        if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) score += 15;
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

//fungsi untuk input pemilik UMKM (JOANNA)
void registerUMKM( dataUMKM* inputUMKM){
    printf("\nInput nama UMKM anda: ");
    getchar();

    scanf("%[^\n]", inputUMKM->namaUMKM);
    getchar();

    printf("Input kota UMKM anda: ");
    scanf("%[^\n]", inputUMKM->kotaUMKM);
    getchar();

    printf("Minimal pendidikan untuk apply \n(0=tidak sekolah, 1=SD, 2=SMP, 3=SMA, 4=D3, 5=D4, 6=S1, 7=S2, 8=s3): ");
    scanf("%d", &inputUMKM->minimalPendidikan);
    getchar();

    printf("Jumlah skill yang dibutuhkan untuk apply (Maksimal 5): "); 
    scanf("%d", &inputUMKM->jumlahSkillDibutuhkan);
    getchar();

    for(int i=0; i<inputUMKM->jumlahSkillDibutuhkan; i++){
        printf("Skill %d yang dibutuhkan untuk apply: ", i+1);
        scanf("%[^\n]", (inputUMKM->skillDibutuhkan[i]));
        getchar();
    }

    printf("Gaji minimal yang diberikan: ");
    scanf("%f", &inputUMKM->gajiMinimal);
    getchar();
    
    printf("Posisi yang dibutuhkan: ");
    scanf("%[^\n]", inputUMKM->posisiDibutuhkan);
    getchar();
}


// Fungsi show all UMKM (Joanna)
void showUMKM(dataUMKM* daftarUMKM) {
    printf("\n==== List UMKM yang tersedia: ====\n\n");
    for (int i = 0; i < 11; i++) {
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

//fungsi untuk input pekerja (Thalita)
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
=======
// Function to get opposite role (Pekerja or UMKM)
const char* getOppositeRole(const char* role) {
    if (strcmp(role, "UMKM") == 0) {
        return "Pekerja";
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
    }
    if (strcmp(role, "Pekerja") == 0) {
        return "UMKM"; 
    }
    return "Tidak Dikenal";
}

<<<<<<< HEAD
//fungsi untuk semua pekerja (Thalita)
void showPekerja(dataJobSeeker *daftarPekerja) {
    printf("\n==== List Pekerja yang tersedia: ====\n\n");
    for(int i = 0; i < 11; i++) {
        printf("%d. ", i + 1);
        printf("%s\n", daftarPekerja[i].namaPekerja);
        printf("    Kota Tinggal: %s\n", daftarPekerja[i].kotaTinggal);
        printf("    Pendidikan Terakhir: ");
        switch (daftarPekerja[i].pendidikanTerakhir)
        {
        case 0:
            printf("Tidak Sekolah\n");
            break;
        case 1:
            printf("SD\n");
            break;
        case 2:
            printf("SMP\n");
            break;
        case 3:
            printf("SMA\n");
            break;
        case 4:
            printf("D3\n");
            break;
        case 5:
            printf("D4\n");
            break;
        case 6:
            printf("S1\n");
            break;
        case 7:
            printf("S2\n");
            break;
        case 8:
            printf("S3\n");
            break;
        default:
            break;
        }
        printf("    Skill yang dimiliki: \n");
        for (int j = 0; j < daftarPekerja[i].jumlahSkillDipunya; j++)
        {
            printf("        %d. %s\n", j + 1, daftarPekerja[i].skillDipunyai[j]);
=======
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
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
        }
        printf("    Gaji Ekspektasi: Rp%.2f juta\n", daftarPekerja[i].gajiEkspektasi);
        printf("    Posisi yang Diharapkan: %s\n\n", daftarPekerja[i].posisiEkspektasi);
    }
<<<<<<< HEAD
}
=======

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
>>>>>>> 44a1ff21e3ca1bff19ab1067e276ab2310fbf5d3
