import random
from string import ascii_letters


def generate_test_string(length: int, max_num_size: int):
    ans = 0
    element = ""
    for i in range(length):
        typy_of_char = random.randint(0, 1)

        if typy_of_char == 0:
            element  += "".join(random.choices(ascii_letters, k=3))

        elif typy_of_char == 1:
            size = typy_of_char = random.randint(3, max_num_size)
            added_el = ""
            c = 0
            if size % 4 == 0:
                for i in range(size // 4):
                    a = "".join(random.choices(["0", "1"], k=4))
                    added_el += a
                    if a[0] == "0" or (a.count("1") <= 2 and a[1] + a[2] == "00"):
                        if c == 0:
                            c = 1
                    else:
                        c = 0
                ans += c
            else:
                added_el = "".join(random.choices(["0", "1"], k=size))
            element += added_el
            element  += "".join(random.choices(ascii_letters, k=2))

    return element, ans


for i in range(1):
    string, count = generate_test_string(100, 5)
    with open("test.txt", "+a", encoding="utf-8") as f:
        f.write(str(count) + " # " + string + "\n")

