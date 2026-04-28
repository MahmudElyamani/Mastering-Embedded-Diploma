#include<stdio.h>
#include<string.h>

struct SDistance
{
    short feet;
    float inches;
};

struct SDistance GetDistance(struct SDistance x)
{
    printf("Enter feet: ");
    scanf("%d",&x.feet);
    printf("Enter inches: ");
    scanf("%f",&x.inches);
    return x;
}

struct SDistance AddDistance(struct SDistance x, struct SDistance y)
{
    struct SDistance z;
    z.feet = x.feet + y.feet;
    z.inches = x.inches + y.inches;
    while(z.inches >= 12)
    {
        z.inches -= 12;
        z.feet += 1;
    }
    return z;
}

int main()
{
    struct SDistance x,y,z;
    printf("Enter information for the 1st Distance: \n");
    x = GetDistance(x);
    printf("Enter information for the 2st Distance: \n");
    y = GetDistance(y);
    z= AddDistance(x,y);
    printf("Sum of distances = %d'%.2f''",z.feet,z.inches);
}
