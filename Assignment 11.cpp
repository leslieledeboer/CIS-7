// Assignment 11
// Leslie Ledeboer

#include <iostream>

using namespace std;

int findMinimum(int, int);
int findGCD(int, int, int);

int main()
{
    int number1, number2;
    
    do
    {
        cout << "Enter a first number: ";
        cin >> number1;
        cout << endl;
    
        cout << "Enter a second number: ";
        cin >> number2;
        cout << endl;
        
    } while (number1 == 0 && number2 == 0);
    
    int minimum = findMinimum(number1, number2);
    
    int GCD = findGCD(minimum, number1, number2);
    
    cout << "The greatest common divisor between " << number1 << " and " << number2 << " is " << GCD << endl << endl;
    
    return 0;
}

int findMinimum(int number1, int number2)
{
    int minimum;
    
    if (number1 <= number2)
    {
        minimum = number1;
    }
    
    else
    {
        minimum = number2;
    }
    
    return minimum;
}

int findGCD(int minimum, int number1, int number2)
{
    int i = 1, GCD = 1;
    
    if (number1 == 0 || number2 == 0)
    {
        if (number1 == 0)
        {
            GCD = number2;
        }
        
        else
        {
            GCD = number1;
        }
    }
    
    else
    {
        while (i <= minimum)
        {
            if (number1 % i == 0 && number2 % i == 0)
            {
                GCD = i;
            }
            
            i++;
        }
    }
    
    return GCD;
}