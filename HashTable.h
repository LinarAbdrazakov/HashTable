//
// Created by Линар on 21/12/2018.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

class Cell {
public:
    int key;
    int value;
    bool filled;
};

class HashTable {
private:
    const int N;
    int size_;
    Cell * table;

public:
    HashTable(int N);
    ~HashTable();
    int hash(int key)  {  return key % N;  }
    int get(int key);
    int size()  {  return this->size_;  }
    void add(int key, int value);
    void del(int key);
};

#endif //HASHTABLE_H
