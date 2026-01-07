#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    printf("Enter the total number of inputs : ");
    scanf("%d" , &n);
    fflush(stdin);
    char str[n][50] , temp[50] ;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d name : " , i+1);
        gets(str[i]);
    }
    
    //sorting the string
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            int r = strcmp(str[j] , str[j+1]);
            if(r>0){
                strcpy(temp , str[j]);
                strcpy(str[j] , str[j+1]);
                strcpy(str[j+1] , temp);
            }
        }
        
    }
    
    printf("The sorted names in dictionary order are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n" ,str[i]);

    }

    return 0;
}