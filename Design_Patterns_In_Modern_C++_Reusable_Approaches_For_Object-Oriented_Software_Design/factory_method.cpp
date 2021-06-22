#include<iostream>
#include<math.h>
struct Point
{
        protected:
                Point (const float x, const float y) :x{x},y{y}{}

        public:

                float x,y,r;
                static Point NewCartesian(float x, float y)
                {
                        return {x,y};
                }


                static Point NewPolar(float r, float theta)
                {
                        return {r*cos(theta),r*sin(theta)};
                }

};

int main()
{
        auto p= Point::NewPolar(5,M_PI_4);
        return 0;
}
