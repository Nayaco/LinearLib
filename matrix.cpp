#include "matrix.h"

MAT::MAT(){
    this->r = 0;
    this->c = 0;
    this->Data = NULL;
}

MAT::MAT(const MAT &B){
    int r = this->r = B.r;
    int c = this->c = B.c;
    this->Data = new double*[r];
    for(int i = 0; i < r; i++){
        this->Data[i] = new double[c];
        memcpy(this->Data[i], B.Data[i], c*sizeof(double));
    }
}

MAT::MAT(int r ,int c){
    this->r = r;
    this->c = c;
    this->Data = new double*[r];
    for(int i = 0; i < r; i++)this->Data[i] = new double[c];
}

MAT::~MAT(){
    int r = this->r;
     for(int i = 0; i <r; i++)free(this->Data[i]);
    free(this->Data);
}

bool MAT::GetM(FILE* stream){
    if(stream == NULL)return 1;
    int r = this->r;
    int c = this->c;
    double **data = this->Data;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fscanf(stream, "%lf", &data[i][j]);
        }
    }
    return 0;
}

void MAT::PrintM(FILE *stream){
    if(stream == NULL)return;
    int r = this->r;
    int c = this->c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fprintf(stream, "%.1lf ", this->Data[i][j]);
        }
        fprintf(stream, "\n");
    }
    return;
}

void MAT::MINUS(){
    int r = this->r;
    int c = this->c; 
    for(int i = 0; i < r; i++){
        for(int j  = 0; j < c; j++){
            this->Data[i][j] = -this->Data[i][j];
        }
    }
}

int MAT::MWISE(std::function<int (MAT&)> func){
    return func(*this);
}

MAT MAT::operator+(const MAT &B)const{
    int r = this->r;
    int c = this->c;
    if(r != B.r || c != B.c)return MAT();
    MAT C = MAT(r, c);
    double **Ad = this->Data;
    double **Bd = B.Data;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            C.Data[i][j] = Ad[i][j] + Bd[i][j];
        }   
    }

    return C;
}

MAT MAT::operator-()const{
    int r = this->r;
    int c = this->c;
    MAT C = MAT(r, c);
    double **Ad = this->Data;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            C.Data[i][j] = -Ad[i][j];
        }   
    }

    return C;
}

MAT MAT::operator*(const MAT &B)const{
    int r = this->r;
    int c = this->c;
    if(c != B.r)return MAT();
    MAT C = MAT(r, B.c);
    double **Ad = this->Data;
    double **Bd = B.Data;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < B.c; j++){
            C.Data[i][j] = 0;
            for(int k = 0; k < c; k++)C.Data[i][j] += Ad[i][k] * Bd[k][j];
        }
    }
    
    return C;
}

MAT MAT::operator*(const int n)const{
    int r = this->r;
    int c = this->c;
    MAT C = MAT(r, c);
    double **data = this->Data;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            C.Data[i][j] = data[i][j] * n;
        }   
    }

    return C;
}

int PLUS(const MAT &A, const MAT &B, MAT &Dest){
    int ar = A.r, br = B.r;
    int ac = A.c, bc = B.c;
    if(ar != br || ac != bc)return 1;
    double **Ad = A.Data;
    double **Bd = B.Data;
    Dest.r = ar;
    Dest.c = ac;
    for(int i = 0; i < ar; i++){
        for(int j = 0; j < ac; j++){
            Dest.Data[i][j] = Ad[i][j] + Bd[i][j];
        }
    }
    return 0;
}

int MULT(const MAT &A, const MAT &B, MAT &Dest){
    int ar = A.r, br = B.r;
    int ac = A.c, bc = B.c;
    if(ac != br)return 1;
    double **Ad = A.Data;
    double **Bd = B.Data;
    Dest.r = ar;
    Dest.c = bc;
    for(int i = 0; i < ar; i++){
        for(int j = 0; j < bc; j++){
            Dest.Data[i][j] = 0;
            for(int k = 0; k < ac; k++)Dest.Data[i][j] += Ad[i][k] * Bd[k][j];
        }
    }
    return 0;
}