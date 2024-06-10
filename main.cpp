#include<iostream>
#include<cassert>
#include<ctime>

#include"StackAlloc.hpp"
#include"MemoryPool.hpp"
using namespace std;

//插入元素个数
#define ELEMS 100000

//重复次数
#define REPS 100


int main()
{
    clock_t start;
    //使用stl默认分配器
    StackAlloc<int,std::allocator<int> > stackDefault;
    start=clock();
    for(int i=0;i<REPS;i++)
    {
        assert(stackDefault.empty() );
        for(int j=0;j<ELEMS;j++)
        {
            stackDefault.push(j);
        }

        for(int j=0;j<ELEMS;j++)
        {
            stackDefault.pop();
        }

    }
    //使用CLOCKS_PER_SEC将程序运行到现在的cpu转化成秒数
    cout<<"Default time :"<<( ( (double)clock()-start  )/CLOCKS_PER_SEC)<<endl;


    // 现在测试使用内存池
    StackAlloc<int, MemoryPool<int> > stackPool;
    start = clock();
    for (int j = 0; j < REPS; j++) {
        assert(stackPool.empty());
        for (int i = 0; i < ELEMS; i++)
            stackPool.push(i);
        for (int i = 0; i < ELEMS; i++)
            stackPool.pop();
    }
    cout << "MemoryPool Allocator Time: ";
    cout << (((double)clock() - start) / CLOCKS_PER_SEC) << endl;




    

    return 0;
}
