#pragma once
#include <iostream>
#include <string>
using namespace std;
	template <class I, class S>
class tree {
	struct noda {
		I key;
		S data;
		noda* left = nullptr;
		noda* right = nullptr;
		noda(I _key = I(), S _data = S());
	};
	int count = 0;
	noda* root = nullptr;
	void clear(noda* _root);
	void add(const I _key, const S _data, noda* _root);
	void copy(noda* _root);
	void output(ostream& out, noda* _root);
	void output_bin(ofstream& out, noda* _root); // for binary write
	noda* new_noda(const I _key, const S _data) {
		noda* new_n = new noda(_key, _data);
		return new_n;
	}
	noda* find(const I _key, noda* _root) {
		if (_root == nullptr)return nullptr;
		else if (_key > _root->key)find(_key, _root->right);
		else if (_key < _root->key)find(_key, _root->left);
		else if (_key == _root->key)return _root;
	}
public:
	tree();
	tree(const tree& obj);
	tree<I, S>& operator=(const tree<I, S>& obj);
	void add(const I _key, const S _data);
	S* find(I _key);
	void clear();
	int size();
	bool empty();
	~tree();
	void output(ostream& out);
	void output_bin(ofstream& out); // for binry write
	template<class I, class S>
	friend ostream& operator<<(ostream& out, const tree<I, S>& obj);
};

template<class I, class S>
inline void tree<I, S>::clear(noda* _root)
{
	if (_root == nullptr) {
		return;
	}
	if (count == 1) {
		delete _root;
		_root = nullptr;
		count--;
	}
	else if (_root->left != nullptr && _root->left->left == nullptr && _root->left->right == nullptr) {
		delete _root->left;
		_root->left = nullptr;
		count--;
	}
	else if (_root->right != nullptr && _root->right->left == nullptr && _root->right->right == nullptr) {
		delete _root->right;
		_root->right = nullptr;
		count--;
	}
	else {
		clear(_root->left);
		clear(_root->right);
	}
}

template<class I, class S>
inline void tree<I, S>::add(const I _key, const S _data, noda* _root)
{
	if (_key == _root->key) {
		cerr << "!";
		_root->data = _data;
	}
	else if (_key < _root->key) {
		if (_root->left == nullptr) {
			noda* _new = new noda(_key, _data);
			_root->left = _new;
			count++;

		}
		else {
			add(_key, _data, _root->left);
		}
	}
	else if (_key > _root->key) {
		if (_root->right == nullptr) {
			noda* _new = new noda(_key, _data);
			_root->right = _new;
			count++;

		}
		else {
			add(_key, _data, _root->right);
		}
	}
}

template<class I, class S>
inline void tree<I, S>::copy(noda* _root)
{
	if (_root == nullptr) {
		return;
	}
	this->add(_root->key, _root->data);
	copy(_root->left);
	copy(_root->right);
}

template<class I, class S>
inline void tree<I, S>::output(ostream& out, noda* _root)
{
	if (_root == nullptr)
		return;
	
	out << _root->data;
	output(out, _root->left);
	output(out, _root->right);
}


template<class I, class S>
inline void tree<I, S>::output_bin(ofstream& out, noda* _root)
{
	if (_root == nullptr)
		return;

	out += _root->data;
	output_bin(out, _root->left);
	output_bin(out, _root->right);

}






template<class I, class S>
inline tree<I, S>::noda::noda(I _key, S _data)
{
	this->key = _key;
	this->data = _data;
}

template<class I, class S>
inline tree<I, S>::tree()
{
}

template<class I, class S>
inline tree<I, S>::tree(const tree& obj)
{
	this->copy(obj.root);
}

template<class I, class S>
inline tree<I, S>& tree<I, S>::operator=(const tree<I, S>& obj)
{
	this->clear();
	this->copy(obj.root);
	return *this;
}

template<class I, class S>
inline void tree<I, S>::add(const I _key, const S _data)
{
	if (root == nullptr) {
		root = new_noda(_key, _data);
		count++;
	}
	else {
		this->add(_key, _data, root);
	}
}

template<class I, class S>
inline S* tree<I, S>::find(I _key)
{

	noda* res = find(_key, root);
	if (res == nullptr)return nullptr;
	else return &(res->data);

}

template<class I, class S>
inline void tree<I, S>::clear()
{
	while (count != 0) {
		this->clear(root);
	}
	root = nullptr;
}

template<class I, class S>
inline int tree<I, S>::size()
{
	return count;
}

template<class I, class S>
inline bool tree<I, S>::empty()
{
	return !this->size();
}

template<class I, class S>
inline tree<I, S>::~tree()
{
	this->clear();
}

template<class I, class S>
inline void tree<I, S>::output(ostream& out)
{
	output(out, root);
}



template<class I, class S>
inline void tree<I, S>::output_bin(ofstream& out)
{
	output_bin(out, root);
}


template<class I, class S>
inline ostream& operator<<(ostream& out, const tree<I, S>& obj)
{
	obj.output(cout);
	return out;
}
