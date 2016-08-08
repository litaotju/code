import sys
import os

records = []
rs = dict()
for line in sys.stdin:
    filename, lineno = line.split()
    filename = os.path.basename(filename)
    if len(filename) > 16:
        filename = filename[-16:]
    if (filename, lineno) not in rs:
    	rs[(filename, lineno)] = 1
        records.append((filename, lineno))
    else:
        rs[(filename, lineno)] += 1
    if len(records) > 8:
        oldest = records[0]
       	del rs[oldest]
        
for r in records:
    print "{} {} {}".format( r[0], r[1], rs[r])