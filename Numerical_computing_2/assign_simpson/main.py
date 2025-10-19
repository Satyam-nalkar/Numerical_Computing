from Simpson import NumericalIntegration


def read_data_from_file(filename):
    with open(filename, "r") as f:
        n = int(f.readline().strip())
        x = list(map(float, f.readline().split()))
        y = list(map(float, f.readline().split()))
    return x, y


if __name__ == "__main__":
    # Trapezoidal aur Simpson 1/3
    x1, y1 = read_data_from_file("input.txt")
    interp1 = NumericalIntegration(x1, y1)
    print("Trapezoidal Integration Result:", interp1.trapezoidal())
    print("Simpson's 1/3 Rule Integration Result:", interp1.simpson_one_third())
    print()  


    # Simpson 3/8 
    x2, y2 = read_data_from_file("input_3_8.txt")
    interp2 = NumericalIntegration(x2, y2)
    print("Simpson's 3/8 Rule Integration Result:", interp2.simpson_three_eighth())
