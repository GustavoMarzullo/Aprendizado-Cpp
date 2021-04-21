import numpy
import sys
sys.setrecursionlimit(1500000000)

def int(a,b,deltax=0.000001):
    '''Retorna a integral de uma funcao qualquer f definida.'''
    total=0	
    for i in numpy.arange(a,b,deltax):
        total+=i*i
    return total*deltax

def simp(a,b,n=1e3 ):
    '''Usa a regra de simpson para retornar uma integral definida. Precisa-se definir uma função f anteriormente.'''
    assert n%2==0, 'O n precisa ser par.'
    deltax=(b-a)/n
    try:
        soma_I= f(a)+f(b)

        soma_II=0 #somaII (termos com n ímpar na regra de simpson)
        for i in numpy.arange(a+deltax,b,2*deltax):
            y=f(i)
            soma_II+=y

        soma_III=0 #somaIII (termos com n par na regra de simpson)
        for p in numpy.arange(a+2*deltax,b,2*deltax):
            z=f(p)
            soma_III+=z

        integral=(soma_I+4*soma_II+2*soma_III)*(deltax/3)
        return integral
    except NameError:
        print('A função f não foi definida.')
