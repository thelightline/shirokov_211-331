#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

bool palindrom(string word)
{
	bool flag = true;
	deque<char> pal;
	for (int i = 0; i < word.size(); i++)
		pal.push_back(word[i]);
	while (pal.size() > 1)
	{
		if (pal.front() == pal.back())
		{
			pal.pop_back();
			pal.pop_front();
		}
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}

struct point
{
	double x, y;
};

bool cmp(point A, point B) //компаратор для сортировки точек слева направо
{
	return A.x < B.x || A.x == B.x && A.y < B.y;
}

bool cw(point A, point B, point C)  //clockwise - по часовой стрелке
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) < 0;
}

bool ccw(point A, point B, point C) //counterclockwise - против чаосовой стрелке
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) > 0;
}

void convex_hull(deque<point>& A)
{
	if (A.size() == 1)  return;

	sort(A.begin(), A.end(), &cmp); //слева направо с увеличением у

	point p1 = A[0], p2 = A.back();
	deque<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (i == A.size() - 1 || cw(p1, A[i], p2))
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], A[i]))
				up.pop_back();
			up.push_back(A[i]);
		}
		if (i == A.size() - 1 || ccw(p1, A[i], p2))
		{
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], A[i]))
				down.pop_back();
			down.push_back(A[i]);
		}
	}
	A.clear();

	for (size_t i = 0; i < up.size(); ++i)
		A.push_back(up[i]);
	for (size_t i = down.size() - 2; i > 0; --i)
		A.push_back(down[i]);
}

int main()
{
	int key = 1;
	int n, x, y;
	deque<point> pts;
	point temp;
	string a;

	while (key != 0)
	{
		cout << "1. Palindrom \n"
			<< "2. Convex hull \n"
			<< "0. Exit \n\n"
			<< "Select task: ";
		cin >> key;
		cout << "\n";
		switch (key)
		{
		case 1:
			cout << "Enter a string: ";
			cin >> a;
			if (palindrom(a))
				cout << "String is palindrome." << "\n\n";
			else 
				cout << "String is not palindrome." << "\n\n";
			break;

		case 2:
			cout << "Enter number of points: ";
			cin >> n;
			cout << "Enter coordinate of points:\n";
			for (int i = 0; i < n; i++)
			{
				cin >> x >> y;
				temp.x = x;
				temp.y = y;
				pts.emplace_back(temp);
			}
			cout << "\n";
			convex_hull(pts);
			cout << "Convex hull:" << "\n";
			for (const auto& point : pts) //const auto& автоматически заменяет расписывание итератора easy-to-write метод
				cout << point.x << " " << point.y << "\n";
			cout << "\n";
			break;

		default:
			return 0;
		}
	}
	return 0;
}