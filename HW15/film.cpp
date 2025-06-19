#include "film.h"
#include <iostream>

using namespace std;

int myStrLen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void myStrCpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int myStrCmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    return str1[i] == '\0' ? -1 : 1;
}

void initFilm(Film& film, const char* title, const char* director, const char* genre, int year, float rating) {
    int titleLen = myStrLen(title);
    int directorLen = myStrLen(director);
    int genreLen = myStrLen(genre);

    film.title = new char[titleLen + 1];
    myStrCpy(film.title, title);
    film.director = new char[directorLen + 1];
    myStrCpy(film.director, director);
    film.genre = new char[genreLen + 1];
    myStrCpy(film.genre, genre);
    film.year = year;
    film.rating = rating;
}

void deleteFilm(Film& film) {
    delete[] film.title;
    delete[] film.director;
    delete[] film.genre;
    film.title = nullptr;
    film.director = nullptr;
    film.genre = nullptr;
}

void printFilm(const Film& film) {
    cout << "Title: " << film.title << endl;
    cout << "Director: " << film.director << endl;
    cout << "Genre: " << film.genre << endl;
    cout << "Year: " << film.year << endl;
    cout << "Rating: " << film.rating << endl;
    cout << "------------------------" << endl;
}

void addFilm(Film*& films, int& count, int& capacity, const Film& newFilm) {
    if (count >= capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        Film* newFilms = new Film[capacity];
        for (int i = 0; i < count; i++) {
            newFilms[i] = films[i];
        }
        delete[] films;
        films = newFilms;
    }
    films[count] = newFilm;
    count++;
}

void printAllFilms(const Film* films, int count) {
    if (count == 0) {
        cout << "No films available." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Film #" << i + 1 << ":" << endl;
        printFilm(films[i]);
    }
}

void printFilmByIndex(const Film* films, int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Film #" << index + 1 << ":" << endl;
    printFilm(films[index]);
}

void deleteAllFilms(Film*& films, int& count, int& capacity) {
    for (int i = 0; i < count; i++) {
        deleteFilm(films[i]);
    }
    delete[] films;
    films = nullptr;
    count = 0;
    capacity = 0;
}

void deleteFilmByIndex(Film*& films, int& count, int& capacity, int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!" << endl;
        return;
    }
    deleteFilm(films[index]);
    for (int i = index; i < count - 1; i++) {
        films[i] = films[i + 1];
    }
    count--;
}

void searchFilms(const Film* films, int count, const char* searchTerm, int searchYear) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if ((myStrLen(searchTerm) > 0 && myStrCmp(films[i].director, searchTerm) == 0) || 
            (searchYear != 0 && films[i].year == searchYear)) {
            cout << "Film #" << i + 1 << ":" << endl;
            printFilm(films[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No films found matching the criteria." << endl;
    }
}
