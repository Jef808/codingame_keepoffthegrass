#include "position.hpp"

#include <climits>
#include <iostream>

namespace offgrass {

bool Position::operator==(const Position& other) const {
	return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& stream, const Position& position) {
	return stream << position.x << ' ' << position.y;
}

std::istream& operator>>(std::istream& stream, Position& position) {
	return stream >> position.x >> position.y;
}

unsigned long ManhattanDistance(const Position &a, const Position &b) {
	return (std::max(a.x, b.x) - std::min(a.x, b.x))
		+ (std::max(a.y, b.y) - std::min(a.y, b.y));
}

unsigned long EuclideanDistanceSqr(const Position &a, const Position &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

}  // namespace offgrass
