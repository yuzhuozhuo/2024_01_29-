#include<iostream>
#include<stdlib.h>
using namespace std;

//���������Ǹ���Ķ�����

//int main()
//{
//	int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year, month, day;
//	//��������һֱ�������룬ֱ����ctrl+c ����
//	while (cin >> year >> month >> day) {
//		int n = 0;
//
//		for (int i = 1; i < month; ++i) {
//			n += MonthDay[i];	//����month-1���µ�����
//		}
//
//		n += day;				//���ϵ�������
//
//		if (month > 2 && ((year & 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
//			n += 1;
//		}
//		//�����һ��
//		cout << n << endl;
//	}
//
//	return 0;
//}

//ABCD�����͹����˳��

//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B {
//public:
//
//	B() {
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//class C {
//public:
//
//	C() {
//		cout << "C()" << endl;
//	}
//	~C()
//	{
//		cout << "~C()" << endl;
//	}
//};
//
//
//class D {
//public:
//
//	D() {
//		cout << "D()" << endl;
//	}
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};
//
//C c;
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return 0;
//}

//����˳�� CABD ����˳�� BADC


//�����������ö��ٴο�������

//class Widget {
//public:
//	Widget()
//	{}
//
//	Widget(const Widget& d) {
//		cout << "Widget(const Widget& d)" << endl;
//	}
//};
//
//Widget f(Widget u) {
//	Widget v(u);
//	Widget w = v;
//	return w;
//}
//
//int main()
//{
//	Widget x;
//	Widget y = f(f(x));
//
//	return 0;
//}

//malloc/calloc/realloc
//#define n 4
//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int) * n);
//	int* p2 = (int*)calloc(n,sizeof(int) * n);
//	int* p3 = (int*)realloc(p2, sizeof(int) * n + 3);
//	free(p1);
//	//free(p3);     p2����free��Ϊp2�Ѿ�ת�Ƶ�p3
//	free(p3);
//
//
//	return 0;
//}

//C������C++��̬����ռ�Ĳ��

//int main()
//{
//	//C	����
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 10);
//	free(p1);
//	free(p2);
//
//	//C++	������
//	int* p3 = new int(10);	//����һ��int��С�Ŀռ� ��ʼ��Ϊ10
//	int* p4 = new int[10];	//����10��int��С�Ŀռ�
//
//	delete p3;
//	delete[]p4;
//
//	return 0;
//}

//C�����Ѿ�����malloc��free ��ônew �� delete�������
//1������������������ͬ
//2���������Զ������Ͳ�ͬ
//class A {
//public:
//	A() {
//		_a = 0;
//		cout << "A()" << endl;
//	}
//	~A() {
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//����������ͬ
//	int* p3 = (int*)malloc(sizeof(int));
//	free(p3);
//
//	int* p4 = new int;
//	delete p4;
//
//	//�Զ������Ͳ�ͬ
//	A* p1 = (A*)malloc(sizeof(A*));	//����ռ�
//	free(p1);	//�ͷſռ�
//
//	A* p2 = new A;	//����ռ�+���캯��
//	delete p2;	//�ͷſռ�+��������
//
//	return 0;
//}


//class A {
//public:
//	A() {
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B {
//public:
//
//	B() {
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//static A a;
//
//B b;
//
//
//int main()
//{
//	return 0;
//}

//malloc/free  Vs  new/delete


//Cд��
//typedef struct ListNode_C {
//	int _val;
//	struct ListNode_C* prev;
//	struct ListNode_C* next;
//}ListNode_C;
//
//ListNode_C* BuyListNode(int val) {
//	ListNode_C* node = (ListNode_C*)malloc(sizeof(ListNode_C));
//	node->_val = val;
//	node->prev = NULL;
//	node->next = NULL;
//
//	return node;
//}
//
//void DestroyListNode_C(ListNode_C* node);
//
////C++д��
//
//struct ListNode_cpp {
//	int _val;
//	ListNode_cpp* prev;
//	ListNode_cpp* next;
//
//	ListNode_cpp(int val =0)
//		:_val(val)
//		,prev(nullptr)
//		,next(nullptr)
//	{}
//
//	~ListNode_cpp()
//	{
//		cout << "~ListNode_cpp()" << endl;
//	}
//};
//
//int main()
//{
//	ListNode_C* node1 = BuyListNode(1);
//
//	ListNode_cpp* node2 = new ListNode_cpp;
//	delete node2;
//
//	return 0;
//}
// 
// 
//struct ListNode_cpp {
//	int _val;
//	ListNode_cpp* prev;
//	ListNode_cpp* next;
//
//	ListNode_cpp(int val =0)
//		:_val(val)
//		,prev(nullptr)
//		,next(nullptr)
//	{
//		cout << "ListNode_cpp(int val = 0)" << endl;
//	}
//
//	~ListNode_cpp()
//	{
//		cout << "~ListNode_cpp()" << endl;
//	}
//};
//
//int main()
//{
//	ListNode_cpp List[10];
//
//	return 0;
//}


//operator new Vs malloc
// ���ۣ�ʹ�÷�ʽ��ͬ  �������ʽ��ͬ
    

//int main()
//{
//	size_t size = 2;
//	
//	void* p1 = malloc(size * 1024 * 1024 * 1024 * 1024);
//	cout << p1 << endl;
//	//free(p1)
//
//	try {
//		void* p2 = operator new(size * 1024 * 1024 * 1024 * 1024);
//		cout << p2 << endl;
//		//free(p2)
//	}
//
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//    size_t size = 2;
//
//    void* p = new int[1000000000];
//
//
//    return 0;
//}

//int main()
//{
//    //malloc
//    //operator new  = malloc + ʧ�����쳣
//    //new  = operator new + ���ù��캯����ʼ��
//    //free/delete delete���������������� 
//    //operator delete �� free û������Ϊ�ͷſռ�ʧ�ܶ�ֱ����ֹ���̡�
//
//
//    return 0;
//}
 
//class A {
//public:
//
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//
//	//ģ��������Ϊ
//	//��ʽ�ĵ���A�Ĺ��캯������������
//	A* p2 = (A*) operator new (sizeof(A));
//
//	//���Ѵ��ڵ�һ��ռ���ù��캯����ʼ���� ��λnew/replacement new
//	new(p2)A(10);	//(�ռ��ָ�룩����(����)
//
//	p2->~A();
//	operator delete(p2);
//
//    return 0;
//
// }

//�ڴ�й©

//int main()
//{
//    size_t n = 2;
//    int* p = (int*)malloc(n* 1024 * 1024 * 1024);
//    //�ڴ�й©�� pָ��Ŀռ䲻��Ҫ�ˣ������ǻ�������ԭ�����ڴ�û���ͷ�
//    //�ڴ�й©��Σ�����������еĳ��򣬳����ڴ�й©��Σ���ܴ󡣻����豸�����ڴ��СҲ��Σ��
//    free(p);
//    return 0;
//}

//int main()
//{
//    size_t n = 2;
//
//    try {
//        void* p = new char(n * 1024 * 1024 * 1024);
//        cout << "new:" << p << endl;
//    }
//
//    catch (exception& e) {
//        cout << e.what() << endl;
//    }
//
//    return 0;
//}


//���ͱ��
//ģ��

//���治�ǵ��õ�ͬһ������
//���õ���ͬһ��ģ��ʵ���������ɵĶ�Ӧ���͵ĺ���

//template <class T>
//void Swap(T& left, T& right)
//{
//    T temp = left;
//    left = right;
//    right = temp;
//}
//
//int main()
//{
//   /* int a = 1, b = 2;
//    Swap(a, b);
//
//    double c = 2.0, d = 3.0;
//    Swap(c, d);
//
//    char e = 'a', f = 'b';
//    Swap(e, f);*/
//
//    return 0;
//}

//C++���ŵ�չʾ

//C����ʵ��һ��ջ
typedef int StDateType;

typedef struct Stack_c {
    StDateType date;
    int size;
    int capacity;
}Stack_c;

void StackInit(Stack_c* st) {
    //...
}

void StackPush(Stack_c* st, StDateType x);
void StackPop(Stack_c* st, StDateType x);

//C++
template <class T>

class Stack_cpp
{
public:
    Stack_cpp()
    {}

    ~Stack_cpp()
    {}

private:
    T _data;
    int _size;
    int _capacity;
};

int main()
{
    Stack_c st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    //C�Ĳ���
    //1.���ܻ����ǳ�ʼ��������     ->C++�Ż� ���캯������������
    Stack_cpp<int> stack_cpp;
    //2.�Ƿ��޸�                  ->C++�Ż� ��+�����޶���
    st.capacity = 0;
    stack_cpp._date = 1;

    //3.�޷�ͬʱ�����������͵�ջ    ->C++�Ż� ģ����
    Stack_cpp<double> st2;

    return 0;
}