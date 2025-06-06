#ifndef VECTOR_HPP
#define VECTOR_HPP

class My_vector{
public:
	My_vector();
	My_vector(size_t);
	My_vector(size_t, int);
	~My_vector();

	My_vector(const My_vector&);
	My_vector& operator=(const My_vector&);

	size_t Size();
	size_t Capacity();

	void push_back(int);
	void pop_back();
	void print();
	void resize(size_t);
	void clear();

private:
	size_t size;
	size_t capacity;
	int *data;
};

#endif
