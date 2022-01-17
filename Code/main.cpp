/**
 * @auther Yaaqov Shkifati and Astroid Cortez
 * @since 02/10/2021
 * @verison 1.0
 */
#include <cstdlib>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_set>
#include <fstream>
#include<random>
#include <chrono>
#include<stdlib.h>
#include <ctime>
#include <algorithm>


using namespace std;

template<typename C>

double insertContain(const vector<int> &v1, C &container, bool isertEnd);

template<typename C1>

double findRange(C1 &contain, int n);

int main() {

    int n = 100000;
    vector<int> v1;
    vector<int> v2;
    set<int> s1;
    list<int> l1;
    unordered_set<int> unorder;

    bool fromEnd = true;

    //populating the vector V1
    for (int i = 1; i <= n; ++i) {
        v1.push_back(i);
    }

    //randomize the ordering in vector V1.
    shuffle(v1.begin(), v1.end(), default_random_engine(time(NULL)));


    double time1 = insertContain(v1, v2, fromEnd);
    double time2 = insertContain(v1, s1, fromEnd);
    double time3 = insertContain(v1, l1, fromEnd);
    double time4 = insertContain(v1, unorder, fromEnd);

    fromEnd = false;

    double time5 = insertContain(v1, v2, fromEnd);
    double time6 = insertContain(v1, s1, fromEnd);
    double time7 = insertContain(v1, l1, fromEnd);
    double time8 = insertContain(v1, unorder, fromEnd);



    //Printing the time it takes to insert to the end of each container.
    cout << "Inserting end time Vector: " << time1 << " (Micro-sec) " << (time1 / time1)*100 << "%" << endl;
    cout << "Inserting end time Set: " << time2 << " (Micro-sec) " << (time2 / time1)*100 << "%" << endl;
    cout << "Inserting end Time List: " << time3 << " (Micro-sec) " << (time3 / time1)*100 << "%" << endl;
    cout << "Inserting end Time Unordered Set: " << time4 << " (Micro-sec) " << (time4 / time1)*100 << "%" << endl;

    cout << "-----------------------------------------------------------------" << endl;


    //Printing the time it takes to insert to the beginning of each container.
    cout << "Inserting begin Time Vector: " << time5 << " (Micro-sec) " << (time5 / time5)*100 << "%" << endl;
    cout << "Inserting begin Time Set: " << time6 << " (Micro-sec) " << (time6 / time5)*100 << "%" << endl;
    cout << "Inserting begin Time List: " << time7 << " (Micro-sec) " << (time7 / time5)*100 << "%" << endl;
    cout << "Inserting begin Time Unordered Set: " << time8 << " (Micro-sec) " << (time8 / time5)*100 << "%" << endl;

    cout << "------------------------------------------------------------------" << endl;



    // Printing the time it takes Vector v2 to find the values 1-100k   
    auto begTime1 = chrono::steady_clock::now();
    for (int i = 0; i <= n; i++) {
        std::find(v2.begin(), v2.end(), i);
    }
    auto endTime1 = chrono::steady_clock::now();
    double time9 = chrono::duration_cast<chrono::microseconds>(endTime1 - begTime1).count();
    cout << "Find Time durations for Vector: " << time9 << " (Micro-sec)" << (time9 / time9)*100 << "%" << endl;



    // Printing the time it takes List to find the values 1-100k   
    auto begTime2 = chrono::steady_clock::now();

    for (int i = 0; i <= n; i++) {
        std::find(l1.begin(), l1.end(), i);
    }
    auto endTime2 = chrono::steady_clock::now();
    double time10 = chrono::duration_cast<chrono::microseconds>(endTime2 - begTime2).count();
    cout << "Find Time durations for List: " << time10 << " (Micro-sec)" << (time10 / time9)*100 << "%" << endl;



    // Printing the time it takes Set to find the values 1-100k   
    auto begTime3 = chrono::steady_clock::now();
    for (int i = 0; i <= n; i++) {
        s1.find(i);
    }
    auto endTime3 = chrono::steady_clock::now();
    double time11 = chrono::duration_cast<chrono::microseconds>(endTime3 - begTime3).count();
    cout << "Find Time durations for Set: " << time11 << " (Micro-sec)" << (time11 / time9)*100 << "%" << endl;



    // Printing the time it takes Unordered Set to find the values 1-100k   
    auto begTime4 = chrono::steady_clock::now();
    for (int i = 0; i <= n; i++) {

        unorder.find(i);
    }
    auto endTime4 = chrono::steady_clock::now();
    double time12 = chrono::duration_cast<chrono::microseconds>(endTime4 - begTime4).count();
    cout << "Find Time durations for Unordered Set: " << time12 << " (Micro-sec)" << (time12 / time9)*100 << "%" << endl;


    return 0;
}

/**
 * The insertContain function inserts the values in Vector V1 into a container.
 * @param v1 Vector 
 * @param container Any container
 * @param isertEnd wether insertion is front or end.
 * @return The time is micro-seconds to insert the values into the container.
 */
template<typename C>
double insertContain(const vector<int> &v1, C &container, bool isertEnd) {

    auto begTime = chrono::steady_clock::now();

    for (int i = 0; i != v1.size(); ++i) {

        if (isertEnd == true) {
            container.insert(container.end(), v1[i]);
        } else {
            container.insert(container.begin(), v1[i]);
        }
    }

    auto endTime = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::microseconds>(endTime - begTime).count();
}

/*
template<typename C1>
double findRange(C1 &contain, int n){
    
     auto begTime1 = chrono::steady_clock::now();
   
     for(int i=0; i< n; i++){
        
        std::find(contain.begin(),contain.end(),i);
       
    }
    auto endTime1 = chrono::steady_clock::now();
    
  return chrono::duration_cast<chrono::microseconds>(endTime1 - begTime1).count();
   
}
 */



