#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



//function prototype
void toLower(char *skill);
int calculateMatchScore(dataJobSeeker *pekerja, dataUMKM *umkm);
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM);
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja);


typedef enum{
    tidak_sekolah, SD, SMP, SMA, D3, D4, S1, S2, S3
} tingkatPendidikan;

typedef struct {
    char namaPekerja[50];
    char kotaTinggal[20];
    tingkatPendidikan pendidikanTerakhir;
    int skillDipunyai[10][20];
    int jumlahSkillDipunya;
    float gajiEkspektasi;
    char posisiEkspektasi[20];
} dataJobSeeker;

typedef struct {
    char namaUMKM[50];
    char kotaUMKM[20];
    tingkatPendidikan minimalPendidikan;
    int skillDibutuhkan[5][20];
    int jumlahSkillDibutuhkan;
    float gajiMinimal;
    char posisiDibutuhkan[20];
} dataUMKM;


int main(){
    
    
    return 0;
}

//function

//fungsi untuk comparing agar lowercase dan uppercase seragam
void toLower(char *skill){
    for (int i = 0; i < skill[i]; i++)
    {
        skill[i] = tolower(skill[i]);
    }
}

//fungsi hitung match score antara perushaan a dan pekerja b
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
            
            toLower(skillUMKM); toLower(skillUser);
            
            if (strcmp(skillUMKM,skillUser) == 0) score += 10;
        }
    }
    //hitung berdasar kota yang sama
    char kotaUser[20], kotaUMKM[20];
    strcpy(kotaUser, pekerja->kotaTinggal);
    strcpy(kotaUMKM, umkm->kotaUMKM);
    if (strcmp(kotaUser, kotaUMKM ) == 0) score += 5;
    
    //hitung berdasar posisi yang sama
    char posisiDiinginkan[20], posisiDicari[20];
    strcpy(posisiDiinginkan, pekerja->posisiEkspektasi);
    strcpy(posisiDicari, umkm->posisiDibutuhkan);
    if (strcmp(kotaUser, kotaUMKM ) == 0) score += 10;
    
    //hitung berdasar gaji
    if(umkm->gajiMinimal >= pekerja->gajiEkspektasi) score += 10;
    
    //hitung berdasar level pendidikan
    if (pekerja->pendidikanTerakhir >= umkm->minimalPendidikan) score += 10;
    else score *= 0;
    
}

//fungsi rekomendasi umkm bagi jobseeker
void rekomendasiUMKM(dataJobSeeker *pekerja, dataUMKM daftarUMKM[], int jumlahUMKM){
    printf("List Rekomendasi UMKM untuk %s:\n", pekerja->namaPekerja);
    for (int i = 0; i < jumlahUMKM; i++)
    {
        int scoreMatch = hitungMatchSkill(pekerja, &daftarUMKM[i]);
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
void rekomendasiPekerja(dataUMKM *umkm, dataJobSeeker daftarPekerja[], int jumlahPekerja){
    printf("List Rekomendasi pekerja untuk usaha %s:\n", umkm->namaUMKM);
    for (int i = 0; i < jumlahPekerja; i++)
    {
        int scoreMatch = hitungMatchSkill(umkm, &daftarPekerja[i]);
        if (scoreMatch >= 20 && scoreMatch < 70)
        {
            printf("> %s : cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } else if (scoreMatch >= 70)
        {
            printf("> %s : sangat cocok [matching score sebesar %d]\n", daftarPekerja[i].namaPekerja, scoreMatch);
        } 
    }
}

void registerUMKM( dataUMKM* inputUMKM){
    printf("Input nama UMKM anda ");
    scanf("%[^\n]", inputUMKM->namaUMKM);
    printf("\nInput kota UMKM anda ");
    scanf("%[^\n]", inputUMKM->kotaUMKM);
    printf("\nMinimal pendidikan untuk apply (0=SD, 1=SMP, 2=SMA, 3=D3, 4=D4, 5=S1, 6=S2, 7=S3)");
    scanf("%d", inputUMKM->minimalPendidikan);
    printf("\nSkill yang dibutuhkan untuk apply");
    scanf("%[^\n]", inputUMKM->skillDibutuhkan);
    printf("\nJumlah skill yang dibutuhkan untuk apply");
    scanf("%d", inputUMKM->skillDibutuhkan);
    printf("\nGaji minimal yang diberikan");
    scanf("%f", inputUMKM->gajiMinimal);
    printf("\nPosisi yang dibutuhkan ");
    scanf("%[^\n]", inputUMKM->posisiDibutuhkan);

}







