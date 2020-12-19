// Josh Williams
// 4/23/2020
// CSC - 234 - 81A
// Chapter 13 - Program 13 - Corporate Sales Output

// Write a program that uses a structure to store Division Name, Quarter, and Quarterly Sales.
// Prompt the user for sales figures for each quarter per division. Save the info to a file.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct CorpData
{
    // Contains the structure for Corporate Data
    char divName[10];
    int qtr;
    double q1Sales, q2Sales, q3Sales, q4Sales;
};

int main()
{
    // Welcome Message
    cout << "Corporate Sales Data Output\n\n";
   
    // Division Names
    const string divisions[4] = { "East", "West", "North", "South" };

    // Filename to write to
    const string filename = "C:\\cabs\\corp_sales_data.txt";

    // Loop through each division
    for (int i = 0; i < 4; i++) {
        // Input header
        cout << divisions[i] << " Divison Sales\n\n";

        // Create new instance for the division
        CorpData div;

        // Set the name
        strcpy_s(div.divName, divisions[i].c_str());
        
        // Gather sales info
        cout << "Quarter 1: $";
        cin >> div.q1Sales;
        cout << "Quarter 2: $";
        cin >> div.q2Sales;
        cout << "Quarter 3: $";
        cin >> div.q3Sales;
        cout << "Quarter 4: $";
        cin >> div.q4Sales;
        cout << endl;

        // Append info to filename
        fstream salesFile;
        salesFile.open(filename, ios::out | ios::app);
        
        // Add division name
        salesFile << div.divName << endl;

        // Add sales info
        salesFile << fixed << setprecision(2) << div.q1Sales << endl;
        salesFile << fixed << setprecision(2) << div.q2Sales << endl;
        salesFile << fixed << setprecision(2) << div.q3Sales << endl;
        salesFile << fixed << setprecision(2) << div.q4Sales << endl << endl;
    }
}

