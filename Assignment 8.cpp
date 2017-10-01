// Assignment 8
// Leslie Ledeboer

#include <iostream>

using namespace std;

bool isPrime(int);
void printPrime(int *, int);

int main()
{
    int number, guess, answer = 0;
    int *primeNumbers = NULL;
    
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    primeNumbers = new int[number] {0};
    
    cout << "Guess the number of prime numbers between 0 and " << number << ": ";
    cin >> guess;
    cout << endl;
    
    for (int i = 0; i < number - 1; i++)
    {
        if (isPrime(i + 2))
        {
            primeNumbers[i] = i + 2;
        }
    }
    
    for (int i = 0; i < number - 1; i++)
    {
        if (primeNumbers[i] != 0)
        {
            answer++;
        }
    }
    
    if (guess == answer)
    {
        cout << "Correct! There are " << answer << " prime numbers in between 0 and " << number << "." << endl << endl;
        cout << "The prime numbers are: ";
        printPrime(primeNumbers, number);
    }
    
    else
    {
        cout << "Incorrect. There are " << answer << " prime numbers in between 0 and " << number << "." << endl << endl;
        cout << "The prime numbers are: ";
        printPrime(primeNumbers, number);
    }
}

bool isPrime(int number)
{
    bool condition;
    
    if (number < 2)
    {
        condition = false;
    }
    
    else if (number == 2)
    {
        condition = true;
    }
    
    else
    {
        for (int i = 2; i < number; i++)
        {
            int remainder;
            
            remainder = number % i;
            
            if (remainder == 0)
            {
                condition = false;
                break;
            }
            
            else
            {
                condition = true;
            }
        }
    }
    
    return condition;
}

void printPrime(int *primeNumbers, int number)
{
    for (int i = 0; i < number - 1; i++)
    {
        if (primeNumbers[i] != 0)
        {
            cout << primeNumbers[i] << " ";
        }
    }
}
