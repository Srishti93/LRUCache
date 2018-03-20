// LRU cache implementation

#include<iostream>
#include<deque>
#include<unordered_map>
#include<list>

using namespace std;

template <typename T, typename K>
class Cacheable
{
	public:
	K key;
	T data;
	
	Cacheable( K k, T t):data(t),key(k) 
	{
		cout<<"key "<<key<<endl;
	}
	
	printData()
	{
		cout<<data<<endl;
	}
};

template<typename T, typename K>
class LRUCache
{
	typedef Cacheable<T, K> ItemType;
	typedef list<ItemType> Queue;
	typedef typename Queue::iterator QueueIterator;
	typedef unordered_map<K, QueueIterator> Map;
	typedef typename Map::iterator MapIterator;
	
	private:
		Queue queue;
		Map map;
		int size;
		//unordered_map<int, deque<int>::iterator> map;
		
	public:	
	LRUCache(int size):size(size)
	{
		
	}
	ItemType* get(K key)
	{
		MapIterator iter = map.find(key);
		if(iter == map.end())
		{
			return NULL;
		}
		else
		{
			queue.splice(queue.begin(), queue, iter->second);
			iter->second = queue.begin();
			return &(*(iter->second));
		}
	}
	void put(const ItemType& item)
	{
		MapIterator iter = map.find(item.key);
		if(iter != map.end())
		{
			return;
		}
		
		if(queue.size() == size)
		{
			evictLRU();
		}
		QueueIterator it = queue.begin();
		it = queue.insert(it,item);
		map.emplace(item.key, it);
	}
	
	void evictLRU()
	{
		QueueIterator it = queue.end();
		--it;
		MapIterator iter = map.find(it->key);
		
	}
	printQueue()
	{
		for(QueueIterator it = queue.begin(); it != queue.end(); ++it)
		{
			it->printData();
		}
	}
};


int main()
{
	LRUCache<int, int> cache(5);
	
	Cacheable<int,int> c(1,10);
	Cacheable<int,int> c1(2,11);
	Cacheable<int,int> c2(3,12);
	Cacheable<int,int> c3(4,13);
	cache.put(c);
	cache.put(c1);
	cache.put(c2);
	cache.put(c3);
	
	cache.printQueue();
	
	cache.get(1)->printData();
}
