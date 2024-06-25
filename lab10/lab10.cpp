#include <iostream>

struct Enterprise {
    const char* name;
    const char* month;
    double profit;
};

void printDocument(Enterprise enterprises[], int size) {
    std::cout << "Financial Report:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enterprise: " << enterprises[i].name
            << ", Month: " << enterprises[i].month
            << ", Profit: " << enterprises[i].profit << std::endl;
    }
}

void sortEnterprisesByProfit(Enterprise enterprises[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (enterprises[j].profit > enterprises[j + 1].profit) {
                Enterprise temp = enterprises[j];
                enterprises[j] = enterprises[j + 1];
                enterprises[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 5;
    Enterprise enterprises[size] = {
        {"Enterprise A", "January", 1500.0},
        {"Enterprise B", "February", 2500.0},
        {"Enterprise C", "March", 2000.0},
        {"Enterprise D", "April", 3000.0},
        {"Enterprise E", "May", 1000.0}
    };

    std::cout << "Original Document:\n";
    printDocument(enterprises, size);

    sortEnterprisesByProfit(enterprises, size);

    std::cout << "\nSorted Document (by increasing profit):\n";
    printDocument(enterprises, size);

    return 0;
}
