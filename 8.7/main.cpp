//
//  main.cpp
//  8.7
//
//  Created by Skye-钟半仙 on 17/8/7.
//  Copyright © 2017年 Skye-钟半仙. All rights reserved.
//
//////////
#include <iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <map>

using namespace std;
using namespace std::placeholders;

//Demo15
template<typename T>
void output(T& t){
    typename T::iterator itor;
    itor=t.begin();
    while (itor!=t.end()){
        cout<<*(itor++)<<" ";
    }
    cout<<endl;
}

void test_stack(){
    deque<int>mydeque(2,100);
    output(mydeque);
    vector<int>myvector(2,200);
    output(myvector);
    
    stack<int>first;
    stack<int>second(mydeque);
    
    stack<int,vector<int>>third;
    stack<int,vector<int>>fourth(myvector);
    
    cout<<"size of first: "<<(int)first.size()<<endl;
    cout<<"size of second: "<<(int)second.size()<<endl;
    cout<<"size of third: "<<(int)third.size()<<endl;
    cout<<"size of fourth: "<<(int)fourth.size()<<endl;
    cout<<"---------------------------------"<<endl;
}

//Demo16
void test_push_pop_empty_size(){
    stack<int>mystack;
    int sum(0);
    cout<<"空栈:size: "<<(int)mystack.size()<<endl;
    
    for (int i=1; i<=10; ++i) {
        mystack.push(i);
    }
    cout<<"满栈:size: "<<(int)mystack.size()<<endl;
    mystack.top()=100;
    cout<<"poping out elements...\n";
    while (!mystack.empty()) {
        sum+=mystack.top();
        cout<<" "<<mystack.top()<<" ";
        mystack.pop();
    }
    cout<<endl;
    cout<<"栈中元素的数据和:total: "<<sum<<endl;
    cout<<"出栈后:size: "<<(int)mystack.size()<<endl;
    cout<<"---------------------------------"<<endl;
}

int QQ=12;
typedef int (*fun)(int,int);

void printResult(fun f){
    int a=10,b=20;
    cout<<f(a,b)<<endl;
}

int add(int i,int j){
    return i+j;
}

//auto mod=[](int i,int j){
//    return i%j;
//};

class Divide{
public:
    int operator()(int denominator,int divisor){
        return denominator/divisor;
    }
};

void callF(int a,int b){
    printf("a:%d\n",a);
    printf("b:%d\n",b);
}

int main(int argc, const char * argv[]) {
    
    test_stack();
    test_push_pop_empty_size();
//    int aa=3;
//    int bb=4;
//    int sz=5;
//    auto vv =[=]()mutable{
//        sz+=1;
//        aa+=1;
//        bb+=2;
//        cout<<sz<<","<<aa<<","<<bb<<endl;;
//    
//    };

    list<int>L{1,2,3,4,5};
    
    L.sort([](const int& a,const int& b){
        return a>b;
    });
    
    for(auto l:L){
    cout<<l<<"\t";
    }
    cout<<"\n---------------------------------"<<endl;
    cout<<endl;
    
    printResult([](int a ,int b){
        return a+b;
    });
    cout<<"\n---------------------------------"<<endl;
   
    
    
//    function<int(int,int)>f1;
//    f1=add;
//    
//    function<int(int,int)>f2=mod;
//    function<int(int,int)>f3=Divide();
//    Divide dd;
//    function<int(int,int)>f4=dd;
//    
//    map<string,function<int(int,int)>>calculator;
//    calculator.insert({"+",f1});
//    calculator.insert({"%",f2});
//    calculator.insert({"/",f3});
//    calculator.insert({"-",minus<int>()});
//    calculator.insert({"*",[](int a,int b){return a*b;}});
//    
//    char c;
//    c=getchar();
//    
//    while (c!='a') {
//        switch (c) {
//            case '+':
//                cout<<calculator["+"](10,3)<<endl;
//                break;
//            case '%':
//                cout<<calculator["%"](10,3)<<endl;
//                break;
//            case '/':
//                cout<<calculator["/"](10,3)<<endl;
//                break;
//            case '-':
//                cout<<calculator["-"](10,3)<<endl;
//                break;
//            case '*':
//                cout<<calculator["*"](10,3)<<endl;
//                break;
//                
//            default:
//                break;
//        }
//        c=getchar();
//    }
    
    
    
    auto newCallF=std::bind(callF, _10,_3);
    newCallF(2,3,4,5,6,1,2,3,4,5,5);
    cout<<"\n---------------------------------"<<endl;
    
    return 0;
}
