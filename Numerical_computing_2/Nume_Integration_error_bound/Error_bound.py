import math

class NumericalIntegration:
    def __init__(self, func):
        self.f = func

    # For Trapezoidal Rule error
    def f2(self, x):
        return self.f(x)   

    # For Simpson’s Rule error
    def f4(self, x):
        return self.f(x)   


    # Trapezoidal Rule
    def trapezoidal(self, a, b, n):
        h = (b - a) / n
        s = self.f(a) + self.f(b)
        for i in range(1, n):
            s += 2 * self.f(a + i * h)
        I = (h / 2) * s

        # Error bound
        E = -((b - a)**3 / (12 * n**2)) * self.f2(b)
        return I, E


    # Simpson’s 1/3 Rule
    def simpson13(self, a, b, n):
        if n % 2 != 0:
            raise ValueError("n must be even for Simpson’s 1/3 rule")
        h = (b - a) / n
        s = self.f(a) + self.f(b)
        for i in range(1, n):
            if i % 2 == 0:
                s += 2 * self.f(a + i * h)
            else:
                s += 4 * self.f(a + i * h)
        I = (h / 3) * s

        # Error bound
        E = -((b - a)**5 / (180 * n**4)) * self.f4(b)
        return I, E


    # Simpson’s 3/8 Rule
    def simpson38(self, a, b, n):
        if n % 3 != 0:
            raise ValueError("n must be multiple of 3 for Simpson’s 3/8 rule")
        h = (b - a) / n
        s = self.f(a) + self.f(b)
        for i in range(1, n):
            if i % 3 == 0:
                s += 2 * self.f(a + i * h)
            else:
                s += 3 * self.f(a + i * h)
        I = (3 * h / 8) * s

        # Error bound
        E = -((3 * (b - a)**5) / (80 * n**4)) * self.f4(b)
        return I, E
