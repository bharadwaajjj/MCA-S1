#include<stdio.h>

int arr1[100],n,arr2[100],m,arr3[200];

void init_arr1();
void init_arr2();
void display();
void merge();

int main()
{
    while(1)
    {
        int ch;
        printf("Enter the choice :\n");
        printf("1)First Array\n2)Second Array\n3)Display Both Arrays\n4)Merge Arrays and Print\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                init_arr1();
                break;
            case 2:
                init_arr2();
                break;
            case 3:
                display();
                break;
            case 4:
                merge();
                break;
            default:
                return 0;
        }
    }
    return 0;
}

void init_arr1()
{
    printf("Enter size of first Array :");
    scanf("%d",&n);
    printf("Enter Array Elements :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
}

void init_arr2()
{
    printf("Enter size of second array :");
    scanf("%d",&m);
    printf("Enter Array Elements :\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
}

void display()
{
    printf("First Array :");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr1[i]);
    }
    printf("\nSecond Array :");
    for(int i=0;i<m;i++)
    {
        printf("%d\t",arr2[i]);
    }
    printf("\n");
}

void merge()
{
    int k;
    k=m+n;
    for(int i=0;i<k;i++)
    {
        if(i<n)
        {
            arr3[i]=arr1[i];
        }
        else{
            arr3[i]=arr2[i-n];
        }
    }
    printf("Merged array : ");
    for(int i=0;i<k;i++)
    {
        printf("%d\t",arr3[i]);
    }
}