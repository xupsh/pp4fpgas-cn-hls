import numpy as np
detection_file = 'samples.npy'
detections = None
if detection_file is not None:
    detections = np.load(detection_file)
np.savetxt('samples.txt', detections, fmt='%0.18f')

f = open('samples.txt')
out = open('complex.txt', "w")
lines = f.readlines()
for line in lines:
    for i in line:
        if i == "+":
            out.write(" ")
        elif i == "-":
            out.write(" -")
        elif i == "(":
            i = i
        elif i == ")":
            i = i
        elif i == "j":
            i = i
        else:
            out.write(str(i))
    #out.write("\n")

    #print(line)

f.close
