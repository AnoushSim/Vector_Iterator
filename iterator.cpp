#include <iostream>


template <typename T>
class Vector
{
public:
    Vector (const int size = 100);
   ~Vector ();
    Vector (const Vector & src);
    
    T* begin();
    T* end();
    
    Vector& operator= (const Vector & rhs);
  void push_back (T element);
  void insert_at (int pos, T element);
  T get_at (int pos);
  int get_size ();
  void showVector () const;
  
  
  class Iterator {
    
    public:
    Iterator(T*);
    Iterator( const Iterator& );
    Iterator& operator=(const Iterator&);
    T& operator*(); 
    Iterator& operator++();
    Iterator operator++(int );
    Iterator& operator--();
    Iterator operator--(int );
    bool operator<=(const Iterator& );
    
    private:
    T* _it;
    
    
  };
  
  
private:
  T* m_arr;
  int m_size;
  int m_index;
};

//Iterator functions

template <typename T>
Vector<T>::Iterator::Iterator(T* ptr) {
  _it = ptr;
}

template <typename T>
Vector<T>::Iterator::Iterator(const typename Vector<T>::Iterator& src) {
  _it = src._it;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator=(const typename Vector<T>::Iterator& rhs) {
  _it = rhs._it;
}

template <typename T>
T& Vector<T>::Iterator::operator*() {
return *_it;  
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
  _it++;
  return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int n) {
  Iterator tmp = *this;
  _it++;
  return tmp;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--() {
  _it--;
  return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int n) {
  Iterator tmp = *this;
  _it--;
  return tmp;
}

template <typename T>
bool Vector<T>::Iterator::operator<=(const typename Vector<T>::Iterator& it) {
	 return _it <= it._it;
}

//Vector class functions

template <typename T>
Vector<T>::Vector(const int size ) {
  m_size = size;
  
  if(size < 1) {
    std::cout << "Size must be positive number!";
    return;
  }
  
  m_arr = new T [size];
  m_index = -1;
}

template <typename T>
Vector<T>::~Vector() {
  delete [] m_arr;
  m_arr = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector& src) {
  m_size = src.m_size;
  m_index = src.m_index;
  T* newVec = new T[m_size];
  for(int ix = 0; ix < m_index; ++ix) 
       newVec[ix] = src.m_arr[ix];
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs) {
  if(this == &rhs) {
    return *this;
  }
  m_size = rhs.m_size;
  m_index = rhs.m_index;
  T* newVec = new T[m_size];
  for(int ix = 0; ix < m_index; ++ix) 
       newVec[ix] = rhs.m_arr[ix];
  return *this;
}

template <typename T>
T* Vector<T>::begin() {
  return &m_arr[0];
}

template <typename T>
T* Vector<T>::end() {
  return &m_arr[m_index];
}

template <typename T>
void Vector<T>::push_back(T element) {
  if(m_index == m_size - 1) {
    {
      T* tmp = new T[2 * m_size];
      for (int ix = 0; ix < m_index; ++ix)
	       tmp[ix] = m_arr[ix];
      delete[]m_arr;
      m_arr = tmp;
      m_size *= 2;
    }
  m_arr[++m_index] = element;
  }
}

template <typename T>
void Vector<T>::insert_at(int pos, T element) {
  T* newarray = new T[m_size];
	int current = 0;
	for (int ix = 0; ix <= m_index; ++ix) {
		if (ix == pos) {
			newarray[pos] = element;
			++m_index;
		}
		else{
		newarray[ix] = m_arr[current];
		current++;
		}
	}
	for (int ix = 0; ix <= m_index; ++ix) {
		m_arr[ix] = newarray[ix];
	}
}

template <typename T>
T Vector<T>::get_at(int pos) {
  if (pos < 0 || pos > m_index) {
    std::cout << "Out of range!" <<std::endl;
    return -1;
  }
  return m_arr[pos];
}

template <typename T>
int Vector<T>::get_size() {
  return m_index + 1;
}

template <typename T> 
void Vector<T>::showVector() const
{
  std::cout << "Your Vector content is: " << std::endl;
  for (int ix = 0; ix < m_index; ++ix)
      std::cout << m_arr[ix] << std::endl;
}

template <typename T>
void showVec(T begin, T end) {
        for(auto it = begin; it <= end; ++it) {
                std::cout << *it << std::endl;
        }
}


int main() {
	Vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	Vector<int>::Iterator begin = vector.begin();
	Vector<int>::Iterator end = vector.end();

	showVec(begin,end);
}
