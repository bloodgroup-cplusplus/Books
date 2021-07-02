/* suppose you're working with a class your colleague wrote and you want
 * to extend that class's functionality. How would you do it, without modifying
 * the original code? Well, one approach is inheritence: You make a derived class and the functionality you need, maybe even override something, and you're good to go.
 *
 * This doesn't always work, and there are many reasons why .. we wouldn't want
 * to inherit from std::vector due to lack of virtual destructor.
 * Inheritence doesn't work when we need several enhancements,and you want to keep those enhancements seperate, to maintain singleton.
 * Decorator pattern allows us to enhance exisiting types without either modifying the original types ( open-closed princlepe)
 *
 * Suppose you have a class called Shape and you Make two inheritors called Colored Shape and Transparent Shape You also need to take into account that someone will need a ColoredTransparentShape. So we've generated three classes to support
 * just two enhancements. If we had three enhancements, we would need seven distinct classes.
 *
 */

//Let's actually write some code for this.

#include<sstream>
#include<iostream>
#include<string>
#include<ostream>
struct Shape
{
        virtual std::string str() const=0;
};



// we can now implement shapes such as Circle or Square with this interface
//

struct Circle :Shape
{
        float radius;
        explicit Circle(const float radius):radius{radius}{}


        void resize(float factor){radius*=factor;}


        std::string str() const override
        {
                std::ostringstream oss;
                oss<<"A circle of radius"<<radius;
                return oss.str();
        }

};
// this was using a normal inheritence.. Let's try using a decorator (dynamic)
//
//


struct ColoredShape : Shape
{
        Shape & shape;
        std::string color;
        ColoredShape( Shape &shape, const std::string & color):shape{shape},color{color}{}

        std::string str() const override
        {
                std::ostringstream oss;
                oss<<shape.str()<<"  Has the color "<<color;
                return oss.str();
        }

};


int main()
{
        Circle circle{0.5f};
        ColoredShape redCircle{circle,"red"};
        std::cout<<redCircle.str();
        return 0;
}

