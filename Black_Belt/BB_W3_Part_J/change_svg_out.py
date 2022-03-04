with open("pic.svg") as f:
    data = f.read()
    print(data)
    data = data.split('\\"')
    print(data)
    
    with open('new_pic.svg', 'w') as f2:
        f2.write('"'.join(data))