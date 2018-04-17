/*
 * SortedVector.cpp
 *
 *  Created on: 03-Apr-2018
 *      Author: Madhukar
 */

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
	Node::reset();
}

SortedVector::~SortedVector()
{
	Node::reset();
	data.clear();
}

/***** Complete this file. *****/


bool SortedVector::check() const
{
	if (size() == 0) return true;

	vector<Node>::const_iterator it = data.begin();
	vector<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is greater than or equal to the previous node.
	while ((it != end()) && (*it >= *prev))
	{
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
	if (size() == 0) return true;

	vector<Node>::const_iterator it = begin();
	vector<Node>::const_iterator prev = it;

	it++;

	// Ensure that each node is less than or equal to the previous node.
	while ((it != end()) && (*it <= *prev))
	{
		prev = it;
		it++;
	}

	return it == end();  // Good if reached the end.
}

void SortedVector::prepend(const long value){
	//vector<Node>::iterator start = data.begin();
	const Node x(value);
	//data.insert(start,x);
	data.insert(data.begin(), x);
	//data.push_back(x);
}

void SortedVector::append(const long value){

	const Node x(value);
	data.push_back(x);
}

void SortedVector::insert(const long value){

	vector<Node>::iterator begin,end;
	begin = data.begin();
	end = data.end();
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

void SortedVector::remove(const int index){
	/*vector<Node>::iterator x = data.begin();
	while(index>0 && iterator!=data.end()){
		x++;
	}*/
	//data.erase(data.begin()+index);
/*	vector<Node>::iterator begin = data.begin();
		for(int i=0;i<index;i++){
		begin++;
	}*/
		//data.pop_back();
	data.erase(data.begin()+index);
}

void SortedVector::reverse(){
/*
vector<Node>::iterator begin = data.begin();
vector<Node>::reverse_iterator rBegin = data.rbegin();
*/

/*for(int i=0;i<data.size()/2;i++){
	iter_swap(begin,rBegin);
	begin++;
	rBegin++;
}*/
vector<Node>::iterator begin = data.begin();
vector<Node>::iterator advance = data.begin();
vector<Node>::iterator end = data.end();
//Node temp;
	while(begin != end)
	{
		begin++;
		data.insert(data.begin(),*begin);
		begin = data.erase(begin);

}


}
