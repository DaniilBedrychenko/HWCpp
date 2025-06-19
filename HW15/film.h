#pragma once

struct Film {
    char* title;
    char* director;
    char* genre;
    int year;
    float rating;
};

int myStrLen(const char* str);
void myStrCpy(char* dest, const char* src);
int myStrCmp(const char* str1, const char* str2);

void initFilm(Film& film, const char* title, const char* director, const char* genre, int year, float rating);
void deleteFilm(Film& film);
void printFilm(const Film& film);
void addFilm(Film*& films, int& count, int& capacity, const Film& newFilm);
void printAllFilms(const Film* films, int count);
void printFilmByIndex(const Film* films, int count, int index);
void deleteAllFilms(Film*& films, int& count, int& capacity);
void deleteFilmByIndex(Film*& films, int& count, int& capacity, int index);
void searchFilms(const Film* films, int count, const char* searchTerm, int searchYear);
