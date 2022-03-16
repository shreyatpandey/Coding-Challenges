'''
A prison has the following parameters:
n: integer, the number of horizontal bars initially
m: integer, the number of vertical bars initially
h[x]: an array of integers, the horizontal bars to remove
v[y]: an array of intgers, the vertical bars to remove

return type:
int: a long integer denoting the area of the biggest hole in the prison gate's bars

the values in array h are distinct
the values in array v are distinct
'''
def prisont(n,m,h,v):
    _x = [0*i for i in range(n+1)]
    _y = [0*i for i in range(m+1)]
    for hor in h:
        _x[hor] = 1
    for vert in v:
        _y[vert] = 1
    x_,y_ = 0,0
    j = 0
    for i in range(1,n+1):
        if not _x[i]:
            j = 0
        else:
            j += 1
            x_ = max(x_,j)
    for i in range(1,m+1):
        if not _y[i]:
            j = 0
        else:
            j += 1
            y_ = max(y_,j)
    return (x_+1)*(y_+1)
