# My solution:
import re
string = 'HaHaHaHa'
matches = re.findall('(?=(aHa))', string) # using positive lookahead
print(len(matches))
