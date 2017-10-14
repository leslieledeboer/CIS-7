// Assignment 13
// Leslie Ledeboer

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

struct tower
{
    char name;
    vector <uint> disks;
};

void initialize(uint, tower &);
void moveDisk(tower &, tower &);
void solve(const uint, uint, tower &, tower &, tower &);
void printTower(uint, const tower &);
bool checkEnd(uint, const tower &);
void clearPause();

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
    
    cin.ignore();
    
    initialize(disks, towerA);
    
    solve(disks, disks, towerA, towerB, towerC);
    
    if (checkEnd(disks, towerC))
    {
        cout << "Solved!" << endl << endl;
    }
    
    return 0;
}

void initialize(uint disks, tower &towerA)
{
    for (int i = disks; i >= 1; i--)
    {
        towerA.disks.push_back(i);
    }
}

void moveDisk(tower &source, tower &destination)
{
    if (destination.disks.empty() || source.disks.back() < destination.disks.back())
    {
        destination.disks.push_back(source.disks.back());
        
        cout << "Move disk " << source.disks.back() << " from " << source.name << " to " << destination.name << endl << endl;
        
        source.disks.pop_back();
    }
}

void solve(const uint constantDisks, uint disks, tower &towerSource, tower &towerAux, tower &towerDest)
{
    if (disks == 0)
    {
        return;
    }
    
    solve(constantDisks, disks - 1, towerSource, towerDest, towerAux);
    
    moveDisk(towerSource, towerDest);
    
    if (towerSource.name == 'A')
    {
        printTower(constantDisks, towerSource);
    }
    
    else if (towerDest.name == 'A')
    {
        printTower(constantDisks, towerDest);
    }
    
    else
    {
        printTower(constantDisks, towerAux);
    }
    
    if (towerSource.name == 'B')
    {
        printTower(constantDisks, towerSource);
    }
    
    else if (towerDest.name == 'B')
    {
        printTower(constantDisks, towerDest);
    }
    
    else
    {
        printTower(constantDisks, towerAux);
    }
    
    if (towerSource.name == 'C')
    {
        printTower(constantDisks, towerSource);
    }
    
    else if (towerDest.name == 'C')
    {
        printTower(constantDisks, towerDest);
    }
    
    else
    {
        printTower(constantDisks, towerAux);
    }
    
    clearPause();
    
    solve(constantDisks, disks - 1, towerAux, towerSource, towerDest);
}

void printTower(uint disks, const tower &towerPrint)
{
    cout << "Tower " << towerPrint.name << ": ";
    
    for (int i = disks - 1; i >= 0; i--)
    {
        if (towerPrint.disks.empty() || i >= towerPrint.disks.size())
        {
            cout << "-";
        }
        
        else
        {
            cout << towerPrint.disks[i];
        }
        
        if (i != 0)
        {
            cout << ",";
        }
    }
    
    cout << endl << endl;
}

bool checkEnd(uint disks, const tower &towerC)
{
    return towerC.disks.size() == disks;
}

void clearPause()
{
    cout << "Press any key to continue: ";
    
    cin.ignore();
    
    cin.get();
    
    for (int i = 0; i <= 1000; i++)
    {
        cout << endl;
    }
}
