#include "matrix.h"

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
    MAT N = MAT(2, 2);
    FILE *file = fopen("test.in", "r");
    M.GetM(file);
    N.GetM(file);
    MAT OP = MAT(2, 2);
    N.MWISE(Plus1);

    N.PrintM(stdout);
    return 0;
}
