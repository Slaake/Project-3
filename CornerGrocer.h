#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <map>
#include <string>
using namespace std;

class CornerGrocer
{
private:
    map<string, int> frequencyMap;
    string inputFileName;
    string backupFileName;

public:
    // Constructor
    CornerGrocer(string inputFile, string backupFile);

    // Load data from input file and populate frequency map
    void LoadData();

    // Write backup file with item frequencies
    void WriteBackup();

    // Get frequency of a specific item
    int GetItemFrequency(const string &item);

    // Print all frequencies
    void PrintAllFrequencies();

    // Print histogram
    void PrintHistogram();
};

#endif
