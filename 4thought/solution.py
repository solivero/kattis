import itertools
solutions = {}
NO_SOLUTION = "no solution"
operators = ('+', '-', '*', '/')
for operations in itertools.product(operators, repeat=3):
    solution = "4"
    for operation in operations:
        solution += " {} 4".format(operation)
    result = eval(solution)
    solutions[result] = solution
testcase_count = input()
for i in range(testcase_count):
    x = input()
    if -60 <= x <= 256:
        try:
            print "{} = {}".format(solutions[x], x)
        except:
            print NO_SOLUTION
    else:
        print NO_SOLUTION


