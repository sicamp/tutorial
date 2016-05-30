#include <cstdio>
#include <cstring>

using namespace std;

int const maxN = 60;
int const dx[4] = { 1, 0, -1, 0 };
int const dy[4] = { 0, 1, 0, -1 };
char const directions[4] = { 'S', 'E', 'N', 'W' };

struct Point{
    int x, y;
    Point() : x(0), y(0){}
    Point(int _x, int _y) : x(_x), y(_y){}

    Point operator+(const Point & other)const
    {
        return Point(x + other.x, y + other.y);
    }

    Point makeTurn(int direction)const
    {
        return *this + Point(dx[direction], dy[direction]);
    }

    bool operator !=(const Point & other)const
    {
        return x != other.x || y != other.y;
    }

    void print()const
    {
        printf("%d %d\n", x + 1, y + 1);
    }
};

struct Map{
    char map[maxN][maxN];
    int dirs[maxN][maxN];
    bool used[maxN][maxN];
    int n;

    void scan()
    {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", map[i]);
        }
    }

    void setUsed(Point v)
    {
        used[v.x][v.y] = true;
    }

    void clear()
    {
        memset(used, false, sizeof(used));
    }

    char& operator[](Point v)
    {
        return map[v.x][v.y];
    }

    Point sym(Point v)const
    {
        return Point(n - 1 - v.x, n - 1 - v.y);
    }

    bool good(Point v)const
    {
        return v.x >= 0 && v.x < n && v.y >= 0 && v.y < n && !used[v.x][v.y] && map[v.x][v.y] != '#';
    }

    void setDirection(Point v, int dir)
    {
        dirs[v.x][v.y] = dir;
    }
};

Map map;


void makeMapSymmetric()
{
    for (int i = 0; i < map.n; i++)
    {
        for (int j = 0; j < map.n; j++)
        {
            Point c(i, j);
            if (map[c] == '#' || map[map.sym(c)] == '#')
                map[c] = map[map.sym(c)] = '#';
            else if (map[c] == '.' || map[map.sym(c)] == '.')
                map[c] = map[map.sym(c)] = '.';
        }
    }
}

Point s, f;

bool dfs(Point v)
{
    map.setUsed(v);
    if (v != s && v != map.sym(s) && map[v] == '*')
    {
        f = v;
        return true;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        Point u = v + Point(dx[dir], dy[dir]);
        if (map.good(u))
        {
            map.setDirection(u, (dir + 2) % 4);
            if (dfs(u))
                return true;
        }
    }
    return false;
}

void getPath(Point v)
{
    v.print();
    while (v != s)
    {
        int dir = map.dirs[v.x][v.y];
        printf("%c", directions[dir]);
        v = v + Point(dx[dir], dy[dir]);
    }
    printf("\n");
}

bool solve()
{
    map.clear();
    if (dfs(s))
    {
        getPath(f);
        return true;
    }
    return false;
}

int main()
{
    freopen("moles.in", "r", stdin);
    freopen("moles.out", "w", stdout);
    map.scan();
    makeMapSymmetric();
    for (int i = 0; i < map.n; i++)
    {
        for (int j = 0; j < map.n; j++)
        {
            s = Point(i, j);
            if (map[s] != '*')
                continue;
            if (solve())
            {
                return 0;
            }
        }
    }
    return 0;
}
