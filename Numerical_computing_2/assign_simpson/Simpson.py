class NumericalIntegration:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.n = len(x)

    def trapezoidal(self):
        h = self.x[1] - self.x[0] 
        result = self.y[0] + self.y[-1]
        for i in range(1, self.n - 1):
            result += 2 * self.y[i]
        result *= h / 2
        return result


#Simpson 1/3 rule
    def simpson_one_third(self):
        if (self.n - 1) % 2 != 0:
            raise ValueError("Simpson's 1/3 rule requires an even number of intervals")
        
        h = self.x[1] - self.x[0]
        result = self.y[0] + self.y[-1]

        # 4 * (odd indices)
        for i in range(1, self.n - 1, 2):
            result += 4 * self.y[i]

        # 2 * (even indices)
        for i in range(2, self.n - 1, 2):
            result += 2 * self.y[i]

        result *= h / 3
        return result


 #Simpson 3/8 rule
    def simpson_three_eighth(self):
        if (self.n - 1) % 3 != 0:
            raise ValueError("Simpson's 3/8 rule requires number of intervals to be a multiple of 3")
        
        h = self.x[1] - self.x[0]
        result = self.y[0] + self.y[-1]

        for i in range(1, self.n - 1):
            if i % 3 == 0:
                result += 2 * self.y[i]
            else:
                result += 3 * self.y[i]

        result *= 3 * h / 8
        return result