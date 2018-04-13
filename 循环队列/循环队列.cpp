#include<iostream>

using namespace std;

const int Maxsize = 1000;//定义循环队列元素个数上限

template<class T>
class CircleQueue
{
private:
	T data[Maxsize];
	int front; //队头下标
	int rear; //队尾下标
public:
	CircleQueue() //无参构造函数
	{
		front = 0;
		rear = 0;
	}
	void EnQueue(T x); //入队
	T DeQueue(); //出队
	T GetFront(); //查找队头元素
	int GetLength(); //求队列长度
	void Print() //遍历函数
	{
		for (int i = front; rear != i; i = (i + 1) % Maxsize)
		{
			cout << data[(i+1)%Maxsize]<<" ";
		}
	}
	bool Empty()
	{
		return front == rear ? true : false;
	}; //判队空
};

template<class T>
void CircleQueue<T>::EnQueue(T x) //实现入队操作
{
	if ((rear + 1) % Maxsize == front)
		throw"上溢";
	rear = (rear + 1) % Maxsize;  //队尾指针“后移”一个
	data[rear] = x;
}

template<class T>
T CircleQueue<T>::DeQueue() //出队
{
	if (rear == front)
		throw"上溢";
	front = (front + 1) % Maxsize; //队头指针移向“下”一个位置
	return data[front]; 
}

template<class T>
T CircleQueue<T>::GetFront() //访问队首元素
{
	if (rear == front)
		throw"下溢";
	return data[(front + 1) % Maxsize];
}

template<class T>
int CircleQueue<T>::GetLength() //求队列长度
{
	return (rear - front + Maxsize) % Maxsize;
}

int main()
{
	CircleQueue<int> M;
	for (int i = 0; i < 20; i++)
	{
		M.EnQueue(i + 1);
	}
	M.Print(); //检验入队操作
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<M.DeQueue()<<" ";
	}
	cout << endl;
	M.Print(); //检验出队操作
	cout << endl;
	cout << M.GetFront() << M.GetLength() << endl; //检验队头和队列长度
	try
	{
		for (int i = 0; i < 1000; i++)
			M.EnQueue(i);

	}

	catch (const char * msg)
	{
		cerr << msg<<endl;
	}


	try
	{
		for (int i = 0; i < 1001; i++)
			M.DeQueue();

	}

	catch (const char * msg)
	{
		cerr << msg << endl;
	} //检验异常处理机制
	system("pause");
	return 0;
}