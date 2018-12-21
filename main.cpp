#include <iostream>
#include <string>
#include <stdexcept>

#include "HashTable.h"

using namespace std;

int main() {
    int N;
    cout << "Amount of elements: ";
    cin >> N;
    HashTable table(N);

    while(true) {
        try {
            string line;
            cin >> line;
            if (line == "add") {
                int key;
                int value;
                cin >> key >> value;
                table.add(key, value);
            } else if (line == "get") {
                int key;
                cin >> key;
                int value = table.get(key);
                cout << "Key: " << key << " Value: " << value << endl;
            } else if (line == "del") {
                int key;
                cin >> key;
                table.del(key);
            } else if (line == "q") {
                break;
            }
        }
        catch (invalid_argument& e) {
            cerr << e.what() << endl;
        }
    }
    return 0;
}