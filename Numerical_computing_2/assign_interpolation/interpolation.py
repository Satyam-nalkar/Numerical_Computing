from math import factorial

class Interpolation:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.n = len(x)
        self.table = self._forward_difference_table()
        self.div_table = self._divided_difference_table()



    # forward difference table
    def _forward_difference_table(self):
        n = self.n
        table = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            table[i][0] = self.y[i]
        for j in range(1, n):
            for i in range(n - j):
                table[i][j] = table[i+1][j-1] - table[i][j-1]
        return table



    def _divided_difference_table(self):
        n = self.n
        table = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            table[i][0] = self.y[i]
        for j in range(1, n):
            for i in range(n - j):
                table[i][j] = (table[i+1][j-1] - table[i][j-1]) / (self.x[i+j] - self.x[i])
        return table



    def print_table(self):
        n = self.n
        print("Forward Difference Table:")
        for i in range(n):
            row = [f"{self.x[i]:<5}"]
            for j in range(n - i):
                row.append(f"{self.table[i][j]:<8.4f}")
            print("  ".join(row))
        #print()



    def print_div_table(self):
        print("Divided Difference Table:")
        for i in range(self.n):
            row = [f"{self.x[i]:<5}"]
            for j in range(self.n - i):
                row.append(f"{self.div_table[i][j]:<10.4f}")
            print("  ".join(row))
        print()



    def forward(self, value):
        self.print_table()
        h = self.x[1] - self.x[0]
        u = (value - self.x[0]) / h
        result = self.table[0][0]
        term = 1
        for i in range(1, self.n):
            term *= (u - (i-1))
            result += (term * self.table[0][i]) / factorial(i)
        return result
        



    def backward(self, value):
        self.print_table()
        h = self.x[1] - self.x[0]
        u = (value - self.x[-1]) / h
        result = self.table[self.n-1][0]
        term = 1
        for i in range(1, self.n):
            term *= (u + (i-1))
            result += (term * self.table[self.n-i-1][i]) / factorial(i)
        return result



    def lagrange(self, value):
        result = 0.0
        for i in range(self.n):
            term = self.y[i]
            for j in range(self.n):
                if j != i:
                    term *= (value - self.x[j]) / (self.x[i] - self.x[j])
            result += term
        return result



    def divided_difference(self, value):
        self.print_div_table()
        result = self.div_table[0][0]
        term = 1
        for i in range(1, self.n):
            term *= (value - self.x[i-1])
            result += term * self.div_table[0][i]
        return result



