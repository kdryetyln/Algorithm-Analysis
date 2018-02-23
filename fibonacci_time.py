
# coding: utf-8

# In[1]:


import time
millis1=int(round(time.time()))
print(millis1)
time.sleep(5)
millis2=int(round(time.time()))
print(millis2)
print(millis2-millis1)


# In[2]:


def fibo_rec(n):
    if(n<2):
        return n
    else:
        return fibo_rec(n-1)+fibo_rec(n-2)


# In[3]:


fibo_rec(0),fibo_rec(1),fibo_rec(2),fibo_rec(3),fibo_rec(4),fibo_rec(5)


# In[4]:


def fibo_loop(n):
    if(n<2):
        return n
    else:
        a=0
        b=1
    while(n>0):
        c=a+b
        a=b
        b=c
        n=n-1
    return c

def fibo_rec(n):
    if(n<2):
        return n
    else:
        return fibo_rec(n-1)+fibo_rec(n-2)

fibo_loop(0),fibo_loop(1), fibo_loop(2), fibo_loop(3),fibo_loop(4), fibo_loop(5)


# In[5]:


import matplotlib.pyplot as plt
for n in range(40):
    time1=int(round(time.time()))
    fibo_rec(n)
    time2=int(round(time.time()))
    print("recursive ve np olan :",n," için geçen süre : ",time2-time1,"saniye")
    time3=int(round(time.time()))
    fibo_loop(n)
    time4=int(round(time.time()))
    print("-----------------------------------------------------------")
    print("loop p(linear) olan : ",n," için geçen süre : ",time4-time3,"saniye")
    plt.plot([n,time2-time1])
    plt.plot([n,time4-time3])
    plt.xlabel("Orange : np values\n Blue : loop values")
    plt.show()

