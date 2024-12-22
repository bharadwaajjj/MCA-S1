#include<stdio.h>

int arr[100],n;
int is_created = 0;

void display();
void create();
void insert();
void search();
void delete();

int main()
{
    while(1){
        int ch;
        printf("Enter the Choice :\n");
        printf("1)Creation\n2)Insertion\n3)Display\n4)Search\n5)Delete\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            delete();
            break;
        default:
            return 0;
        }
    }
    return 0;
}
void create()
{
    if(!is_created){
        printf("Enter the size of array : ");
        scanf("%d",&n);
        printf("Enter Array Elements :\n");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        is_created = 1;
    }
    else{
        printf("Array Already created\n");
    }
    
}
void display()
{
    printf("Elements in Array are :");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insert()
{
    int pos,val,temp;
    printf("Enter the position you want to insert new element (Should be less than %d):\n",n);
    scanf("%d",&pos);
    if(pos <= n)
    {
        printf("Enter the element you want to insert :");
        scanf("%d",&val);
        n++;
        for(int i=n;i>=pos;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[pos-1]=val;
    }
    else
    {
        printf("Cannot insert element since it is out of size of array\n");
    }
}

void search()
{
    int element , found=0;
    printf("Enter the element to be searched :");
    scanf("%d",&element);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            printf("Element found at position %d\n",i+1);
            found=1;
        }
    }
    if(!found)
    {
        printf("Element not found");
    }
}

void delete()
{
    int index;
    printf("Enter the index from which you need to delete the element(Should be less than %d) :",n);
    scanf("%d",&index);
    if(0<index<=n)
    {
        for(int i=index;i<n;i++)
        {
            arr[i]=arr[i+1];
        }
        n=n-1;
    }
    else{
        printf("Cannot delete from the inputed index");
    }
}