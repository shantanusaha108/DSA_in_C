//gcd of two numbers using reccursion

#include<stdio.h>

int gcd(int a , int b){
    if(b==0){
        return a;
    }else{
        return gcd(b , a%b);
    }
}

int main()
{
    int b , a;
    printf("Enter the first number : ");
    scanf(" %d" , &a);
    printf("Enter the second number : ");
    scanf(" %d" , &b);
    printf("The GCD of the two numbers is : %d" , gcd(a,b));
    return 0;
}
//Here's an example of how the function works with the inputs a = 24 and b = 18:

// 1> The gcd function is called with a = 24 and b = 18.

// 2> b is not equal to 0, so the function calculates the remainder of a divided by b, which is 24 % 18 = 6, and calls itself recursively with b = 18 and a % b = 6.

// 3> b is not equal to 0, so the function calculates the remainder of 18 divided by 6, which is 18 % 6 = 0, and calls itself recursively with b = 6 and a % b = 0.

// 4> b is equal to 0, so the function returns a, which is 6. Therefore, the GCD of 24 and 18 is 6.

//now if we reverse them we get 

// The gcd function is called with a = 18 and b = 24.

// 1> b is not equal to 0, so the function calculates the remainder of a divided by b, which is 18 % 24 = 18, and calls itself recursively with b = 24 and a % b = 18.

// 2> b is not equal to 0, so the function calculates the remainder of 24 divided by 18, which is 24 % 18 = 6, and calls itself recursively with b = 18 and a % b = 6.

// 3> b is not equal to 0, so the function calculates the remainder of 18 divided by 6, which is 18 % 6 = 0, and calls itself recursively with b = 6 and a % b = 0.

// 4> b is equal to 0, so the function returns a, which is 6. Therefore, the GCD of 18 and 24 is 6.


// Note that the order of a and b does not matter in this algorithm, as the function will always calculate the same GCD regardless of the order of the inputs.








//tower of brahma


#include<stdio.h>

void tower_of_brahma(int n , char source , char destination  , char intemidiary){
    if(n==1){
        printf("Move disk %d from %c to %c.\n" , n , source , destination);
    }else{
        tower_of_brahma(n-1 , source , intemidiary , destination);
        printf("Move disk %d from %c to %c\n" , n , source , destination);
        tower_of_brahma(n-1 , intemidiary , destination , source);
    }
}

int main()
{
    int n;
    printf("Enter total no of disks : ");
    scanf(" %d" , &n);
    tower_of_brahma(n,'A' , 'B' , 'C');
    return 0;
}





//lcm using recurrsion


#include <stdio.h>

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    static int multiple = 0;
    multiple += b;
    if ((multiple % a == 0) && (multiple % b == 0)) {
        return multiple;
    } else {
        return lcm(a, b);
    }
}

int main() {
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    printf("LCM of %d and %d is %d\n", a, b, lcm(a, b));
    return 0;
}


// The gcd() function is used to find the greatest common divisor of the two numbers, which is used to calculate the LCM using the formula:

// LCM(a, b) = (a * b) / GCD(a, b)

// The lcm() function uses recursion to find the LCM. It first calculates the sum of the second number with itself repeatedly until the resulting number is a multiple of the first number. The multiple variable is static to preserve its value across function calls.

// Finally, in the main() function, the user inputs two positive integers, and the LCM of the two numbers is calculated and displayed.