from time import time
from int_python import int as int_py
from log_int import integral as int_cpp

def main(n=10):
    total_cpp=0
    total_py=0
    for i in range(n):
        #C++
        t0=time()
        int_cpp(2,10)
        t1=time()
        total_cpp+=t1-t0

        #Python
        t0=time()
        int_py(2,10)
        t1=time()
        total_py+=t1-t0
    t_cpp=round(1000*total_cpp/n,1)
    t_py=round(1000*total_py/n,1)
    print('C++:',t_cpp,'ms\n')
    print('Python:',t_py,'ms\n')
    print('Python/C++ =',int(t_py/t_cpp),'\n')
    
    
main()
