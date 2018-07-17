/*
* MATRIX BY Gangdou
*/

#ifndef MAT_H
#define MAT_H

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <functional>

class MAT{
    public:
        int r, c;
        double **Data;
        MAT();
        
        MAT(const MAT &B);
        
        MAT(int r, int c);
        
        ~MAT();

        //////////////////////////////////////////////////
        
        bool GetM(FILE *stream);

        void PrintM(FILE *stream);
        
        void MINUS();
        
        void TRANS();
        
        int MWISE(std::function<int (MAT&)> func);
        
        //////////////////////////////////////////////////
        
        MAT operator +(const MAT &B)const;
        
        MAT operator -()const;
        
        MAT operator *(const MAT &B)const;
        
        MAT operator *(const int n)const;        
};

//////////////////////////////////////////////////

int PLUS(const MAT &A, const MAT &B, MAT &Dest);
        
int MULT(const MAT &A, const MAT &B, MAT &Dest);

#endif