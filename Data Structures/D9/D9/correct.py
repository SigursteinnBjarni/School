import sys

lines = sys.stdin.read().splitlines()

no_bad = int(lines.pop(0))
bad = set(lines[:no_bad])

for url in lines[no_bad + 1:]:
    if url in bad:
        print('Possibly bad')
    else:
        print('OK')
