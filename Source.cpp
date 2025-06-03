#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void addElement(int element, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index\n";
            return;
        }

        if (size == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

        for (int* ptr = arr + size; ptr > arr + index; ptr--) {
            *ptr = *(ptr - 1);
        }
        *(arr + index) = element;
        size++;
    }

    void removeElement(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }

        for (int* ptr = arr + index; ptr < arr + size - 1; ptr++) {
            *ptr = *(ptr + 1);
        }
        size--;
    }

    void display() {
        cout << "Array: ";
        for (int* ptr = arr; ptr < arr + size; ptr++) {
            cout << *ptr << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray dynArr(5);

    dynArr.addElement(1, 0);
    dynArr.addElement(2, 1);
    dynArr.addElement(3, 2);
    dynArr.addElement(4, 3);
    dynArr.display();

    dynArr.addElement(10, 2);
    dynArr.display();

    dynArr.removeElement(1);
    dynArr.display();

    dynArr.addElement(20, 0);
    dynArr.display();

    dynArr.removeElement(2);
    dynArr.display();

    return 0;
}
