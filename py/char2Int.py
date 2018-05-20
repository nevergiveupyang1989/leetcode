#coding:utf-8
'''
map/reduce是高阶函数
map(fn,(x1,x2,x3))以列表的形式返回，fn依次作用于x1,x2,x3元素
reduce(fn,(x1,x2,x3))==fn(fn(x1,x2),x3)
'''

def fn(x,y):
    '''
    python 2.7当无符号数据范围超出0x7fffffff范围时,将自动转换为long类型,则不会溢出
    '''
    return x*10+y

def char2Int(s):
    res = None

    try:
        res = {'0':0,'1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '0':0}[s]
    except Exception as e:
        print "异常对象是:%s"%type(e)
    finally:
        return res 

if __name__ == '__main__':
    tmp = map(char2Int, "")
    
    if tmp is not None:
        print reduce(fn, tmp)
    

