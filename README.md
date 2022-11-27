# A_array
An organized generic array with so many functions to ease your work

## How to use it
#### The library comes in two forms, header file with a template class and module, which is recommended to use it with C++20 standards

```cpp

#include <iostream>
import a_array;

int main() {

	A_Array<int, 50> mylist;
	mylist.pushBack(1);
	mylist.pushBack(3);
	mylist.pushBack(7);
	mylist.pushBack(11);

	for (int i = 0; i < mylist.Size(); i++)
		std::cout << mylist.getAt(i) << "  ";		//will print 1 3 7 11
	std::cout << std::endl;

	std::cout << mylist.pullFromFront() << std::endl;		//will print 1 and decrease size
	std::cout << mylist.pullFromBack() << std::endl;		//will print 11 and decrease size
	std::cout << mylist.Size() << std::endl;			//will print 2
	mylist.pushFront(99);						//will put 99 in front

	for (int i = 0; i < mylist.Size(); i++)
		std::cout << mylist.getAt(i) << "  ";		//will print 99 3 7
	std::cout << std::endl;

	std::cout << mylist.pullFrom(1) << std::endl;			//will print 3

	for (int i = 0; i < mylist.Size(); i++)
		std::cout << mylist.getAt(i) << "  ";		//will print 99 7
	std::cout << std::endl;

	mylist.At(1) = 23;
	for (int i = 0; i < mylist.Size(); i++)
		std::cout << mylist.getAt(i) << "  ";		//will print 99 23
	std::cout << std::endl;

	//you can initialize your array using initialzer list
	A_Array<int, 10> ob1 = { 34,3422,65 };
	A_Array<int, 10>ob2 = { 43562,356,45,5,56,456,5,32,56,3 };
	ob1 = ob2;
	for (int i = 0; i < ob1.Size(); i++)
		std::cout << ob1.getAt(i) << "  ";		//will print 43562 356 45 5 56 456 5 32 56 3
	std::cout << std::endl;

	ob1.pullFromBack();

	ob1.insertAt(99, 2);
	for (int i = 0; i < ob1.Size(); i++)
		std::cout << ob1.getAt(i) << "  ";		//will print 43562 356 99 45 5 56 456 5 32 56
	std::cout << std::endl;

	ob1.pullFrom(1);
	for (int i = 0; i < ob1.Size(); i++)
		std::cout << ob1.getAt(i) << "  ";		//will print 43562 99 45 5 56 456 5 32 56
	std::cout << std::endl;

	//you can print using a direct pointer or const pointer from the array
	const int* ptr = ob1.data_const();
	for (int i = 0; i < ob1.Size(); i++)
		std::cout << ptr[i] << "  ";		//will print 43562 99 45 5 56 456 5 32 56
	std::cout << std::endl;

	std::cout << ob1.accumulate() << std::endl;	//will print sum of all elements 44316 in case all operators are ready to print!!

	ob1 = std::move(ob2);
	for (int i = 0; i < ob2.Size(); i++)
		std::cout << ob2.getAt(i) << "  ";		//will print nothing ob2 now is empty
	std::cout << std::endl;

	return 0;
}
```
