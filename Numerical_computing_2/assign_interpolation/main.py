from interpolation import Interpolation

def read_data_from_file(filename):
    with open(filename, "r") as f:
        n = int(f.readline().strip())
        x = list(map(float, f.readline().split()))
        y = list(map(float, f.readline().split()))
        value = float(f.readline().strip())
    return x, y, value


if __name__ == "__main__":
    x, y, value = read_data_from_file("input.txt")
    interp = Interpolation(x, y)

    print("Forward:", interp.forward(value),"\n")
    print("Backward:", interp.backward(value),"\n")
    print("Lagrange:", interp.lagrange(value))
    print("Divided Difference:", interp.divided_difference(value))
