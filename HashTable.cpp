//
// Created by Линар on 21/12/2018.
//
#include "HashTable.h"

#include <stdexcept>


// Создание хеш-таблицы
HashTable::HashTable(int N)
: N {N}
{
    // this->N     = N;
    this->size_ = 0;
    table = new Cell[N];
    for(int i = 0; i < N; ++i) {
        table[i].filled = false;
    }
}

// Удаление хеш-таблицы
HashTable::~HashTable() {
    delete [] table;
}

// Получение элемента
int HashTable::get(int key) {
    int hash_ = hash(key);
    if(table[hash_].filled && table[hash_].key == key) {
        return table[hash_].value;
    } else {
        throw std::invalid_argument { "the item is missing" };
    }
}

// Добавление элемента в хеш-таблицу
void HashTable::add(int key, int value) {
    int hash_ = hash(key);

    if(!table[hash_].filled) {
        table[hash_].key = key;
        table[hash_].value = value;
        table[hash_].filled = true;
        size_++;
    } else {
        throw std::invalid_argument { "the cell is busy" };
    }

}

// Удаление элемента из хеш-таблицы
void HashTable::del(int key) {
    int hash_ = hash(key);
    if(table[hash_].filled && table[hash_].key == key ) {
        table[hash_].filled = false;
        size_--;
    } else {
        throw std::invalid_argument { "the item is missing" };
    }
}