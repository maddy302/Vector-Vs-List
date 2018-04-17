/*
 * Node.cpp
 *
 *  Created on: 03-Apr-2018
 *      Author: Madhukar
 */

#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::assign_count;
long Node::destructor_count;

/***** Complete this file. *****/
Node::Node(const long the_value){
this->value = the_value;
constructor_count++;
}


Node::Node(const Node& x){
this->value = x.get_value();
copy_count++;
}

Node& Node::operator =(const Node& rhs){
	this->value = rhs.get_value();
	assign_count++;
	return *this;
}

 Node::~Node(){
//	/this = nullptr;
	destructor_count++;
}

long Node::get_value() const{
	return this->value;
}

 long Node::get_constructor_count(){
	return constructor_count;
}

 long Node::get_assign_count(){
	return assign_count;
}

 long Node::get_copy_count(){
	return copy_count;
}

 long Node::get_destructor_count(){
	return destructor_count;
}

 void Node::reset(){
	constructor_count = 0;
	assign_count = 0;
	copy_count = 0;
	destructor_count = 0;
}

bool Node::operator ==(const Node& rhs) const{
return this->value==rhs.get_value();
}

bool Node::operator <=(const Node& rhs)const{
	return this->value <= rhs.get_value();
}

bool Node::operator >=(const Node& rhs)const{
	return this->value >= rhs.get_value();
}
