#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    
    int numPassengers;
    if (!(cin >> numPassengers)) return 1;

    double fuelPrice, mileage, wearTear;
    cin >> fuelPrice >> mileage >> wearTear;

    int totalNodes = numPassengers + 2; 
    
    
    vector<double> directDistances(numPassengers + 1); 
    for (int i = 0; i <= numPassengers; ++i) {
        cin >> directDistances[i];
    }

    
    vector<vector<double>> matrix(totalNodes, vector<double>(totalNodes));
    for (int i = 0; i < totalNodes; ++i) {
        for (int j = 0; j < totalNodes; ++j) {
            cin >> matrix[i][j];
        }
    }

    
    vector<int> currentRoute(numPassengers);
    iota(currentRoute.begin(), currentRoute.end(), 1); 
    
    vector<int> bestRoute;
    double minDistance = 1e9;

    sort(currentRoute.begin(), currentRoute.end());
    do {
        double currentDistance = 0.0;
        int currentNode = 0;

        for (int nextNode : currentRoute) {
            currentDistance += matrix[currentNode][nextNode];
            currentNode = nextNode;
        }
        currentDistance += matrix[currentNode][totalNodes - 1]; 

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = currentRoute;
        }
    } while (next_permutation(currentRoute.begin(), currentRoute.end()));

   
    double totalGasCost = ((minDistance / mileage) * fuelPrice) + (minDistance * wearTear);
    
    double sumDirectDistances = 0;
    for(double d : directDistances) sumDirectDistances += d;

    
    cout << "{";
    cout << "\"optimal_distance\": " << minDistance << ", ";
    cout << "\"total_cost\": " << totalGasCost << ", ";
    
    cout << "\"fares\": [";
    for(int i = 0; i <= numPassengers; ++i) {
        double share = (directDistances[i] / sumDirectDistances) * totalGasCost;
        cout << share << (i < numPassengers ? ", " : "");
    }
    cout << "], ";
    
    cout << "\"route\": [0";
    for(int node : bestRoute) cout << ", " << node;
    cout << ", " << (totalNodes - 1) << "]";
    cout << "}" << endl;

    return 0;
}