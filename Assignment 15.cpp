// Assignment 15
// Leslie Ledeboer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int displayMenu(const vector <string> &, const vector <string> &);
void displaySet(const vector <string> &);
void addElement(vector <string> &);
void findIntersection(const vector <string> &, const vector <string> &);
void findUnionOfSets(const vector <string> &, const vector <string> &);
void findDifference(const vector <string> &, const vector <string> &);
void findCrossProduct(vector <string>, vector <string>);
void findPowerset(vector <string>);

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
        case 1: addElement(setA);
            
        case 2: addElement(setB);
            
        case 3: findIntersection(setA, setB);
            
        case 4: findUnionOfSets(setA, setB);
            
        case 5: findDifference(setA, setB);
            
        case 6: findDifference(setB, setA);
            
        case 7:
            
        case 8:
            
        case 9:
            
        case 10:
            
        case 11:
            
        default: cout << "Error." << endl;
    }
    
    return 0;
}

int displayMenu(const vector <string> & setA, const vector <string> & setB)
{
    int choice;
    
    cout << "Set A: ";
    displaySet(setA);
    
    cout << "Set B: ";
    displaySet(setB);
    
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

void displaySet(const vector <string> & set)
{
    cout << "{";
    
    if (set.size() == 0)
    {
        cout << " } ";
    }
    
    else
    {
        for (int i = 0; i < set.size(); i++)
        {
            if (i == set.size() - 1)
            {
                cout << set[i] << "} ";
            }
            
            else
            {
                cout << set[i] << ", ";
            }
        }
    }
    
    cout << "|" << set.size() << "|" << endl;
}

void addElement(vector <string> & set)
{
    string element;
    
    cout << "Enter a new element: ";
    getline(cin, element);
    cout << endl;
    
    cin.ignore();
    
    set.push_back(element);
}

void findIntersection(const vector <string> & setA, const vector <string> & setB)
{
    vector <string> intersection;
    
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(intersection));
    
    displaySet(intersection);
}

void findUnionOfSets(const vector <string> & setA, const vector <string> & setB)
{
    vector <string> unionOfSets;
    
    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(unionOfSets));

    displaySet(unionOfSets);
}

void findDifference(const vector <string> & first, const vector <string> & second)
{
    vector <string> difference;
    
    set_difference(first.begin(), first.end(), second.begin(), second.end(), inserter(difference, difference.begin()));
    
    displaySet(difference);
}

void findCrossProduct(vector <string>, vector <string>)
{
    // for each element in the first set, loop through all elements in the second set
    // display ordered pairs
}

void findPowerset(vector <string>)
{
    
}
