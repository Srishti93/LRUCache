// LRU cache implementation

#include<iostream>
#include<deque>
#include<unordered_map>

using namespace std;

template <typename T>
class Cache
{
	T get();
	put(const T& );	
};

template<typename T>
class LRUCache: public Cache<T>
{
	private:
		std::deque<T> queue;
		std::unordered_map<T, T> map;
		
	public:	
	T get()
	{
		
	}
	put(const T& data)
	{
		
	}
};


int main()
{
	LRUCache<int> cache;
}
