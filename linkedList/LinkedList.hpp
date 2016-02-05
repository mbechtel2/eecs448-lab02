/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//Returns the size member variable
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	//Continues while there are still elements in the list
	while(temp != nullptr)
	{
		//Determines if the value parameter is in the current Node
		if(value == temp->getValue())
		{
			//Changes variable to show the desired value was present
			isFound = true;
		}
		
		//Increments the temp Node to the next Node in the list
		temp = temp->getNext();
	}
	
	//Return if the given value was found
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//Determines if there is only one Node in the list
	if(m_size == 1)
	{
		//Deletes the only Node
		delete m_front;
	
		//Changes the pointer to null
		m_front = nullptr;
		
		//Decreases size list by 1
		m_size--;

		//States that an element was removed from the list
		isRemoved = true;
	}
	else if(m_size > 1) //Checks to see if there are 2+ elements in the list
	{
		//Initializes lastNode equal to the first Node in the list
		lastNode = m_front;

		//Continues while lastNode is not equal to the last node
		while(lastNode->getNext() != nullptr)
		{
			//Sets both node variables to the next one (from where they are) in the list
			secondintoLast = lastNode;
			lastNode = lastNode->getNext();
		}

		//Sets second to last node's next pointer to null
		secondintoLast->setNext(nullptr);

		//Deletes last node and sets pointer to null
		delete lastNode;
		lastNode = nullptr;

		//Decreases size of list by 1
		m_size--;

		//States that an element was removed from the list
		isRemoved = true;
	}
	
	//Returns if an element was removed from the list
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
