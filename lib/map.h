#define MAX_HEIGHT 100
#define MAX_WIDTH 100

#define MIN_ROOMS 1
#define MAX_ROOMS 10

typedef tile_graphic char;
typedef map_coord uint32;

struct tile_t{
	tile_graphic m_graphic;
	bool         m_passable;
	bool         m_seen;
}

struct map_t{
	public:
	    map_t();
		void move(map_coord x, map_coord y);
	private:
	    tile_graphic[MAX_HEIGHT][MAX_WIDTH] m_tile_array;
}
