def f(s):
    def fn(func):
        def wrapper(*args,**kw):
            print s
            return func(*args,**kw)
        return wrapper
    return fn


@f(s="hello")
def stu():
    print "stu"

@f(s="hello")
def tea():
    print "teacher"

stu()
tea()
