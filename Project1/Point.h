#pragma once
#include <vector>

#define UNIT_VECTOR_0 0,0
#define UNIT_VECTOR_NORTH 0,-1
#define UNIT_VECTOR_EAST 1,0
#define UNIT_VECTOR_SOUTH 0,1
#define UNIT_VECTOR_WEST -1,0

class Point {
private:
	int x, y;
public:
	Point();
	Point(const int& x, const int& y);
	int GetX() const;
	int GetY() const;
	int& RefX();
	int& RefY();
	void Set(const int& x, const int& y);
	void SetX(const int& x);
	void SetY(const int& y);
	void Offset(const Point& point);
	void Offset(const int& x, const int& y);
	void OffsetX(const int& x);
	void OffsetY(const int& y);

	static const Point O;
	static const Point North;
	static const Point East;
	static const Point West;
	static const Point South;

	bool operator== (const Point& other);
	bool operator!= (const Point& other);

	static Point GetRandomUnitVector();
	static Point GetRandomPoint(const int& xMin, const int& yMin, const int& xMax, const int& yMax);
	
	static std::vector<Point> GetAllUnitVectors();
	static std::vector<Point> GetOffsetByAllUnitVectors(const Point& point);
};