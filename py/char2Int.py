#coding:utf-8
'''
map/reduce�Ǹ߽׺���
map(fn,(x1,x2,x3))���б����ʽ���أ�fn����������x1,x2,x3Ԫ��
reduce(fn,(x1,x2,x3))==fn(fn(x1,x2),x3)
'''

def fn(x,y):
    '''
    python 2.7���޷������ݷ�Χ����0x7fffffff��Χʱ,���Զ�ת��Ϊlong����,�򲻻����
    '''
    return x*10+y

def char2Int(s):
    res = None

    try:
        res = {'0':0,'1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '0':0}[s]
    except Exception as e:
        print "�쳣������:%s"%type(e)
    finally:
        return res 

if __name__ == '__main__':
    tmp = map(char2Int, "")
    
    if tmp is not None:
        print reduce(fn, tmp)
    

