import cv2
import numpy as np
img = cv2.imread('./2.jpg')

kernel = np.ones((5,5), np.float32)/25
temp = cv2.filter2D(img,-1,kernel)
temp = cv2.GaussianBlur(temp,(5,5),0)
temp = cv2.medianBlur(temp,5)
temp = cv2.GaussianBlur(temp,(11,11),0)
temp = cv2.medianBlur(temp,5)
temp = cv2.medianBlur(temp,5)
temp = cv2.medianBlur(temp,5)
temp = cv2.GaussianBlur(temp,(11,11),0)
temp = cv2.GaussianBlur(temp,(13,13),0)
temp = cv2.GaussianBlur(temp,(15,15),0)
temp = cv2.GaussianBlur(temp,(11,11),0)
cv2.imshow('Dst', temp)
cv2.imwrite('3.jpg',temp)
print(temp.shape)
cv2.waitKey(0)
cv2.destroyAllWindows()
