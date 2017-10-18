// Assignment 14
// Leslie Ledeboer

#include <iostream>
#include <vector>

using namespace std;

int factorial(int, vector <int> &);
int fibonacci(int, vector <int> &);

int main()
{
    char choice;
    int number, answer;
    vector <int> stack;
    
    do
    {
        cout << "Enter a for factorial or b for Fibonacci: ";
        cin >> choice;
        cout << endl;
        
    } while (choice != 'a' && choice != 'b');
    
    if (choice == 'a')
    {
        do
        {
            cout << "Enter a number to find the factorial: ";
            cin >> number;
            cout << endl;
            
        } while (number < 0);
        
        answer = factorial(number, stack);
        
        cout << "The factorial of " << number << " is: " << answer << endl << endl;
    }
    
    else
    {
        do
        {
            cout << "Enter a number n to find the Fibonacci number at the nth place: ";
            cin >> number;
            cout << endl;
            
        } while (number < 0);
        
        answer = fibonacci(number, stack);
        
        cout << "The Fibonacci number at the nth place is: " << answer << endl << endl;
    }
    
    return 0;
}

int factorial(int number, vector <int> & stack)
{
    stack.push_back(number);
    
    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack[i] << " ";
    }
    
    cout << endl << endl;
    
    if (number == 0 || number == 1)
    {
        stack.pop_back();
        
        for (int i = 0; i < stack.size(); i++)
        {
            cout << stack[i] << " ";
        }
        
        cout << endl << endl;
        
        return 1;
    }
    
    int x = number * factorial(number - 1, stack);
    
    stack.pop_back();
    
    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack[i] << " ";
    }
    
    cout << endl << endl;
    
    return x;
}

int fibonacci(int number, vector <int> & stack)
{
    if (number == 0)
    {
        return 0;
    }
    
    if (number == 1 || number == 2)
    {
        return 1;
    }
    
    return fibonacci(number - 1, stack) + fibonacci(number - 2, stack);
}
