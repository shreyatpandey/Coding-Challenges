from collections import defaultdict
fileName= "Badge.txt"
with open(fileName,'r') as file:
    buildingMinTime = {}
    buildingMaxTime = {}
    buildingCounter = {}
    buildingPerson = defaultdict(set)
    for lines in file:
        linesplit = lines.split(',')
        person = linesplit[0]
        badge = linesplit[1]
        buildingName = linesplit[2]
        time = linesplit[3].strip()
        if buildingName not in buildingMinTime:
            buildingMinTime[buildingName] = time
            buildingMaxTime[buildingName] = time
            buildingCounter[buildingName] = 1
        else:
            if buildingMinTime[buildingName]< time:
                buildingMinTime[buildingName] = time
            if buildingMaxTime[buildingName] > time:
                buildingMaxTime[buildingName] = time
            buildingCounter[buildingName] += 1
        print(buildingMinTime[buildingName], buildingMaxTime[buildingName] )
        buildingPerson[buildingName].add(person)
    
    for key,values in buildingCounter.items():
        string = key + ": was accessed " + str(values) + " times by " + str(len(buildingPerson[key])) + " person between timeframe " + buildingMinTime[key] + " and " + buildingMaxTime[key]
        print(string)
        with open("Output.txt",'a') as file1:
            file1.write(string+"\n")
