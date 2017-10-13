// Assignment 12
// Leslie Ledeboer

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int bruteForce(int, int);
int euclidean(int, int);

int main()
{
    int number1, number2;
    
    clock_t start1, start2;
    
    do
    {
        cout << "Enter a first number: ";
        cin >> number1;
        cout << endl;
        
        cout << "Enter a second number: ";
        cin >> number2;
        cout << endl;
        
    } while (number1 == 0 && number2 == 0);
    
    if (number1 < number2)
    {
        swap(number1, number2);
    }

    start1 = clock();
    
    int gcd1 = bruteForce(number1, number2);
    
    double duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    start2 = clock();
    
    int gcd2 = euclidean(number1, number2);
    
    double duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    
    cout << fixed << setprecision(10);
    
    cout << "GCD found using brute force: " << gcd1 << endl << endl;
    cout << "GCD found using Euclidean algorithm: " << gcd2 << endl << endl;
    cout << "Time duration using brute force: " << duration1 << " seconds" << endl << endl;
    cout << "Time duration using Euclidean algorithm: " << duration2 << " seconds" << endl << endl;
    
    if (duration1 == duration2)
    {
        cout << "Both methods took the same amount of time." << endl << endl;
    }
    
    else if (duration1 < duration2)
    {
        cout << "Brute force was the faster method." << endl << endl;
    }
    
    else
    {
        cout << "Euclidean algorithm was the faster method." << endl <<endl;
    }
    
    return 0;
}

int bruteForce(int number1, int number2)
{
    int i = 1, gcd = 1;
    
    if (number2 == 0)
    {
        gcd = number1;
    }
    
    else
    {
        while (i <= number2)
        {
            if (number1 % i == 0 && number2 % i == 0)
            {
                gcd = i;
            }
            
            i++;
        }
    }
    
    return gcd;
}

int euclidean(int number1, int number2)
{
    if (number2 == 0)
    {
        return number1;
    }
    
    return euclidean(number2, number1 % number2);
}
