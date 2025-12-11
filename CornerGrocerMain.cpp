/*
Created by Shirl Lakeway
Created date 12/6/2025
CS-210 Project 3: Corner Grocer
*/

#include <iostream>
#include "CornerGrocer.h"

using namespace std;

int main()
{
    CornerGrocer grocer("CS210_Project_Three_Input_File.txt", "frequency.dat");
    grocer.LoadData();

    int choice;
    cout << "\n=================================================\n";
    cout << "=====>           Welcome to the           <=====\n";
    cout << "=====>   Corner Grocer Inventory System    <=====\n";
    cout << "=================================================\n";
    while (true)
    {
        cout << "Please select an option from the menu below\n";
        cout << "\nMenu Options:\n";
        cout << "(1) Search for item frequency\n";
        cout << "(2) Print all item frequencies\n";
        cout << "(3) Print histogram\n";
        cout << "(4) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Error handling for non-integer input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number 1-4.\n";
            continue;
        }

        // Search for item frequency
        if (choice == 1)
        {
            string item;
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " " << grocer.GetItemFrequency(item) << endl;
        }
        // Print all item frequencies
        else if (choice == 2)
        {
            grocer.PrintAllFrequencies();
        }

        // Print histogram of item frequencies
        else if (choice == 3)
        {
            grocer.PrintHistogram();
        }

        // Exits the program
        else if (choice == 4)
        {
            cout << "\n=================================================\n";
            cout << "=====>        Thank you for using          <=====\n";
            cout << "=====>   Corner Grocer Inventory System    <=====\n";
            cout << "=================================================\n";
            break;
        }
        // Invalid choice handling
        else
        {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}
