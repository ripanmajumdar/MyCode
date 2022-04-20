#include <iostream>
#include <memory>

using namespace std;

class base {
    int i;
    public:
    base(int a):i(a) {}
    void fun(weak_ptr<base> c);
    void fun1(weak_ptr<base> &c);
    int getVal(){return i;}
};

void base :: fun(weak_ptr<base> c) {
    cout<<"Inside of fun(), use_count() = "<<c.use_count()<<"\n";
    if (auto pt=c.lock()) {
        cout<<"Value of i is : "<<pt->getVal();
    }
    
}

void base :: fun1(weak_ptr<base> &c) {
    cout<<"Inside of fun1(), use_count() = "<<c.use_count()<<"\n";
    if (auto pt=c.lock()) {
        cout<<"Value of i is : "<<pt->getVal();
    }
}

int main()
{
    shared_ptr<base> ob=make_shared<base>(10);
    cout<<" 1 :: ob.use_count() : "<<ob.use_count()<<"\n";
    shared_ptr<base> ob1(ob);
    cout<<"2 :: ob.use_count() : "<<ob.use_count()<<"\n";
    weak_ptr<base> ob2;
    ob2=ob;
    cout<<"3 :: ob.use_count() : "<<ob.use_count()<<"\n";
    ob->fun(ob2);
    ob->fun1(ob2);
    return 0;
}
