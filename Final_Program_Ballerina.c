#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//function prototype
void calculateMatchScore(dataUMKM *umkm, dataJobSeeker *pekerja);


//struct
typedef enum{
    design, copywriting, data_engineering, microsoft_office, programming, marketing, data_analysis, writing, digital_security, project_management, customer_relations, problem_solving, communication, adaptability, teamwork, time_management, conflict, creativity, leadership, critical_thinking, negotiation 
} skill;

typedef union{
    char tidak_sekolah[10];
    char SD[20];
    char SMP[20];
    char SMA[20];
    char S1[10];
    char S2[10];
    char S3[10];
} tingkatPendidikan;

typedef struct {
    char namaPekerja[50];
    char kotaTinggal[20];
    tingkatPendidikan pendidikanTerakhir;
    int skillDipunyai[20];
    float gajiEkspektasi;
    char posisiEkspektasi[20];
} dataJobSeeker;

typedef struct {
    char namaUMKM[50];
    char kotaUMKM[20];
    tingkatPendidikan minimalPendidikan;
    int skillDibutuhkan[20];
    float gajiMinimal;
    char posisiDibutuhkan[20];
} dataUMKM;



int main(){


    return 0;
}


//function
void calculateMatchScore(dataUMKM *umkm, dataJobSeeker *pekerja){
    
}




