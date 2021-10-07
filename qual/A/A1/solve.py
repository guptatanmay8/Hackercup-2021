from collections import Counter

inp = open('consistency_chapter_1_input.txt','r')
out = open('output.txt','w')

first=1
tt=-1
for N in inp:
    tt+=1
    if first:
        t=int(N.strip())
        first=0
        tt-=1
        continue
    s=N.strip()

    n=len(s)
    c=Counter(s)
    vvs={'A','E','I','O','U'}
    vs=0
    for ele in s:
        if ele in vvs:
            vs+=1
    cons=n-vs
    mostc,mostv=0,0
    for i in range(65,91):
        char=chr(i)
        if char in vvs:
            mostv=max(mostv,c[char])
        else:
            mostc=max(mostc,c[char])
    ans1=cons+2*(vs-mostv)
    ans2=vs+2*(cons-mostc)
    ans=min(ans1,ans2)
    answer='Case #'+str(tt+1)+': '+str(ans)+'\n'
    out.write(answer)