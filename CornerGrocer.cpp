#include "CornerGrocer.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor
CornerGrocer::CornerGrocer(string inputFile, string backupFile)
{
    inputFileName = inputFile;
    backupFileName = backupFile;
}
// Load data from input file and populate frequency map
void CornerGrocer::LoadData()
{
    ifstream inFile(inputFileName);
    string item;
    while (inFile >> item)
    {
        frequencyMap[item]++;
    }
    inFile.close();
    WriteBackup();
}
// Create backup file with item frequencies
void CornerGrocer::WriteBackup()
{
    ofstream outFile(backupFileName);
    for (auto &pair : frequencyMap)
    {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}

// Get frequency of a specific item and normalize input
int CornerGrocer::GetItemFrequency(const string &item)
{
    string normalized = item;
    if (!normalized.empty() && islower(static_cast<unsigned char>(normalized[0])))
    {
        normalized[0] = static_cast<char>(toupper(static_cast<unsigned char>(normalized[0])));
    }
    // Lookup using normalized string
    auto it = frequencyMap.find(normalized);
    if (it != frequencyMap.end())
    {
        return it->second;
    }
    return 0;
}
// Print all item frequencies
void CornerGrocer::PrintAllFrequencies()
{
    for (auto &pair : frequencyMap)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}
// Print histogram of item frequencies
void CornerGrocer::PrintHistogram()
{
    cout << "\nProduce Histogram\n";
    cout << "--------------------\n";
    for (const auto &pair : frequencyMap)
    {
        cout << left << setw(12) << pair.first
             << " " << string(pair.second, '|') << endl;
    }
}
