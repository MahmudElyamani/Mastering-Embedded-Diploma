//Assignment 3
//Arrays and string (Lesson 4)
//by Mahmoud Elyamani.


#include <stdio.h>
#include <string.h>
int main()
{
    /*Ex.1
    float m1[2][2], m2[2][2], ms[2][2];
    int i,j;
    printf("Enter the elements of 1st matrix: \n\r");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%f",&m1[i][j]);
        }
    }
    printf("Enter the elements of 2nd matrix: \n\r");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter b%d%d: ",i+1,j+1);
            scanf("%f",&m2[i][j]);
            ms[i][j]= m1[i][j]+m2[i][j];
        }
    }
    printf("Sum of Matrix: \n\r");
     for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%1.1f   ",ms[i][j]);
        }
        printf("\n\r");
    }
        */



    /*Ex.2
    float a[100],sum=0;
    int i,j,num;
    printf("Enter the number of data: ");
    scanf("%d",&num);
    for (i=0; i<num; i++)
    {
        printf("%d. Enter number: ",i+1);
        scanf("%f",&a[i]);
        sum += a[i];
    }
    printf("Average = %2.2f",sum/num);
    */


    /*Ex.3
    float m[100][100], mt[100][100];
    int i,j,r,c;
    printf("Enter rows of Matrix: ");
    scanf("%d",&r);
    printf("Enter Columns of Matrix: ");
    scanf("%d",&c);
    printf("Enter elements of matrix: \n\r");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("Enter element a%d%d: ",i+1,j+1);
            scanf("%f",&m[i][j]);
            mt[j][i] = m[i][j];
        }
    }
    printf("Entered Matrix: \n\r");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%1.1f  ",m[i][j]);
        }
        printf("\n\r");
    }
    printf("Transpose of Matrix: \n\r");
    for (i=0; i<c; i++)
    {
        for (j=0; j<r; j++)
        {
            printf("%1.1f  ",mt[i][j]);
        }
        printf("\n\r");
    }
    */

    /*Ex.4
   int i,j,n;
   float a[100], newnum, numloc;
   printf("Enter number of elements: ");
   scanf("%d",&n);
   printf("Enter the elements one by one: ");
   for(i=0; i<n; i++)
   {
    scanf("%f",&a[i]);
   }
   printf("Enter the element to be inserted: ");
   scanf("%f",&newnum);
   printf("Enter its location: ");
   scanf("%f",&numloc);
   for (i=n; i>0; i--)
   {
    a[i+1] = a[i];
    if(i == numloc-1)
    {
        a[i] = newnum;
        continue;
    }
   }
   for(i=0; i<=n; i++)
   printf("%1.1f  ",a[i]);
   */

    /*Ex.5
    int n, loc, i, j;
    float elements[30], srchd;
    printf("Enter no. elements: ");
    scanf("%d",&n);
    printf("Enter The elements: ");
    for (i=0; i<n; i++)
    scanf("%f",&elements[i]);
    printf("Enter element to be searched: ");
    scanf("%f",&srchd);
    for (i=n; i>=0; i--)
    {
        if (elements[i] == srchd)
        printf("Number found at the location: %d",i+1);
    }
    */
//###############################################################################################

  // * HW: String * //

  /*Ex.1
  char c;
  int i, count = 0;
  char text[100];
  printf("Enter a string: ");
  gets(text);
  printf("Enter a characer to find frequency: ");
  scanf("%c",&c);
  for (i=0; i<sizeof(text); i++)
  {
    if(text[i] == c)
    count++;
  }
  printf("Frequency of %c = %d",c,count);
  */

  /*Ex.2
    char text[100];
    int count=0, i;
    printf("Enter a string: ");
    gets(text);
    for (i=0; i<sizeof(text); i++)
    {
        if(text[i] == '\0')
        break;
        count++;
    }
    printf("Length of string: %d",count);
    */

    /*Ex.3
    char text [100], rev[100];
    int i, j=0;
    printf("Enter the string: ");
    gets(text);
    for (i=strlen(text); i>0; i--)
    {
        rev[j] = text[i-1];
        j++;
    }
    rev[j] = '\0';
    printf("Reverse sting is: %s",rev);
    */
}
