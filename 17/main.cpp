#include "film.h"
#include <iostream>

using namespace std;

int main() {
    Film* films = nullptr;
    int count = 0;
    int capacity = 0;
    int choice;

    do {
        cout << "\nМеню библиотеки фильмов:\n";
        cout << "1) Добавить новый фильм\n";
        cout << "2) Показать все фильмы\n";
        cout << "3) Показать фильм по индексу\n";
        cout << "4) Удалить все фильмы\n";
        cout << "5) Удалить фильм по индексу\n";
        cout << "6) Поиск фильмов\n";
        cout << "7) Вывести базу данных в файл\n"; // Новый пункт меню
        cout << "8) Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                char title[100], director[50], genre[50];
                int year;
                float rating;

                cout << "Введите название: ";
                cin.getline(title, 100);
                cout << "Введите режиссера: ";
                cin.getline(director, 50);
                cout << "Введите жанр: ";
                cin.getline(genre, 50);
                cout << "Введите год: ";
                cin >> year;
                cout << "Введите рейтинг: ";
                cin >> rating;
                cin.ignore();

                Film newFilm;
                initFilm(newFilm, title, director, genre, year, rating);
                addFilm(films, count, capacity, newFilm);
                cout << "Фильм успешно добавлен!" << endl;
                break;
            }
            case 2:
                printAllFilms(films, count);
                break;
            case 3: {
                int index;
                cout << "Введите индекс (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                printFilmByIndex(films, count, index - 1);
                break;
            }
            case 4:
                deleteAllFilms(films, count, capacity);
                cout << "Все фильмы удалены." << endl;
                break;
            case 5: {
                int index;
                cout << "Введите индекс (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                deleteFilmByIndex(films, count, capacity, index - 1);
                cout << "Фильм удален." << endl;
                break;
            }
            case 6: {
                char director[50];
                int year;
                cout << "Введите режиссера для поиска (или нажмите Enter, чтобы пропустить): ";
                cin.getline(director, 50);
                cout << "Введите год для поиска (0 для пропуска): ";
                cin >> year;
                cin.ignore();
                searchFilms(films, count, director, year);
                break;
            }
            case 7:
                saveFilmsToFile(films, count);
                break;
            case 8:
                deleteAllFilms(films, count, capacity);
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 8);

    return 0;
}
