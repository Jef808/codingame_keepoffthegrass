#ifndef POSITION_HPP
# define POSITION_HPP

# include <iosfwd>
# include <string>

namespace offgrass {

struct Position
{
	unsigned long x;
	unsigned long y;

	bool operator==(const Position&) const;

	friend std::ostream& operator<<(std::ostream& stream, const Position&);
	friend std::istream& operator>>(std::istream& stream, Position&);
};

unsigned long ManhattanDistance(const Position& a, const Position& b);
unsigned long EuclideanDistanceSqr(const Position& a, const Position& b);

extern int GeodesicDistance(const Position&);

} // namespace offgrass

#endif
