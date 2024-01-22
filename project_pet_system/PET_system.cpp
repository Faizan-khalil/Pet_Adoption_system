#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
struct Pet {
    string name; 
    string breed;
    int age; 
    string gender; 

    void add() {
    cout << "Enter the name of the pet: ";
    cin >> name;
    cout << "Enter the breed of the pet: ";
    cin >> breed;
    cout << "Enter the age of the pet: ";
    cin >> age;
    cout << "Enter the gender of the pet (M/F): ";
    cin >> gender;
    }

    void del() {
    name = "";
    breed = "";
    age = 0;
    gender = ' ';
    }

    bool search(string n) {
    if (name == n) {
    return true;
    }
    else {
    return false;
    }
    }

    void display() {
        cout<<"---------------------------------------------"<<endl;
        cout <<left << setw(15) << "Name:" << name << endl;
        cout <<left <<setw(15) << "Breed:" << breed <<endl;
        cout <<left <<setw(15) << "Age:" << age <<endl;
        cout <<left <<setw(15) << "Gender:" << gender <<endl;
        cout<<"---------------------------------------------"<<endl;
    }
    };
    
    void sort(Pet ar[], int size) {
    for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
    if (ar[i].age > ar[j].age) {
    swap(ar[i], ar[j]);
    }
    }
    }
    }
    const int MAX_PETS = 10;
    // global array of sturcture with variable arr
    Pet arr[MAX_PETS];

    void displayMenu() {
    cout << "\n\n\n\t\t\t====== MAIN MENU ======\n";
    cout << "1. Add a pet"<< endl;
    cout << "2. Delete a pet" << endl;
    cout << "3. Search a pet" << endl;
    cout << "4. Sort the pets" << endl;
    cout << "5. Display the pets" << endl;
    cout << "6. Exit the program" << endl;
    }

int main() {
	cout << "\n\n\n__________\n\n\n";
	cout << " \n\t          ============>>  WELCOME  <<============";
	cout << " \n\n\t\t\t\t    TO\n\t          ---------------------------------------\n";
	cout << "\t\t\t    PET ADOPTION SYSTEM  \n";
	cout << "\t          _______________________________________\n";
	cout << "\n\t            MADE BY : FAIZAN,ARSLAN,HASEEB,ZAIN";
	cout << "\n\n\n\n__________\n\n\n";
    system("pause");
	system("cls");
    int size = 0;
    int choice;
    string name;
    int index;
    bool found;
    while(true){
    displayMenu(); 
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: // add a pet
    if (size < MAX_PETS) {
        arr[size].add(); // call the add function from the member function of sturct
        size++; // increment the size
        cout << "Pet added successfully." << endl;
    }else { // if the array is full IT WILL PRINT NO SPACE LEFT
        cout << "No more space for new pets." << endl;
    }
    break;
    case 2:

    cout << "Enter the name of the pet to delete: ";
    cin >> name; 
    index = -1; 

    for (int i = 0; i < size; i++) { 
        if (arr[i].search(name)) { 
            index = i; 
        break;
    }
    }
    if (index != -1) { 
        arr[index].del();
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    cout << "Pet deleted successfully." << endl;
    }
    else { 
    cout << "Pet not found." << endl;
    }
    break;
    case 3: 
    cout << "Enter the name of the pet to search: ";
    cin >> name; 
    found = false; 
    for (int i = 0; i < size; i++) { 
        if (arr[i].search(name)) { 
        found = true; 
        cout << "Pet found." << endl;
        arr[i].display(); 
        break;
    }
    }
    // check if the pet was not found
    if (!found) { 
    cout << "Pet not found." << endl;
    }
    break;
    case 4: 
    sort(arr, size); 
    cout << "Pets sorted successfully." << endl;
    break;
    case 5: 
    for (int i = 0; i < size; i++) { 
        arr[i].display(); 
    }
    break;
    case 6:
    cout << "Thank you for using the pet adoption system." << endl;
    exit(0);
    break;
    default: 
    cout << "Invalid choice. Please try again." << endl;
    break;
    }
    }
    return 0;
}