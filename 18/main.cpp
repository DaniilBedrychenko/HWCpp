#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 20

struct Record {
    int number;
    char text[MAX_TEXT_LENGTH];
};

int main() {

    struct Record records[] = {
        {18, "Hello 0"},
        {30, "Hello 1"},
        {21, "Hello 2"},
        {22, "Hello 3"},
        {13, "Hello 4"},
        {25, "Hello 5"},
        {23, "Hello 6"},
        {14, "Hello 7"},
        {30, "Hello 8"},
        {21, "Hello 9"}
    };
    int record_count = sizeof(records) / sizeof(records[0]);
    const char* filename = "data.bin";

    FILE* outFile = fopen(filename, "wb");
    if (outFile == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        return 1;
    }

    for (int i = 0; i < record_count; i++) {
        fwrite(&records[i].number, sizeof(int), 1, outFile);
        size_t textLength = strlen(records[i].text) + 1;
        fwrite(&textLength, sizeof(size_t), 1, outFile);
        fwrite(records[i].text, sizeof(char), textLength, outFile);
    }
    fclose(outFile);

    FILE* inFile = fopen(filename, "rb");
    if (inFile == NULL) {
        printf("Ошибка открытия файла для чтения!\n");
        return 1;
    }

    printf("Чтение данных из файла:\n");
    while (!feof(inFile)) {
        int number;
        if (fread(&number, sizeof(int), 1, inFile) != 1) {
            break;
        }
        size_t textLength;
        if (fread(&textLength, sizeof(size_t), 1, inFile) != 1) {
            break;
        }
        char text[MAX_TEXT_LENGTH];
        if (fread(text, sizeof(char), textLength, inFile) != textLength) {
            break;
        }
        text[textLength] = '\0';
        printf("%d %s\n", number, text);
    }
    fclose(inFile);

    return 0;
}
