#include <iostream>
#include <string>
#include <limits>
#include "../include/array.h"
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/eightug.h"

using namespace std;

void menu() {
    cout << "1. add triangle to array\n";
    cout << "2. add kvadrat to array\n";
    cout << "3. add eightugolnik to array\n";
    cout << "4. delete figure from array\n";
    cout << "5. get total square\n";
    cout << "6. get centr and square of figure\n";
    cout << "0. exit\n";
}

int main() {
    Array arr;
    Figure* f = nullptr;
    int ch;
    while (1) {
        menu();
        cin >> ch;
        if (cin.fail()) {
            cout << "error: invalid input\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch(ch) {
            case 1: {
                f = new Triangle();
                f->read(cin);
                arr.add_to_arr(f);
                break;
            }
            case 2: {
                f = new Square();
                f->read(cin);
                arr.add_to_arr(f);
                break;
            }
            case 3: {
                f = new Eightug();
                f->read(cin);
                arr.add_to_arr(f);
                break;
            }
            case 4: {
                size_t i;
                cout << "input idx: ";
                cin >> i;
                if (cin.fail()) {
                    cout << "error: invalid idx\n";
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    arr.del_from_arr(i);
                }
                break;
            }
            case 5:
                arr.print_total();
                break;
            case 6:
                arr.print_get_centr_and_square();
                break;
            case 0:
                cout << "you've exit the program. bye :)\n";
                return 0;
            default:
                cout << "unknown action\n";
                break;
        }
    }
}
