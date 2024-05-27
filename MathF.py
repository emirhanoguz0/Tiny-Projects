class MathF:

    def can_be_divisible(a,b):
        i = 0
        while a % b == 0 :
            i = i + 1
            a = a/b
        return f"{(b**i * a + b**i%b):.0f} is {i} times divisible by {b}."

    def Factorization(x):

        list = []
        for a in range(2,x):
            i = 0
            while x % a == 0:
                i = i + 1
                x = x/a
            if i != 0:
                list.append(f"{a}^{i}")
        return list