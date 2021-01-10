hash = dict()

hash['a'] = ["apple"]
hash['b'] = ["banana"]
hash['c'] = ['coconut']

hash['a'].append('avocado')
hash['b'].append('bleach')
hash['c'].append('chive')

req = input("What fruit do you want to search? ")

res_list = hash.get(req[0], "No such fruit is available!")

for res in res_list:
    if res == req:
        print(f"{res} is found")
else:
    print("No such fruit is available.")

# for key in hash.keys():
#     print(key)

# for val in hash.values():
#     print(val)