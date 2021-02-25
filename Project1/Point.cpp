#include "Point.h"
#include <cstdlib>

const Point Point::O = Point(UNIT_VECTOR_0);
const Point Point::North = Point(UNIT_VECTOR_NORTH);
const Point Point::East = Point(UNIT_VECTOR_EAST);
const Point Point::South = Point(UNIT_VECTOR_SOUTH);
const Point Point::West = Point(UNIT_VECTOR_WEST);

Point::Point() : x(0), y(0) {}

Point::Point(const int& x, const int& y) : x(x), y(y) {}

int Point::GetX() const {
	return x;
}

int Point::GetY() const {
	return y;
}

int& Point::RefX() {
	return x;
}

int& Point::RefY() {
	return y;
}

void Point::Set(const int& x, const int& y) {
	this->x = x;
	this->y = y;
}

void Point::SetX(const int& x) {
	this->x = x;
}

void Point::SetY(const int& y) {
	this->y = y;
}

void Point::Offset(const Point& point) {
	Offset(point.x, point.y);
		
}

void Point::Offset(const int& x, const int& y) {
	OffsetX(x);
	OffsetY(y);
}

void Point::OffsetX(const int& x) {
	this->x += x;
}

void Point::OffsetY(const int& y) {
	this->y += y;
}

bool Point::operator==(const Point& other) {
	return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) {
	return !(*this == other);
}

Point Point::GetRandomUnitVector() {
	int kierunek = std::rand() % 4;
	switch (kierunek)
	{
	case 0:
		return Point::North;
	case 1:
		return Point::East;
	case 2:
		return Point::South;
	case 3:
		return Point::West;
	}
}

Point Point::GetRandomPoint(const int& xMin, const int& yMin, const int& xMax, const int& yMax) {
	int x = (std::rand() % xMax) + xMin;
	int y = (std::rand()% yMax) + yMin;
	return Point(x, y);
}

std::vector<Point> Point::GetAllUnitVectors() {
	std::vector<Point> unitVectors;
	unitVectors.push_back(North);
	unitVectors.push_back(East);
	unitVectors.push_back(South);
	unitVectors.push_back(West);
	return unitVectors;
}

std::vector<Point> Point::GetOffsetByAllUnitVectors(const Point& point) {
	std::vector<Point> offsets;
	std::vector<Point> unitVectors = GetAllUnitVectors();
	for (int i = 0; i < unitVectors.size(); ++i) {
		offsets.emplace_back(point);
		offsets[i].Offset(unitVectors[i]);
	}
	return offsets;
}