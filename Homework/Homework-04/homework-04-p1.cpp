#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

int mapMinX, mapMaxX, mapMinY, mapMaxY;

void createMap() {
    int halfWidth = (rand() % 10) + 5;    // 5..14
    int halfHeight = (rand() % 10) + 5;   // 5..14

    mapMinX = -halfWidth;
    mapMaxX = halfWidth;
    mapMinY = -halfHeight;
    mapMaxY = halfHeight;
}

bool isValidLocation(int x, int y) {
    return (x >= mapMinX && x <= mapMaxX && y >= mapMinY && y <= mapMaxY);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    string name;
    int x, y;

    createMap();

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your location (x y): ";
    if (!(cin >> x >> y)) {
        cout << "Invalid input. Please enter two integers for x and y.\n";
        return 1;
    }

    if (isValidLocation(x, y)) {
        cout << name << ", your location is inside the map boundaries.\n";
    } else {
        cout << name << ", your location is outside the map boundaries.\n";
    }

    cout << "Map boundaries were: "
         << "(" << mapMinX << "," << mapMinY << ") to ("
         << mapMaxX << "," << mapMaxY << ")\n";

    return 0;
}
