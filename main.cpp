#include "matrix.h"
#include <time.h>

int Plus1(MAT &A){
    int r = A.r;
    int c = A.c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            A.Data[i][j] += 1;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    MAT M = MAT(2, 2);    
    //MAT N = MAT(100, 100);
    FILE *file = fopen("test.in", "r");
    FILE *out = fopen("test.out", "w");
    M.GetM(file);
    //N.GetM(file);
    M.TRANS();    
    //printf("%x\n", &OP);
    //MULT(M, M, OP);
    M.PrintM(out);
    return 0;
}
