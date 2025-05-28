#include <iostream>

class My_vector{
private:
	size_t size;
	size_t capacity;
	int *data;
public:
	My_vector(){
		size = 0;
		capacity = 0;
		data = nullptr;
	}

	My_vector(size_t _size){
		size = _size;
		capacity = _size * 2;
		data = new int[capacity];
	}

	My_vector(size_t _size, int val){
		size = _size;
		capacity = _size * 2;
		data = new int[capacity];

		for(int i = 0; i < size; ++i){
			data[i] = val;
		}
	}

	~My_vector(){
		delete []data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	size_t Size(){
		return size;
	}

	size_t Capacity(){
		return capacity;
	}

	void push_back(int val){
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

	void pop_back(){
		if(size > 0){
			--size;
		}
	}
	
	void print(){
		for(int i = 0; i < size; ++i){
			std::cout<<data[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void resize(size_t new_size){
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

	void clear(){
		size = 0;
	}

};

int main()
{
	My_vector vec(3, 7);
	vec.push_back(10);
	vec.pop_back();
	vec.push_back(3);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(1);
	vec.print();
	std::cout<<"capacity - "<<vec.Capacity()<<" size - " << vec.Size()<<std::endl;
	return 0;
 
}







