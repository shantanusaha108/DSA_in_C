#include<stdio.h>
#include<string.h>

void substring_match(char *str , char *sttr){
    int i = 0;
    while (str[i] != '\0')
    {
        int j = i;
        int n = 0;
        int count = 0;
        while (sttr[n] != '\0')
        {
            if(str[j] == sttr[n]){
                count++;
            }
            n++;
            j++;
        }
        if(count == strlen(sttr) ){
            printf("The substring : %s exist inside the string : %s.\n" , sttr , str);
            return;
        }
        i++;
    }
    printf("The substring : %s dosen't exist inside the string : %s.\n" , sttr , str);
    
}

int main()
{
    char str[100] , sttr[100];
    printf("Enter the main string : ");
    gets(str);
    fflush(stdin);
    printf("Enter the substring to be checked : ");
    gets(sttr);
    fflush(stdin);
    substring_match(str,sttr);
    return 0;
}


//this above code has a time compkexity of O^2.