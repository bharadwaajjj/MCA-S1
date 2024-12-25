#include<stdio.h>

int isPresent(int arr[],int size,int element)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

int main(){
    int n,uni[100],i,element,n1,set1[100],bit1[100],n2,set2[100],bit2[100],exists;
    int setUnion[100],setIntersection[100];
    printf("Enter the size of Universal Set :");
    scanf("%d",&n);
    printf("Enter the elements in universal set\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&element);
        if(isPresent(uni,i,element)==0)
        {
            uni[i]=element;
        }
        else{
            printf("Element already exists in set!!!\n");
            i--;
        }
    }

    printf("\nEnter the size of first set :");
    scanf("%d",&n1);
    if(n1>n)
    {
        printf("Size of first set cannot be greater than universal set !!");
        return 0;
    }
    else{
        for(i=0;i<n1;i++)
        {
            printf("Enter element %d : ",i+1);
            scanf("%d",&element);
            if(isPresent(set1,i,element)==0)
            {
                set1[i]=element;
            }
            else{
                printf("Element already exists in set!!!\n");
                i--;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        exists = isPresent(set1,n1,uni[i]);
        bit1[i]=exists;
            
    }

    printf("\nEnter the size of second set :");
    scanf("%d",&n2);
    if(n2>n)
    {
        printf("Size of second set cannot be greater than universal set !!");
        return 0;
    }
    else{
        for(i=0;i<n2;i++)
        {
            printf("Enter element %d : ",i+1);
            scanf("%d",&element);
            if(isPresent(set2,i,element)==0)
            {
                set2[i]=element;
            }
            else{
                printf("Element already exists in set!!!\n");
                i--;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        exists = isPresent(set2,n2,uni[i]);
        bit2[i]=exists;
    }

    for(int i=0;i<n;i++)
    {
        if(bit1[i]==1 && bit2[i]==1){
            setIntersection[i]=1;
        }
        else{
            setIntersection[i]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(bit1[i]==1 || bit2[i]==1){
            setUnion[i]=1;
        }
        else{
            setUnion[i]=0;
        }
    }

    printf("\nUniversal SET\n");
    printf("{");
    for(i=0;i<n;i++)
    {
        printf("%d,",uni[i]);
    }
    printf("}\n");
    printf("\nFirst SET\n");
    printf("{");

    for(i=0;i<n1;i++)
    {
        printf("%d,",set1[i]);
    }
    printf("}\n");

    printf("\nBit Representation of First SET\n");
    printf("{");
    for(i=0;i<n;i++)
    {
        printf("%d,",bit1[i]);
    }
    printf("}\n");

    printf("\nSecond SET\n");
    printf("{");
    for(i=0;i<n2;i++)
    {
        printf("%d,",set2[i]);
    }
    printf("}\n");
    printf("\nBit Representation of Second SET\n");
    printf("{");
    for(i=0;i<n;i++)
    {
        printf("%d,",bit2[i]);
    }
    printf("}\n");

    printf("\nUnion Of Both Sets\n");
    printf("{");
    for(i=0;i<n;i++)
    {
        printf("%d,",setUnion[i]);
    }
    printf("}\n");

    printf("\nIntersection Of Both Sets\n");
    printf("{");
    for(i=0;i<n;i++)
    {
        printf("%d,",setIntersection[i]);
    }
    printf("}\n");

    return 0;
}