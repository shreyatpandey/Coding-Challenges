'''
Given a calendar with working days and holidays and defined number of vacations/PTO you can take. 
Find how can you plan your PTO so that you get maximum number of days as vacation, 
and return maximun number of vacation days

I/P -
PTO - 3
W H W H W W W H H H

Output - 7
'''

def maximizeVacation(cal,pto):
    pto_added=0
    max_vac=0
    l=0
    for r,item in enumerate(cal):
        if item=="W":
            pto_added+=1
        while pto_added>pto:
            if cal[l]=="W":
                pto_added-=1
            l+=1
        max_vac=max(max_vac,r-l+1)
    return max_vac