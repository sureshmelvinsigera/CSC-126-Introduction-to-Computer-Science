#include <iostream> //standard input / output streams

using namespace std;

const int ARRAY_SIZE = 10;

void initializeArray(int list[], int listSize);

void fillArray(int list[], int listSize);

void printArray(int list[], int listSize);

void copyArray(int list1[], int src, int list2[], int tar, int numOfElements);

int sumArray(const int list[], int listSize);

int indexLargestElement(const int list[], int listSize);


int main() {
    int mylistA[ARRAY_SIZE];
    int mylistB[ARRAY_SIZE];

    int sum, max = 0;

    initializeArray(mylistA, ARRAY_SIZE);
    printArray(mylistA, ARRAY_SIZE);
    fillArray(mylistA, ARRAY_SIZE);
    printArray(mylistA, ARRAY_SIZE);
    sum = sumArray(mylistA, ARRAY_SIZE);
    cout << endl << "Sum of the values in the array " << sum << " " << endl;
    max = indexLargestElement(mylistA, ARRAY_SIZE);
    cout << "Max Index " << max << endl;
    copyArray(mylistA, 0, mylistB, 0, ARRAY_SIZE);
    //cout << endl << copyArray << endl;
    cout << "Done with copyArray" << endl;
    printArray(mylistB, ARRAY_SIZE);

}

void initializeArray(int list[], int listSize) {
    cout << "initializeArray" << endl;
    int index;
    for (index = 0; index < listSize; index++)
        list[index] = 0;

}

void fillArray(int list[], int listSize) {
    cout << "fillArray" << endl;
    int index;
    for (index = 0; index < listSize; index++)
        cin >> list[index];

}

void printArray(int list[], int listSize) {
    cout << "printArray" << endl;
    int index;
    for (index = 0; index < listSize; index++)
        cout << list[index] << " " << endl;

}

int sumArray(const int list[], int listSize) {
    cout << "sumArray" << endl;
    int index;
    int sum = 0;
    for (index = 0; index < listSize; index++)
        sum = sum + list[index];
    return sum;

}

int indexLargestElement(const int list[], int listSize) {
    cout << "indexLargestElementArray" << endl;
    int index;
    int maxIndex = 0; //Assume the first element is the largest
    for (index = 1; index < listSize; index++)
        if (list[maxIndex] < list[index])
            maxIndex = index;
    return maxIndex;
}

void copyArray(int list1[], int src, int list2[], int tar, int numOfElements) {
    cout << "copyArray" << endl;
    for (int index = src; index < src + numOfElements; index++) {
        list2[index] = list1[tar];
        tar++;
    }
}