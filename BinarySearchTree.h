#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

using namespace std;

/**
 * @struct Node
 * @brief Struct with template variables
 *
 * This struct will have a variable of T type, a counter and Node pointers
 * We can use struct for better usage of memory
 *
 * @author Wei Xing
 * @version 01
 * @date 21/07/2022 Wei Xing, Started
 *
 * @todo None for now
 *
 * @bug To the best of my knowledge, my program has no bugs
 */

template <class T>
struct Node
{
    T m_data;
    unsigned m_count = 0;
    Node<T>* m_left, * m_right;
};

/**
 * @class BinarySearchTree
 * @brief Templated data structure that stores any type of data
 *
 * This class is a binary search tree which contains nodes
 * It will handle the following functions:
 * 1. Size of tree
 * 2. Insertion of data
 * 3. Deletion of data
 * 4. Three traversal techniques using recursive function
 * 5. Searching of element in tree
 * 6. Deletion of tree
 * 7. Copy constructor, Copy method and Overloaded assignment
 *
 * @author Wei Xing
 * @version 01
 * @date 21/07/2022 Wei Xing, Started
 *
 * @todo None for now
 *
 * @bug To the best of my knowledge, my program has no bugs
 */

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    /**
     * Get size of binary search tree
     * @param None
     * @return Tree size
     */
    unsigned GetSize() const;

    /**
     * Insertion of data to binary search tree
     * @param data of T type
     * @return true/false
     */
    bool Insert(const T& data);

    /**
     * Deletion of data in binary search tree
     * @param data of T type
     * @return true/false
     */
    bool Delete(const T& data);

    /**
     * In order traversing for visiting node in tree
     * @param Pointer function
     * @return None
     */
    void InOrderTraversal(void(*func)(T&)) const;

    /**
     * In order traversing for visiting node with counter in tree for checking
     * @param Pointer function
     * @return None
     */
    void InOrderTraversalCount(void(*func)(T&, unsigned&)) const;

    /**
     * In order traversing for visiting node in tree to perform calculations
     * @param Pointer function and 2 variables of T type
     * @return None
     */
    void InOrderTraversalCalc(void(*func)(T&, T&, unsigned&, unsigned&), T& totalSum, unsigned& totalCount) const;

    /**
     * Pre order traversing for visiting node in tree
     * @param Pointer function
     * @return None
     */
    void PreOrderTraversal(void(*func)(T&)) const;

    /**
     * Post order traversing for visiting node in tree
     * @param Pointer function
     * @return None
     */
    void PostOrderTraversal(void(*func)(T&)) const;

    /**
     * Search for element in binary search tree
     * @param data of T type
     * @return true/false
     */
    bool Search(const T& dataKey) const;

    /**
     * Copy constructor
     * @param BinarySearchTree of T type
     * @return None
     */
    BinarySearchTree(const BinarySearchTree<T>& initialiser);

    /**
     * Copy method
     * @param old and new BinarySearchTree of T type
     * @return true/false
     */
    bool Copy(const BinarySearchTree<T>& rhs, BinarySearchTree<T>& newBst);

    /**
     * Overloaded assignment
     * @param BinarySearchTree of T type
     * @return new BinarySearchTree
     */
    BinarySearchTree<T>& operator= (const BinarySearchTree<T>& rhs);

private:
    /// Root pointer of T type
    Node<T>* m_root;

    /// Size of tree
    unsigned m_treeSize;

    /**
     * Function to delete all nodes of tree
     * @param Node pointer
     * @return None
     */
    void DestroyTree(Node<T>* tempNode);

    /**
     * Insertion of data to binary search tree
     * @param Node pointer, data of T type
     * @return true/false
     */
    bool Insert(Node<T>* tempNode, const T& data);

    /**
     * Deletion of data in binary search tree
     * @param Node pointer by reference, data of T type
     * @return true/false
     */
    bool Delete(Node<T>* &tempNode, const T& data);

    /**
     * Created specifically for Delete function to find smallest node of right tree
     * @param Node pointer
     * @return Node pointer
     */
    Node<T>* MinValueNode(Node<T>* node);

    /**
     * In order traversing for visiting node in tree
     * @param Node pointer, pointer function
     * @return None
     */
    void InOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const;

    /**
     * In order traversing for visiting node with counter in tree for checking
     * @param Node pointer, pointer function
     * @return None
     */
    void InOrderTraversalCount(Node<T>* tempNode, void(*func)(T&, unsigned&)) const;

    /**
     * In order traversing for visiting node in tree to perform calculations
     * @param Node pointer, pointer function and 2 variables of T type
     * @return None
     */
    void InOrderTraversalCalc(Node<T>* tempNode, void(*func)(T&, T&, unsigned&, unsigned&), T& totalSum, unsigned& totalCount) const;

    /**
     * Pre order traversing for visiting node in tree
     * @param Node pointer, pointer function
     * @return None
     */
    void PreOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const;

    /**
     * Post order traversing for visiting node in tree
     * @param Node pointer, pointer function
     * @return None
     */
    void PostOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const;

    /**
     * Search for element in binary search tree
     * @param Node pointer, data of T type
     * @return true/false
     */
    bool Search(Node<T>* tempNode, const T& dataKey) const;

    /**
     * Recursive copy function for copy method
     * @param Node pointer, BinarySearchTree of T type
     * @return new BinarySearchTree
     */
    BinarySearchTree<T>& CopyOf(const Node<T>* rhs, BinarySearchTree<T>& newBst) const;
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = nullptr; // Default set to null pointer
    m_treeSize = 0; // Default set to 0
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    DestroyTree(m_root); // Calls function to delete tree
}

template <class T>
void BinarySearchTree<T>::DestroyTree(Node<T>* tempNode)
{
    if (tempNode != nullptr)
    {
        DestroyTree(tempNode->m_left);
        DestroyTree(tempNode->m_right);
        delete tempNode;
        tempNode = nullptr;
        m_treeSize--; // For each deletion, tree size minus one
    }
}

template <class T>
unsigned BinarySearchTree<T>::GetSize() const
{
    return m_treeSize;
}

template <class T>
bool BinarySearchTree<T>::Insert(const T& data)
{
    if (m_root == nullptr) // Check if root node is null
    {
        m_root = new Node<T>;
        m_root->m_data = data;
        m_root->m_left = nullptr;
        m_root->m_right = nullptr;
        m_root->m_count = 1;
        m_treeSize++;
        return true;
    }
    return Insert(m_root, data);
}

template <class T>
bool BinarySearchTree<T>::Insert(Node<T>* tempNode, const T& data)
{
    if (data == tempNode->m_data)
    {
        tempNode->m_count++; // Increase count if duplicate data
        return true;
    }

    if (data > tempNode->m_data)
    {
        if (tempNode->m_right == nullptr) // Check if right node is null
        {
            tempNode->m_right = new Node<T>;
            tempNode->m_right->m_data = data;
            tempNode->m_right->m_left = nullptr;
            tempNode->m_right->m_right = nullptr;
            tempNode->m_right->m_count = 1;
            m_treeSize++;
            return true;
        }
        return Insert(tempNode->m_right, data);
    }
    else if ( data < tempNode->m_data)
    {
        if (tempNode->m_left == nullptr) // Check if left node is null
        {
            tempNode->m_left = new Node<T>;
            tempNode->m_left->m_data = data;
            tempNode->m_left->m_left = nullptr;
            tempNode->m_left->m_right = nullptr;
            tempNode->m_left->m_count = 1;
            m_treeSize++;
            return true;
        }
        return Insert(tempNode->m_left, data);
    }
    return false;
}

template<class T>
bool BinarySearchTree<T>::Delete(const T& data)
{
    return Delete(m_root, data);
}

template<class T>
bool BinarySearchTree<T>::Delete(Node<T>* &tempNode, const T& data)
{
    if (tempNode == nullptr) // Return false if no such value
        return false;

    if (data > tempNode->m_data)
    {
        return Delete(tempNode->m_right, data);
    }
    else if (data < tempNode->m_data)
    {
        return Delete(tempNode->m_left, data);
    }

    if (tempNode->m_left == nullptr && tempNode->m_right == nullptr) // Check no child node
    {
        delete tempNode;
        tempNode = nullptr;
        m_treeSize--;
        return true;
    }
    if (tempNode->m_left == nullptr && tempNode->m_right != nullptr) // Check if have right child node
    {
        Node<T>* holdNode = tempNode->m_right;
        tempNode->m_right = nullptr;
        delete tempNode; // Prevent memory leak
        tempNode = holdNode;
        m_treeSize--;
        return true;
    }
    if (tempNode->m_left != nullptr && tempNode->m_right == nullptr) // Check if have left child node
    {
       Node<T>* holdNode = tempNode->m_left;
       tempNode->m_left = nullptr;
       delete tempNode; // Prevent memory leak
       tempNode = holdNode;
       m_treeSize--;
       return true;
    }
    T tempData = MinValueNode(tempNode->m_right)->m_data; // Two child nodes
    Delete(tempNode->m_right, tempData);
    tempNode->m_data = tempData;
    return true;
}

template <class T>
Node<T>* BinarySearchTree<T>::MinValueNode(Node<T>* node) // Function to find the smallest node of right tree
{
    while (node && node->m_left != nullptr)
        node = node->m_left;
    return node;
}

template <class T>
void BinarySearchTree<T>::InOrderTraversal(void(*func)(T&)) const
{
    InOrderTraversal(m_root, *func);
}

template <class T>
void BinarySearchTree<T>::InOrderTraversalCount(void(*func)(T&, unsigned&)) const
{
    InOrderTraversalCount(m_root, *func);
}

template <class T>
void BinarySearchTree<T>::InOrderTraversalCalc(void(*func)(T&, T&, unsigned&, unsigned&), T& totalSum, unsigned& totalCount) const
{
    InOrderTraversalCalc(m_root, *func, totalSum, totalCount);
}

template <class T>
void BinarySearchTree<T>::InOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const
{
    if (tempNode != nullptr)
    {
        InOrderTraversal(tempNode->m_left, *func);
        (*func)(tempNode->m_data); // Function pointer to print each node
        InOrderTraversal(tempNode->m_right, *func);
    }
}

template <class T>
void BinarySearchTree<T>::InOrderTraversalCount(Node<T>* tempNode, void(*func)(T&, unsigned&)) const
{
    if (tempNode != nullptr)
    {
        InOrderTraversalCount(tempNode->m_left, *func);
        (*func)(tempNode->m_data, tempNode->m_count); // Function pointer to print each node and the counter
        InOrderTraversalCount(tempNode->m_right, *func);
    }
}

template <class T>
void BinarySearchTree<T>::InOrderTraversalCalc(Node<T>* tempNode, void(*func)(T&, T&, unsigned&, unsigned&), T& totalSum, unsigned& totalCount) const
{
    if (tempNode != nullptr)
    {
        InOrderTraversalCalc(tempNode->m_left, *func, totalSum, totalCount);
        (*func)(tempNode->m_data, totalSum, tempNode->m_count, totalCount); // Function pointer to return total sum and total count
        InOrderTraversalCalc(tempNode->m_right, *func, totalSum, totalCount);
    }
}

template <class T>
void BinarySearchTree<T>::PreOrderTraversal(void(*func)(T&)) const
{
    PreOrderTraversal(m_root, *func);
}

template <class T>
void BinarySearchTree<T>::PreOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const
{
    if (tempNode != nullptr)
    {
        (*func)(tempNode->m_data); // Function pointer to print each node
        PreOrderTraversal(tempNode->m_left, *func);
        PreOrderTraversal(tempNode->m_right, *func);
    }
}

template <class T>
void BinarySearchTree<T>::PostOrderTraversal(void(*func)(T&)) const
{
    PostOrderTraversal(m_root, *func);
}

template <class T>
void BinarySearchTree<T>::PostOrderTraversal(Node<T>* tempNode, void(*func)(T&)) const
{
    if (tempNode != nullptr)
    {
        PostOrderTraversal(tempNode->m_left, *func);
        PostOrderTraversal(tempNode->m_right, *func);
        (*func)(tempNode->m_data); // Function pointer to print each node
    }
}

template <class T>
bool BinarySearchTree<T>::Search(const T& dataKey) const
{
    return Search(m_root, dataKey);
}

template <class T>
bool BinarySearchTree<T>::Search(Node<T>* tempNode, const T& dataKey) const
{
    if (tempNode == nullptr) // Not found
        return false;

    if (tempNode->m_data == dataKey) // Found
        return true;

    if (tempNode->m_data < dataKey)
        return Search(tempNode->m_right, dataKey);

    if (tempNode->m_data > dataKey)
        return Search(tempNode->m_left, dataKey);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& initialiser)
{
    m_root = nullptr; // Set root node to null pointer
    m_treeSize = 0;
    Copy(initialiser, *this); // Calls copy method
}

template <class T>
bool BinarySearchTree<T>::Copy(const BinarySearchTree<T>& rhs, BinarySearchTree<T>& newBst)
{
    if (rhs.m_root != nullptr)
    {
        CopyOf(rhs.m_root, newBst); // Calls a recursive function
        return true;
    }
    return false;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::CopyOf(const Node<T>* rhs, BinarySearchTree<T>& newBst) const
{
    if (rhs != nullptr)
    {
        for (int i = 0; i < rhs->m_count; i++) // To ensure count will be correct for the copied set
        {
            newBst.Insert(rhs->m_data);
        }
        CopyOf(rhs->m_left, newBst);
        CopyOf(rhs->m_right, newBst);
        return newBst;
    }
    return newBst;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& rhs)
{
    DestroyTree(this->m_root); // Deletes 'this' pointer
    this->m_root = nullptr; // Set 'this' pointer to null pointer
    this->m_treeSize = 0;
    Copy(rhs, *this); // Calls copy method
    return *this;
}

#endif // BINARYSEARCHTREE_H_INCLUDED
