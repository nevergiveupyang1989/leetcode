#coding:utf-8
from math import sqrt

def isPrimeNumber1(number):
    '''
    ���һ�������ڳ������1�������������ӣ�
    Ҫô����������ȣ�����������������tmp��
    Ҫôһ������С��tmp,һ������tmp������ֻ��Ҫ����2-tmp�Ƿ�������Ӽ���
    '''
    tmp = int(sqrt(number))

    for i in xrange(2,tmp+1):
        if number % i == 0:
            return False

    return True


def isPrimeNumber2(number):
    '''
    1��С��5ֻ��2��3������

    2��ͨ���۲����5��������������6X-1,6X+1��7��11��13...����������6Ϊ���ڽ�һ������֮�������ʾ���£�
    6X-1,6X,6X+1,6X+2,6X+3,6X+4

    ���Ͽ�֪��6x,6x+2[2(3x+1)],6x+3[3(2x+1)],6x+4[2(3x+2)]�϶�����������
    6x-1��6x+1����������������6Ϊ����ֵ���۲�6x+1,6x-1�ǲ�����������    
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
