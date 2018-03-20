// LRU cache implementation

#include<iostream>
#include<deque>
#include<unordered_map>
#include<list>

using namespace std;

template <typename T, typename K>
class Cacheable
{
	K key;
	T data;
};

template<typename T, typename K>
class LRUCache
{
	typedef Cacheable<T, K> ItemType;
	typedef deque<ItemType> Queue;
	typedef typename Queue::iterator Pointer;
	
	private:
		Queue queue;
		unordered_map<K, Pointer> map;
		//unordered_map<int, deque<int>::iterator> map;
		
	public:	
	ItemType& get(K key)
	{
		if(map.find(key) == map.end())
		{
			
		}
	}
	put(const ItemType& item)
	{
		
	}
};


int main()
{
	LRUCache<int, int> cache;
}
