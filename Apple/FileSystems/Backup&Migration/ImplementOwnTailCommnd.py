'''
Approach-1
'''
import sys
import os

bufsize = 8192

lines = int(sys.argv[1])
fname = sys.argv[2]
fsize = os.stat(fname).st_size

iter = 0
with open(sys.argv[2]) as f:
    if bufsize > fsize:
        bufsize = fsize-1
    data = []
    while True:
        iter +=1
        f.seek(fsize-bufsize*iter)
        data.extend(f.readlines())
        if len(data) >= lines or f.tell() == 0:
            print(''.join(data[-lines:]))
            break
           
'''
Approach-2
Without using buffer
'''
def tail_file(filename, nlines):
    with open(filename) as qfile:
        qfile.seek(0, os.SEEK_END)
        endf = position = qfile.tell()
        linecnt = 0
        while position >= 0:
            qfile.seek(position)
            next_char = qfile.read(1)
            if next_char == "\n" and position != endf-1:
                linecnt += 1

            if linecnt == nlines:
                break
            position -= 1

        if position < 0:
            qfile.seek(0)

        print(qfile.read(),end='')


if __name__ == '__main__':
    filename = sys.argv[1]
    nlines = int(sys.argv[2])
    tail_file(filename, nlines)
