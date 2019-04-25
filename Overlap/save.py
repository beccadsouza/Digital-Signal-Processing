from itertools import chain

def circular_convolution(x,h):
    y = []
    for n in range(len(x)):
        temp = 0
        for k in range(2*len(x)-1):
            temp_x = x[k] if k in range(len(x)) else 0
            temp_h = h[n-k] if n-k in range(len(x)) else 0
            temp += temp_x*temp_h
        y.append(temp)
    return y

x = list(map(int, input("Enter signal x : ").strip(" ").split(" ")))
h = list(map(int, input("Enter signal h : ").strip(" ").split(" ")))
N = int(input("Enter value of N: "))
M = len(h)
L = N - M + 1
print("\nValue of L : {0}\n".format(L))
x_n = [[0]*(M-1) + x[:L]]
h_n = h + [0]*(L-1)
y_n = []
X_k = []

x_temp = x
while True:
    x_temp = x_temp[L:]
    if len(x_n[-1]) < N:
        x_n[-1] = x_n[-1] + [0]*(N - len(x_n[-1]))
        break
    x_n.append(x_n[-1][-(M-1):] + x_temp[:L])

print("Number of segments : {0}\n\nThe segments are : \n".format(len(x_n)))
for i in x_n:
    print("{",", ".join([str(j) for j in i]),"}")

for i in range(len(x_n)):
    y_n.append(circular_convolution(x_n[i],h_n))
print("\nCircular convolution of each segment is : \n")
for i in y_n:
    print("{",", ".join([str(j) for j in i]),"}")

print("\nDiscarding the first M-1 values in each y(n) segment and combining them we get - ")
[X_k.append(y[M-1:]) for y in y_n]
print('{',", ".join([str(j) for j in list(chain.from_iterable(X_k))]),'}','\n')
