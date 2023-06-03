import random

# Open the file in write mode
with open("output.txt", "w") as file:
    for _ in range(10000000):
        random_number = random.randint(0, 9999999999999999999)
        file.write(str(random_number) + " ")
