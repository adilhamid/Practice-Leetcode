//#include<iostream>
//#include <math.h>
//#include <vector>
//
//using namespace std;
////
////float invSqrt(float x)
////{
////	float xhalf = 0.5f*x;
////	union
////	{
////		float x;
////		int i;
////	} u;
////	u.x = x;
////	u.i = 1597463007 - (u.i >> 1);
////	/* The next line can be repeated any number of times to increase accuracy */
////	u.x = u.x * (1.5f - xhalf * u.x * u.x);
////	u.x = u.x * (1.5f - xhalf * u.x * u.x);
////	u.x = u.x * (1.5f - xhalf * u.x * u.x);
////	return 1 / u.x;
////}
////
////float sqrt_approx(float z)
////{
////	int val_int = *(int*)&z; /* Same bits, but as an int */
////							 /*
////							 * To justify the following code, prove that
////							 *
////							 * ((((val_int / 2^m) - b) / 2) + b) * 2^m = ((val_int - 2^m) / 2) + ((b + 1) / 2) * 2^m)
////							 *
////							 * where
////							 *
////							 * b = exponent bias
////							 * m = number of mantissa bits
////							 *
////							 * .
////							 */
////
////	val_int -= 1 << 23; /* Subtract 2^m. */
////	val_int >>= 1; /* Divide by 2. */
////	val_int += 1 << 29; /* Add ((b + 1) / 2) * 2^m. */
////
////	return *(float*)&val_int; /* Interpret again as float */
////}
////
////double sqrt_local(double x) {
////	if (x <= 0)
////		return 0;       // if negative number throw an exception?
////	int exp = 0;
////	x = frexp(x, &exp); // extract binary exponent from x
////	if (exp & 1) {      // we want exponent to be even
////		exp--;
////		x *= 2;
////	}
////	double y = (1 + x) / 2; // first approximation
////	double z = 0;
////	while (y != z) {    // yes, we CAN compare doubles here!
////		z = y;
////		y = (y + x / y) / 2;
////	}
////	return ldexp(y, exp / 2); // multiply answer by 2^(exp/2)
////}
////
////double desi_function_sqrt(double val, int decimal_places=5) {
////
////	double rand_number = rand() % (int)val + 1;
////	double intial_num = rand_number -  (rand_number * rand_number - val)/(2*rand_number);
////
////	if (intial_num == 0)
////		return rand_number;
////	double next_num = 0;
////	while (decimal_places >0) {
////		next_num = intial_num - (intial_num * intial_num - val)/ (2* intial_num);
////		if (next_num == 0)
////			break;
////		decimal_places--;
////		intial_num = next_num;
////		
////		
////	}
////	return intial_num;
////
////}
////
////#include <stack>
////
////bool isValid(string s) {
////	stack< char > mystack;
////
////	if (s.length() % 2 != 0)
////		return false;
////
////	for (int i = 0; i < s.length(); i++) {
////		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
////			mystack.push(s[i]);
////		}
////		else {
////			if (mystack.empty())
////				return false;
////			char test = mystack.top();
////			mystack.pop();
////
////			if (s[i] == ')') {
////				if (test == '(')
////					continue;
////				else
////					return false;
////			}
////			if (s[i] == '}') {
////				if (test == '{')
////					continue;
////				else
////					return false;
////			}
////			if (s[i] == ']') {
////				if (test == '[')
////					continue;
////				else
////					return false;
////			}
////		}
////	}
////
////	if (mystack.empty())
////		return true;
////	else
////		return false;
////
////}
////struct ListNode {
////	int val;
////	ListNode *next;
////	ListNode(int x) : val(x), next(NULL) {}
////	
////};
////ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
////	struct ListNode* newlist;
////	struct ListNode* tail = newlist;
////	newlist->next = NULL;
////
////	if (l1 == NULL) return l2;
////	if (l2 == NULL) return l1;
////
////	while (l1 != NULL && l2 != NULL) {
////		if (l1->val <= l2->val) {
////			struct ListNode temp(l1->val);
////			tail->next = &temp;
////			tail = tail->next;
////			l1 = l1->next;
////		}
////		else {
////			struct	ListNode temp(l2->val);
////			tail->next = &temp;
////			tail = tail->next;
////			l2 = l2->next;
////
////		}
////
////	}
////	while (l1 != NULL) {
////		struct	ListNode temp(l1->val);
////		tail->next = &temp;
////		tail = tail->next;
////		l1 = l1->next;
////
////	}
////	while (l2 != NULL) {
////		struct ListNode temp(l2->val);
////		tail->next = &temp;
////		tail = tail->next;
////		l2 = l2->next;
////	}
////
////	return newlist;
////
////}
////ListNode* mergeKLists(vector<ListNode*>& lists) {
////
////	if (lists.size() == 0) return NULL;
////	int n = lists.size() - 1;
////
////	while (n > 0) {
////		for (int i = 0; i < (n + 1) / 2; i++) {
////			lists[i] = mergeTwoLists(lists[0], lists[n - i]);
////		}
////		n /= 2;
////	}
////
////	return lists[0];
////
////}
//int voimain() {
//	//cout << isValid("))}}]]{[([}}[}[(([[]]([}(}}[[[]{){[)") << endl;
//	//cout << isValid("()") << endl
//	//vector <ListNode *> list;
//	
//
//	vector < vector <int, int> > temp_vect;
//
//
//
//	//cout << mergeKLists();
//
//	return 0;
//}