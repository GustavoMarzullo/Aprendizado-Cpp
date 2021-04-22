import os 

print('Testando a funcionalidade Python/C++')
print('Fazendo a integral da função f(x)=x^2 de 0 a 1')
print('Valor analítico é igual a 0,333...\n')
print('Compilando o arquivo C++')
os.system('c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` int_mc.cpp -o int_mc`python3-config --extension-suffix`')
print('Compilado!\n')
print("Importando a função integral")
from int_mc import integral
print("Calculando a integral de Monte Carlo de 0 a 1 com 100 milhões de pontos")
A=integral(lambda x: x**2,0,1,int(1e8))
print("Integral =",round(A,5))
os.remove("int_mc.cpython-38-x86_64-linux-gnu.so")



