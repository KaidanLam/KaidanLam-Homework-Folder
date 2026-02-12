#include <iostream>
#include <string>

using namespace std;

int main() {
string country;
cout << "Enter a country: ";
getline(cin, country);

cout << "WOAH, I LOVE " << country << ". What part of " << country << " are you from?" << endl;


return 0;
}
