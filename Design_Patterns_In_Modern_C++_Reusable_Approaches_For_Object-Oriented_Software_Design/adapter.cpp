// adapter ( simple model as in case of software models)
// client can call paint function and provide only two params x,y
// our client has print function (x,y)
// but it has to be extended to function(x,y,z)
// so such extension  is provided by the adapter
// when there is such dependency by the point function.
// People create an adapter and then adapter 
// complexity does increase
// but it eases out our works
// how heavy or light is it to introduce an adapter.

#include<iostream>
#include<memory>
class IndSocket
{
        public:
                        virtual void indcharge(int type)=0;
};


class USocket
{

        public:
                        void uscharge()
                        {
                                std::cout<<"USA plug is charging " << std::endl;
                        }

};

// this will have ind socket as an input but it will have a support for USA charge as well
// there are several ways to achieve the same way but this is the intuitive socket 
// there is an indian socket and we are attaching adapter to it.
// we are calling indcharge but it's calling us charge
// how to make a single adapter with one inputs and several other outputs 
// only we can choose what to put in the USA board
// we will take and put it inside the USA board .
// we will put Germany into german socket
//

class Gsocket
{
                public:
                        void gcharge()
                        {
                                std::cout<<"G plug is charging "<<std::endl;
                        }
};

class SocketAdapter: public IndSocket, public USocket, public Gsocket
{
        public:
                void indcharge (int type)
                {
                        switch(type)
                        {
                                case 1:
                                        uscharge();
                                        break;
                                case 2:
                                        gcharge();
                                        break;
                                default:
                                        break;
                        }
                }

};

int main()
{
        std::unique_ptr<IndSocket> socket = std::make_unique<SocketAdapter>();
        socket->indcharge(1);
        socket->indcharge(2);
        return 0;
}
