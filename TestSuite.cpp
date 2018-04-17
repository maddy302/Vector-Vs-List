/*
 * TestSuite.cpp
 *
 *  Created on: 03-Apr-2018
 *      Author: Madhukar
 */
#include<iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

/***** Complete this file. *****/

void vector_appends(SortedVector& sv, const int size)
{
    for (int i = 0; i < size; i++) sv.append(i);
}

void list_appends(SortedList& sl, const int size)
{
    for (int i = 0; i < size; i++) sl.append(i);
}

void vector_prepends(SortedVector& sv,const int size){
for(long i=size-1;i>=0;i--){
sv.prepend(i);
}
}

void list_prepends(SortedList& sl, const int size){
	 for (int i = size-1; i>=0; i--) sl.prepend(i);
}

void vector_gets(SortedVector& sv, const int size) throw(string)
{
    /***** Complete this function. *****/

    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();
//cout<<"The size of the vector is"<<sv.data.size();
    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()% size ;
       // Node x = sv.data.at(index);
        long value =  sv.data.at(index).get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw(string)
{
    /***** Complete this function. *****/

    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
/*        int index = ... rand() ... ;
        long value = ... ;*/
    	int index = rand()% size ;
    	//Node x = sl[index];
    	        long value = sl[index].get_value() ;

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

void vector_inserts(SortedVector& sv, const int size) throw(string)
{
    /***** Complete this function. *****/
	for(int i=0;i<size;i++){
		sv.insert(rand()%size);
		//sv.insert(i);
	}
    if (!sv.check()) throw("Vector sort error!");
}

void list_inserts(SortedList& sl, const int size) throw(string)
{
    /***** Complete this function. *****/
	for(int i=0;i<size;i++){
			//sv.insert(rand()%size);
			sl.insert(i);
		}
    if (!sl.check()) throw("List sort error!");
}

void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    /***** Complete this function. *****/
    for(int i=0;i<size;i++){
    	sv.remove(i);
    }
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    /***** Complete this function. *****/
    for(int i=0;i<size;i++){
       	sl.remove(i);
       }
}

void vector_reverse(SortedVector& sv, const int size) throw(string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    /***** Complete this function. *****/
    sv.reverse();

    if (!sv.check_reversed()) throw("Vector reverse sort error!");
}

void list_reverse(SortedList& sl, const int size) throw(string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    /***** Complete this function. *****/

    sl.reverse();
    if (!sl.check_reversed()) throw("List reverse sort error!");
}
