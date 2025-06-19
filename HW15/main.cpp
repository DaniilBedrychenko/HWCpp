#include "film.h"
#include <iostream>

using namespace std;

int main() {
    Film* films = nullptr;
    int count = 0;
    int capacity = 0;
    int choice;

    do {
        cout << "\nFilm Library Menu:\n";
        cout << "1) Add new film\n";
        cout << "2) Show all films\n";
        cout << "3) Show film by index\n";
        cout << "4) Delete all films\n";
        cout << "5) Delete film by index\n";
        cout << "6) Search films\n";
        cout << "7) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                char title[100], director[50], genre[50];
                int year;
                float rating;

                cout << "Enter title: ";
                cin.getline(title, 100);
                cout << "Enter director: ";
                cin.getline(director, 50);
                cout << "Enter genre: ";
                cin.getline(genre, 50);
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter rating: ";
                cin >> rating;
                cin.ignore();

                Film newFilm;
                initFilm(newFilm, title, director, genre, year, rating);
                addFilm(films, count, capacity, newFilm);
                cout << "Film added successfully!" << endl;
                break;
            }
            case 2:
                printAllFilms(films, count);
                break;
            case 3: {
                int index;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                printFilmByIndex(films, count, index - 1);
                break;
            }
            case 4:
                deleteAllFilms(films, count, capacity);
                cout << "All films deleted." << endl;
                break;
            case 5: {
                int index;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                deleteFilmByIndex(films, count, capacity, index - 1);
                cout << "Film deleted." << endl;
                break;
            }
            case 6: {
                char director[50];
                int year;
                cout << "Enter director to search (or press Enter to skip): ";
                cin.getline(director, 50);
                cout << "Enter year to search (0 to skip): ";
                cin >> year;
                cin.ignore();
                searchFilms(films, count, director, year);
                break;
            }
            case 7:
                deleteAllFilms(films, count, capacity);
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
