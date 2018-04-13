#include<iostream>

using namespace std;

const int Maxsize = 1000;//����ѭ������Ԫ�ظ�������

template<class T>
class CircleQueue
{
private:
	T data[Maxsize];
	int front; //��ͷ�±�
	int rear; //��β�±�
public:
	CircleQueue() //�޲ι��캯��
	{
		front = 0;
		rear = 0;
	}
	void EnQueue(T x); //���
	T DeQueue(); //����
	T GetFront(); //���Ҷ�ͷԪ��
	int GetLength(); //����г���
	void Print() //��������
	{
		for (int i = front; rear != i; i = (i + 1) % Maxsize)
		{
			cout << data[(i+1)%Maxsize]<<" ";
		}
	}
	bool Empty()
	{
		return front == rear ? true : false;
	}; //�жӿ�
};

template<class T>
void CircleQueue<T>::EnQueue(T x) //ʵ����Ӳ���
{
	if ((rear + 1) % Maxsize == front)
		throw"����";
	rear = (rear + 1) % Maxsize;  //��βָ�롰���ơ�һ��
	data[rear] = x;
}

template<class T>
T CircleQueue<T>::DeQueue() //����
{
	if (rear == front)
		throw"����";
	front = (front + 1) % Maxsize; //��ͷָ�������¡�һ��λ��
	return data[front]; 
}

template<class T>
T CircleQueue<T>::GetFront() //���ʶ���Ԫ��
{
	if (rear == front)
		throw"����";
	return data[(front + 1) % Maxsize];
}

template<class T>
int CircleQueue<T>::GetLength() //����г���
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
	M.Print(); //������Ӳ���
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<M.DeQueue()<<" ";
	}
	cout << endl;
	M.Print(); //������Ӳ���
	cout << endl;
	cout << M.GetFront() << M.GetLength() << endl; //�����ͷ�Ͷ��г���
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
	} //�����쳣�������
	system("pause");
	return 0;
}