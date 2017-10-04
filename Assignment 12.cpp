// Assignment 12
// Leslie Ledeboer

#include <iostream>
#include <ctime>

using namespace std;

int findMinimum(int, int);
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
        int sum = number1 + number2;
        number1 = sum - number1;
        number2 = sum - number2;
    }

    start1 = clock();
    
    int GCD1 = bruteForce(number1, number2);
    
    double duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    
    start2 = clock();
    
    int GCD2 = euclidean(number1, number2);
    
    double duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    
    cout << "GCD found using brute force: " << GCD1 << endl << endl;
    cout << "GCD found using Euclidean algorithm: " << GCD2 << endl << endl;
    cout << "Time duration using brute force: " << duration1 << " seconds" << endl << endl;
    cout << "Time duration using Euclidean algorithm: " << duration2 << " seconds" << endl << endl;
    
    if (duration1 < duration2)
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
    int i = 1, GCD = 1;
    
    if (number2 == 0)
    {
        GCD = number1;
    }
    
    else
    {
        while (i <= number2)
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

int euclidean(int number1, int number2)
{
    if (number2 == 0)
    {
        return number1;
    }
    
    return euclidean(number2, number1 % number2);
}
