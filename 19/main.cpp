#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100

int myStrlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int myStrstr(const char* str, const char* substr) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; substr[j] != '\0' && str[i + j] != '\0'; j++) {
            if (str[i + j] != substr[j]) break;
        }
        if (substr[j] == '\0') return i;
    }
    return -1;
}

int myStrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void removeLastLine(const char* inputFile, const char* outputFile) {
    FILE* inFile = fopen(inputFile, "r");
    if (!inFile) {
        printf("Ошибка открытия входного файла!\n");
        return;
    }
    FILE* outFile = fopen(outputFile, "w");
    if (!outFile) {
        printf("Ошибка открытия выходного файла!\n");
        fclose(inFile);
        return;
    }
    char lineBuffer[MAX_LINE_LENGTH];
    char prevLineBuffer[MAX_LINE_LENGTH] = "";
    int lineCount = 0;
    
    while (fgets(lineBuffer, MAX_LINE_LENGTH, inFile)) {
        if (lineCount > 0) {
            fputs(prevLineBuffer, outFile);
        }
        myStrcpy(prevLineBuffer, lineBuffer);
        lineCount++;
    }
    
    fclose(inFile);
    fclose(outFile);
}

int findLongestLine(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Ошибка открытия файла!\n");
        return -1;
    }
    int maxLength = 0;
    char lineBuffer[MAX_LINE_LENGTH];
    
    while (fgets(lineBuffer, MAX_LINE_LENGTH, file)) {
        int len = myStrlen(lineBuffer);
        if (lineBuffer[len - 1] == '\n') len--;
        if (len > maxLength) maxLength = len;
    }
    
    fclose(file);
    return maxLength;
}

int countWordOccurrences(const char* fileName, const char* word) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Ошибка открытия файла!\n");
        return -1;
    }
    int wordCount = 0;
    char lineBuffer[MAX_LINE_LENGTH];
    
    while (fgets(lineBuffer, MAX_LINE_LENGTH, file)) {
        int pos = 0;
        while (lineBuffer[pos] != '\0') {
            if (myStrstr(&lineBuffer[pos], word) == 0) {
                wordCount++;
                pos += myStrlen(word);
            } else {
                pos++;
            }
        }
    }
    
    fclose(file);
    return wordCount;
}

void replaceWord(const char* inputFile, const char* outputFile, const char* searchWord, const char* replaceWord) {
    FILE* inFile = fopen(inputFile, "r");
    if (!inFile) {
        printf("Ошибка открытия входного файла!\n");
        return;
    }
    FILE* outFile = fopen(outputFile, "w");
    if (!outFile) {
        printf("Ошибка открытия выходного файла!\n");
        fclose(inFile);
        return;
    }
    char lineBuffer[MAX_LINE_LENGTH];
    char tempBuffer[MAX_LINE_LENGTH];
    
    while (fgets(lineBuffer, MAX_LINE_LENGTH, inFile)) {
        int pos = 0, tempPos = 0;
        tempBuffer[0] = '\0';
        while (lineBuffer[pos] != '\0') {
            if (myStrstr(&lineBuffer[pos], searchWord) == 0) {
                int j = 0;
                while (replaceWord[j] != '\0') {
                    tempBuffer[tempPos++] = replaceWord[j++];
                }
                pos += myStrlen(searchWord);
            } else {
                tempBuffer[tempPos++] = lineBuffer[pos++];
            }
        }
        tempBuffer[tempPos] = '\0';
        fputs(tempBuffer, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

void compareFiles(const char* file1, const char* file2, const char* outputFile) {
    FILE* firstFile = fopen(file1, "r");
    FILE* secondFile = fopen(file2, "r");
    if (!firstFile || !secondFile) {
        printf("Ошибка открытия одного из файлов!\n");
        if (firstFile) fclose(firstFile);
        if (secondFile) fclose(secondFile);
        return;
    }
    FILE* outFile = fopen(outputFile, "w");
    if (!outFile) {
        printf("Ошибка открытия выходного файла!\n");
        fclose(firstFile);
        fclose(secondFile);
        return;
    }
    char line1Buffer[MAX_LINE_LENGTH], line2Buffer[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int differ = 0;
    
    while (fgets(line1Buffer, MAX_LINE_LENGTH, firstFile) && fgets(line2Buffer, MAX_LINE_LENGTH, secondFile)) {
        lineNumber++;
        if (myStrcmp(line1Buffer, line2Buffer) != 0) {
            fprintf(outFile, "Строка %d в файле %s: %s", lineNumber, file1, line1Buffer);
            fprintf(outFile, "Строка %d в файле %s: %s", lineNumber, file2, line2Buffer);
            differ = 1;
        }
    }
    while (fgets(line1Buffer, MAX_LINE_LENGTH, firstFile)) {
        lineNumber++;
        fprintf(outFile, "Строка %d в файле %s: %s", lineNumber, file1, line1Buffer);
        differ = 1;
    }
    while (fgets(line2Buffer, MAX_LINE_LENGTH, secondFile)) {
        lineNumber++;
        fprintf(outFile, "Строка %d в файле %s: %s", lineNumber, file2, line2Buffer);
        differ = 1;
    }
    
    if (!differ) {
        fprintf(outFile, "Файлы идентичны\n");
    }
    
    fclose(firstFile);
    fclose(secondFile);
    fclose(outFile);
}

void caesarCipher(const char* inputFile, const char* outputFile, int shift) {
    FILE* inFile = fopen(inputFile, "r");
    if (!inFile) {
        printf("Ошибка открытия входного файла!\n");
        return;
    }
    FILE* outFile = fopen(outputFile, "w");
    if (!outFile) {
        printf("Ошибка открытия выходного файла!\n");
        fclose(inFile);
        return;
    }
    char ch;
    
    while ((ch = fgetc(inFile)) != EOF) {
        if (ch >= 'А' && ch <= 'Я') {
            ch = 'А' + ((ch - 'А' + shift) % 32);
        } else if (ch >= 'а' && ch <= 'я') {
            ch = 'а' + ((ch - 'а' + shift) % 32);
        }
        fputc(ch, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

int main() {
 
    
    int longestLine = findLongestLine("input.txt");
    if (longestLine >= 0) {
        printf("Длина самого длинного ряда: %d\n", longestLine);
    }
    
    char wordBuffer[MAX_WORD_LENGTH];
    printf("Введите слово для подсчета: ");
    scanf("%s", wordBuffer);
    int wordCount = countWordOccurrences("input.txt", wordBuffer);
    if (wordCount >= 0) {
        printf("Слово '%s' встречается %d раз\n", wordBuffer, wordCount);
    }
    
    char searchWord[MAX_WORD_LENGTH], replaceWord[MAX_WORD_LENGTH];
    printf("Введите слово для поиска: ");
    scanf("%s", searchWord);
    printf("Введите слово для замены: ");
    scanf("%s", replaceWord);
    replaceWord("input.txt", "output4.txt", searchWord, replaceWord);
    
    compareFiles("file1.txt", "file2.txt", "output5.txt");
    
    caesarCipher("input.txt", "output6.txt", 3);

    return 0;
}
