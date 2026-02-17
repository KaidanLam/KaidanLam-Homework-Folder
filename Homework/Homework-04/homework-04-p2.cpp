#include <iostream>
#include <iomanip>

using namespace std;

// Function to check leap year
bool isLeap(int year) {
    if ((year % 400 == 0) || 
       (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

// Function to get days in month
int getDays(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 30;
    }
}

// Zeller’s Congruence to calculate starting day
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int h = (1 + (13*(month + 1))/5 + k + k/4 + j/4 + 5*j) % 7;

    return (h + 5) % 7;  // Convert to Monday = 0
}

int main() {
    int year;

    cout << "Enter a year  :  ";
    cin >> year;

    cout << "\nCalendar for " << year << "\n\n";

    string monthNames[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    for (int month = 1; month <= 12; month++) {

        cout << "--" << monthNames[month - 1] 
             << " " << year << " --\n";

        cout << " Mon Tue Wed Thu Fri Sat Sun\n";

        int days = getDays(month, year);
        int startDay = getStartDay(month, year);

        // spacing before first day
        for (int i = 0; i < startDay; i++)
            cout << setw(4) << " ";

        for (int day = 1; day <= days; day++) {
            cout << setw(4) << day;

            if ((day + startDay) % 7 == 0)
                cout << endl;
        }

        cout << "\n\n";
    }

    return 0;
}
