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
	

My_vector::~My_vector(){
	delete []data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

size_t My_vector::Size(){
	return size;
}

size_t My_vector::Capacity(){
	return capacity;
}

void My_vector::push_back(int val){
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
	
void My_vector::print(){
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




