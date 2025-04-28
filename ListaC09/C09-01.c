#include<stdio.h>
#include<stdlib.h>
int main(){
    int varint = 50;
    float varfloat = 25.5;
    char varchar = 'B';
    int* ptrint;
    float* ptrfloat;
    char* ptrchar;
    ptrint = &varint;
    ptrfloat = &varfloat;
    ptrchar = &varchar;
    printf("varint = %d\n", varint );
    printf("varfloat = %f\n", varfloat );
    printf("varchar = %c\n", varchar );
    *ptrint = 25;
    *ptrfloat = 32.5;
    *ptrchar = 'F';
    printf("varint = %d\n", varint );
    printf("varfloat = %f\n", varfloat );
    printf("varchar = %c\n", varchar );
}