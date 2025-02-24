import math
from sys import argv


def test_div():
    with open("unit_tests\\data\\div_data.txt", 'r') as f:
        
        lines = f.readlines()
        flag = True
        for line in lines:
            line = line.split()
            if int(line[0]) // int(line[1]) != int(line[2]):
                print(f"НЕВЕРНО -> div({line[0]}, {line[1]}) != {line[2]}. Должно быть {int(line[0]) // int(line[1])}")
                flag = False
            else:
                print(f"ВЕРНО -> div({line[0]}, {line[1]}) = {line[2]}. Должно быть {int(line[0]) // int(line[1])}")

    return flag
    
def test_mod():
    with open("unit_tests\\data\\mod_data.txt", 'r') as f:
        
        lines = f.readlines()
        flag = True
        for line in lines:
            line = line.split()
            if int(line[0]) % int(line[1]) != int(line[2]):
                print(f"НЕВЕРНО -> mod({line[0]}, {line[1]}) != {line[2]}. Должно быть {int(line[0]) % int(line[1])}")
                flag = False
            else:
                print(f"Верно -> mod({line[0]}, {line[1]}) = {line[2]}. Должно быть {int(line[0]) % int(line[1])}")
    return flag

def test_max():
    with open("unit_tests\\data\\max_data.txt", 'r') as f:
        
        lines = f.readlines()
        flag = True
        for line in lines:
            line = line.split()
            if max(int(line[0]), int(line[1])) != int(line[2]):
                print(f"НЕВЕРНО -> max({line[0]}, {line[1]}) != {line[2]}. Должно быть {max(int(line[0]), int(line[1]))}")
                flag = False
            else:
                print(f"ВЕРНО -> max({line[0]}, {line[1]}) = {line[2]}. Должно быть {max(int(line[0]), int(line[1]))}")
        return flag

def test_min(): 
    with open("unit_tests\\data\\min_data.txt", 'r') as f:
        
        lines = f.readlines()
        flag = True
        for line in lines:
            line = line.split()
            if min(int(line[0]), int(line[1])) != int(line[2]):
                print(f"НЕВЕРНО -> min({line[0]}, {line[1]}) != {line[2]}. Должно быть {min(int(line[0]), int(line[1]))}")
                flag = False
            else:
                 print(f"ВЕРНО-> min({line[0]}, {line[1]}) = {line[2]}. Должно быть {min(int(line[0]), int(line[1]))}")
        return flag
    
flags = [0, 0, 0, 0]
if len(argv) == 1:
    flags[0] = (test_div())
    flags[1] = (test_mod())
    flags[2] = (test_max())
    flags[3] = (test_min())
else:
    for arg in argv[1:]:
        if arg == 'div':
            flags[0] = (test_div())
        if arg == 'mod':
            flags[1] = (test_mod())
        if arg == 'max':
            flags[2] = (test_max())
        if arg == 'min':
            flags[3] = (test_min())

for i in range(len(flags)):
    if flags[i] != 0:   
        if i == 0 and flags[i]:
            print("div -> ошибок нет")
        elif i == 1 and flags[i]:
            print("mod -> ошибок нет")
        elif i == 2 and flags[i]:
            print("max -> ошибок нет")
        elif i == 3 and flags[i]:
            print("min -> ошибок нет")