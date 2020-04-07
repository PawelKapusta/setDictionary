//
// Created by sony on 09.03.2020.
//

#ifndef ZESTAW1D_DICTIONARYSIMPLE_H
#define ZESTAW1D_DICTIONARYSIMPLE_H

#include <form.h>

using namespace std;

#define SIZE  3000000
template <class T>
class DictionarySimple {

public:
    T *array = new T[SIZE];
    int countElements = 0;

    void insert(T x) {
        if(x.length() != 50){
            cout << "Length of element: " << x << " not equals 50! try to edit your word" << endl;
            return;
        }else if (countElements == 0) {
            array[0] = x;
            countElements++;
        } else if (countElements >= SIZE) {
            cout << "Set is FULL " << endl;
            return;
        } else if (isExist(x)) {
            cout << "This element: " << x << " already exist in this set" << endl;
            return;
        } else {
            for (int i = 0; i < countElements; i++) {
                if (array[i] >= x) {
                    for (int j = countElements; j > i; j--) {
                        array[j] = array[j - 1];
                    }
                    array[i] = x;
                    countElements++;
                    return;
                }
                if (i == countElements - 1) {
                    array[i + 1] = x;
                    countElements++;
                    return;
                }
            }
        }
    }

    void remove(T x) {
        if (countElements == 0) {
            std::cout << "Set is empty" << std::endl;
            return;
        }
        for (int i = 0; i < countElements; i++) {
            if (array[i] == x) {
                for (int j = i; j < countElements - 1; j++) {
                    array[j] = array[j + 1];
                }
                countElements--;
                i--;
            }
        }
        // return;
    }

    bool isExist(T x){
        for (int i = 0; i < countElements; ++i) {
            if(array[i] == x){
                return true;
            }
        }
        return false;
    }
    void size(){
        cout<< "Size of set is equal to: " << countElements << endl;
    }
    void printSet(){
        cout<<"Our set looks like this: " << endl;
        for (int i = 0; i < countElements; ++i) {
            cout << i+1<<". " << array[i] << endl;
        }
    }


};




#endif //ZESTAW1D_DICTIONARYSIMPLE_H
