#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct Point{

        int x,y;

        Point(){}
        Point(int X, int Y)
        {
                x=X;
                y=Y;
        }

};

Point rootPoint;

int pointLocation(Point a, Point b,  Point c)
{

        int vectorProduct = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

        if(vectorProduct>0) return  -1;
        else if(vectorProduct<0) return  1;

        return 0;;
}

int pointDistance(Point a, Point b){

        int X = a.x - b.x, Y = a.y - b.y;

        return X * X + Y * Y;

}

bool cmp(Point a, Point b)
{
        int temp=pointLocation(rootPoint, a, b);

        if(temp==0) return (pointDistance(rootPoint,a)<pointDistance(rootPoint,b));

        return (temp==1);

}

stack<Point> grahamScan(vector<Point> points){

        int numOfpoints=points.size();
        int leastY = 0;
        for (int i = 1; i < numOfpoints; i++)
                if (points.at(i).y < points.at(leastY).y)
                        leastY = i;

        rootPoint=leastY;

        stack<Point> convexHull;
        sort(points+1 ,points+numOfpoints, cmp);
        convexHull.push(points.at(0));
        convexHull.push(points.at(1));
        convexHull.push(points.at(2));

        for(int i=3;i<numOfpoints;i++)
        {
                Point top = convexHull.top();
                convexHull.pop();

			while(Point.pointLocation(convexHull.top(), top, Points.get(i))!=-1)
			{
				top = convexHull.top();
				convexHull.pop();
			}

			convexHull.push(top);
			convexHull.push(Points.at(i));
        }

        return convexHull;
}

int main()
{




        return 0;
}
