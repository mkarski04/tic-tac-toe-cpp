#include <iostream>
using namespace std;

char arr[3][3];
bool check = false;

void clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

void showBoard() {
    cout << endl << "TIC TAC TOE" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void checkX(int i, int j) {
    if (arr[i][j] == '-') {
        arr[i][j] = 'X';
        check = true;
        clearScreen();
    }else {
        clearScreen();
        cout << "This spot is taken. Try again." << endl;
        check = false;
    }
}

void fillX(int choice) {
    if (choice > 0 && choice < 10) {
        int i = (choice - 1) / 3;
        int j = (choice - 1) % 3;
        checkX(i, j);
    }else {
        clearScreen(); cout << "Wrong input. Try again." << endl; check = false;
    }
}

void placeX() {
    showBoard();
    int choice;

    cout << endl;
    cout << "Enter where to place X (1-9): ";
    cin >> choice;
    fillX(choice);
    if (check == false) {
        placeX();
    }
}

void checkO(int i, int j) {
    if (arr[i][j] == '-') {
        arr[i][j] = 'O';
        check = true;
        clearScreen();
    }else {
        clearScreen();
        cout << "This spot is taken. Try again." << endl;
        check = false;
    }
}

void fillO(int choice) {
    if (choice > 0 && choice < 10) {
        int i = (choice - 1) / 3;
        int j = (choice - 1) % 3;
        checkO(i, j);
    }else {
        clearScreen(); cout << "Wrong input. Try again." << endl; check = false;
    }
}

void placeO() {
    showBoard();
    int choice;

    cout << endl;
    cout << "Enter where to place O (1-9): ";
    cin >> choice;
    fillO(choice);
    if (check == false) {
        placeO();
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '-') {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != '-') {
            return true;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '-') {
        return true;
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '-') {
        return true;
    }
    return false;
}

void winMsg(char player) {
    clearScreen();
    showBoard();
    cout << endl << "Congratulations! " << player << " wins." << endl;
}

int main() {
    bool win;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = '-';
        }
    }

    for (;;) {
        placeX();
        win = checkWin();
        if (win == true) {
            winMsg('X');
            break;
        }
        placeO();
        win = checkWin();
        if (win == true) {
            winMsg('O');
            break;
        }
    }

    char exitKey;
    cout << "\nGame over! Enter any character and press Enter to exit the programme: ";
    cin >> exitKey;

    return 0;
}
