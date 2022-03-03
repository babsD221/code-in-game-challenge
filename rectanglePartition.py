import sys
import math

def add_toSegments(list_elements, num):
    listOfValues = list()
    for element in list_elements:
        new_value = abs(element -num)
        listOfValues.append(new_value)
    return listOfValues
cpt =0
w, h, count_x, count_y = [int(i) for i in input().split()]
list_x = [0,w]
list_y = [0,h]
list_segments_x = [w]
list_segments_y = [h]
for i in input().split():
    x = int(i)
    list_segments_x += add_toSegments(list_x,x)
    list_x.append(x)
for i in input().split():
    y = int(i)
    list_segments_y += add_toSegments(list_y,y)
    list_y.append(y)

for segment in  list_segments_y:
    if segment in list_segments_x:
        cpt += list_segments_x.count(segment)
# Write an answer using print
# To debug: 