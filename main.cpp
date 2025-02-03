#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int index;
	Node* next;
};




class counting_rhyme_ver1
{
public:

	int* deleter_list;
	Node* list_names;
	int N;
	int k;

	template<typename T>
	counting_rhyme_ver1(vector<T> arr_, int k_)
	{
		list_names = get_ñircular_list(arr_);
		Node* list_names_copy = get_ñircular_list(arr_);
		N = arr_.size;
		k = k_;
		deleter_list = new int[N];

		int counter_list = N;

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < k % counter_list + 1; j++)
			{
				list_names_copy = list_names_copy->next;
			}

			list_names_copy = pop_from_ñircular_list(list_names_copy, counter_list);
		}

		return list_names_copy->index;
	}

	template<typename T>
	Node* get_ñircular_list(vector<T> arr_)
	{
		Node* root = new Node;;
		root->index = 1;
		Node* current = root;
		root->next = current;

		for (int i = 1; i < arr_.size; i++)
		{
			current->next = new Node;
			current->index = i + 1;
			current = current->next;
		}
		current->next = current;

		return root;
	}


	Node* pop_from_ñircular_list(Node* a_, int counter_list_)
	{
		Node* b = a_;

		for (int i = 1; i < counter_list_; i++)
		{
			b = b->next;
		}

		b->next = a_->next;

		delete a_;
		return b->next;
	}


};


int main()
{
	return 0;
}