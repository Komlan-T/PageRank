#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include "AdjacencyList.h"

using namespace std;

int main()
{
    AdjacencyList list;
    vector<pair<string, string>> allInput;
    map<string, double> outDegrees;

    string read;
    getline(cin, read);
    istringstream breakup(read);

    string x;
    breakup >> x;
    int n = stoi(x);

    string y;
    breakup >> y;
    int p = stoi(y);
    

    for (int i = 0; i < n; i++) {

        string line;
        getline(cin, line);
        istringstream in(line);

        //source vertex
        string from;
        in >> from;
        
        //destination vertex
        string to;
        in >> to;
        
        //store all input
        pair<string, string> newPair;
        newPair.first = from;
        newPair.second = to;
        allInput.push_back(newPair);
        
        //give each string an empty vector
        vector<pair<string, double>> newVector;
        vector<pair<string, double>> newVector2;
        list.internet[to] = newVector;
        list.internet[from] = newVector2;
    }

    //zero out map
    for (int i = 0; i < allInput.size(); i++) {
        outDegrees[allInput[i].first] = 0;
        outDegrees[allInput[i].second] = 0;
    }
    
    //find outDegrees
    for (int i = 0; i < allInput.size(); i++) {
        outDegrees[allInput[i].first]++;
    }

    //up date vectors of pair in the list
    for (int i = 0; i < allInput.size(); i++) {
        vector<pair<string, double>> currentVector = list.internet[allInput[i].second];
        pair<string, double> newPair;
        newPair.first = allInput[i].first;
        double reciprocal = 1.00 / outDegrees[allInput[i].first];
        newPair.second = reciprocal;
        currentVector.push_back(newPair);
        list.internet[allInput[i].second] = currentVector;
    }

    //do power iterations
    list.PageRank(p - 1);
}