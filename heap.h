#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap{
public:
  Heap(int m=2, PComparator c = PComparator());
  ~Heap();
  void push(const T& item);
  T const & top() const;
  void pop();
  bool empty() const;
  size_t size() const;
private:
	vector<T> elements;
  int mAry;
	PComparator comparator;
};

// MEMBER FUNCTIONS
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
	mAry = m;
	comparator = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	return elements.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return elements.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	elements.push_back(item);

	if(elements.size() == 1){
		return;
	}

	int child =  elements.size() - 1;
	int parent = (child - 1) / mAry;

	if(parent < 0){
		parent = 0;
	}
	while(comparator(elements[child], elements[parent])){
		T a = elements[parent];
		elements[parent] = elements[child];
		elements[child] = a;
		child = parent;
		parent = (child - 1) / mAry;
		if(child == 0){
			break;
		}
		if(parent < 0){
			parent = 0;
		}
  }
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(elements.empty()){
		throw std::out_of_range("Empty heap!");
  }
  else{
    return elements[0];
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
	if(elements.empty()){
		throw std::out_of_range("heap is empty");
  }
	else{
		elements[0] = elements[elements.size() - 1];
		elements.pop_back();

		if(elements.size() == 0){
			return;
		}

		int parent = 0;
		int child = parent * mAry + 1;
		int bestChild = child;
		

		bool keepGoing = true;
		while(keepGoing){
			T bestChildVal = elements[child];
			bestChild = child;
			for(int i = child + 1; i <= child + mAry; i++){
				if(i >= elements.size()){
					break;
				}
				if(comparator(elements[i], bestChildVal)){
					bestChild = i;
					bestChildVal = elements[i];
				}
			}
			if(comparator(elements[bestChild], elements[parent])){
				T temp = elements[parent];
				elements[parent] = elements[bestChild];
				elements[bestChild] = temp;

				parent = bestChild;
				child = parent * mAry + 1;
				if(child >= elements.size()){
					keepGoing = false;
				}
			}
			else{
				keepGoing = false;
			}
		}
	}
}

#endif

