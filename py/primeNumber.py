#coding:utf-8
from math import sqrt

def isPrimeNumber1(number):
    '''
    如果一个数存在出自身和1，还有其它因子；
    要么两个因子相等，等于输入数开方（tmp）
    要么一个因子小于tmp,一个大于tmp，所以只需要遍历2-tmp是否存在因子即可
    '''
    tmp = int(sqrt(number))

    for i in xrange(2,tmp+1):
        if number % i == 0:
            return False

    return True


def isPrimeNumber2(number):
    '''
    1、小于5只有2，3是素数

    2、通过观察大于5的素数基本都是6X-1,6X+1（7，11，13...），所以以6为周期将一个周期之类的数表示如下：
    6X-1,6X,6X+1,6X+2,6X+3,6X+4

    由上可知：6x,6x+2[2(3x+1)],6x+3[3(2x+1)],6x+4[2(3x+2)]肯定不是素数；
    6x-1和6x+1可能是素数，则以6为步进值，观察6x+1,6x-1是不是素数即可    
    '''

    if number == 2 or number == 3:
        return True
    
    if number % 6 != 1 and number % 6 != 5:
        return False

    tmp = int(sqrt(number))

    for i in xrange(5,tmp+1, 6):
        if number % i == 0:
            return False

    return True


def generateNum(numList):
    return filter(isPrimeNumber1, numList)

if __name__ == '__main__':
    print generateNum([1,2,3,4,5,6,7,8,9])
