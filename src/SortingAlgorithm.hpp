#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


namespace SortLibrary {
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v){
	const unsigned int n = v.size();
	for (unsigned int i=0; i<n-1; i++){
		for (unsigned int j=i+1; j<n; j++){
			if (v[j]<v[i]){
				// swap:
				T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
		}
	}	
}

template<Sortable T>
void HeapSort(std::vector<T>& v){
	vector<T> tree;
	for (unsigned int i=0; i<v.size(); i++){
		// enqueue(v[i]):
		tree.push_back(v[i]);
		push_heap(tree.begin(), tree.end(), greater<T>());
	}
	unsigned int j = 0;
	while (tree.size()>0){
		// dequeue():
		pop_heap(tree.begin(), tree.end(), greater<T>());
		v[j] = tree.back();
		tree.pop_back();
		j++;
	}
}

}
