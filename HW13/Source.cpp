#include <iostream>

using namespace std;

void removeCharAt(char* str, int index) {
    if (str == nullptr || index < 0)
        return;
    
    int len = 0;
    while (str[len] != '\0') len++;
    if (index >= len)
        return;
    
    for (int i = index; i < len; i++) {
        str[i] = str[i + 1];
    }
}


void removeAllChar(char* str, char ch) {
    if (str == nullptr)
        return;
    
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}


void insertChar(char* str, int index, char ch, int maxLen) {
    if (str == nullptr || index < 0 || index > maxLen)
        return;
    
    int len = 0;
    while (str[len] != '\0') len++;
    if (len >= maxLen)
        return;
    
    for (int i = len; i >= index; i--) {
        str[i + 1] = str[i];
    }
    str[index] = ch;
}


void replaceDotsWithExclamations(char* str) {
    if (str == nullptr)
        return;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}


int countChar(const char* str, char ch) {
    if (str == nullptr)
        return 0;
    
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}


void countCharTypes(const char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    if (str == nullptr)
        return;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            letters++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            others++;
        }
    }
}


int mystrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (*str1 == *str2) return 0;
    return (*str1 > *str2) ? 1 : -1;
}

int StringToNumber(char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }
    return sign * result;
}

char* NumberToString(int number) {
    static char buffer[32];
    int i = 0;
    int isNegative = 0;
    
    if (number < 0) {
        isNegative = 1;
        number = -number;
    }
    
    do {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    } while (number > 0);
    
    if (isNegative) {
        buffer[i++] = '-';
    }
    
    buffer[i] = '\0';
    
    // Реверс рядка
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start++] = buffer[end];
        buffer[end--] = temp;
    }
    
    return buffer;
}

char* Uppercase(char* str) {
    if (str == nullptr)
        return str;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

char* Lowercase(char* str) {
    if (str == nullptr)
        return str;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

char* mystrrev(char* str) {
    if (str == nullptr)
        return str;
    
    int len = 0;
    while (str[len] != '\0') len++;
    
    int start = 0;
    int end = len - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    return str;
}

int main() {
    const int MAX_LEN = 256;
    char str[MAX_LEN];
    char ch;
    int index, count, letters, digits, others;
    
    // Тестування функцій
    cout << "Введіть рядок: ";
    cin.getline(str, MAX_LEN);
    
    // 1. 
    cout << "Введіть індекс символу для видалення: ";
    cin >> index;
    removeCharAt(str, index);
    cout << "Рядок після видалення: " << str << endl;
    
    // 2.
    cout << "Введіть символ для видалення: ";
    cin >> ch;
    removeAllChar(str, ch);
    cout << "Рядок після видалення символу '" << ch << "': " << str << endl;
    
    // 3.
    cout << "Введіть позицію для вставки: ";
    cin >> index;
    cout << "Введіть символ для вставки: ";
    cin >> ch;
    insertChar(str, index, ch, MAX_LEN);
    cout << "Рядок після вставки: " << str << endl;
    
    // 4. 
    replaceDotsWithExclamations(str);
    cout << "Рядок після заміни '.' на '!': " << str << endl;
    
    // 5. 
    cout << "Введіть символ для пошуку: ";
    cin >> ch;
    count = countChar(str, ch);
    cout << "Символ '" << ch << "' зустрічається " << count << " разів" << endl;
    
    // 6.
    countCharTypes(str, letters, digits, others);
    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших: " << others << endl;
    
    // 7. 
    char str2[MAX_LEN];
    cout << "Введіть другий рядок для порівняння: ";
    cin.ignore();
    cin.getline(str2, MAX_LEN);
    
    cout << "Порівняння рядків: " << mystrcmp(str, str2) << endl;
    cout << "Рядок у верхньому регістрі: " << Uppercase(str) << endl;
    cout << "Рядок у нижньому регістрі: " << Lowercase(str) << endl;
    cout << "Реверс рядка: " << mystrrev(str) << endl;
    
    char numStr[] = "12345";
    cout << "Рядок у число: " << StringToNumber(numStr) << endl;
    cout << "Число у рядок: " << NumberToString(12345) << endl;
    
    return 0;
}
