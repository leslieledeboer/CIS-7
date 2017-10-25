// Assignment 15
// Leslie Ledeboer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int displayMenu(vector <string>, vector <string>);
void displaySet(vector <string>);
vector <string> addElement(vector <string> &);
void intersection(vector <string>, vector <string>);
void unionOfSets(vector <string>, vector <string>);
void difference(vector <string>, vector <string>);
void crossProduct(vector <string>, vector <string>);
void powerset(vector <string>);

int main()
{
    int choice;
    vector <string> setA, setB;
    
    do
    {
        choice = displayMenu(setA, setB);
        
    } while (choice < 1 || choice > 11);
    
    switch (choice)
    {
        case 1:
            
        case 2:
            
        case 3:
            
        case 4:
            
        case 5:
            
        case 6:
            
        case 7:
            
        case 8:
            
        case 9:
            
        case 10:
            
        case 11:
            
        default:
    }
    
    return 0;
}

int displayMenu(vector <string> setA, vector <string> setB)
{
    int choice;
    
    // cout << "Set A: " << displaySet(setA) << endl;
    // cout << "Set B: " << displaySet(setB) << endl;
    cout << "(1) Add element to set A" << endl;
    cout << "(2) Add element to set B" << endl;
    cout << "(3) Find intersection" << endl;
    cout << "(4) Find union" << endl;
    cout << "(5) Find A - B" << endl;
    cout << "(6) Find B - A" << endl;
    cout << "(7) Find A X B" << endl;
    cout << "(8) Find B X A" << endl;
    cout << "(9) Find powerset of set A" << endl;
    cout << "(10) Find powerset of set B" << endl;
    cout << "(11) Exit program" << endl;
    
    cout << "Enter a number 1 - 11: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}

void displaySet(vector <string> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        if (i == set.size() - 1)
        {
            cout << set[i] << endl;
        }
        
        else
        {
            cout << set[i] << ", ";
        }
    }
    
    // display cardinality of set (number of elements)
}

vector <string> addElement(vector <string> & set)
{
    string element;
    
    cout << "Enter a new element: ";
    getline(cin, element);
    cout << endl;
    
    set.push_back(element);
    
    return set;
}

void intersection(vector <string>, vector <string>)
{
    // for each element in set A, search for the same element in set B
    // add found element to a new vector called intersection
    // display the elements of the intersection vector
    // display the number of elements of the intersection vector
}

void unionOfSets(vector <string>, vector <string>)
{
    // store all elements of both sets into a new vector called unionOfSets
    // remove duplicates
    // display the elements of the unionOfSets vector
    // display the number of elements of the unionOfSets vector
}

void difference(vector <string>, vector <string>)
{
    // store all elements from first set into a new vector called difference
    // if any elements are also found in second set, remove from difference vector
    // display the remaining elements of the difference vector
    // display the number of elements of the difference vector
}

void crossProduct(vector <string>, vector <string>)
{
    
}

void powerset(vector <string>)
{
    
}
