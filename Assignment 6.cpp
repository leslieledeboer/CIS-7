// Assignment 6
// Leslie Ledeboer

#include <iostream>

using namespace std;

int main()
{
    float input;
    char choice = 'a';
    
    do
    {
        cout << "Enter an integer: ";
        cin >> input;
        cout << endl;
        
        if (cin.fail() || input - static_cast<int>(input) != 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error. ";
        }

        else
        {
            int integer = static_cast<int>(input);
            
            if (integer % 2 == 0)
            {
                cout << "The integer is even." << endl << endl;
            }
            
            else
            {
                cout << "The integer is odd." << endl << endl;
            }
            
            do
            {
                cout << "Enter p to continue or q to exit: ";
                cin >> choice;
                cout << endl;
                
            } while (choice != 'p' && choice != 'q');
        }
        
    } while (choice != 'q');
    
    return 0;
}
