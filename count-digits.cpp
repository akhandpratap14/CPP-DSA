#include <iostream>
#include <algorithm>

using namespace std;

int countDigits(int number){
    int count = 0;
    while(number > 0){
        count++;
        number = number / 10;
    }
    return count;
}

int reverseNumber(int number){
    int lastDigit = 0;
    int reverse = 0;
    while(number > 0){
        lastDigit = number % 10;
        reverse = reverse * 10 + lastDigit;
        number = number / 10;
    }
    return reverse;
}

bool checkPalindrome(int number){
    int lastDigit = 0;
    int reverse = 0;
    int dup = number;
    while(number > 0){
        lastDigit = number % 10;
        reverse = (reverse * 10) + lastDigit;
        number = number / 10;
    }
    if (dup == reverse){ 
        return true;
    } else{ 
        return false;
    }
}

int consumeGcd(int n1, int n2){
    int gcd = 1;
    for(int i=1; i<=min(n1,n2); i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

int euclideanGcd(int a, int b){
    while(a > 0 && b > 0){
        if(a>b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if(a == 0){
        return b;
    } 
    return a;
}

bool isArm(int a){
    int k = to_string(a).length();
    int sum = 0;
    int dup = a;
    while(a>0){
        int ld = a % 10;
        sum += pow(ld, k);
        a = a / 10;
    }
    return  sum == dup ? true : false;;
}

int main() {

    int number = 121;

    cout << "isArm : " << isArm(121) << endl;

    return 0;
}