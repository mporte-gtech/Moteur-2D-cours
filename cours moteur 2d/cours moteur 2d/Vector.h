#pragma once
#include "Iterator.h"

template<typename T> class Vector
{
private:
	Node<T>* firstNode, *lastNode;

	int size;

public:
	Vector();

	void PushBack(T value);

	Iterator<T> Begin();

	Iterator<T> End();

	int GetSize();

	T* operator [] (int index){
		if (index >= size)
			return nullptr;
		Node<T>* returnedNode = firstNode;
		for (int i = 0; i < index; i++) {
			returnedNode = returnedNode->GetNextNode();
		}
		return returnedNode;
	}
};

template<typename T>
inline Vector<T>::Vector()
{
	firstNode = nullptr;
	lastNode = nullptr;
}

template<typename T>
inline void Vector<T>::PushBack(T value)
{
	Node<T>* node = new Node<T>(value);

	if (lastNode == nullptr)
	{
		firstNode = node;
		lastNode = node;
	}
	else
	{
		lastNode->SetNextNode(node);
	}

	size += 1;
}

template<typename T>
inline Iterator<T> Vector<T>::Begin()
{
	return firstNode;
}

template<typename T>
inline Iterator<T> Vector<T>::End()
{
	return lastNode;
}

template<typename T>
inline int Vector<T>::GetSize()
{
	return size;
}
