#pragma once
template <typename T> class Node
{
private:
	Node<T>* previousNode, *nextNode;

	T value;

public:
	Node(T value, Node* previousNode = nullptr);

	T GetValue();
	void SetValue(T newValue);

	Node* GetPreviousNode();
	void SetPreviousNode(Node* newPreviousNode);

	Node* GetNextNode();
	void SetNextNode(Node* newNextNode);
};

template<typename T>
inline Node<T>::Node(T value, Node* previousNode) :
	value(value), previousNode(previousNode != nullptr ? previousNode : nullptr)
{
	if (previousNode != nullptr)
		previousNode->SetNextNode(this);
	SetNextNode(nullptr);
}

template<typename T>
inline T Node<T>::GetValue()
{
	return value;
}
template<typename T>
inline void Node<T>::SetValue(T newValue)
{
	value = newValue;
}

template<typename T>
inline Node<T>* Node<T>::GetPreviousNode()
{
	return previousNode;
}
template<typename T>
inline void Node<T>::SetPreviousNode(Node* newPreviousNode)
{
	previousNode = newPreviousNode;
	if (newPreviousNode->GetNextNode() != this)
		newPreviousNode->SetNextNode(this);
}

template<typename T>
inline Node<T>* Node<T>::GetNextNode()
{
	return nextNode;
}
template<typename T>
inline void Node<T>::SetNextNode(Node* newNextNode)
{
	if (newNextNode != nullptr && newNextNode->GetPreviousNode() != this)
		newNextNode->SetPreviousNode(this);
	nextNode = newNextNode;
}
