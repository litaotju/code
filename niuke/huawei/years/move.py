import re
import sys
## handle the multiple test case
for line in sys.stdin:
    moves = line.split(";")
    cord = [0, 0]
    for move in moves:
        move = move.strip()
        m = re.match(r"([AWSD])(\d{1,2})", move)
        direc = None
        steps = 0
        if m is not None:
            direc = m.groups()[0]
            steps = int(m.groups()[1])
            #print direc, steps
        if direc == "A":
            cord[0] -= steps
        elif direc == "D":
            cord[0] += steps
        elif direc == "W":
            cord[1] += steps
        else:
            cord[1] -= steps
    print "{},{}".format(cord[0], cord[1])