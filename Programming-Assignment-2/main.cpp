int main() {
    int a[] = {10,45,23,67,89,34,12,99};
    Data* newData = new Data(a[0]);
    BinarySearchTree<Data>* newBST = new BinarySearchTree<Data>(a[0]);
    for(int i=1;i< (sizeof(a)/sizeof(int));i++)
    {
        newData = new Data(a[i]);
        newBST->insertElement(newData);
    }
    newBST->print();
    newBST->findSmallest();
    newBST->findBiggest();
    NewData = new Data(10);
    newBST->deleteElement(newData); // delete root
    newBST->print();
    NewData = new Data(45);
    newBST->deleteElement(newData); //delete with two children
    newBST->print();
    NewData = new Data(12);
    newBST->deleteElement(newData); //delete with one child
    newBST->print();
    NewData = new Data(10);
    newBST->deleteElement(newData); // delete a number that doesnt exist. What will you print?
    newBST->print();
    newBST->findKthElement(1); //first element
    newBST->findKthElement(newBST->getnumberOfElements()); //last element
    newBST->findKthElement(3); // some element in between
    newBST->findKthElement(7); // Edge case where item does not exist. What will you print?
    newBST->findSmallest();
    newBST->findBiggest();
    newBST->sortAscending();
    newBST->sortDescending();
    return 0;
}
Expected Output :
10, 45, 23, 12, 34, 67, 89, 99
CS210 Manju Muralidharan
4
10
99
45, 23, 12, 34, 67, 89, 99
34, 23, 12, 67, 89, 99
34, 23, 67, 89, 99
Number does not exist
34, 23, 67, 89, 99
23
99
67
Number does not exist
23
99
23, 34, 67, 89, 99
99, 89, 67, 34, 23