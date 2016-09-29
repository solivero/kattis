smallest = input()
values = map(int, raw_input().split())

def tape_needed(size, count, long_s, short_s):
    stock = values[size-2]
    tape_lenght = (count/2)*long_s
    if stock < count:
        if size == smallest:
            return None
        needed = tape_needed(
            size+1,
            (count-stock)*2,
            short_s,
            long_s/2.0,
        )
        if needed:
            return tape_lenght + needed
    else:
        return tape_lenght

all_the_tape = tape_needed(2, 2, 2**(-3.0/4), 2**(-5.0/4))
if all_the_tape:
    print all_the_tape
else:
    print "impossible"
