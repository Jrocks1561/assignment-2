//JoshaLynn Worth
//3-2-2024

#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    //giving a starting list
    SLinkedL List;
    for (int i = 10; i > 0; i--) {
        List.push_back({i});
    }

    int choice;
    int number;

    do {
        // DISPLAYYIN THE MNUEUUU
        cout << "\nWELCOME TO THE MAIN MENU:\n";
        cout << "1. Print Linked List\n";
        cout << "2. Insert at Front\n";
        cout << "3. Insert at Back\n";
        cout << "4. Remove from Front\n";
        cout << "5. Remove from Back\n";
        cout << "6. Insert at Index\n";
        cout << "7. Remove at Index\n";
        cout << "8. Find Item\n";
        cout << "9. Display Front Item\n";
        cout << "10. Display Back Item\n";
        cout << "0. Exit\n";

        
        cout << "Enter your choice==> ";
        cin >> choice;
//print list
        if (choice == 1) {
            List.printSingLinkedL();
          //insert at front
        } else if (choice == 2) {
            cout << "Enter number to insert in the front! ==> ";
            cin >> number;
            List.push_front({number});
          //insert at back
        } else if (choice == 3) {
            cout << "Enter number to insert at back! ==> ";
            cin >> number;
            List.push_back({number});
          //remove from front
        } else if (choice == 4) {
            List.pop_front();
          //remove from back
          } else if (choice == 5) {
              if (!List.isEmpty()) {
                  List.pop_back();
              } else {
                  cout << "List is empty ==( \n";
              }
          //insert at index
        } else if (choice == 6) {
            size_t index;
            cout << "Enter index ==> ";
            cin >> index;
            cout << "Enter number to insert ==> ";
            cin >> number;
            List.insert(index, {number});
          //remove at index
        } else if (choice == 7) {
            size_t removeIndex;
            cout << "Enter index to remove ==> ";
            cin >> removeIndex;
            List.remove(removeIndex);
          //find item
        } else if (choice == 8) {
            cout << "Enter number to find ==> ";
            cin >> number;
            size_t foundIndex = List.find({number});
            if (foundIndex < List.getNumItems()) {
                cout << "Item found at index " << foundIndex << "YAYY" << endl;
            } else {
                cout << "Item not found in the list :((((" << endl;
            }
          //display front item
        } else if (choice == 9) {
            try {
                cout << "Front item: " << List.front().size << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
          //display back item
        } else if (choice == 10) {
            try {
                cout << "Back item: " << List.back().size << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
          //bye bye
        } else if (choice == 0) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}
