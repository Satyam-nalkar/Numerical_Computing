import math
from Error_bound import NumericalIntegration

def f(x):
    return math.exp(x)   # f(x) = e^x


if __name__ == "__main__":
    # Input 
    print("Numerical Integration")
    a = float(input("Enter lower limit (a): "))
    b = float(input("Enter upper limit (b): "))
    n = int(input("Enter number of intervals (n): "))


    NI = NumericalIntegration(f)


    It, Et = NI.trapezoidal(a, b, n)
    Is1_3, Es1_3 = NI.simpson13(a, b, n)
    Is3_8, Es3_8 = NI.simpson38(a, b, n)


    print("Results:")
    print(f"Trapezoidal Rule: I = {It:.6f}, Error Bound = {Et:.6e}")
    print(f"Simpson 1/3 Rule: I = {Is1_3:.6f}, Error Bound = {Es1_3:.6e}")
    print(f"Simpson 3/8 Rule: I = {Is3_8:.6f}, Error Bound = {Es3_8:.6e}")

    # integral of e^x from a to b = e^b - e^a    
    exact = math.exp(b) - math.exp(a)
    print(f"\nExact Value = {exact:.6f}")
