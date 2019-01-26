#include "Stack.h"
#include "ArrayList.h"

#ifndef TREEMAP
#define TREEMAP

namespace acm
{
	template<class K, class V>
	struct TreeNode
	{
		TreeNode<K, V> *left;
		TreeNode<K, V> *right;
		K key;
		V value;
		TreeNode(K, V);
	};

	template<class K, class V>
	class TreeMap
	{
		public:
			TreeMap();
			~TreeMap();
			void put(K, V);
			V get(K) const;
			bool contains(K&) const;
			void remove(K&);
			ArrayList<K> getKeys() const;
			int size() const;
		private:
			void deleteNode(TreeNode<K, V>*);
			TreeNode<K, V>* findMinimum(TreeNode<K, V>*) const;
			TreeNode<K, V>* remove(TreeNode<K, V>*, K&);
			V get(TreeNode<K, V>*, K) const;
			bool contains(TreeNode<K, V>*, K&) const;
			TreeNode<K, V>* put(TreeNode<K, V>*, K, V);
			TreeNode<K, V> *head;
			unsigned int _size;
	};

	template<class K, class V>
	TreeNode<K, V>::TreeNode(K k, V v)
		: left(nullptr), right(nullptr), key(k), value(v)
	{
		left = nullptr;
		right = nullptr;
	}

	template<class K, class V>
	TreeMap<K, V>::TreeMap()
		: head(nullptr), _size(0)
	{
	}

	template<class K, class V>
	TreeMap<K, V>::~TreeMap()
	{
		deleteNode(head);
	}

	template<class K, class V>
	void TreeMap<K, V>::put(K key, V value)
	{
		head = put(head, key, value);
	}

	template<class K, class V>
	TreeNode<K, V>* TreeMap<K, V>::put(TreeNode<K, V> *node, K key, V value)
	{
		if(node == nullptr)
		{
			node = new TreeNode<K, V>(key, value);
			_size++;
		}
		else if(key < node->key)
		{
			node->left = put(node->left, key, value);
		}
		else if(key > node->key)
		{
			node->right = put(node->right, key, value);
		}

		return node;
	}

	template<class K, class V>
	V TreeMap<K, V>::get(K key) const
	{
		return get(head, key);
	}

	template<class K, class V>
	V TreeMap<K, V>::get(TreeNode<K, V> *node, K key) const
	{
		V* value = nullptr;
		if(!node)
		{
			return *value;
		}
		if(node->key == key)
		{
			return node->value;
		}
		else if(key < node->key)
		{
			return get(node->left, key);
		}
		else
		{
			return get(node->right, key);
		}
	}

	template<class K, class V>
	bool TreeMap<K, V>::contains(K& key) const
	{
		return contains(head, key);
	}

	template<class K, class V>
	bool TreeMap<K, V>::contains(TreeNode<K, V> *node, K& key) const
	{
		if(node != nullptr)
		{
			return node->key == key || contains(node->right, key) || contains(node->left, key);
		}

		return false;
	}

	template<class K, class V>
	void TreeMap<K, V>::remove(K& key)
	{
		head = remove(head, key);
	}

	template<class K, class V>
	TreeNode<K, V>* TreeMap<K, V>::remove(TreeNode<K, V> *node, K& key)
	{
		if(node == nullptr)
		{
			return nullptr;
		}
		if(key < node->key)
		{
			node->left = remove(node->left, key);
		}
		else if(key > node->key)
		{
			node->right = remove(node->right, key);
		}
		else if(!node->left && !node->right)
		{
			TreeNode<K, V> *min = findMinimum(node->right);
			V originalValue = node->value;
			node->key = min->key;
			node->value = min->value;
			min->key = key;
			min->value = originalValue;
			node->right = delete(node->right, key);
		}
		else
		{
			delete node;
			node = (node->left) ? node->left : node->right;
			_size--;
		}

		return node;
	}

	template<class K, class V>
	TreeNode<K, V>* TreeMap<K, V>::findMinimum(TreeNode<K, V>* node) const
	{
		return (!node->left) ? node : findMinimum(node->left);
	}

	template<class K, class V>
	int TreeMap<K, V>::size() const
	{
		return _size;
	}

	template<class K, class V>
	void TreeMap<K, V>::deleteNode(TreeNode<K, V> *node)
	{
		if(node)
		{
			deleteNode(node->left);
			deleteNode(node->right);
			delete node;
		}
	}

	template<class K, class V>
	ArrayList<K> TreeMap<K, V>::getKeys() const
	{
		ArrayList<K> keys(size());
		Stack<TreeNode<K, V>*> keyStack;

		TreeNode<K, V>* currentNode = head;
		keyStack.push(currentNode);
		while(!keyStack.isEmpty())
		{
			currentNode = keyStack.pop();
			if(currentNode != nullptr)
			{
				keys.add(currentNode->key);
				keyStack.push(currentNode->left);
				keyStack.push(currentNode->right);
			}
		}

		return keys;
	}
}

#endif