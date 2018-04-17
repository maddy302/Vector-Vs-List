/*
 * SortedList.cpp
 *
 *  Created on: 03-Apr-2018
 *      Author: Madhukar
 */

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
    data.clear();
}

/***** Complete this file. *****/

bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = data.begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

void SortedList::prepend(const long value){
	Node x(value);
	data.push_front(x);
}

void SortedList::append(const long value){
	Node x(value);
	data.push_back(x);
}

void SortedList::insert(const long value){
list<Node>::iterator begin = data.begin();
list<Node>::iterator end = data.end();
Node x(value);

while(begin!=end){
	if(*begin<=x){
		begin++;
	}else{
		data.insert(begin,x);
		break;
	}
}
if(begin==end){
	data.push_back(x);
}

}

void SortedList::remove(const int index){
/*list<Node>::iterator begin = data.begin();
	for(int i=0;i<index;i++){
	begin++;
}
	data.erase(begin);*/
	data.pop_back();
}

void SortedList::reverse(){
/*list<Node>::iterator begin = data.begin();
list<Node>::reverse_iterator rBegin = data.rbegin();
//Node x((*begin).get_value());
for(int i=0;i<data.size()/2;i++){
	iter_swap(begin,rBegin);
	Node x = *begin;
	*begin = *rBegin;
	*rBegin = x;
	begin++;
	rBegin++;
}*/
	list<Node>::iterator begin = data.begin();
	list<Node>::iterator advance = data.begin();
	list<Node>::iterator end = data.end();
	//Node temp;
		while(begin != end)
		{
			begin++;
			data.insert(data.begin(),*begin);
			begin = data.erase(begin);

	}
}

Node& SortedList::operator [](const int index){
	list<Node>::iterator begin = data.begin();
		for(int i=0;i<index;i++){
		begin++;
	}
	return *begin;
}
