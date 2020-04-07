#include <iostream>
#include <fstream>
#include "dictionarySimple.h"
#include <list>
#include <chrono>


int main() {
    DictionarySimple<string> a;
    a.insert("F2CPTBlDQkk6OA2cLwZkrcoSlxTESXiUSY43GvuVUbsbKBbsej");
    a.insert("25sfBLwaZdSsxhxMIbCkdBjaw0Q4bWh4jXViTdqjUQWCtnJhxQ");
    a.insert("mItXR0u4orXn0fpzjiJPZx2sjbWXDgplcuri1bG5uxtDmAoLBW");
    a.insert("ziurGkL9lH7DcUEy4EKeyoYekrLDlmGusQHdjulILZ1mK0ccvO");
    a.insert("aaYxkhDRs5T2mZ53gPKF1NesmEYiO9AhQxYPt9QahhlUpX4SHV");
    a.insert("EsXJzlRMPQkfPqMnqcDeFcuqKlAbmttBvGNURjJDCVDvhVydWS");
    a.insert("hpULipQOBpiOsIdNBSsaZYxsHkTZThMqFJtMXtzipPKPmCurwu");
    a.printSet();
    a.size();
    a.remove("EsXJzlRMPQkfPqMnqcDeFcuqKlAbmttBvGNURjJDCVDvhVydWS");
    a.printSet();
    a.size();
    cout << a.isExist("EsXJzlRMPQkfPqMnqcDeFcuqKlAbmttBvGNURjJDCVDvhVydWS") << endl;
    cout << a.isExist("mItXR0u4orXn0fpzjiJPZx2sjbWXDgplcuri1bG5uxtDmAoLBW") << endl;

    srand(time(NULL));
    DictionarySimple<string> set;
    int n=100000;
    char tab[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    ofstream zapis;
    string word;
    string wordsTab[n];
    for(int i =0; i< n ; i++){
        for(int k=0; k < 50 ; k++){
            word+= tab[rand() % 62];
        }
        wordsTab[i] = word;
        word ="";
    }

   zapis.open("/home/sony/CLionProjects/AISD2/Zestaw1D/daneDelete.txt",ios::out | ios::app);
    for (int j = 0; j < n; ++j) {
        set.insert(wordsTab[j]);
    }

    double totalTime=0;
    if (zapis.good()) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < n; ++j) {
            set.remove(wordsTab[j]);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        totalTime = elapsed.count();
    }
   zapis << n  << " " << totalTime << endl;
   // zapis << "e" << endl;
   zapis.flush();
    zapis.close();
    return 0;
}
