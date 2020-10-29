from itertools import product
import re

ef combo_1(main_parent_band,child_band):
    main_parent_list = main_parent_band.split("\n")
    child_band_list = child_band.split("\n")
    main_parent_setup = []
    
    for i in range(0,len(main_parent_list)):
        main_parent_loop = re.findall(r'\d+\.*\d*',str(main_parent_list[i]))
        main_parent_setup.append(main_parent_loop)

    superset =list(product(*main_parent_setup))
    #print("superset:",superset)

    child_setup = []
    for j in range(0,len(child_band_list)):
        child_loop = re.findall(r'\d+\.*\d*',str(child_band_list[j]))
        child_setup.append(child_loop)
    
    child = list(product(*child_setup))

    #print("child_setup:",child)
