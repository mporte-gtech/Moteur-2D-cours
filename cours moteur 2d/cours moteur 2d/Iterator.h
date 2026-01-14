#pragma once
#include "Node.h"

template<typename T> class Iterator
{
private:
	Node<T>* CurrentNode;

public:
	Iterator(Node<T>* node);

	void operator ++ () {
		if (Node<T>* nextNode = CurrentNode->GetNextNode() != nullptr)
			CurrentNode = nextNode;
	}

	void operator -- () {
		if (Node<T>* previousNode = CurrentNode->GetPreviousNode() != nullptr)
			CurrentNode = previousNode;
	}

	void operator * () {
		return CurrentNode->GetValue();
	}

	void operator + (int amount) {
		for (int i = 0; i < amount; i++)
		{
			if (Node<T>* nextNode = CurrentNode->GetNextNode() != nullptr)
				CurrentNode = nextNode;
		}
	}

	void operator - (int amount) {
		for (int i = 0; i < amount; i++)
		{
			if (Node<T>* previousNode = CurrentNode->GetPreviousNode() != nullptr)
				CurrentNode = previousNode;
		}
	}
};

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	CurrentNode = node;
}
