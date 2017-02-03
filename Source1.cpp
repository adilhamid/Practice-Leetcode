//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct treenode {
//	int data;
//	struct treenode* leftChild;
//	struct treenode* rightChild;
//};
//
//struct treenode* insertData(int data, struct treenode* root) {
//	struct treenode* tempNode = (struct treenode*) malloc(sizeof(struct treenode));
//	treenode *nodeCurrent;
//	treenode *nodeParent;
//
//	tempNode->data = data;
//	tempNode->leftChild = NULL;
//	tempNode->rightChild = NULL;
//
//	if (root == NULL) {
//		root = tempNode;
//		return root;
//	}
//	else {
//		nodeCurrent = root;
//		nodeParent = NULL;
//
//		while (true) {
//			nodeParent = nodeCurrent;
//			// searching the insert position of the left subtree
//			if (data < nodeParent->data) {
//				nodeCurrent = nodeCurrent->leftChild;
//				if (nodeCurrent == NULL) {
//					nodeParent->leftChild = tempNode;
//					return root;
//				}
//			}
//			else {
//				nodeCurrent = nodeCurrent->rightChild;
//
//				if (nodeCurrent == NULL)
//				{
//					nodeParent->rightChild = tempNode;
//					return root;
//				}
//			}
//		}
//	}
//
//}
//
//struct treenode* searchElement(int data, treenode* root) {
//	if (root == NULL)
//		return root;
//
//	treenode* currentNode = root;
//
//	while (currentNode->data != data) {
//		if (currentNode->data > data) {
//			currentNode = currentNode->leftChild;
//		}
//		else {
//			currentNode = currentNode->rightChild;
//		}
//
//		if (currentNode == NULL)
//			return NULL;
//	}
//
//	return currentNode;
//}
//
//void preOrderTraversal(treenode* root) {
//
//	if (root != NULL) {
//		cout << root->data<<endl;
//		preOrderTraversal(root->leftChild);
//		preOrderTraversal(root->rightChild);
//	}
//}
//
//void inOrderTraversal(treenode* root)
//{
//	if (root != NULL) {
//		inOrderTraversal(root->leftChild);
//		cout << root->data<<endl;
//		inOrderTraversal(root->rightChild);
//	}
//}
//
//void postOrderTraversal(treenode* root) {
//	if (root != NULL) {
//		postOrderTraversal(root->leftChild);
//		postOrderTraversal(root->rightChild);
//		cout << root->data << endl;
//	}
//}
//
//
//int main() {
//
//	//27, 14, 35, 10, 19, 31, 42
//	treenode *root = NULL;
//	root = insertData(27,root);
//	root = insertData(14, root);
//	root = insertData(35, root);
//	root= insertData(10, root);
//	root= insertData(19, root);
//	root= insertData(31, root);
//	root= insertData(42, root);
//
//	//postOrderTraversal(root);
//
//	treenode*  temp = searchElement(19, root);
//	cout << temp->data << endl;
//	return 0;
//}