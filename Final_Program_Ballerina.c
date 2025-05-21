#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



//struct enum
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

//function prototype
void toLowerRemoveSpace(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm, modeFilter);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM, modeFilter);
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja, modeFilter);

int main(){


    
    return 0;
}

//function

//fungsi untuk comparing agar lowercase dan uppercase seragam
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

//fungsi hitung match score antara perushaan a dan pekerja b
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm, modeFilter mode){
    int score = 0;

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

//fungsi rekomendasi umkm bagi jobseeker
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM, modeFilter mode){
    printf("List Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++)
    {
        int scoreMatch = calculateMatchScore(pekerja, &daftarUMKM[i], mode);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } else if (scoreMatch >= 70)
        {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarUMKM[i].namaUMKM, scoreMatch);
        } 
    }
}

//fungsi rekomendasi pekerja bagi umkm
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja, modeFilter mode){
    printf("List Rekomendasi pekerja untuk usaha %s:\n", umkm->namaUMKM);
    for (int i = 0; i < jumlahPekerja; i++)
    {
        int scoreMatch = calculateMatchScore(&daftarPekerja[i], umkm, mode);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } else if (scoreMatch >= 70)
        {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } 
    }
}


