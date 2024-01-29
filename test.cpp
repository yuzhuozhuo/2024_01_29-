#include<iostream>
#include<stdlib.h>
using namespace std;

//计算日期是该年的多少天

//int main()
//{
//	int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year, month, day;
//	//这样可以一直接受输入，直到按ctrl+c 结束
//	while (cin >> year >> month >> day) {
//		int n = 0;
//
//		for (int i = 1; i < month; ++i) {
//			n += MonthDay[i];	//计算month-1个月的天数
//		}
//
//		n += day;				//加上当月天数
//
//		if (month > 2 && ((year & 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
//			n += 1;
//		}
//		//闰年加一天
//		cout << n << endl;
//	}
//
//	return 0;
//}

//ABCD析构和构造的顺序

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

//构造顺序 CABD 析构顺序 BADC


//分析代码会调用多少次拷贝构造

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
//	//free(p3);     p2不用free因为p2已经转移到p3
//	free(p3);
//
//
//	return 0;
//}

//C语言与C++动态申请空间的差别

//int main()
//{
//	//C	函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 10);
//	free(p1);
//	free(p2);
//
//	//C++	操作符
//	int* p3 = new int(10);	//申请一个int大小的空间 初始化为10
//	int* p4 = new int[10];	//申请10的int大小的空间
//
//	delete p3;
//	delete[]p4;
//
//	return 0;
//}

//C语言已经有了malloc和free 那么new 和 delete意义何在
//1、作用于内置类型相同
//2、作用域自定义类型不同
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
//	//内置类型相同
//	int* p3 = (int*)malloc(sizeof(int));
//	free(p3);
//
//	int* p4 = new int;
//	delete p4;
//
//	//自定义类型不同
//	A* p1 = (A*)malloc(sizeof(A*));	//申请空间
//	free(p1);	//释放空间
//
//	A* p2 = new A;	//申请空间+构造函数
//	delete p2;	//释放空间+析构函数
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


//C写法
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
////C++写法
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
// 结论：使用方式相同  处理错误方式不同
    

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
//    //operator new  = malloc + 失败抛异常
//    //new  = operator new + 调用构造函数初始化
//    //free/delete delete调用析构函数清理 
//    //operator delete 和 free 没区别，因为释放空间失败都直接终止进程。
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
//	//模仿上面行为
//	//显式的调用A的构造函数和析构函数
//	A* p2 = (A*) operator new (sizeof(A));
//
//	//对已存在的一块空间调用构造函数初始化。 定位new/replacement new
//	new(p2)A(10);	//(空间的指针）类型(参数)
//
//	p2->~A();
//	operator delete(p2);
//
//    return 0;
//
// }

//内存泄漏

//int main()
//{
//    size_t n = 2;
//    int* p = (int*)malloc(n* 1024 * 1024 * 1024);
//    //内存泄漏： p指向的空间不需要了，但忘记或者其他原因导致内存没有释放
//    //内存泄漏的危害：长期运行的程序，出现内存泄漏的危害很大。或者设备本身内存很小也有危害
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


//泛型编程
//模板

//下面不是调用的同一个函数
//调用的是同一个模板实例化所生成的对应类型的函数

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

//C++的优点展示

//C语言实现一个栈
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
    //C的不足
    //1.可能会忘记初始化和销毁     ->C++优化 构造函数和析构函数
    Stack_cpp<int> stack_cpp;
    //2.非法修改                  ->C++优化 类+访问限定符
    st.capacity = 0;
    stack_cpp._date = 1;

    //3.无法同时创建两种类型的栈    ->C++优化 模板类
    Stack_cpp<double> st2;

    return 0;
}