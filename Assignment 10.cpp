//  Assignment 10
//  Leslie Ledeboer

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int);
int* primeNumbers(int);
int* primeFactors(int, int *);
void printPrimeFactors(vector <int>);
vector <int> trimArray(int, int *);
vector <int> countFactors(int, vector <int> &);

int main()
{
    int number, *primeArray = NULL;
    vector <int> primeVector;
    
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;
    
    primeArray = primeFactors(number, primeNumbers(number));
    
    primeVector = trimArray(number, primeArray);
    
    delete[] primeArray;
    
    cout << "The prime factorization of " << number << " is ";
    printPrimeFactors(countFactors(number, primeVector));
    cout << endl << endl;
    
    return 0;
}

bool isPrime(int number)
{
    bool condition = false;
    
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

int* primeNumbers(int number)
{
    int *primeNumbers = new int[number] {0};
    
    for (int i = 0; i < number - 1; i++)
    {
        if (isPrime(i + 2))
        {
            primeNumbers[i] = i + 2;
        }
    }
    
    return primeNumbers;
}

int* primeFactors(int number, int *primeArray)
{
    for (int i = 0; i < number - 1; i++)
    {
        if (primeArray[i] != 0 && number % primeArray[i] != 0)
        {
            primeArray[i] = 0;
        }
    }
    
    return primeArray;
}

void printPrimeFactors(vector <int> primeVector)
{
    for (int i = 0; i < primeVector.size(); i++)
    {
        if (primeVector[i] != 0)
        {
            cout << primeVector[i] << " ";
        }
    }
}

vector <int> trimArray(int number, int *primeArray)
{
    vector <int> returnValue;
    
    for (int i = 0; i < number - 1; i++)
    {
        if (primeArray[i] != 0)
        {
            returnValue.push_back(primeArray[i]);
        }
    }
    
    return returnValue;
}

vector <int> countFactors(int number, vector <int> & primeVector)
{
    vector <int> returnValue;
    
    for (int i = 0; i < primeVector.size();)
    {
        if (number % primeVector[i] != 0)
        {
            i++;
        }
        
        else
        {
            number /= primeVector[i];
            
            returnValue.push_back(primeVector[i]);
        }
    }
    
    return returnValue;
}