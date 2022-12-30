// composite.cpp : Defines the entry point for the console application.
//
#pragma warning(disable: 4786)

#include <iostream.h>
#include <vector>
#include <map>


using namespace std;
class Shape;

//different IDs have been hard coded here
#define  ID_LINE1 0
#define ID_LINE2  1
#define ID_LINE3  2
#define ID_RECTANGLE1 3
#define ID_PICTURE 4
//end

class LeafClassTypeException
{
public:
	void printerrormsg()
	{
		cout<<"This is a leaf class"<<endl;
	}
};
//The class shape is working as the component class
class Shape
{
public:
	Shape(){}
	virtual void Add(unsigned int id)
	{
		throw LeafClassTypeException();
	};
	virtual void Remove(unsigned int id){};
	
	//leaf classes will not override it..however, it will be overridden by the composite class.
	virtual Shape* GetChild(unsigned int id)
	{
		throw LeafClassTypeException();
	};
	
	//Using this reference the "Chain of Responsibility" can be implemented
	virtual Shape* GetParentOfComponent()
	{
		return ParentOfComponent;
	};

	virtual void SetParentOfComponent(Shape* s)
	{
		ParentOfComponent = s;
	}
	
	virtual void Display(){};

	
	virtual Shape* FindItem(unsigned int id); //implementation afterwards
	
	virtual ~Shape(){};

protected:	
	Shape* ParentOfComponent;
	unsigned int resource_id;
};

typedef map <unsigned int, Shape*, less<unsigned int> > theMap;

theMap Resource_Map;
theMap::iterator theIterator;

Shape* Shape::FindItem(unsigned int id)
{
	theIterator = Resource_Map.begin();
		while (theIterator != Resource_Map.end())
		{
		theIterator = Resource_Map.find(id);
		Shape* s = (*theIterator).second;
		theIterator++;
		return s;
		}

		return NULL;
}


class Point : public Shape
{
public:
	Point():x_Coord(0),y_Coord(0){}
	Point(int x, int y):x_Coord(x), y_Coord(y){}
	Point(const Point& p)
	{
		x_Coord = p.x_Coord;
		y_Coord = p.y_Coord;
	}
	Point& operator = (const Point& p)
	{
		x_Coord = p.x_Coord;
		y_Coord = p.y_Coord;
		
		return *this;
	}

	virtual void Display()
	{
		cout<<"X Coordinate is:"<<x_Coord<<endl;
		cout<<"Y Coordinate is:"<<y_Coord<<endl;
	}

	int X_COORD() 
	{
		return x_Coord;
	}

	int Y_COORD()
	{
		return y_Coord;
	}

	virtual ~Point(){}
private:
	int x_Coord;
	int y_Coord;
};
//class Line is working as a leaf class.. Lets implement it as a final class
class Line : public Shape
{
private:
	Line(unsigned int id):begin(0,0),end(0,0)
	{
		resource_id = id;
		Resource_Map.insert(theMap::value_type(resource_id,(Shape*)this));
	}
	
	Line(unsigned int id, Point a, Point b):begin(a),end(b)
	{
		resource_id = id;
		Resource_Map.insert(theMap::value_type(resource_id,(Shape*)this));
	}
	
public:
	virtual void Display()
	{
		cout<<"Begining point is:";
			begin.Display();
		cout<<"End Point is:";
			end.Display();
	}
	static Line* CreateLine(unsigned int id, Point a, Point b)
	{
		return new Line(id,a,b);
	}

	virtual ~Line(){}
private:
	Point begin;
	Point end;
};

//this will work as another leaf class. Lets implement it as a final class.
class Rectangle : public Shape
{
private:
	Rectangle(unsigned int id, Point& p, int width, int height)
	{
		top_left = p;
		top_right = Point(p.X_COORD() + width, p.Y_COORD());
		bottom_left = Point(p.X_COORD() , p.Y_COORD() + height); 
		bottom_right = Point(p.X_COORD() + width, p.Y_COORD() + height);
		resource_id = id;
		Resource_Map.insert(theMap::value_type(resource_id,(Shape*)this));

	}
	
public:
	static Rectangle* CreateRectange(unsigned int id, Point& p, int width, int height)
	{
		return new Rectangle(id, p, width, height);
		
	}
	virtual ~Rectangle(){}
	virtual void Display()
	{
		cout<<"The four vertices are:"<<endl;
		cout<<"Top Left :" ;
			top_left.Display();
		cout <<"Top Right :";
			top_right.Display();
		cout<<"Bottom Left :";
			bottom_left.Display();
		cout<<"Bottom Right :";
			bottom_right.Display();
		
	}

	//Attributes
private:
	Point top_left;
	Point top_right;
	Point bottom_left;
	Point bottom_right;
};

//this will work as a composite class
class Picture : public Shape
{
public:
	Picture(unsigned int id)
	{
		resource_id = id;
		Resource_Map.insert(theMap::value_type(resource_id,(Shape*)this));
	}
	virtual void Display()
	{
		vector<Shape*>::iterator p = Components.begin();
		while (p != Components.end())
		{
			(*p)->Display();
			p++;
		}
	}

	//Adds the component with the resource id equal to the passed parameter
	virtual void Add (unsigned int id)
	{
		Shape* s = FindItem(id);

		Components.push_back(s);

		s->SetParentOfComponent(this);
			
	}
	
	//removes the  component from the list with the resource_id equal to the parameter passed
	virtual void Remove(unsigned int id)
	{
		Shape* s = FindItem(id);
		vector<Shape*>::iterator p = Components.begin();
		int pos = 0;
		while (p != Components.end())
		{
			if(Components.at(pos) == s)
				break;
			pos++;
			p++;
		}
		Components.erase(p);
		s->SetParentOfComponent(NULL);
	}
	
	//will return the chile having the id equal to the passed value.
	virtual Shape* GetChild (unsigned int id)
	{
		return FindItem(id);
	}


	virtual ~Picture()
	{
		vector<Shape*>::iterator p = Components.begin();
		
		int pos = 0;
		while (p != Components.end())
		{
			delete(Components.at(pos));
			p++;
			pos++;
		}
		
		
		Components.clear();
	}
private:
	vector<Shape*> Components;
};


void main()
{
	Point p1(10,20);
	Point p2(30,40);
	Point p3(50,60);
	Point p4(70,80);
	Point p5(100,110);
	Point p6(150,200);
	Line* l1 = Line::CreateLine(ID_LINE1,p1,p2);
	try
	{
	l1->Add(0);
	}
	catch(LeafClassTypeException& e)
	{
		e.printerrormsg();
	}
	Line* l2 = Line::CreateLine(ID_LINE2,p3,p4);
	Line* l3 = Line::CreateLine(ID_LINE3,p5,p6);
	
	Rectangle* r1 = Rectangle::CreateRectange(ID_RECTANGLE1, p1, 50,25);


	Shape* p = new Picture(ID_PICTURE);
	p->Add(ID_LINE1);
	p->Add(ID_LINE2);
	p->Add(ID_LINE3);
	p->Add(ID_RECTANGLE1);
	
	(p->GetChild(ID_RECTANGLE1))->Display();

	p->Remove(ID_RECTANGLE1);

	p->Display();
	
	cout<<p<<endl;

	cout<<l1->GetParentOfComponent()<<endl;
	
	delete p;
	
}



