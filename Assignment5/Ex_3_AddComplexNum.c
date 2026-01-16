#include<stdio.h>
#include<string.h>

struct SComplex
{
    float Real;
    float imaginary;
};

struct SComplex GetComplex(struct SComplex x)
{
    printf("Enter real and imaginary respectively: ");
    scanf("%f",&x.Real);
    scanf("%f",&x.imaginary);
    return x;
}

struct SComplex AddComplex(struct SComplex x, struct SComplex y)
{
    struct SComplex z;
    z.Real = x.Real + y.Real;
    z.imaginary = x.imaginary + y.imaginary;
    return z;
}

int main()
{
    struct SComplex x,y,z;
    x = GetComplex(x);
    y = GetComplex(y);
    z= AddComplex(x,y);
    printf("Sum = %.1f + %.1fi",z.Real,z.imaginary);
}
