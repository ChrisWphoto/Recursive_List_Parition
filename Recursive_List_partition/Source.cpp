#include <list>
#include <iostream>
using namespace std;

/*

Question II:
Write a recursive function that partitions a doubly linked list around a value x, such that all nodes
less than x come before all nodes greater than or equal to x.


Assumption:
"X" refers to an integer and only one of those values exist in the list
*/



void partition_rec(list<int> & theList, list<int>::iterator & itr, int x, bool& pivot_found){
	if (itr == theList.end())
		return;

	//push item to back if in front of "X"
	if (*itr > x && !pivot_found){
		theList.push_back(*itr);
		auto temp_itr = itr;
		partition_rec(theList, ++itr, x, pivot_found);
		theList.erase(temp_itr); //erase duplicate node After incrementing itr
	}

	//are we at the end?
	if (itr == theList.end())
		return;

	//"X" has been found stop pushing back
	if (*itr == x){
		pivot_found = true;
	}

	//Push items to front if "X" is found
	if (*itr < x && pivot_found){
		theList.push_front(*itr);
		auto tempItr = itr;
		partition_rec(theList, ++itr, x, pivot_found);
		theList.erase(tempItr);
	}
	if (itr == theList.end())
		return;

	partition_rec(theList, ++itr, x, pivot_found);
}


void partition_wrapper(list<int> & theList, int x){
	if (theList.begin() == theList.end())
		return;
	bool pivot_found = false;
	list<int>::iterator itr = theList.begin();
	partition_rec(theList, itr, x, pivot_found);
}



int main(){

	list<int> theList{ 9, 1, 4, 7, 5, 3 };

	partition_wrapper(theList, 5);

	system("pause");
}