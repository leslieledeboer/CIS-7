// Assignment 15
// Leslie Ledeboer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int displayMenu(const vector <string> &, const vector <string> &);
template <typename T> void displaySet(const vector <T> &);
void addElement(vector <string> &);
void findIntersection(const vector <string> &, const vector <string> &);
void findUnionOfSets(const vector <string> &, const vector <string> &);
void findDifference(const vector <string> &, const vector <string> &);
void findCrossProduct(const vector <string> &, const vector <string> &);
ostream & operator<<(ostream &, const tuple<string, string> &);
void findPowerset(const vector <string> &);
void increment(vector <bool> &);
ostream & operator<<(ostream &, const vector <string> &);

int main()
{
    int choice;
    vector <string> setA, setB;
    
    do
    {
        do
        {
            choice = displayMenu(setA, setB);
            
        } while (choice < 1 || choice > 11);
        
        switch (choice)
        {
            case 1: addElement(setA);
                    break;
                
            case 2: addElement(setB);
                    break;
                
            case 3: findIntersection(setA, setB);
                    break;
                
            case 4: findUnionOfSets(setA, setB);
                    break;
                
            case 5: findDifference(setA, setB);
                    break;
                
            case 6: findDifference(setB, setA);
                    break;
                
            case 7: findCrossProduct(setA, setB);
                    break;
                
            case 8: findCrossProduct(setB, setA);
                    break;
                
            case 9: findPowerset(setA);
                    break;
                
            case 10: findPowerset(setB);
                     break;
                
            case 11: break;
                
            default: cout << "Error." << endl << endl;
        }
        
    } while (choice != 11);
    
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
    cout << "(11) Exit program" << endl << endl;
    
    cout << "Enter a number 1 - 11: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}

template <typename T> void displaySet(const vector <T> & set)
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
    
    cout << "|" << set.size() << "|" << endl << endl;
}

void addElement(vector <string> & set)
{
    string element;
    
    cin.ignore();
    
    cout << "Enter a new element: ";
    getline(cin, element);
    cout << endl;
    
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

void findCrossProduct(const vector <string> & first, const vector <string> & second)
{
    vector <tuple<string, string>> crossProduct;
    
    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            crossProduct.push_back(make_tuple(first[i], second[j]));
        }
    }
    
    displaySet(crossProduct);
}

ostream & operator<<(ostream & lhs, const tuple<string, string> & rhs)
{
    lhs << "(" << get<0>(rhs) << ", " << get<1>(rhs) << ")";
    
    return lhs;
}

void findPowerset(const vector <string> & set)
{
    vector <bool> binary(set.size());
    
    vector <vector <string>> powerset(1 << set.size());
    
    for (int i = 0; i < powerset.size(); i++)
    {
        vector <string> element;
        
        for (int j = 0; j < set.size(); j++)
        {
            if (binary[j])
            {
                element.push_back(set[j]);
            }
        }
        
        powerset[i] = element;
        
        increment(binary);
    }
    
    displaySet(powerset);
}

void increment(vector <bool> & binary)
{
    bool carry = true;
    
    for (int i = 0; i < binary.size() && carry; i++)
    {
        if (binary[i])
        {
            carry = true;
        }
        
        else
        {
            carry = false;
        }
        
        binary[i] = !binary[i];
    }
}

ostream & operator<<(ostream & lhs, const vector <string> & rhs)
{
    lhs << "{";
    
    for (int i = 0; i < rhs.size(); i++)
    {
        lhs << rhs[i];
        
        if (i + 1 < rhs.size())
        {
            lhs << ", ";
        }
    }
    
    lhs << "}";
    
    return lhs;
}
