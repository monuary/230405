//연산자 오버로딩은 클래스에 연산자를 적용시킬 수 있도록 정의하는 것이다.

#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y){}	//x나 y가 초기화되지 않으면, x나 y의 값이 0으로 맞춰진다.
	void Show() { cout << "[" << xpos << ", " << ypos << "]" << endl; }
	Point& operator+=(const Point& ref)	//Point 객체를 변경한다. 반환을 주소에 하기 때문에 &를 쓴다.
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
	Point operator+(const Point& ref)	//원래 객체에 영향을 미치지 않는다.
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
bool operator!=(const Point& ref1, const Point& ref2) { return !(ref1 == ref2); }	//==와 반대되는 출력을 한다.