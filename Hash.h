#ifndef WEATHERPROJECT_HASH_H
#define WEATHERPROJECT_HASH_H
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

template<typename T>
class HashTable {
    long size;
    List<T>* hashtable;
    int count, average, collisions;

public:

    /*
    ** Header: setData(T data)
    ** Sets data
    ** Pre:
    ** Post:
    ** Return:
    */
    HashTable(int size){
        this->size = size;
        hashtable = new List<T>[size];
        count = 0;
        average = 0;
        collisions;
    }

    /*
    ** Header: hash()
    ** creates hash key
    ** Pre: temp, hum, and wind doubles
    ** Post:
    ** Return: hash key 
    */
    int hash(double temp, double hum, double wind) {
        return (int)(temp * hum + wind) % size;
    }

    /*
    ** Header: insert()
    ** Adds data to Hash table
    ** Pre: T val, int key, and double temperature, humidity and wind values
    ** Post: Element is processed ot table
    ** Return:
    */
    void insert(T val, double temperature, double humidity, double wind, int key) {

        int index = hash(temperature, humidity, wind);
        hashtable[index].add(val, key);
        count = count + 1;
    }

    /*
    ** Header: remove()
    ** Removes key from hash table
    ** Pre:int key
    ** Post: element is removed/ or not removed
    ** Return: bool expression accordingly
    */
    bool remove(int key){
        for(int i = 0; i < size; i++) {
            if(hashtable[i].getCount()>0) {
                if (hashtable[i].remove(key)) {
                    return true;
                }
            }
        }
        return false;
    }

    /*
    ** Header: loadFactor()
    ** generates loadFactor
    ** Pre:
    ** Post: generates laod factor
    ** Return: count divided by size (pased by double)
    */
    double loadFactor() {
        return count/(double)size;
    }

    /*
    ** Header: efficiency()
    ** Sets data
    ** Pre: ofstream object
    ** Post: efficiency statistics is printed
    ** Return: 
    */
    void efficiency(std::ofstream& outstream){
        average = 0;
        int temp = 0, temp2 = 0;
        collisions = 0;
        for(int i = 0; i < size; i++) {
            if(hashtable[i].getCount() > 1){
                collisions++;
            }
            else if(hashtable[i].getCount() > 0){
                average++;

            }
            if(hashtable[i].getCount() > temp){
                temp = hashtable[i].getCount();
                temp2 = i;
            }
        }
        std::cout<<"Load Factor: "<<loadFactor()<<std::endl;
        std::cout<<"\nLongest Linked-List: "<<temp2+1<<" count: " <<hashtable[temp2].getCount()<<std::endl;
        outstream<<"Load Factor: "<<loadFactor()<<std::endl;
        outstream<<"\nLongest Linked-List: "<<temp2+1<<" count: " <<hashtable[temp2].getCount()<<std::endl;
        hashtable[temp2].print(outstream);
        std::cout<<"\nAverage nodes in Linked List: "<<(double)count/average<<std::endl;
        std::cout<<"\nCollisions Resolved: "<<collisions<<std::endl;
        outstream<<"\nAverage nodes in Linked List: "<<(double)count/average<<std::endl;
        outstream<<"\nCollisions Resolved: "<<collisions<<std::endl;
    }

    /*
    ** Header: printTable()
    ** Prints enitre hash table
    ** Pre: ofstream object
    ** Post: 
    ** Return:
    */
    void printTable(std::ofstream& outstream) {
        int index = 0;
        average = 0;
        for (int i = 0; i < size; i++) {
            std::cout << "Index " << i + 1 << "--> ";
            outstream << "Index " << i + 1 << "--> ";
            hashtable[i].print(outstream);
            std::cout << endl;
            outstream << endl;
        }
    }

};
#endif //WEATHERPROJECT_HASH_H
