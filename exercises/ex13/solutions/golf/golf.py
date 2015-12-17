p=print
a=A=b=''
i=26
while i:l=chr(123-i);L=chr(91-i);a+=l;A+=L;b+=L+l;i-=1
c='-'*23
p(A+a);p(b);p(c)
while b:p('| %-20s|'%' '.join(b[:10]));b=b[10:]
p(c)
d='apple','grape','lemon','olive'
for e in a:
 if e in'aglo':b+='%s begins with %%s, '%d[i]%e;e=e+': ',d[i];i+=1
 p(list(e))
p(b[:-2])