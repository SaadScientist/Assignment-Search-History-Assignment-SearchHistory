#include <iostream>
#include <string>
using namespace std;
const int SIZE = 1000;

void sortInputs(string usrString[], int freqs[], int size);
int  searchInputs(string usrString[], string searchString, int size);

int main()
{
    string usrString[SIZE];
    string searchString;
    int    freqns[SIZE] = {};
    int    choice;
    int    n = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        freqns[i] = 0;
    }

    
    do
    {
        cout << "(1) Enter a string" << endl;
        cout << "(2) Print a sorted list of inputs and their frequencies" << endl;
        cout << "(3) Quit" << endl;
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "Enter a string: ";
            cin.ignore();
            getline(cin, searchString);
            
            int returnValue = searchInputs(usrString, searchString, n);
            
            if (returnValue == -1)
            {
                usrString[n] = searchString;
                freqns[n] = 1;
                n++;
               
            }
            else
            {
                freqns[returnValue]++;
            }
        }
        if (choice == 2)
        {
            sortInputs(usrString, freqns, n);
            for (int i = 0; i < n; i++)
            {
                cout << "Input: " << usrString[i]  << endl;
                cout << "Frequency: " << freqns[i] << endl;
            }
        }
    }
    while (choice != 3);
}

void sortInputs(string usrString[], int freqs[], int size)
{
    int i = 0;
    int j = 0;
    string sTemp = "";
    int iTemp = 0;
    
    for (i = 1; i < size; ++i)
    {
        j = i;
        
        while (j > 0 && usrString[j] < usrString[j - 1])
        {
            sTemp = usrString[j];
            usrString[j] = usrString[j - 1];
            usrString[j - 1] = sTemp;
            
            iTemp = freqs[j];
            freqs[j] = freqs[j - 1];
            freqs[j - 1] = iTemp;
            --j;
        }
    }
    
}
int searchInputs(string usrString[], string searchString, int size)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    
    high = size - 1;
    
    while (high >= low) {
        mid = (high + low) / 2;
        
     if (usrString[mid] < searchString){
            low = mid + 1;
        }
        else if(usrString[mid] > searchString){
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
