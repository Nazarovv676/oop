#pragma once

#include "MapExceptions.h"
#include <vector>
#include <algorithm>
#include <functional>

template<typename KeyT, typename ValT>
class _MapEntry {
public:
	KeyT key;
	ValT* value;

	_MapEntry(KeyT key) : key(key), value(new ValT()) {}
	_MapEntry(KeyT key, ValT value) : key(key), value(&value) {}
};

// Needs ValT with default constructor
template<typename KeyT, typename ValT>
class Map {
	std::vector<_MapEntry<KeyT, ValT>>* _data;


public:
	Map() {
		_data = new std::vector<_MapEntry<KeyT, ValT>>();
	}

	int length() {
		return _data->size();
	}

	ValT& operator[](const KeyT key);

	ValT& getByIndex(const int index);

	void sort(std::function<bool(_MapEntry<KeyT, ValT>, _MapEntry<KeyT, ValT>)>& comparator);
};

// If not found, creates new value by key and return value equals NULL
template<typename KeyT, typename ValT>
ValT& Map<KeyT, ValT>::operator[](const KeyT key) {
	for (int i = 0; i < _data->size(); i++) {
		_MapEntry<KeyT, ValT> entry = _data->operator[](i);
		if (entry.key == key) {
			return *entry.value;
		}
	}

	_MapEntry<KeyT, ValT> newEntry(key);
	_data->push_back(newEntry);
	return *newEntry.value;
}

template<typename KeyT, typename ValT>
ValT& Map<KeyT, ValT>::getByIndex(const int index) {
	if (index >= _data->size() || index < 0) {
		throw MapRangeException();
	}

	return *_data->operator[](index).value;
}


template<typename KeyT, typename ValT>
void Map<KeyT, ValT>::sort(std::function<bool(_MapEntry<KeyT, ValT>, _MapEntry<KeyT, ValT>)>& comparator) {
	std::sort(_data->begin(), _data->end(), comparator);
}