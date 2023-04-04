//������ �����ε��� Ŭ������ �����ڸ� �����ų �� �ֵ��� �����ϴ� ���̴�.

#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y){}	//x�� y�� �ʱ�ȭ���� ������, x�� y�� ���� 0���� ��������.
	void Show() { cout << "[" << xpos << ", " << ypos << "]" << endl; }
	Point& operator+=(const Point& ref)	//Point ��ü�� �����Ѵ�. ��ȯ�� �ּҿ� �ϱ� ������ &�� ����.
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return*this;
	}
	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return*this;
	}
	Point operator+(const Point& ref)	//���� ��ü�� ������ ��ġ�� �ʴ´�.
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	Point operator-(const Point& ref)
	{
		Point pos(xpos - ref.xpos, ypos - ref.ypos);
		return pos;
	}
	friend bool operator==(const Point& ref1, const Point& ref2);
	friend bool operator!=(const Point& ref1, const Point& ref2);
};
bool operator==(const Point& ref1, const Point& ref2)
{
	if (ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos)return true;
	else return false;
}
bool operator!=(const Point& ref1, const Point& ref2) { return !(ref1 == ref2); }	//==�� �ݴ�Ǵ� ����� �Ѵ�.