#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BigInteger.h"

int main(int argc, char* argv[])
{
    FILE* in, * out;


    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n");
        exit(1);
    }

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if (in == NULL)
    {
        fprintf(stderr, "Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }
    if (out == NULL)
    {
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }

    int a;
    fscanf(in, "%d", &a);
    char* str1= new char[];

    char c;
    int i = 0;
    for (; i < a + 0; i++)
    {
        fscanf(in, " %c", &c);
        str1[i] = c;
        if (c == '+' || c == '-')
        {
            a += 1;
        }
    }
    fscanf(in, "%d", &a);
    char* str2 = new char[];
    for (i = 0; i < a + 0; i++)
    {
        fscanf(in, " %c", &c);
        str2[i] = c;
        if (c == '+' || c == '-')
        {
            a += 1;
        }
    }

    BigInteger A = stringToBigInteger((char*)str1);
    BigInteger B = stringToBigInteger((char*)str2);
    BigInteger C = newBigInteger();
 
    printBigInteger(out, A);
    fprintf(out, "\n");

    printBigInteger(out, B);
    fprintf(out, "\n");

    C = sum(A, B);
    printBigInteger(out, C);
    fprintf(out, "\n");

    subtract(C, A, B);
    printBigInteger(out, C);
    fprintf(out, "\n");

    C = diff(A, A);
    printBigInteger(out, C);
    fprintf(out, "\n");

    C = diff(MultiplyByConstant(A, 3), MultiplyByConstant(B, 2));
    printBigInteger(out, C);
    fprintf(out, "\n");

    C = prod(A, B);
    printBigInteger(out, C);
    fprintf(out, "\n");

    multiply(C, A, A);
    printBigInteger(out, C);
    fprintf(out, "\n");

    C = prod(B, B);
    printBigInteger(out, C);
    fprintf(out, "\n");

    C = sum(MultiplyByConstant(prod(prod(A, A), prod(A, A)), 9), MultiplyByConstant(prod(B, prod(prod(B, B), prod(B, B))), 16));
    printBigInteger(out, C);



}