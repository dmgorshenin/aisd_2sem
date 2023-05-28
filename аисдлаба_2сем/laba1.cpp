#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <complex>
using namespace std;

struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

//class Set {
//private:
//	struct TreeNode {
//		int data;
//		TreeNode* left, * right;
//		TreeNode(int data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
//	}*root;
//
//	TreeNode* copy(TreeNode* n_root) {
//		if (!n_root) { return nullptr; }
//		TreeNode* temp = new TreeNode(n_root->data, nullptr, nullptr);
//		temp->left = copy(n_root->left);
//		temp->right = copy(n_root->right);
//		return temp;
//	}
//
//	void clear_(TreeNode* n_root) {
//		if (n_root->left) { clear_(n_root->left); }
//		if (n_root->right) { clear_(n_root->right); }
//		root = nullptr;
//	}
//
//	TreeNode* insert_(TreeNode* root, int key) {
//		if (!root) {
//			root = new TreeNode(key, nullptr, nullptr);
//			return root;
//		}
//		if (key >= root->data) {
//			root->right = insert_(root->right, key);
//		}
//		if (key < root->data) {
//			root->left = insert_(root->left, key);
//		}
//		return root;
//	}
//
//	bool contains_(const TreeNode* root, int key) const {
//		if (!root) { return false; }
//		if (root->data == key) {
//			return true;
//		}
//		if (key > root->data) { return contains_(root->right, key); }
//		return contains_(root->left, key);
//	}
//
//	TreeNode* minimum(const TreeNode* root) const {
//		if (!root->left) { return const_cast<TreeNode*>(root); }
//		return minimum(root->left);
//	}
//
//	TreeNode* erase_(TreeNode* root, int key) {
//		if (!root) {
//			return root;
//		}
//		if (key < root->data) {
//			root->left = erase_(root->left, key);
//		}
//		else if (key > root->data) {
//			root->right = erase_(root->right, key);
//		}
//		else if (root->left and root->right) {
//			root->data = minimum(root->right)->data;
//			root->right = erase_(root->right, root->data);
//		}
//		else {
//			if (root->left) {
//				root = root->left;
//			}
//			else if (root->right) {
//				root = root->right;
//			}
//			else {
//				root = nullptr;
//			}
//		}
//		return root;
//	}
//
//	void showTrunks(Trunk* p)
//	{
//		if (p == nullptr) {
//			return;
//		}
//
//		showTrunks(p->prev);
//		cout << p->str;
//	}
//
//	void printTree_(TreeNode* root, Trunk* prev, bool isLeft)
//	{
//		if (root == nullptr) {
//			return;
//		}
//
//		string prev_str = "    ";
//		Trunk* trunk = new Trunk(prev, prev_str);
//
//		printTree_(root->right, trunk, true);
//
//		if (!prev) {
//			trunk->str = "---";
//		}
//		else if (isLeft)
//		{
//			trunk->str = ".---";
//			prev_str = "   |";
//		}
//		else {
//			trunk->str = "`---";
//			prev->str = prev_str;
//		}
//
//		showTrunks(trunk);
//		cout << " " << root->data << endl;
//
//		if (prev) {
//			prev->str = prev_str;
//		}
//		trunk->str = "   |";
//
//		printTree_(root->left, trunk, false);
//	}
//
//	static void to_vector_(vector<int>& vec, const TreeNode* root) {
//		if (!root) { return; }
//		to_vector_(vec, root->left);
//		vec.push_back(root->data);
//		to_vector_(vec, root->right);
//	}
//
//	void LKP(const TreeNode* root) {
//		if (root) {
//			LKP(root->left);
//			cout << root->data << "  ";
//			LKP(root->right);
//		}
//	}
//
//	void LPK(const TreeNode* root) {
//		if (root) {
//			LPK(root->left);
//			LPK(root->right);
//			cout << root->data << "  ";
//		}
//	}
//
//	void KLP(const TreeNode* root) {
//		if (root) {
//			cout << root->data << "  ";
//			KLP(root->right);
//			KLP(root->left);
//		}
//	}
//
//public:
//
//	Set() {
//		root = nullptr;
//	}
//
//	Set(const Set& new_root) {
//		if (!new_root.root) {
//			clear_(root);
//			delete root;
//		}
//		else {
//			if (!root) {
//				root = copy(new_root.root);
//			}
//			else {
//				clear_(root);
//				delete root;
//				root = copy(new_root.root);
//			}
//		}
//	}
//
//	~Set() {
//		if (root) {
//			clear_(root);
//			delete root;
//		}
//
//	}
//
//	Set& operator=(const Set& new_root) {
//		if (!new_root.root) {
//			clear_(root);
//			delete root;
//			return *this;
//		}
//		else {
//			if (!root) {
//				root = copy(new_root.root);
//			}
//			else {
//				clear_(root);
//				delete root;
//				root = copy(new_root.root);
//			}
//			return *this;
//		}
//	}
//
//	bool contains(int key) {
//		return contains_(root, key);
//	}
//
//	bool insert(int key) {
//		if (!contains_(root, key)) {
//			root = insert_(root, key);
//			return true;
//		}
//		return false;
//	}
//
//	bool erase(int key) {
//		if (contains_(root, key)) {
//			root = erase_(root, key);
//			if (!contains_(root, key)) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void clear() {
//		clear_(root);
//	}
//
//	void print_tree() {
//		printTree_(root, nullptr, false);
//	}
//
//	void print() {
//		LKP(root);
//	}
//
//	vector<int> to_vector() const {
//		vector<int> vec;
//		to_vector_(vec, root);
//		return vec;
//	}
//};

template<typename T>
class Set {
private:

	struct TreeNode {
		T data;
		int height = 0;
		TreeNode* left, * right;
		TreeNode(const T& data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
	} *root;

	TreeNode* copy(TreeNode* n_root) {
		if (!n_root) { return nullptr; }
		TreeNode* temp = new TreeNode(n_root->data, nullptr, nullptr);
		temp->height = n_root->height;
		temp->left = copy(n_root->left);
		temp->right = copy(n_root->right);
		return temp;
	}

	void clear_(TreeNode* n_root) {
		if (n_root->left) { clear_(n_root->left); }
		if (n_root->right) { clear_(n_root->right); }
		n_root = nullptr;
	}

	void update_height(TreeNode* node) {
		node->height = max(get_height(node->left), get_height(node->right)) + 1;
	}

	int get_balance(const TreeNode* node) {
		return (node == nullptr) ? 0 : get_height(node->right) - get_height(node->left);
	}

	void swap(TreeNode* a, TreeNode* b) {
		T a_data = a->data;
		a->data = b->data;
		b->data = a_data;
	}

	void right_rotate(TreeNode* node) {
		swap(node, node->left);
		TreeNode* buffer = node->right;
		node->right = node->left;
		node->left = node->right->left;
		node->right->left = node->right->right;
		node->right->right = buffer;
		update_height(node->right);
		update_height(node);
	}

	void left_rotate(TreeNode* node) {
		swap(node, node->right);
		TreeNode* buffer = node->left;
		node->left = node->right;
		node->right = node->left->right;
		node->right->left = node->right->right;
		node->left->right = node->left->left;
		node->left->left = buffer;
		update_height(node->left);
		update_height(node);
	}

	void balance(TreeNode* node) {
		int balance = get_balance(node);
		if (balance == -2) {
			if (get_balance(node->left) == 1) {
				left_rotate(node->left);
			}
			right_rotate(node);
		}
		else if (balance == 2) {
			if (get_balance(node->right) == -1) {
				right_rotate(node->right);
			}
			left_rotate(node);
		}
	}

	TreeNode* insert_(TreeNode* root, const T& key) {
		if (!root) {
			root = new TreeNode(key, nullptr, nullptr);
			return root;
		}
		if (key >= root->data) {
			root->right = insert_(root->right, key);
		}
		if (key < root->data) {
			root->left = insert_(root->left, key);
		}
		update_height(root);
		balance(root);
		return root;
	}

	bool contains_(const TreeNode* root, const T& key) const {
		if (!root) { return false; }
		if (root->data == key) {
			return true;
		}
		if (key > root->data) { return contains_(root->right, key); }
		return contains_(root->left, key);
	}

	TreeNode* minimum(const TreeNode* root) const {
		if (!root->left) { return const_cast<TreeNode*>(root); }
		return minimum(root->left);
	}

	TreeNode* erase_(TreeNode* root, const T& key) {
		if (!root) {
			return root;
		}
		if (key < root->data) {
			root->left = erase_(root->left, key);
		}
		else if (key > root->data) {
			root->right = erase_(root->right, key);
		}
		else if (root->left and root->right) {
			root->data = minimum(root->right)->data;
			root->right = erase_(root->right, root->data);
		}
		else {
			if (root->left) {
				root = root->left;
			}
			else if (root->right) {
				root = root->right;
			}
			else {
				update_height(root);
				balance(root);
				root = nullptr;
			}
		}
		
		return root;
	}

	void showTrunks(Trunk* p)
	{
		if (p == nullptr) {
			return;
		}

		showTrunks(p->prev);
		cout << p->str;
	}

	void printTree_(TreeNode* root, Trunk* prev, bool isLeft)
	{
		if (root == nullptr) {
			return;
		}

		string prev_str = "    ";
		Trunk* trunk = new Trunk(prev, prev_str);

		printTree_(root->right, trunk, true);

		if (!prev) {
			trunk->str = "---";
		}
		else if (isLeft)
		{
			trunk->str = ".---";
			prev_str = "   |";
		}
		else {
			trunk->str = "`---";
			prev->str = prev_str;
		}

		showTrunks(trunk);
		cout << " " << root->data << endl;

		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";

		printTree_(root->left, trunk, false);
	}

	static void to_vector_(vector<T>& vec, const TreeNode* root) {
		if (!root) { return; }
		to_vector_(vec, root->left);
		vec.push_back(root->data);
		to_vector_(vec, root->right);
	}

	void LKP(const TreeNode* root) {
		if (root) {
			LKP(root->left);
			cout << root->data << "  ";
			LKP(root->right);
		}
	}

	void LPK(const TreeNode* root) {
		if (root) {
			LPK(root->left);
			LPK(root->right);
			cout << root->data << "  ";
		}
	}

	void KLP(const TreeNode* root) {
		if (root) {
			cout << root->data << "  ";
			KLP(root->right);
			KLP(root->left);
		}
	}

	
public:

	Set() {
		root = nullptr;
	}

	Set(const Set& new_root) {
		if (!new_root.root) {
			clear_(root);
			delete root;
		}
		else {
			if (!root) {
				root = copy(new_root.root);
			}
			else {
				clear_(root);
				delete root;
				root = copy(new_root.root);
			}
		}
	}

	~Set() {
		if (root) {
			clear_(root);
			delete root;
		}

	}

	Set& operator=(const Set& new_root) {
		if (!new_root.root) {
			clear_(root);
			delete root;
			return *this;
		}
		else {
			if (!root) {
				root = copy(new_root.root);
			}
			else {
				clear_(root);
				delete root;
				root = copy(new_root.root);
			}
			return *this;
		}
	}

	bool contains(const T& key) {
		return contains_(root, key);
	}

	bool insert(const T& key) {
		if (!contains_(root, key)) {
			root = insert_(root, key);
			return true;
		}
		return false;
	}

	bool erase(const T& key) {
		if (contains_(root, key)) {
			root = erase_(root, key);
			if (!contains_(root, key)) {
				return true;
			}
		}
		return false;
	}

	static int get_height(const TreeNode* node) {
		return node == nullptr ? -1 : node->height;
	}

	void clear() {
		clear_(root);
	}

	void print_tree() {
		printTree_(root, nullptr, false);
	}

	void print() {
		LKP(root);
	}

	vector<T> to_vector() const {
		vector<T> vec;
		to_vector_(vec, root);
		return vec;
	}
};

template<typename T>
class Set<complex<T>> {
private:
	struct TreeNode {
		complex<T> data;
		int height = 0;
		TreeNode* left, * right;
		TreeNode(const complex<T>& data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {}
	} *root;

	TreeNode* copy(TreeNode* n_root) {
		if (!n_root) { return nullptr; }
		TreeNode* temp = new TreeNode(n_root->data, nullptr, nullptr);
		temp->height = n_root->height;
		temp->left = copy(n_root->left);
		temp->right = copy(n_root->right);
		return temp;
	}

	static T modul(complex<T> comp) {
		return sqrt(pow(comp.real(), 2) + pow(comp.imag(), 2));
	}

	void clear_(TreeNode* n_root) {
		if (n_root->left) { clear_(n_root->left); }
		if (n_root->right) { clear_(n_root->right); }
		n_root = nullptr;
	}

	void update_height(TreeNode* node) {
		node->height = max(get_height(node->left), get_height(node->right)) + 1;
	}

	int get_balance(const TreeNode* node) {
		return (node == nullptr) ? 0 : get_height(node->right) - get_height(node->left);
	}

	void swap(TreeNode* a, TreeNode* b) {
		T a_data = a->data;
		a->data = b->data;
		b->data = a_data;
	}

	void right_rotate(TreeNode* node) {
		swap(node, node->left);
		TreeNode* buffer = node->right;
		node->right = node->left;
		node->left = node->right->left;
		node->right->left = node->right->right;
		node->right->right = buffer;
		update_height(node->right);
		update_height(node);
	}

	void left_rotate(TreeNode* node) {
		swap(node, node->right);
		TreeNode* buffer = node->left;
		node->left = node->right;
		node->right = node->left->right;
		node->left->right = node->right->right;
		node->left->right = node->left->left;
		node->left->left = buffer;
		update_height(node->left);
		update_height(node);
	}

	void balance(TreeNode* node) {
		int balance = get_balance(node);
		if (balance == -2) {
			if (get_balance(node->left) == 1) {
				left_rotate(node->left);
			}
			right_rotate(node);
		}
		else if (balance == 2) {
			if (get_balance(node->right) == -1) {
				right_rotate(node->right);
				left_rotate(node);
			}
		}
	}

	TreeNode* insert_(TreeNode* root, const complex<T>& key) {
		if (!root) {
			root = new TreeNode(key, nullptr, nullptr);
			return root;
		}
		if (modul(key) >= modul(root->data)) {
			root->right = insert_(root->right, key);
		}
		if (modul(key) < modul(root->data)) {
			root->left = insert_(root->left, key);
		}
		update_height(root);
		balance(root);
		return root;
	}

	bool contains_(const TreeNode* root, const complex<T>& key) const {
		if (!root) { return false; }
		if (key.imag() == root->data.imag() and key.real() == root->data.real()) {
			return true;
		}
		if (modul(key) > modul(root->data)) { return contains_(root->right, key); }
		return contains_(root->left, key);
	}

	TreeNode* minimum(const TreeNode* root) const {
		if (!root->left) { return const_cast<TreeNode*>(root); }
		return minimum(root->left);
	}

	TreeNode* erase_(TreeNode* root, const complex<T>& key) {
		if (!root) {
			return root;
		}
		if (modul(key) < modul(root->data)) {
			root->left = erase_(root->left, key);
		}
		else if (modul(key) > modul(root->data)) {
			root->right = erase_(root->right, key);
		}
		else if (root->left and root->right) {
			root->data = minimum(root->right)->data;
			root->right = erase_(root->right, root->data);
		}
		else {
			if (root->left) {
				root = root->left;
			}
			else if (root->right) {
				root = root->right;
			}
			else {
				update_height(root);
				balance(root);
				root = nullptr;
			}
		}
		return root;
	}

	void showTrunks(Trunk* p)
	{
		if (p == nullptr) {
			return;
		}

		showTrunks(p->prev);
		cout << p->str;
	}

	void printTree_(TreeNode* root, Trunk* prev, bool isLeft)
	{
		if (root == nullptr) {
			return;
		}

		string prev_str = "    ";
		Trunk* trunk = new Trunk(prev, prev_str);

		printTree_(root->right, trunk, true);

		if (!prev) {
			trunk->str = "---";
		}
		else if (isLeft)
		{
			trunk->str = ".---";
			prev_str = "   |";
		}
		else {
			trunk->str = "`---";
			prev->str = prev_str;
		}

		showTrunks(trunk);
		cout << " " << root->data << endl;

		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";

		printTree_(root->left, trunk, false);
	}

	static void to_vector_(vector<complex<T>>& vec, const TreeNode* root) {
		if (!root) { return; }
		to_vector_(vec, root->left);
		vec.push_back(root->data);
		to_vector_(vec, root->right);
	}

	void LKP(const TreeNode* root) {
		if (root) {
			LKP(root->left);
			cout << root->data << "  ";
			LKP(root->right);
		}
	}

	void LPK(const TreeNode* root) {
		if (root) {
			LPK(root->left);
			LPK(root->right);
			cout << root->data << "  ";
		}
	}

	void KLP(const TreeNode* root) {
		if (root) {
			cout << root->data << "  ";
			KLP(root->right);
			KLP(root->left);
		}
	}

public:

	Set() {
		root = nullptr;
	}

	Set(const Set& new_root) {
		if (!new_root.root) {
			clear_(root);
			delete root;
		}
		else {
			if (!root) {
				root = copy(new_root.root);
			}
			else {
				clear_(root);
				delete root;
				root = copy(new_root.root);
			}
		}
	}

	~Set() {
		if (root) {
			clear_(root);
			delete root;
		}

	}

	Set& operator=(const Set& new_root) {
		if (!new_root.root) {
			clear_(root);
			delete root;
			return *this;
		}
		else {
			if (!root) {
				root = copy(new_root.root);
			}
			else {
				clear_(root);
				delete root;
				root = copy(new_root.root);
			}
			return *this;
		}
	}

	bool contains(const complex<T>& key) {
		return contains_(root, key);
	}

	bool insert(const complex<T>& key) {
		if (!contains_(root, key)) {
			root = insert_(root, key);
			return true;
		}
		return false;
	}

	bool erase(const complex<T>& key) {
		if (contains_(root, key)) {
			root = erase_(root, key);
			if (!contains_(root, key)) {
				return true;
			}
		}
		return false;
	}

	static int get_height(const TreeNode* node) {
		return node == nullptr ? -1 : node->height;
	}

	void clear() {
		clear_(root);
	}

	void print_tree() {
		printTree_(root, nullptr, false);
	}

	void print() {
		LKP(root);
	}

	vector<complex<T>> to_vector() const {
		vector<complex<T>> vec;
		to_vector_(vec, root);
		return vec;
	}
};


template<typename T>
Set<T> intersection(const Set<T>& first_tree, const Set<T>& second_tree) {
	Set<T> temp;
	for (auto i : second_tree.to_vector()) {
		for (auto j : first_tree.to_vector()) {
			if (i==j) {
				temp.insert(i);
			}
		}
	}
	return temp;
}

template<typename T>
Set<T> difference(const Set<T>& first_tree, const Set<T>& second_tree) {
	Set temp = first_tree;
	for (auto i : second_tree.to_vector()) {
		if (temp.contains(i)) {
			temp.erase(i);
		}
	}
	return temp;
}

//size_t lcg() {
//		static size_t x = 0;
//		x = (1021 * x + 24631) % 116640;
//		return x;
//	}
//
//double AVG_for_100(const double* ar) {
//	double sum = 0;
//	for (size_t i = 0; i < 100; ++i) {
//		sum += ar[i];
//	}
//	return sum / 100;
//}
//
//double AVG_for_1000(const double* ar) {
//	double sum = 0;
//	for (size_t i = 0; i < 1000; ++i) {
//		sum += ar[i];
//	}
//	return sum / 1000;
//}

//int main() {
//	/*//ТЕСТОВАЯ ЗОНА
//	Set<int> tt_1000, tt_10000, tt_100000;
//	vector<int> vtt_1000, vtt_10000, vtt_100000;
//
//	double vect_attempts_1000[100], vect_attempts_10000[100], vect_attempts_100000[100];
//	double set_attempts_1000[100], set_attempts_10000[100], set_attempts_100000[100];
//
//	//ЗАПОЛНЕНИЕ НА 1000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//
//		//start
//		clock_t begin = clock();
//		while (counter != 1000) {
//			tt_1000.insert(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//
//		if (i != 99) { tt_1000.clear(); }
//		set_attempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill tree with 1000 elem: " << AVG_for_100(set_attempts_1000) << endl;
//
//	//ЗАПОЛНЕНИЕ НА 10000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//		//start
//		clock_t begin = clock();
//		while (counter != 10000) {
//			tt_10000.insert(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//		if (i != 99) { tt_10000.clear(); }
//		set_attempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill tree with 10000 elem: " << AVG_for_100(set_attempts_10000) << endl;
//
//	//ЗАПОЛНЕНИЕ НА 100000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//		//start
//		clock_t begin = clock();
//		while (counter != 100000) {
//			tt_100000.insert(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//		if (i != 99) { tt_100000.clear(); }
//		set_attempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill tree with 100000 elem: " << AVG_for_100(set_attempts_100000) << endl;
//
//	cout << "-------------------------------------------------------------------" << endl;
//
//	//ЗАПОЛНЕНИЕ std::vector НА 1000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//		//start
//		clock_t begin = clock();
//		while (counter != 1000) {
//			vtt_1000.push_back(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//		if (i != 99) { vtt_1000.clear(); }
//		vect_attempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill vector with 1000 elem: " << AVG_for_100(vect_attempts_1000) << endl;
//
//	//ЗАПОЛНЕНИЕ std::vector НА 10000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//		//start
//		clock_t begin = clock();
//		while (counter != 10000) {
//			vtt_10000.push_back(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//		if (i != 99) { vtt_10000.clear(); }
//		vect_attempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill vector with 10000 elem: " << AVG_for_100(vect_attempts_10000) << endl;
//
//	//ЗАПОЛНЕНИЕ std::vector НА 100000
//	for (size_t i = 0; i < 100; ++i) {
//		int counter = 0;
//		//start
//		clock_t begin = clock();
//		while (counter != 100000) {
//			vtt_100000.push_back(lcg());
//			++counter;
//		}
//		clock_t end = clock();
//		//end
//		if (i != 99) { vtt_100000.clear(); }
//		vect_attempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to fill vector with 100000 elem: " << AVG_for_100(vect_attempts_100000) << endl;
//
//	cout << "-------------------------------------------------------------------" << endl;
//
//	double findattempts_1000[1000], findattempts_10000[1000], findattempts_100000[1000];
//	//ПОИСК ЭЛЕМЕНТА В ДЕРЕВЕ 1000
//	for (size_t i = 0; i < 1000; ++i) {
//		//start
//		clock_t begin = clock();
//		tt_1000.contains(lcg());
//		clock_t end = clock();
//		//end
//
//		findattempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in tree with 1000 elem: " << AVG_for_1000(findattempts_1000) << endl;
//
//	//ПОИСК ЭЛЕМЕНТА В ДЕРЕВЕ 10000
//	for (size_t i = 0; i < 1000; ++i) {
//		//start
//		clock_t begin = clock();
//		tt_10000.contains(lcg());
//		clock_t end = clock();
//		//end
//
//		findattempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in tree with 10000 elem: " << AVG_for_1000(findattempts_10000) << endl;
//
//	//ПОИСК ЭЛЕМЕНТА В ДЕРЕВЕ 100000
//	for (size_t i = 0; i < 1000; ++i) {
//		//start
//		clock_t begin = clock();
//		tt_100000.contains(lcg());
//		clock_t end = clock();
//		//end
//
//		findattempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in tree with 100000 elem: " << AVG_for_1000(findattempts_100000) << endl;
//
//	cout << "-------------------------------------------------------------------" << endl;
//
//	double vfindattempts_1000[1000], vfindattempts_10000[1000], vfindattempts_100000[1000];
//	//ПОИСК ЭЛЕМЕНТА В ВЕКТОРЕ 1000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		for (size_t i = 0; i < vtt_1000.size(); ++i) {
//			if (vtt_1000[i] == elem) { break; }
//		}
//		clock_t end = clock();
//		//end
//
//		vfindattempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 1000 elem: " << AVG_for_1000(vfindattempts_1000) << endl;
//
//	//ПОИСК ЭЛЕМЕНТА В ВЕКТОРЕ 10000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		for (size_t i = 0; i < vtt_10000.size(); ++i) {
//			if (vtt_10000[i] == elem) { break; }
//		}
//		clock_t end = clock();
//		//end
//
//		vfindattempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 10000 elem: " << AVG_for_1000(vfindattempts_10000) << endl;
//
//	//ПОИСК ЭЛЕМЕНТА В ВЕКТОРЕ 100000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		for (size_t i = 0; i < vtt_100000.size(); ++i) {
//			if (vtt_100000[i] == elem) { break; }
//		}
//		clock_t end = clock();
//		//end
//
//		vfindattempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 100000 elem: " << AVG_for_1000(vfindattempts_100000) << endl;
//
//	cout << "-------------------------------------------------------------------" << endl;
//
//	double add_del_attempts_1000[1000], add_del_attempts_10000[1000], add_del_attempts_100000[1000];
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В ДЕРЕВЕ 1000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		tt_1000.insert(elem);
//		tt_1000.erase(elem);
//		clock_t end = clock();
//		//end
//
//		add_del_attempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to add and delete elem in set with 1000 elem: " << AVG_for_1000(add_del_attempts_1000) << endl;
//
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В ДЕРЕВЕ 10000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		tt_10000.insert(elem);
//		tt_10000.erase(elem);
//		clock_t end = clock();
//		//end
//
//		add_del_attempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to add and delete elem in set with 10000 elem: " << AVG_for_1000(add_del_attempts_10000) << endl;
//
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В ДЕРЕВЕ 100000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		tt_100000.insert(elem);
//		tt_100000.erase(elem);
//		clock_t end = clock();
//		//end
//
//		add_del_attempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to add and delete elem in set with 100000 elem: " << AVG_for_1000(add_del_attempts_100000) << endl;
//
//	cout << "-------------------------------------------------------------------" << endl;
//
//	double add_del_vecattempts_1000[1000], add_del_vecattempts_10000[1000], add_del_vecattempts_100000[1000];
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В VECTOR 1000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		vtt_1000.push_back(elem);
//		vtt_1000.pop_back();
//		clock_t end = clock();
//		//end
//
//		add_del_vecattempts_1000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 1000 elem: " << AVG_for_1000(add_del_vecattempts_1000) << endl;
//
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В VECTOR 10000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		vtt_10000.push_back(elem);
//		vtt_10000.pop_back();
//		clock_t end = clock();
//		//end
//
//		add_del_vecattempts_10000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 10000 elem: " << AVG_for_1000(add_del_vecattempts_10000) << endl;
//
//	//ДОБАВЛЕНИЕ И УДАЛЕНИЕ В VECTOR 100000
//	for (size_t i = 0; i < 1000; ++i) {
//		int elem = lcg();
//		//start
//		clock_t begin = clock();
//		vtt_100000.push_back(elem);
//		vtt_100000.pop_back();
//		clock_t end = clock();
//		//end
//
//		add_del_vecattempts_100000[i] = double(end - begin) / double(CLOCKS_PER_SEC);
//	}
//	cout << "Average time to find elem in std::vector with 100000 elem: " << AVG_for_1000(add_del_vecattempts_100000) << endl;*/
//
//	Set<int> a;
//	a.insert(10);
//	a.insert(1);
//	a.insert(19);
//	a.print_tree();
//	cout << endl;
//	a.insert(13);
//	a.print_tree();
//	cout << endl;
//	a.insert(20);
//	a.print_tree();
//	cout << endl;
//	a.insert(3);
//	a.print_tree();
//	cout << endl;
//	a.insert(9);
//	a.print_tree();
//	cout << endl;
//	a.insert(12);
//	a.print_tree();
//	cout << endl;
//	a.insert(2);
//	a.print_tree();
//	cout << endl;
//	a.insert(11);
//	a.print_tree();
//	cout << endl;
//	a.insert(14);
//	a.print_tree();
//}