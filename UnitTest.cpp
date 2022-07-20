#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BinarySearchTree.h"
#include "Date.h"
#include "Time.h"

using namespace std;

void DateCompareCheck();
void TimeCompareCheck();
void BSTCheck();
void IntFileBstCheck();
bool AssignmentOneCheck();
void Print(int &x);
void Print(float &x);
void PrintCount(int &x, unsigned &y);
void PrintCount(float& x, unsigned& y);
void GetSumAndCount(int& data, int& totalSum, unsigned& count, unsigned& totalCount);
void GetSumAndCount(float& data, float& totalSum, unsigned& count, unsigned& totalCount);

int main()
{
    //DateCompareCheck();
    //TimeCompareCheck();
    BSTCheck();
    return 0;
}

void DateCompareCheck()
{
    //DATE COMPARISON CHECK
    cout << "==================" << endl
         << "   Year Check" << endl
         << "=================="  << endl;
    Date tempDate1(1,1,2022);
    Date tempDate2(1,1,2022);
    cout << "Date 1: " << tempDate1 << endl
         << "Date 2: " << tempDate2 << endl
         << "===Test ID 1===\nDate 1 == Date 2" << endl;
    if (tempDate1 == tempDate2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    tempDate2.SetYear(2023);
    cout << "\nDate 1: " << tempDate1 << endl
         << "Date 2: " << tempDate2 << endl
         << "===Test ID 2===\nDate 1 == Date 2" << endl;
    if (tempDate1 == tempDate2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    cout << "===Test ID 3===\nDate 1 > Date 2" << endl;
    if (tempDate1 > tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 4===\nDate 2 > Date 1" << endl;
    if (tempDate2 > tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 5===\nDate 1 < Date 2" << endl;
    if (tempDate1 < tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 6===\nDate 2 < Date 1" << endl;
    if (tempDate2 < tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    cout << "\n==================" << endl
         << "   Month Check" << endl
         << "=================="  << endl;
    tempDate2.SetYear(2022);
    tempDate2.SetMonth(2);
    cout << "\nDate 1: " << tempDate1 << endl
         << "Date 2: " << tempDate2 << endl
         << "===Test ID 7===\nDate 1 == Date 2" << endl;
    if (tempDate1 == tempDate2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    cout << "===Test ID 8===\nDate 1 > Date 2" << endl;
    if (tempDate1 > tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 9===\nDate 2 > Date 1" << endl;
    if (tempDate2 > tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 10===\nDate 1 < Date 2" << endl;
    if (tempDate1 < tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 11===\nDate 2 < Date 1" << endl;
    if (tempDate2 < tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    cout << "\n==================" << endl
         << "   Day Check" << endl
         << "=================="  << endl;
    tempDate2.SetMonth(1);
    tempDate2.SetDay(2);
    cout << "\nDate 1: " << tempDate1 << endl
         << "Date 2: " << tempDate2 << endl
         << "===Test ID 12===\nDate 1 == Date 2" << endl;
    if (tempDate1 == tempDate2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    cout << "===Test ID 13===\nDate 1 > Date 2" << endl;
    if (tempDate1 > tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 14===\nDate 2 > Date 1" << endl;
    if (tempDate2 > tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 15===\nDate 1 < Date 2" << endl;
    if (tempDate1 < tempDate2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 16===\nDate 2 < Date 1" << endl;
    if (tempDate2 < tempDate1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}

void TimeCompareCheck()
{
    //TIME COMPARISON CHECK
    cout << "==================" << endl
         << "   Hour Check" << endl
         << "=================="  << endl;
    Time tempTime1(10,30);
    Time tempTime2(10,30);
    cout << "Time 1: " << tempTime1 << endl
         << "Time 2: " << tempTime2 << endl
         << "===Test ID 1===\nTime 1 == Time 2" << endl;
    if (tempTime1 == tempTime2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    tempTime2.SetHour(11);
    cout << "\nTime 1: " << tempTime1 << endl
         << "Time 2: " << tempTime2 << endl
         << "===Test ID 2===\nTime 1 == Time 2" << endl;
    if (tempTime1 == tempTime2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    cout << "===Test ID 3===\nTime 1 > Time 2" << endl;
    if (tempTime1 > tempTime2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 4===\nTime 2 > Time 1" << endl;
    if (tempTime2 > tempTime1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 5===\nTime 1 < Time 2" << endl;
    if (tempTime1 < tempTime2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 6===\nTime 2 < Time 1" << endl;
    if (tempTime2 < tempTime1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    cout << "==================" << endl
         << "   Minute Check" << endl
         << "=================="  << endl;
    tempTime2.SetHour(10);
    tempTime2.SetMinute(40);
    cout << "Time 1: " << tempTime1 << endl
         << "Time 2: " << tempTime2 << endl
         << "===Test ID 7===\nTime 1 == Time 2" << endl;
    if (tempTime1 == tempTime2){
            cout << "True" << endl;
    }
    else{
            cout << "False" << endl;
    }
    cout << "===Test ID 8===\nTime 1 > Time 2" << endl;
    if (tempTime1 > tempTime2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 9===\nTime 2 > Time 1" << endl;
    if (tempTime2 > tempTime1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 10===\nTime 1 < Time 2" << endl;
    if (tempTime1 < tempTime2){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "===Test ID 11===\nTime 2 < Time 1" << endl;
    if (tempTime2 < tempTime1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}

void BSTCheck()
{
    BinarySearchTree<int> intTree;
    BinarySearchTree<float> floatTree;

    //INSERTION CHECK
    cout << "=================================================================" << endl
         << "                        Insertion Check" << endl
         << "=================================================================" << endl;
    if (intTree.Insert(5)){
        cout << "\n===Test ID 1===" << endl;
        cout << "\nSuccessful" << endl;
    }
    else{
        cout << "\n===Test ID 1===" << endl;
        cout << "\nUnsuccessful" << endl;
    }
    if (floatTree.Insert(2.3)){
        cout << "\n===Test ID 2===" << endl;
        cout << "\nSuccessful" << endl;
    }
    else{
        cout << "\n===Test ID 2===" << endl;
        cout << "\nUnsuccessful" << endl;
    }

    //THREE TRAVERSAL AND TREESIZE CHECK
    cout << "\n=================================================================" << endl
         << "                Three Traversal and TreeSize Check" << endl
         << "=================================================================" << endl;
    int intArray[] = {10, 53, 2, 105, 53, 1, 53, 4, 120, 3};
    float floatArray[] = {5.1, 1.2, 10.4, 100.2, 3.5, 4.2, 2.3, 1.1, 35.2, 2.3};

    for(int i = 0; i < 10; i++){
        intTree.Insert(intArray[i]);
        floatTree.Insert(floatArray[i]);
    }
    //INTEGER TREE
    cout << "---------------INTEGER TREE---------------" << endl;
    cout << "\n===Test ID 3===" << endl;
    cout << "\nIn-Order Traversal for int tree: ";
    intTree.InOrderTraversal(Print);
    cout << "\n\n===Test ID 4===" << endl;
    cout << "\nPre-Order Traversal for int tree: ";
    intTree.PreOrderTraversal(Print);
    cout << "\n\n===Test ID 5===" << endl;
    cout << "\nPost-Order Traversal for int tree: ";
    intTree.PostOrderTraversal(Print);
    cout << "\n\n===Test ID 6===" << endl;
    cout << "\nInteger tree Size: " << intTree.GetSize() << endl;

    //FLOAT TREE
    cout << "\n---------------FLOAT TREE---------------" << endl;
    cout << "\n===Test ID 7===" << endl;
    cout << "\nIn-Order Traversal for float tree: ";
    floatTree.InOrderTraversal(Print);
    cout << "\n\n===Test ID 8===" << endl;
    cout << "\nPre-Order Traversal for float tree: ";
    floatTree.PreOrderTraversal(Print);
    cout << "\n\n===Test ID 9===" << endl;
    cout << "\nPost-Order Traversal for float tree: ";
    floatTree.PostOrderTraversal(Print);
    cout << "\n\n===Test ID 10===" << endl;
    cout << "\nFloat tree Size: " << floatTree.GetSize() << endl;

    //COPY CHECK
    cout << "\n=================================================================" << endl
         << "                          Copy Check" << endl
         << "=================================================================" << endl;
    cout << "---------------INTEGER TREE---------------" << endl;
    BinarySearchTree<int> intTree2;
    intTree2 = intTree;
    BinarySearchTree<int> intTree3(intTree);
    cout << "\n===Test ID 11===" << endl;
    cout << "\nIn-Order Traversal for int tree 1: " << endl;
    intTree.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for int tree 1: " << endl;
    intTree.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for int tree 1: " << endl;
    intTree.PostOrderTraversal(Print);
    cout << '\n' << "Tree 1 address: " << &intTree << endl;
    cout << "Tree 1 Size: " << intTree.GetSize() << endl;

    cout << '\n' << "In-Order Traversal for int tree 2: " << endl;
    intTree2.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for int tree 2: " << endl;
    intTree2.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for int tree 2: " << endl;
    intTree2.PostOrderTraversal(Print);
    cout << '\n' << "Tree 2 address: " << &intTree2 << endl;
    cout << "Tree 2 Size: " << intTree2.GetSize() << endl;

    cout << "\n===Test ID 12===" << endl;
    cout << '\n' << "In-Order Traversal for int tree 3: " << endl;
    intTree3.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for int tree 3: " << endl;
    intTree3.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for int tree 3: " << endl;
    intTree3.PostOrderTraversal(Print);
    cout << '\n' << "Tree 3 address: " << &intTree3 << endl;
    cout << "Tree 3 Size: " << intTree3.GetSize() << endl;

    cout << "\n---------------FLOAT TREE---------------" << endl;
    BinarySearchTree<float> floatTree2;
    floatTree2 = floatTree;
    BinarySearchTree<float> floatTree3(floatTree);
    cout << "\n===Test ID 13===" << endl;
    cout << "\nIn-Order Traversal for float tree 1: " << endl;
    floatTree.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for float tree 1: " << endl;
    floatTree.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for float tree 1: " << endl;
    floatTree.PostOrderTraversal(Print);
    cout << '\n' << "Tree 1 address: " << &floatTree << endl;
    cout << "Tree 1 Size: " << floatTree.GetSize() << endl;

    cout << '\n' << "In-Order Traversal for float tree 2: " << endl;
    floatTree2.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for float tree 2: " << endl;
    floatTree2.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for float tree 2: " << endl;
    floatTree2.PostOrderTraversal(Print);
    cout << '\n' << "Tree 2 address: " << &floatTree2 << endl;
    cout << "Tree 2 Size: " << floatTree2.GetSize() << endl;

    cout << "\n===Test ID 14===" << endl;
    cout << '\n' << "In-Order Traversal for float tree 3: " << endl;
    floatTree3.InOrderTraversal(Print);
    cout << '\n' << "Pre-Order Traversal for float tree 3: " << endl;
    floatTree3.PreOrderTraversal(Print);
    cout << '\n' << "Post-Order Traversal for float tree 3: " << endl;
    floatTree3.PostOrderTraversal(Print);
    cout << '\n' << "Tree 3 address: " << &floatTree3 << endl;
    cout << "Tree 3 Size: " << floatTree3.GetSize() << endl;

    //DELETION CHECK
    cout << "\n=================================================================" << endl
         << "                        Deletion Check" << endl
         << "=================================================================" << endl;
    cout << "---------------INTEGER TREE---------------" << endl;
    //NO CHILD
    cout << "\n===Test ID 15===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    intTree2.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree2.GetSize() << endl;
    cout << "\nDeleting the value: 3 (no child)";
    if(intTree2.Delete(3)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    intTree2.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree2.GetSize() << endl;

    //ONE LEFT CHILD
    BinarySearchTree<int> intTree4;
    intTree4 = intTree;
    cout << "......................................." << endl
         << "\n===Test ID 16===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    intTree4.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree4.GetSize() << endl;
    cout << "\nDeleting the value: 4 (one left child)";
    if(intTree4.Delete(4)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    intTree4.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree4.GetSize() << endl;

    //ONE RIGHT CHILD
    BinarySearchTree<int> intTree5;
    intTree5 = intTree;
    cout << "......................................." << endl
         << "\n===Test ID 17===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    intTree5.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree5.GetSize() << endl;
    cout << "\nDeleting the value: 53 (one right child)";
    if(intTree5.Delete(53)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    intTree5.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree5.GetSize() << endl;

    //TWO CHILD
    BinarySearchTree<int> intTree6;
    intTree6 = intTree;
    cout << "......................................." << endl
         << "\n===Test ID 18===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    intTree6.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree6.GetSize() << endl;
    cout << "\nDeleting the value: 5 (two child)";
    if(intTree6.Delete(5)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    intTree6.PreOrderTraversal(Print);
    cout << "\nTree Size: " << intTree6.GetSize() << endl;

    cout << "\n---------------FLOAT TREE---------------" << endl;
    //NO CHILD
    cout << "\n===Test ID 19===" << endl
         << "Before deletion, Pre-Order Traversal: ";
    floatTree2.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree2.GetSize() << endl;
    cout << "\nDeleting the value: 1.1 (no child)";
    if(floatTree2.Delete(1.1)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    floatTree2.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree2.GetSize() << endl;

    //ONE LEFT CHILD
    BinarySearchTree<float> floatTree4;
    floatTree4 = floatTree;
    cout << "......................................." << endl
         << "\n===Test ID 20===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    floatTree4.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree4.GetSize() << endl;
    cout << "\nDeleting the value: 100.2 (one left child)";
    if(floatTree4.Delete(100.2)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    floatTree4.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree4.GetSize() << endl;

    //ONE RIGHT CHILD
    BinarySearchTree<float> floatTree5;
    floatTree5 = floatTree;
    cout << "......................................." << endl
         << "\n===Test ID 21===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    floatTree5.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree5.GetSize() << endl;
    cout << "\nDeleting the value: 3.5 (one right child)";
    if(floatTree5.Delete(3.5)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    floatTree5.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree5.GetSize() << endl;

    //TWO CHILD
    BinarySearchTree<float> floatTree6;
    floatTree6 = floatTree;
    cout << "......................................." << endl
         << "\n===Test ID 22===" << endl
         << "\nBefore deletion, Pre-Order Traversal: ";
    floatTree6.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree6.GetSize() << endl;
    cout << "\nDeleting the value: 2.3 (two child)";
    if(floatTree6.Delete(2.3)){
        cout << "\nDeletion successful" << endl;
    }
    else{
        cout << "\nDeletion unsuccessful" << endl;
    }
    cout << "\nAfter deletion, Pre-Order Traversal: ";
    floatTree6.PreOrderTraversal(Print);
    cout << "\nTree Size: " << floatTree6.GetSize() << endl;

    //SEARCH CHECK
    cout << "\n=================================================================" << endl
         << "                        Search Check" << endl
         << "=================================================================" << endl;
    cout << "---------------INTEGER TREE---------------" << endl;
    cout << "\n===Test ID 23===" << endl
         << "\nPerforming search for 53:" << endl;
    if(intTree.Search(53)){
        cout <<"Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "\n===Test ID 24===" << endl
         << "\nPerforming search for 17:" << endl;
    if(intTree.Search(17)){
        cout <<"Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    cout << "\n---------------FLOAT TREE---------------" << endl;
    cout << "\n===Test ID 25===" << endl
         << "\nPerforming search for 3.5:" << endl;
    if(intTree.Search(3.5)){
        cout <<"Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "\n===Test ID 26===" << endl
         << "\nPerforming search for 202.3:" << endl;
    if(intTree.Search(202.3)){
        cout <<"Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    //CALCULATION TEST
    cout << "\n=================================================================" << endl
         << "                        Counter Check" << endl
         << "=================================================================" << endl;
    cout << "---------------INTEGER TREE---------------" << endl;
    cout << "\n===Test ID 27===" << endl;
    intTree.InOrderTraversalCount(PrintCount);

    cout << "\n\n---------------FLOAT TREE---------------" << endl;
    cout << "\n===Test ID 28===" << endl;
    floatTree.InOrderTraversalCount(PrintCount);
    cout << endl;
}

void Print(int& x)
{
    cout << x << " ";
}

void Print(float& x)
{
    cout << x << " ";
}

void PrintCount(int& x, unsigned& y)
{
    cout << x << "(" << y << ") ";
}

void PrintCount(float& x, unsigned& y)
{
    cout << x << "(" << y << ") ";
}

void GetSumAndCount(int& data, int& totalSum, unsigned& count, unsigned& totalCount) // Pointer function to get total sum and total count
{
    totalSum += (data * count);
    totalCount += count;
}

void GetSumAndCount(float& data, float& totalSum, unsigned& count, unsigned& totalCount) // Pointer function to get total sum and total count
{
    totalSum += (data * count);
    totalCount += count;
}
