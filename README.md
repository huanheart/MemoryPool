# 高性能内存池的实现

主要自己实现了一个链栈，然后使用stl默认分配器以及自己内存池实现的分配器进行一个比较。


直观发现，内存池在当前场景下效率比默认分配器要高

## 测试步骤
* 拉取到本地后，使用命令  make
* 将会得到memory_pool文件,使用命令 ./memory_pool 即可运行起来

## 测试结果图
 **百万数据的时间耗费比**

![image](https://github.com/huanheart/MemoryPool/assets/144020230/88bf6926-cc0d-4e66-a011-e125cd05690b)

