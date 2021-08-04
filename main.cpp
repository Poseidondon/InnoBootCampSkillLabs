#include <iostream>
#include <cmath>
using namespace std;


bool is_prime(int number){
    for (int i=2; i <= int(sqrt(number)) + 1; i++){
        if (number % i == 0){
            return false;
        }
    }
    return true;
}


void square_equation(float a, float b, float c){
    float d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "Discriminant is negative" << "\n";
    } else if (d == 0) {
        float answ1 = (-b + sqrt(d)) / (2 * a);
        cout << "Answer is " << answ1 << "\n";
    } else {
        float answ1 = (-b + sqrt(d)) / (2 * a);
        float answ2 = (-b - sqrt(d)) / (2 * a);
        cout << "Answers are " << answ1 << " and " << answ2 << "\n";
    }
}


void triangle(float a, float b, float c){
    if ((a + b <= c) || (a + c <= b) || (c + b <= a)){
        cout << "Such triangle doesn't exist" << '\n';
        return;
    }
    float p = (a + b + c) / 2;
    float s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Triangle square is " << s << '\n';
}


int gcd(int n1, int n2){
    for (int i = n1; i >= 1; --i){
        if ((n1 % i == 0) && (n2 % i == 0))
            return i;
    }
}


int main(){
    triangle(3, 4, 50);
    triangle(3, 4, 5);
    cout << gcd(5436, 4422) << '\n';
}
