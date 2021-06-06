#include <iostream>
#include "Weather.cpp"
#include "BST.h"
#include "Hash.h"
#include <fstream>

using namespace std;

int main() {
    bool runProgram = true, elements_added = false;
    int choice, addChoice, size = 0;
    double temp, hum, wind;
    temp = hum = wind = 0;
    int key;
    auto* tree = new BST<Weather>;
    HashTable<Weather>* table;
    table = new HashTable<Weather>(60);
    Weather w;
    string loc;
    ofstream output;
    output.open("DataRecord.txt", ios::app);
    output << "<--Data Record-->\n\n" << endl;
    ifstream input;
    string filename;

    while (runProgram) {
        cout << "\n1. Add new data\n2. Delete data\n3. Search and display using the primary key\n4. "
            "List data in hash table sequence\n5. List data in sorted key sequence\n6. Print indented tree\n7. Efficiency\n8. Average Data\n9. End\n" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "1. Import from file\n2. Add manual data" << endl;
            cin >> addChoice;
            if (addChoice == 1) {
                cout << "\nEnter the file name: ";
                cin >> filename;
                input.open(filename.c_str());
                while (input.fail()) {
                    cout << "Incorrect filename, please enter again\n";
                    cout << "\nEnter the file name: ";
                    cin >> filename;
                    input.open(filename.c_str());
                }
                if (input) {
                    while (input >> w) {
                        if (w.getTemperature() && w.getHumidity()) {
                            temp = temp + w.getTemperature();
                            wind = wind + w.getWind();
                            hum = hum + w.getHumidity();
                            size++;
                            table->insert(w, w.getTemperature(), w.getHumidity(), w.getWind(), w.getUniqueKey());
                            tree->insert(w, w.getUniqueKey());
                            elements_added = true;
                        }
                        else {
                            cout << "Line was ignored." << endl;
                        }
                    }
                }
                break;
            }
            else if (addChoice == 2) {
                cout << "Please enter weather data (temperature | humidity | wind | location) :" << endl;
                cin >> w;
                if (w.getHumidity() && w.getTemperature()) {
                    temp = temp + w.getTemperature();
                    wind = wind + w.getWind();
                    hum = hum + w.getHumidity();
                    size++;
                    table->insert(w, w.getTemperature(), w.getHumidity(), w.getWind(), w.getUniqueKey());
                    tree->insert(w, w.getUniqueKey());
                    elements_added = true;
                    cout << w << "Has been added to the database.";
                    output << w << "Has been added to the database.";
                }
                else {
                    cout << "Invalid data entry. Please try again." << endl;
                }
                break;
            }
            else {
                cout << "\n" << addChoice << " is not a valid option." << endl;
                break;
            }
        }
        case 2: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "----Delete Data----\nInsert Key: ";
            cin >> key;
            cout << endl;
            tree->remove(key, output);
            if (table->remove(key)) {
                cout << key << " deleted." << endl;
                output << key << " deleted." << endl;
            }
            else {
                cout << key << " not deleted." << endl;
                output << key << " deleted." << endl;
            }
            break;
        }
        case 3: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "----Find Element----\nInsert Key: ";
            cin >> key;
            cout << endl;
            tree->Search(key, output);
            break;
        }
        case 4: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "----Hash Table Sequence----" << endl;
            table->printTable(output);
            break;
        }
        case 5: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "----Sorted Key Sequence----" << endl;
            output << "----Sorted Key Sequence----" << endl;
            tree->print(output);
            cout << endl;
            break;
        }
        case 6: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "----Indented Tree----" << endl;
            output << "----Indented Tree----" << endl;
            tree->printD(output);
            break;
        }
        case 7: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "------Efficiency------" << endl;
            output << "------Efficiency------" << endl;
            table->efficiency(output);
            break;
        }
        case 8: {
            if (!elements_added) {
                cout << "You must insert elements into the database first." << endl;
                break;
            }
            cout << "\n----Average data attributes----" << endl;
            cout << "Temperature: " << temp / size << "\nHumidity:     " << hum / size << "\nWind:         " << wind / size << endl;
            output << "\n----Average data attributes----" << endl;
            output << "Temperature: " << temp / size << "\nHumidity:     " << hum / size << "\nWind:         " << wind / size << endl;
            break;
        }
        case 9: {
            runProgram = false;
            break;
        }
        default:
        {
            cout << choice << " is not a valid option" << endl;
        }
        }
    }

    input.close();
    output.close();
    delete tree;
    cout << "End of program." << endl;
    output << "End of run. " << endl;
    system("pause");
    return 0;
}