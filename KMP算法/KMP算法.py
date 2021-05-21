s = input().strip()
p = input().strip()

nxt = []

def buildnxt():
    nxt.append(0)
    x = 1
    now = 0

    while x < len(p):
        if p[x] == p[now]:
            x += 1
            now += 1
            nxt.append(now)
        elif now:
            now = nxt[now - 1]
        else:
            nxt.append(0)
            x += 1

def search():
    tar = 0
    pos = 0

    while tar < len(s):
        if s[tar] == s[pos]:
            tar += 1
            pos += 1
        elif pos:
            pos = nxt[pos - 1]
        else:
            tar += 1

        if pos == len(p):
            print(tar - pos + 1)
            pos = nxt[pos - 1]

buildnxt()
search()
print(' '.join(map(str, nxt)))
