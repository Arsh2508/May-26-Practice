#include <iostream>
#include "vector.hpp"

My_vector::My_vector() 
	: size{0}
	, capacity{0}
	, data{nullptr} 
{}

My_vector::My_vector(size_t _size)
	: size{_size}
	, capacity{_size * 2}
	, data{new int[capacity]}
{}

My_vector::My_vector(size_t _size, int val)
	: size{_size}
	, capacity{_size * 2}
	, data{new int[capacity]}
{
	for(size_t i = 0; i < size; ++i){
		data[i] = val;
	}
}

// copy ctor
My_vector::My_vector(const My_vector& other)	
	: size{other.size}, capacity{other.capacity}, data{nullptr}{

	if(other.data == nullptr){
		return;
	}
	
	data = new int[capacity];

	for(size_t i = 0; i < size; ++i){
		data[i] = other.data[i];
	}

}

// copy assignment operator
My_vector& My_vector::operator=(const My_vector& other){
	if(&other == this){
		return *this;
	}

	delete []data;
	
	capacity = other.capacity; 
	data = new int[capacity];
	size = other.size;

	for(size_t i = 0; i < size; ++i){
		data[i] = other.data[i];
	}

	return *this;
}

// move ctor
My_vector::My_vector(My_vector&& other)
	: size{other.size}
	, capacity{other.capacity}
	, data{other.data}
{
	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

//move assignment operator
My_vector& My_vector::operator=(My_vector&& rhs){
	if(this == &rhs){
		return *this;
	}
	size = rhs.size;
	capacity = rhs.capacity;
	delete []this->data;
	data = rhs.data;

	rhs.data = nullptr;
	rhs.size = 0;
	rhs.capacity = 0;

	return *this;
}

My_vector::~My_vector(){
	delete []data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

size_t My_vector::Size() const{
	return size;
}

size_t My_vector::Capacity() const{
	return capacity;
}

void My_vector::push_back(const int val){
	if((size + 1) > capacity){
		capacity = capacity == 0 ? 1 : size * 2;
		int * tmp = new int[capacity];
		for(int i = 0; i < size; ++i){
			tmp[i] = data[i];		//copying old data
		}
		delete []data;
		data = tmp;
	}
	data[size++] = val;		
}


void My_vector::pop_back(){
	if(size > 0){
		--size;
	}
}
	
void My_vector::print() const{
	for(int i = 0; i < size; ++i){
		std::cout<<data[i]<<" ";
	}
	std::cout<<std::endl;
}

void My_vector::resize(size_t new_size){
	if(new_size > size){
		if(capacity < new_size){
			capacity = new_size * 2;
			int * tmp = new int[capacity];

			for(int i = 0; i < size; ++i){
				tmp[i] = data[i];	
			}
			delete []data;
				data = tmp;
		}
	}	
	size = new_size;
}

void My_vector::clear(){
	size = 0;
}
