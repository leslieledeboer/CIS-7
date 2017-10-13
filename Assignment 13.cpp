// Assignment 13
// Leslie Ledeboer

// move n disks from start to end using aux
// move n-1 disks from start to aux using end
// move nth disk from start to end
// move n-1 disks from aux to end using start

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

struct tower
{
    vector <uint> towerDisks;
    char name;
};

void initializeTowerA(uint, tower &);
void moveDisk(tower &, tower &);
bool checkWin(uint, const tower &);
void solveRecursive(const uint, uint, tower &, tower &, tower &);
void printTower(uint, const tower &);

int main()
{
    uint disks;
    tower towerA, towerB, towerC;
    
    towerA.name = 'A';
    towerB.name = 'B';
    towerC.name = 'C';
    
    do
    {
        cout << "Enter the number of disks to use: ";
        cin >> disks;
        cout << endl;
        
    } while (disks < 1);
    
    initializeTowerA(disks, towerA);
    
    solveRecursive(disks, disks, towerA, towerB, towerC);
    
    if (checkWin(disks, towerC))
    {
        cout << "You won!" << endl << endl;
    }
    
    // wait for user input
    // accept any key for user input
    // clear the screen
    
    return 0;
}

void initializeTowerA(uint disks, tower &towerA)
{
    for (int i = disks; i >= 1; i--)
    {
        towerA.towerDisks.push_back(i);
    }
}

void moveDisk(tower &source, tower &destination)
{
    if (destination.towerDisks.empty() || source.towerDisks.back() < destination.towerDisks.back())
    {
        destination.towerDisks.push_back(source.towerDisks.back());
        
        cout << "Move disk " << source.towerDisks.back() << " to Tower " << source.name << endl << endl;
        
        source.towerDisks.pop_back();
    }
}

bool checkWin(uint disks, const tower &towerC)
{
    return towerC.towerDisks.size() == disks;
}

void solveRecursive(const uint constantDisks, uint disks, tower &towerS, tower &towerA, tower &towerD)
{
    if (disks == 0)
    {
        return;
    }
    
    printTower(constantDisks, towerS);
    printTower(constantDisks, towerA);
    printTower(constantDisks, towerD);
    
    solveRecursive(constantDisks, disks - 1, towerS, towerD, towerA);
    
    moveDisk(towerS, towerD);
    
    solveRecursive(constantDisks, disks - 1, towerA, towerS, towerD);
}

void printTower(uint disks, const tower &towerPrinting)
{
    cout << "Tower " << towerPrinting.name << ": ";
    
    for (int i = disks - 1; i >= 0; i--)
    {
        if (disks > towerPrinting.towerDisks.size())
        {
            cout << "-";
        }
        
        else
        {
            cout << towerPrinting.towerDisks[i];
        }
        
        if (i != 0)
        {
            cout << ",";
        }
    }
    
    cout << endl;
}
