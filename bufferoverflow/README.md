
[youtube]
https://github.com/igavriil/buffer-overflow

http://www.cse.scu.edu/~tschwarz/coen152_05/Lectures/BufferOverflow.html

https://github.com/igavriil/buffer-overflow

http://guang.logdown.com/posts/236293-c-programs-memory-usage
# stack diagram


---------------------------
stack before calling foo
--------------------------


--------------------------
buf[3] buf[2] buf[1] buf[0]
buf[7] buf[6] buf[5] buf[4]
              buf[8] buf[9]
-------------------------
argument of foo
-----------------------
address of return
---------------------------
stack before calling foo
--------------------------


If you use an older version of Visual Studio, 
you will not get this error message, 
but one that is much more helpful for the attacker. 
Microsoft is trying to stem this type of an attack. If you use a different compiler, 
e.g. on a Unix system, the stack will look quite different. 

This is because compilers have freedom in how to structure the stack, and also, 
because they try to prevent exactly this type of problem.


-------------------- high address
# stack : OS will handle it
#  存放"Automatic Variables"，比方說function內的local variable
# record function的堆疊狀況，比如caller的address，讓function結束後可以順利return。每個function都有自己的堆疊空間，不同function的變數不會互相干擾
1.local variable
2.function 
    function argument
    return address
a0
a1
a2
a3
----------------------

heap and stack shared

---------------------
# heap
malloc and free

a3
a2
a1
a0
-------------------
# bss : uninitialized data
# initialized to zero by exec
# 包含所有宣告為global/static的變數中，沒有任何初始值，或是初始值為0的變數
(global)int i;
(global)int i=0;
static int i; // BBS segment
static int j = 0 ; // BBS segment

-------------------
# initialized data
# read from program by exec
(global)int a = 1 ; //RW
const int a = 1; //R

---------------------------
# text



---------------------------low address
# 
