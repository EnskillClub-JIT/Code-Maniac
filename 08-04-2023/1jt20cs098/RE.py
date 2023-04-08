import re 

string = "Hello World"

pattern = re.compile("Hel?lo")

match = pattern.match(string)

if match:
    print("true")
else:
    print("false")