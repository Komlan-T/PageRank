#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>

using namespace std;

struct AdjacencyList {

	map<string, vector<pair<string, double>>> internet;

	void PageRank(int n);
};

void AdjacencyList::PageRank(int n) {

	map<string, double> ranks;

	double initialRank = 1.00 / internet.size();
	
	for (auto iter = internet.begin(); iter != internet.end(); iter++) {
		vector<pair<string, double>> newVector = iter->second;
		for (int i = 0; i < newVector.size(); i++) {
			ranks[iter->first] = initialRank;
			ranks[newVector[i].first] = initialRank;
		}
	}
	
	for (int i = 0; i < n; i++) {
		vector<double> _newRanks;
		for (auto iter = internet.begin(); iter != internet.end(); iter++) {
			double newRank = 0;
			vector<pair<string, double>> newVector = iter->second;
			for (int j = 0; j < newVector.size(); j++) {
				double currentRank = ranks[newVector[j].first];
				double result = currentRank * newVector[j].second;
				newRank += result;
			}
			_newRanks.push_back(newRank);
		}
		int j = 0;
		for (auto iter = ranks.begin(); iter != ranks.end(); iter++) {
			ranks[iter->first] = _newRanks[j];
			j++;
		}
	}


	for (auto iter = ranks.begin(); iter != ranks.end(); iter++) {
		double temp = iter->second;
		double convert = round(temp * 100.0) / 100.0;
		if (convert == 0) {
			cout << iter->first << " " << "0.00" << endl;
		}
		else {
			cout << iter->first << " " << left << setfill('0') << setw(4) << convert << endl;
		}
	}
}